// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WidgetManageActor.generated.h"

class UTitleMenuWidget;

UCLASS()
class SAMPLE_API AWidgetManageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AWidgetManageActor();
	/** タイトルメニュー画面 */
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UTitleMenuWidget> TitleMenuWidget;

private:
	UPROPERTY()
	UTitleMenuWidget* TitleMenuInstance;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
