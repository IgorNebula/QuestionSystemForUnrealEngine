#pragma once

#include <iostream>
#include <functional>
#include "QuestionStateInterfaces.h"

/**
 * @class MainQuestState
 * @brief Класс, реализующий состояние основного квеста.
 *
 * Реализует интерфейсы IQuestState и ISignalHandler для обработки
 * событий и передачи сигналов между ветвями квеста.
 */
class MainQuestState : public IQuestState, public ISignalHandler
{
public:
  /**
   * @brief Метод вызывается при входе в состояние основного квеста.
   */
  void enter() override
  {
    std::cout << "Entering Main Quest State" << std::endl;
  }
  /**
   * @brief Метод вызывается при выходе из состояния основного квеста.
   */
  void exit() ovveride
  {
    std::cout << "Exit Main Quest State" << std::endl;
  }
  /**
   * @brief Обрабатывает событие, переданное состоянию.
   * @param event Имя события.
   * @param handler Функция-обработчик события.
   * @param context Контекст, передаваемый обработчику.
   */
  void handleEvent(const std::string &event, std::function<void(Context &)> handler, Context &context) override
  {
    std::cout << "Main Quest State handling event: " << event << std::endl;
    handler(context);
  }
  /**
   * @brief Отправляет сигнал другим ветвям квеста.
   * @param signal Имя сигнала.
   */
  void sendSignal(const std::string &signal) override
  {
    std::cout << "Main Quest State sending signal: " << signal << std::endl;
  }
  /**
   * @brief Получает сигнал от других ветвей квеста.
   * @param signal Имя сигнала.
   */
  void receiveSignal(const std::string &signal) override
  {
    std::cout << "Main Quest State received signal: " << signal << std::endl;
  }
};