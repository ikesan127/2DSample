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

	/** クリア表示用テキスト */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextClear;

	/** GameOver表示用テキスト */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextGameOver;

	/** キャラクターデータテーブル */
    UPROPERTY(EditAnywhere, Category = "Data")
    UDataTable* CharaDataTable;

    /** 敵データテーブル */
    UPROPERTY(EditAnywhere, Category = "Data")
    UDataTable* EnemyDataTable;

	/** プログレスバー更新用メソッド */
    void UpdateEnemyHPBar();

public:
    /** ダメージ計算を行うメソッド */
    int32 CalculateDamage(int32 AttackDamage, float DefenceRate);

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnAttackButtonClicked();
	// ----------------------------------------
	// プレイヤー
	// ----------------------------------------
    /** プレイヤーの最大体力 */
    float PlayerMaxHp;

    /** プレイヤーの体力 */
    float CurrentPlayerHp;

	/** プレイヤーの攻撃力 */
    int32 PlayerAttackDamage;

    /** プレイヤーの防御率 */
    float PlayerDefenceRate;

	// ----------------------------------------
	// 敵
	// ----------------------------------------
	/** 敵の名前 */
    FString EnemyName;

    /** 敵の最大体力 */
    float MaxEnemyHp;

	/** 敵の体力 */
	float CurrentEnemyHp;

    /** 敵の攻撃力 */
    int32 EnemyAttackDamage;

    /** 敵の防御率 */
    float EnemyDefenceRate;

    UFUNCTION()
    void CloseWidget();

	FTimerHandle DelayTimerHandle;
};
