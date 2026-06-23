// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/ProgressBar.h"
#include "CharacterData.h"

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
}

void UBattleWidget::OnAttackButtonClicked(){
    TextHp->SetText(FText::FromString(TEXT("Hello")));
}