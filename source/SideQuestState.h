#pragma once

#include <iostream>
#include <functional>
#include "QuestionStateInterfaces.h"

class SideQuestState : public IQuestState, public ISignalHandler
{
};