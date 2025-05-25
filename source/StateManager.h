#pragma once

#include <memory>
#include <string>
#include <functional>
#include "QuestionStateInterfaces.h"

<<<<<<< HEAD
class Context; // Forward declaration

=======
>>>>>>> c4f17cd1fac00b27a842bf79c2401b5cf69a8871
/**
 * @class StateManager
 * @brief Класс для управления текущим состоянием квеста.
 *
 * Отвечает за установку текущего состояния, обработку событий,
 * а также вход и выход из текущего состояния.
 */
class StateManager
{
public:
  StateManager();

  ~StateManager();
  /**
   * @brief Устанавливает текущее состояние квеста.
   * @param state Умный указатель на новое состояние.
   */
  void setCurrentState(std::shared_ptr<IQuestState> state);
  /**
   * @brief Обрабатывает событие, вызывая переданный обработчик.
   * @param event Имя события.
   * @param handler Функция-обработчик события.
   * @param context Контекст, передаваемый обработчику.
   */
  void handleEvent(const std::string &event, std::function<void(Context &)> handler, Context &context);

  /**
   * @brief Выполняет действия при входе в текущее состояние.
   */
  void enterCurrentState();

  /**
   * @brief Выполняет действия при выходе из текущего состояния.
   */
  void exitCurrentState();

private:
  std::shared_ptr<IQuestState> currentState; ///< Текущее состояние квеста.
<<<<<<< HEAD
};
=======
};
>>>>>>> c4f17cd1fac00b27a842bf79c2401b5cf69a8871
