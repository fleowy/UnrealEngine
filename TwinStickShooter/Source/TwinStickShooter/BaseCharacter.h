// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
	
	GENERATED_BODY()

public:
	
//Healt Property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BaseCharacter")
    float Health = 100;
//Is Dead Property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "BasicCharacter")
	bool isDead = false;
//Calculate death function
	virtual void CalculateDead();
//calculate health funtion
		UFUNCTION(BlueprintCallable, Category = "BasicCharacter")
			virtual void CalculateHealth(float delta);
#if WITH_EDITOR
	//Editor-center code for changing properstuies
		virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
			override;
#endif
public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
};
