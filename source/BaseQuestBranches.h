#include <iostream>
#include <vector>
#include "QuestionStateInterfaces.h"

/*
Родительский класс для главного квеста
*/
class MainQuestBranch : public QuestStateInterface, public ISignalHandler
{
public
  void enter() override;
  void exit() override;
  void handleEvent(const std::string &event) override;
  void sendSignal(const std::string &event) override;
  void receiveSignal(const std::string &event) override;
};

/*
Родительский класс для побочных квестов
*/
class SideQuestBranch : public IQusetState, public IsignalHandler
{
public:
  void enter() override;
  void exit() override;
  void handleEvent(const std::string &event) override;
  void sendSignal(const std::string &event) override;
  receiveSignal(const std::string &event) override;
};