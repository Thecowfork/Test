// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"




AFloor::AFloor()
{
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->InitBoxExtent(FVector(HalfXY, HalfXY, HalfZ));
	SetRootComponent(BoxComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Floor(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	StaticMeshComponent->SetStaticMesh(Floor.Object);
	StaticMeshComponent->SetRelativeScale3D(FVector(HalfXY / XYZScale, HalfXY / XYZScale, HalfZ / XYZScale));
	StaticMeshComponent->SetRelativeLocation(FVector(0, 0, -HalfZ));


}


// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
	this->SetMaterial(TEXT("Material/'Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AFloor::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AFloor::OnOverlapEnd);
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AFloor::SetCollision(ECollisionEnabled::Type Type)
{
	StaticMeshComponent->SetCollisionEnabled(Type);
	if (Type == ECollisionEnabled::QueryOnly)
	{
		StaticMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	}
	else
	{
		StaticMeshComponent->SetCollisionResponseToChannels(ECollisionResponse::ECR_Block);
	}
}
void AFloor::SetMaterial(FString Value)
{
	UMaterialInterface* Material = LoadObject<UMaterialInterface>(NULL, Value);
	StaticMeshComponent->SetMaterial(0, Material);
}

void AFloor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBody)
{
	BlockActorName = OtherActor->GetName();
	IsBlock = true;
}
void AFloor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBody)
{
	BlockActorName = nullptr;
	IsBlock = false;
}