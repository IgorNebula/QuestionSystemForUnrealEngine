#include <iostream>
#include <memory>
#include "StateManager.h"
#include "EventDispatcher.h"
#include "QuestFactoryAbstraction.h"

void exampleHandler(Context &context)
{
  std::cout << "Обработка контекста в примере. Квест прогресс: " << context.questProgress << std::endl;
  context.questProgress++;
}

int main()
{
  ConcreteQuestStateFactory factory;
  std::shared_ptr<IQuestState> mainQuestState(factory.createMainQuestState());
  StateManager stateManager;
  EventDispatcher eventDispatcher(stateManager);

  stateManager.setCurrentState(mainQuestState);
  stateManager.enterCurrentState();

  Context context;
  context.questProgress = 0;
  context.currentObjective = "Найти потерянный меч";

  eventDispatcher.dispatchEvent("StartQuest", exampleHandler, context);

  stateManager.exitCurrentState();

  return 0;
}
