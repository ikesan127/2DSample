// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleMenuWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "BattleWidget.h"

/** 
 * タイトル画面向けC++ファイル
 */

void UTitleMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (StartButton){
        StartButton->OnClicked.AddDynamic(this, &UTitleMenuWidget::OnStartButtonClicked);
    }
    TextTest->SetText(FText::FromString(TEXT("Hello")));
}

/** スタートボタン押下時 */ 
void UTitleMenuWidget::OnStartButtonClicked(){
    TextTest->SetText(FText::FromString(TEXT("Clicked StartButton")));
    if (BattleWidgetInstance){
        BattleWidgetInstance->AddToViewport(1000);
        return;
    }
    if (BattleWidget){
        BattleWidgetInstance = CreateWidget<UBattleWidget>(GetWorld(), BattleWidget);
        if (BattleWidgetInstance){
            BattleWidgetInstance->AddToViewport(1000);
        }
    }
}
