#include "StateManager.h"

StateManager::StateManager() : currentState(nullptr)
{
}

StateManaget::~StateManager()
{
  if (currentState)
  {
    currentState->Exit();
  }
}

void StateManager::setCurrentState(std::shared_ptr<IQuestState> state)
{
  if (currentState)
  {
    currentState->exit();
  }
  currentState = state;
  if (currentState)
  {
    currentState->enter();
  }

  void StateManager::handleEvent(const std::string &event, std::function<void(Context &)> hendler, Context &context)
  {
    if (currentState)
    {
      currentCtate->handleEvent(event, handler, context);
    }
  }

  void StateManager::enterCurrentState()
  {
    if (currentState)
    {
      currentState->enter();
    }
  }

  void StateManager::exitCurrentState()
  {
    if (currentState)
    {
      currentState->exit();
    }
  }
}