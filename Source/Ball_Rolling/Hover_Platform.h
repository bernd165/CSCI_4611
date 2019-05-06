// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Hover_Platform.generated.h"

UCLASS()
class BALL_ROLLING_API AHover_Platform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHover_Platform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool going_up = true;
	FVector start_pos;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		float speed = 75;

	UPROPERTY(EditAnywhere)
		float max_height = 500;
};
