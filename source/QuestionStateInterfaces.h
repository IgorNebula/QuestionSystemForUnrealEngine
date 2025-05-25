#include <iostream>
#include <vector>

/*
Базовый интерфейс для состояний
 */

class IQuestState
{
public:
  virtual ~IQuestState() {}
  virtual void enter() = 0;
  virtual void exit() = 0;
  virtual void handleEvent(const std::string &event) = 0;
};

/*
 Интерфейс для передачи сообщений между ветвями
*/

class IsignalHandler
{
public:
  virtual void sendSignal(const std::string &signal) = 0;
  virtual void receiveSignal(const std::string &signal) = 0;
};