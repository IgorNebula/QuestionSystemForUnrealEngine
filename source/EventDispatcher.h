#pragma once

#include <string>
#include <functional>
#include "QuestionStateInterfaces.h"
#include "StateManager.h"

/**
 * @class EventDispatcher
 * @brief Класс для отправки событий в систему состояний квеста.
 *
 * Использует StateManager для передачи событий и вызова соответствующих обработчиков.
 */
class EventDicpatcher
{
  /**
   * @brief Конструктор.
   * @param stateManager Ссылка на менеджер состояний.
   */
  EventDispatcher(StateManager &stateManaget);

  /**
   * @brief Отправляет событие с обработчиком  и контекстом.
   *
   * @param event Имя события.
   * @param handler Функция-обработчик события.
   * @param context Контекст, передаваемый обработчику.
   */
  void dispatchEvent(const std::string &event, std::function<void(Context &)> handler, Context &context);

private:
  StateManager &stateManager; ///< Менеджер состояний для обработки событий.
};