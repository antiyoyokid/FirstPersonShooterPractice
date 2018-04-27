// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Cube.generated.h"


UCLASS()
class ATTEMPT1_API ACube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACube();
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Rock;

	UPROPERTY(EditAnywhere)
		UBoxComponent* Cube;

	UPROPERTY(EditAnywhere)
		float cubeSpeed = 0.0f;
	UPROPERTY(EditAnywhere)
		bool movementY = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float RunningTime;

	
	
};
