// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPickup.h"
#include "cmath"


// Sets default values
AMovingPickup::AMovingPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPickup::BeginPlay()
{
	Super::BeginPlay();
	pos = GetActorLocation();
	theta = 0.0;
	radius = 3000;
	speed = 0.0035;
}

// Called every frame
void AMovingPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	theta += speed;
	if (theta > 360) {
		theta -= 360;
	}

	pos.X = radius * cos(theta);
	pos.Y = radius * sin(theta);
	SetActorLocation(pos);
}

