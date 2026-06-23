// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BattleWidget.generated.h"

class UTextBlock;
class UButton;
class UProgressBar;

/**
 * 戦闘画面向けC++
 */
UCLASS()
class SAMPLE_API UBattleWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	UButton* AttackButton;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* EnemyHPBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextHp;

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnAttackButtonClicked();
};
