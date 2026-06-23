// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleMenuWidget.generated.h"

class UButton;
class UTextBlock;
class UBattleWidget;

/**
 * タイトル画面向けC++
 */
UCLASS()
class SAMPLE_API UTitleMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	UButton* StartButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextTest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UBattleWidget> BattleWidget;

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnStartButtonClicked();

	UPROPERTY()
	UBattleWidget* BattleWidgetInstance;
};
