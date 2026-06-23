// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetManageActor.h"

#include "TitleMenuWidget.h"

// Sets default values
AWidgetManageActor::AWidgetManageActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWidgetManageActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (TitleMenuWidget){
		TitleMenuInstance = CreateWidget<UTitleMenuWidget>(GetWorld(), TitleMenuWidget);
		if (TitleMenuInstance){
			TitleMenuInstance->AddToViewport(500);
		}
	}
}

// Called every frame
void AWidgetManageActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

