// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/ProgressBar.h"

void UBattleWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (AttackButton){
        AttackButton->OnClicked.AddDynamic(this, &UBattleWidget::OnAttackButtonClicked);
    }
}

void UBattleWidget::OnAttackButtonClicked(){
    TextHp->SetText(FText::FromString(TEXT("Hello")));
}