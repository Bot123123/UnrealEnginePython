#pragma once


#include "GameFramework/Pawn.h"

#include "PyPawn.generated.h"



UCLASS(BlueprintType, Blueprintable)
class APyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	APyPawn();
	~APyPawn();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere , Category = "Python")
	FString PythonModule;

	UPROPERTY(EditAnywhere, Category = "Python")
	FString PythonClass;

	UPROPERTY(EditAnywhere, Category = "Python")
	bool PythonTickForceDisabled;

	UFUNCTION(BlueprintCallable, Category = "Python")
	void CallPythonPawnMethod(FString method_name);

	UFUNCTION(BlueprintCallable, Category = "Python")
	bool CallPythonPawnMethodBool(FString method_name);

	UFUNCTION(BlueprintCallable, Category = "Python")
	FString CallPythonPawnMethodString(FString method_name);

private:
	PyObject *py_pawn_instance;

	UFUNCTION()
	void PyOnActorBeginOverlap(AActor *overlapped, AActor *other);

	UFUNCTION()
	void PyOnActorClicked(AActor *touched_actor, FKey button_pressed);
};

