#pragma once

/**
 * @class Context
 * @brief Класс, представляющий контекст, передаваемый в обработчики событий.
 *
 * В данном примере класс пустой, но его можно расширить по необходимости.
 */
class Context
{
public:
  Context() = default;
  ~Context() = default;

  // Добавьте необходимые поля и методы для контекста

  bool operator==(const Context &other) const
  {
    // Для пустого класса всегда возвращаем true
    return true;
  }
};
