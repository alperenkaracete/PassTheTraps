// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	startLocation = GetActorLocation();
	currentPos = GetActorLocation();
	SetActorLocation(currentPos);
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	movePlatform(DeltaTime);
	rotatePlatform(DeltaTime);

}

void AMovingPlatform::movePlatform(float deltaTime){

	if (platformShouldReturn()){

		FVector moveDirection = platformVelocity.GetSafeNormal();
		startLocation = startLocation + moveDirection * returnDistance; 
		SetActorLocation(currentPos);
		platformVelocity = -platformVelocity;
	}

	else {

		currentPos = GetActorLocation();
		currentPos = currentPos + (platformVelocity * deltaTime);
		SetActorLocation(currentPos);
	}
}

void AMovingPlatform::rotatePlatform(float deltaTime){

	AddActorLocalRotation(rotationVelocity * deltaTime);
}

bool AMovingPlatform::platformShouldReturn(){

	distance = getDistanceMoved();
	if (distance > returnDistance)
		return true;

	return false;	
}

float AMovingPlatform::getDistanceMoved() const{

	return FVector::Dist(startLocation,currentPos);	
}