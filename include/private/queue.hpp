#pragma once

#include <optional>

#include "private/element.hpp"  // Element

namespace itis {

/**
 * Интерфейс Queue.
 * Определяется функционал очереди вне зависимости от способа ее реализации.
 * Методы интерфейса являются абстрактными функциями, т.е. функциями без определения.
 * Функции необходимо переопределить в дочерних структурах.
 */
struct Queue {
 public:
  // деструктор - реализация по умолчанию (т.е. пустой)
  virtual ~Queue() = default;

  // === абстрактные методы ==

  /**
   * Добавление элемента в конец очереди.
   * @param e - значение элемента
   */
  virtual void Enqueue(Element e) = 0;

  /**
   * Удаление элемента из начала очереди.
   */
  virtual void Dequeue() = 0;

  /**
   * Удаление всех элементов очереди.
   */
  virtual void Clear() = 0;

  /**
   * Получение элемента в начале очереди.
   * @return значение элемента или ничего, если очередь пустая
   */
  virtual std::optional<Element> front() const = 0;

  /**
   * Получение элемента в конце очереди.
   * @return значение элемента или ничего, если очередь пустая
   */
  virtual std::optional<Element> back() const = 0;

  /**
   * Проверка является ли очередь пустой.
   * @return очередь пустая - true, иначе - false.
   */
  virtual bool IsEmpty() const = 0;

  /**
   * Количество элементов в очереди.
   * @return неотрицательное число
   */
  virtual int size() const = 0;
};

}  // namespace itis