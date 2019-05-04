// Fill out your copyright notice in the Description page of Project Settings.

#include "Hover_Platform.h"

// Sets default values
AHover_Platform::AHover_Platform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHover_Platform::BeginPlay()
{
	Super::BeginPlay();
	// Store the initial position of the platform
	start_pos = GetActorLocation();
}

// Called every frame
void AHover_Platform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector pos = GetActorLocation();

	// Ascend or descend, and switch direction if too low or high
	if (going_up) {
		pos.Z += speed * DeltaTime;
		if (pos.Z >= start_pos.Z + max_height) going_up = false;
	}
	else {
		pos.Z -= speed * DeltaTime;
		if (pos.Z <= start_pos.Z) going_up = true;
	}
	SetActorLocation(pos);
}