#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EnemyData.generated.h"

/** 
 * 敵情報用構造体
 */
USTRUCT(BlueprintType)
struct FEnemyData : public FTableRowBase
{
    GENERATED_BODY()

    /** 敵の名前 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString EnemyName;

    /** 敵の最大体力 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 EnemyMaxHp;

    /** 敵の防御率 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EnemyDefenceRate;
};
