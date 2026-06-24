// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/ProgressBar.h"
#include "CharacterData.h"
#include "EnemyData.h"

void UBattleWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (AttackButton){
        AttackButton->OnClicked.AddDynamic(this, &UBattleWidget::OnAttackButtonClicked);
    }
    if (CharaDataTable){
        // プレイヤーのデータを取得
        FCharacterData* Row = CharaDataTable->FindRow<FCharacterData>(
            FName("C_001"), 
            TEXT("BattleWidget")
        );
        if (Row){
            TextHp->SetText(FText::Format(
                FText::FromString(TEXT("{0}/{1}")),
                FText::AsNumber(Row->MaxHP),
                FText::AsNumber(Row->MaxHP)
            ));
            PlayerAttackDamage = Row->AttackDamage;
            PlayerMaxHp = Row->MaxHP;
            CurrentPlayerHp = Row->MaxHP;
            PlayerDefenceRate = Row->DefenceRate;
        }
    }

    if (EnemyDataTable){
        // 敵データの取得
        FEnemyData* EnemyRow = EnemyDataTable->FindRow<FEnemyData>(
            FName("E_001"), 
            TEXT("BattleWidget")
        );
        if (EnemyRow){
            MaxEnemyHp = EnemyRow->EnemyMaxHp;
            CurrentEnemyHp = MaxEnemyHp;
            EnemyName = EnemyRow->EnemyName;
            EnemyDefenceRate = EnemyRow->EnemyDefenceRate;
            EnemyAttackDamage = EnemyRow->EnemyAttackDamage;

            // プログレスバーの更新
            if (EnemyHPBar) {
                EnemyHPBar->SetPercent(1);
            }
        }
    }
}

void UBattleWidget::UpdateEnemyHPBar()
{
    if (EnemyHPBar) {
        EnemyHPBar->SetPercent(CurrentEnemyHp / MaxEnemyHp);
    }
}

void UBattleWidget::OnAttackButtonClicked(){
    // 敵へのダメージ計算と更新
    int32 DamageToEnemy = CalculateDamage(PlayerAttackDamage, EnemyDefenceRate); 
    CurrentEnemyHp -= static_cast<float>(DamageToEnemy);

    if (CurrentEnemyHp < 0) {
        CurrentEnemyHp = 0;
    }

    UpdateEnemyHPBar();

    // プレイヤーへのダメージ計算と更新
    if (CurrentEnemyHp > 0) {
        int32 DamageToPlayer = CalculateDamage(EnemyAttackDamage, PlayerDefenceRate);
        CurrentPlayerHp -= static_cast<float>(DamageToPlayer);

        if (CurrentPlayerHp < 0) {
            CurrentPlayerHp = 0;
            TextGameOver->SetRenderOpacity(1.0f);
            GetWorld()->GetTimerManager().SetTimer(
                DelayTimerHandle,
                this,
                &UBattleWidget::CloseWidget,
                5.0f,
                false
            );
        }

        // 体力表示テキストの更新
        if (TextHp) {
            TextHp->SetText(FText::Format(
                FText::FromString(TEXT("{0}/{1}")),
                FText::AsNumber(static_cast<float>(CurrentPlayerHp)),
                FText::AsNumber(PlayerMaxHp)
            ));
        }
    } else {
        TextClear->SetRenderOpacity(1.0f);
        GetWorld()->GetTimerManager().SetTimer(
            DelayTimerHandle,
            this,
            &UBattleWidget::CloseWidget,
            5.0f,
            false
        );
    }
}

/**
 * ダメージ計算を行うメソッド
 * @param AttackDamage 攻撃力
 * @param DefenceRate 防御率
 * @return 計算されたダメージ量
 */
int32 UBattleWidget::CalculateDamage(int32 AttackDamage, float DefenceRate)
{
    if (AttackDamage > 0) {
        // ダメージ計算: 攻撃力 * (1 - 敵の防御率)
        return static_cast<int32>(static_cast<float>(AttackDamage) * (1.0f - DefenceRate));
    }
    return 0;
}

void UBattleWidget::CloseWidget()
{
    RemoveFromParent();
}