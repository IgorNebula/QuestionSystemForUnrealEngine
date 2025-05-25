#pragma once

#include <iostream>
#include <functional>
#include "QuestionStateInterfaces.h"

/**
 * @class SideQuestState
 * @brief Класс, реализующий состояние побочного квеста.
 *
 * Реализует интерфейсы IQuestState и ISignalHandler для обработки
 * событий и передачи сигналов между ветвями квеста.
 */
class SideQuestState : public IQuestState, public ISignalHandler
{
public:
  /**
   * @brief Метод вызывается при входе в состояние побочного квеста.
   */
  void enter() override
  {
    std::cout << "Entering Side Quest State" << std::endl;
  }

  /**
   * @brief Метод вызывается при выходе из состояния побочного квеста.
   */
  void exit() override
  {
    std::cout << "Exiting Side Quest State" << std::endl;
  }

  /**
   * @brief Обрабатывает событие, переданное состоянию.
   * @param event Имя события.
   * @param handler Функция-обработчик события.
   * @param context Контекст, передаваемый обработчику.
   */
  void handleEvent(const std::string &event, std::function<void(Context &)> handler, Context &context) override
  {
    std::cout << "Side Quest State handling event: " << event << std::endl;
    handler(context);
  }

  /**
   * @brief Отправляет сигнал другим ветвям квеста.
   * @param signal Имя сигнала.
   */
  void sendSignal(const std::string &signal) override
  {
    std::cout << "Side Quest State sending signal: " << signal << std::endl;
  }

  /**
   * @brief Получает сигнал от других ветвей квеста.
   * @param signal Имя сигнала.
   */
  void receiveSignal(const std::string &signal) override
  {
    std::cout << "Side Quest State received signal: " << signal << std::endl;
  }
};