// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActor.h"

// Sets default values
AMyTestActor::AMyTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Root");
	
	UStaticMesh* sphereMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("'StaticMesh'/Engine/BasicShapes/Sphere.Sphere")).Object;
	
	mesh->SetStaticMesh(sphereMesh);
	this->SetRootComponent(mesh);


}

// Called when the game starts or when spawned
void AMyTestActor::BeginPlay()
{
	Super::BeginPlay();

	Hello(name);
}

// Called every frame
void AMyTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTestActor::Hello(FString input)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, input);
}

