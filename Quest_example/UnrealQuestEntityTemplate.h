// Unreal Engine C++ Actor template to integrate with the Quest System

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnrealQuestEntityTemplate.generated.h"

// Декларации для подготовки к Quest System Class
class UQuestStateManager;
class UQuestEventDispatcher;
class UQuestContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestEvent, const FString &, EventName);

UCLASS()
class AUnrealQuestEntityTemplate : public AActor
{
  GENERATED_BODY()

public:
  AUnrealQuestEntityTemplate();

protected:
  virtual void BeginPlay() override;

public:
  virtual void Tick(float DeltaTime) override;

  // Компоненты системы квеста
  UPROPERTY()
  UQuestStateManager *QuestStateManager;

  UPROPERTY()
  UQuestEventDispatcher *QuestEventDispatcher;

  UPROPERTY()
  UQuestContext *QuestContext;

  // Событие для перевода Quest Events
  UPROPERTY(BlueprintAssignable, Category = "Quest")
  FOnQuestEvent OnQuestEvent;

  // Функция для отправки события в систему квеста
  UFUNCTION(BlueprintCallable, Category = "Quest")
  void SendQuestEvent(const FString &EventName, TFunction<void(UQuestContext *)> Handler);

private:
  // Внутренняя функция для обработки Quest Event
  void HandleQuestEvent(const FString &EventName, TFunction<void(UQuestContext *)> Handler);
};
