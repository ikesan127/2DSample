// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleMenuWidget.generated.h"

class UButton;
class UTextBlock;
class UBattleWidget;

/**
 * タイトル画面向けヘッダファイル
 */
UCLASS()
class SAMPLE_API UTitleMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/** 開始ボタン */
	UPROPERTY(meta = (BindWidget))
	UButton* StartButton;

	/** 終了ボタン */
	UPROPERTY(meta = (BindWidget))
	UButton* EndButton;

	/** タイトル表示用テキスト */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextTest;

	/** 戦闘画面UI */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UBattleWidget> BattleWidget;

protected:
	virtual void NativeConstruct() override;

private:
	/** スタートボタン押下時 */
	UFUNCTION()
	void OnStartButtonClicked();

	/** 終了ボタン押下時 */
	UFUNCTION()
	void OnEndButtonClicked();

	UPROPERTY()
	UBattleWidget* BattleWidgetInstance;
};
