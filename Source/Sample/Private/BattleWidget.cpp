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

            // プログレスバーの更新
            if (EnemyHPBar) {
                EnemyHPBar->SetPercent(CurrentEnemyHp / MaxEnemyHp);
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
    TextHp->SetText(FText::FromString(TEXT("Hello")));
}