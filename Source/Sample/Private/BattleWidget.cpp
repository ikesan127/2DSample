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
            PlayerAttackDamage = Row->AttackDamage; // プレイヤーの攻撃力を取得
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
            EnemyDefenceRate = EnemyRow->EnemyDefenceRate; // 敵の防御率を取得

            // プログレスバーの更新
            if (EnemyHPBar) {
                EnemyHPBar->SetPercent(1);
            }
        }
    }
}

void UBattleWidget::UpdateEnemyHPBar()
{
    if (MaxEnemyHp > 0) {
        if (EnemyHPBar) {
            EnemyHPBar->SetPercent(CurrentEnemyHp / MaxEnemyHp);
        }
    }
}

void UBattleWidget::OnAttackButtonClicked(){
    if (MaxEnemyHp > 0 && PlayerAttackDamage > 0) {
        // ダメージ計算メソッドを呼び出し、戻り値としてダメージを取得
        int32 Damage = CalculateDamage(PlayerAttackDamage, EnemyDefenceRate); 
        CurrentEnemyHp -= static_cast<float>(Damage);

        // 体力が負値になることを修正
        if (CurrentEnemyHp < 0) {
            CurrentEnemyHp = 0;
        }

        // 体力バーの更新
        UpdateEnemyHPBar();
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