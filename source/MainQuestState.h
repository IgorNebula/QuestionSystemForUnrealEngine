#pragma once

#include <iostream>
#include <functional>
#include "QuestionStateInterfaces.h"

class MainQuestState : public IQuestState, public ISignalHandler
{
};