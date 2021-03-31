#pragma once

#include <optional>

#include "private/element.hpp"  // Element

namespace itis {

/**
 * Интерфейс Stack.
 * Определяет функционал стека вне зависимости от способа его реализации.
 * Методы интерфейса являются абстрактными функциями, т.е. функциями без тела / определения.
 * Функции необходимо переопределить в дочерних структурах.
 */
struct Stack {
 public:
  // деструктор - реализация по умолчанию (т.е. пустой)
  virtual ~Stack() = default;

  // === абстрактные методы  ===

  /**
   * Добавление элемента на вершину стека.
   * @param e - значение элемента
   */
  virtual void Push(Element e) = 0;

  /**
   * Удаление элемента на вершине стека.
   */
  virtual void Pop() = 0;

  /**
   * Получение элемента на вершине стека.
   * @return значение элемента или ничего, если стек пустой
   */
  virtual std::optional<Element> Peek() const = 0;

  /**
   * Удаление всех элементов стека.
   */
  virtual void Clear() = 0;

  /**
   * Проверка является ли стек пустым.
   * @return стек пустой - true, иначе - false
   */
  virtual bool IsEmpty() const = 0;

  /**
   * Количество элеметов в стеке.
   * @return неотрицательное число
   */
  virtual int size() const = 0;
};

}  // namespace itis