#include "EventDispatcher.h"

EventDispatcher::EventDispatcher(StateManager &stateManager) : stateManager(stateManager)
{
}

void EventDispatcher::dispatchEvent(const std::string &event, std::function<void(Context &)> handler, Context &context)
{
  stateManager.handleEvent(event, handler, context);
}