#include <iostream>
#include <vector>
#include "MainQuestState.h"
#include "SideQuestState.h"

class IQuestStateFactory
{
public:
  virtual ~IQuestStatefactory() {}
  virtual IQuestState *createMainQuestState() = 0;
  virtual IQuestState *createSideQuestState() = 0;
};

class ConcreteQuestStateFactory : public IQuestStateFactory
{
public:
  IQuestState *createMainQuestState() override
  {
    return new MainQuestState();
  };
  IQuestState *createSideState() override
  {
    return new SideQuestState();
  }
};