// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PASSTHETRAPS_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY (EditAnywhere,Category = "Moving Platform")
	FVector startLocation;

	UPROPERTY (EditAnywhere,Category = "Moving Platform")
	FVector platformVelocity = FVector (800,0,0);

	UPROPERTY (VisibleAnywhere,Category = "Moving Platform")
	float distance;	

	UPROPERTY (EditAnywhere,Category = "Moving Platform")
	float returnDistance = 1000;

	UPROPERTY (VisibleAnywhere,Category = "Moving Platform")
	FVector currentPos;

	UPROPERTY (EditAnywhere,Category = "Rotating Platform")
	FRotator rotationVelocity;

private:
	void movePlatform (float deltaTime);	
	void rotatePlatform (float deltaTime);
	bool platformShouldReturn ();
	float getDistanceMoved () const;
	
};
