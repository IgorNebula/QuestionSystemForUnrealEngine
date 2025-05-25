#include <iostream>
#include <vector>
#include "QuestionStateInterfaces.h"

/*
Родительский класс для главного квеста
*/
class MainQuestBranch : public QuestStateInterface, public ISignalHandler
{
};

/*
Родительский класс для побочных квестов
*/
class SideQuestBranch : public IQusetState, public IsignalHandler
{
};