// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleMenuWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UTitleMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (StartButton){
        StartButton->OnClicked.AddDynamic(this, &UTitleMenuWidget::OnStartButtonClicked);
    }
    TextTest->SetText(FText::FromString(TEXT("Hello")));
}

void UTitleMenuWidget::OnStartButtonClicked(){
    TextTest->SetText(FText::FromString(TEXT("Clicked StartButton")));
    
}
