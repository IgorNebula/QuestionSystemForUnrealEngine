#include "StateManager.h"

StateManager::StateManager() : currentState(nullptr)
{
}

StateManager::~StateManager()
{
  if (currentState)
  {
    currentState->exit();
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
}

void StateManager::handleEvent(const std::string &event, std::function<void(Context &)> handler, Context &context)
{
  if (currentState)
  {
    handler(context);
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
