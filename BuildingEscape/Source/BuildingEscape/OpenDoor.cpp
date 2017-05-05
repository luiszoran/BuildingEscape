// Copyright Luis Zoran 2017

#include "BuildingEscape.h"
#include "OpenDoor.h"
#include "Grabber.h"

#define OUT

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
	Owner = GetOwner();

	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s has no PressurePlate"), *GetOwner()->GetName());
	}


}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalMassOfActorOnPlate() > TriggerMass) {
		OnOpen.Broadcast();
	} else {
		OnClose.Broadcast();
	}

}

float UOpenDoor::GetTotalMassOfActorOnPlate() {
	float TotalMass = 0.f;
	TArray<AActor*> OverlappingActors;

	if (!PressurePlate) return TotalMass;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for (auto* Actor : OverlappingActors ) {
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s is overlapping"), *Actor->GetName(), *GetOwner()->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("Total Mass: %f"), TotalMass);

	return TotalMass;
}


