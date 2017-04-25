// Copyright Luis Zoran 2017

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	UE_LOG(LogTemp, Warning, TEXT("%s has FRotator %s"), *Owner->GetName(), *Owner->GetActorRotation().ToString());

	FRotator NewRotation = FRotator(0.f, -60.f, 0.f);

	Owner->SetActorRotation(NewRotation);

	UE_LOG(LogTemp, Warning, TEXT("%s has now FRotator %s"), *Owner->GetName(), *Owner->GetActorRotation().ToString());
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

