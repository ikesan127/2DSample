// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BattleWidget.generated.h"

class UTextBlock;
class UButton;
class UProgressBar;
class UDataTable;

/**
 * 戦闘画面向けC++
 */
UCLASS()
class SAMPLE_API UBattleWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/** 攻撃ボタン */
	UPROPERTY(meta = (BindWidget))
	UButton* AttackButton;

	/** 敵のHPバー */
	UPROPERTY(meta = (BindWidget))
	UProgressBar* EnemyHPBar;

	/** キャラクターのHP表示用テキスト */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextHp;

	/** キャラクターデータテーブル */
    UPROPERTY(EditAnywhere, Category = "Data")
    UDataTable* CharaDataTable;

    /** 敵データテーブル */
    UPROPERTY(EditAnywhere, Category = "Data")
    UDataTable* EnemyDataTable;

	/** プログレスバー更新用メソッド */
    void UpdateEnemyHPBar();

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnAttackButtonClicked();

	/** 現在の敵の体力 */
	float CurrentEnemyHp;

    /** 敵の最大体力 */
    float MaxEnemyHp;

    /** 敵の名前 */
    FString EnemyName;
};
