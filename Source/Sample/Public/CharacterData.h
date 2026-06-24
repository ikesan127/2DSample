#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CharacterData.generated.h"
/** 
 * キャラクター情報用構造体
 */
USTRUCT(BlueprintType)
struct FCharacterData : public FTableRowBase
{
    GENERATED_BODY()

    /** キャラクター名 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString CharacterName;

    /** キャラクターの最大HP */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MaxHP;

    /** キャラクターの防御率 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float DefenceRate;

    /** キャラクターの攻撃力 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 AttackDamage;
};