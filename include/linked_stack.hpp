#pragma once

#include <ostream>

#include "private/node.hpp"   // SinglyNode, Element
#include "private/stack.hpp"  // Stack

namespace itis {

/**
 * Стек на базе односвязного списка.
 * Реализует функционал интерфейса Stack.
 *
 * 0 -> 1 -> 2 -> 3 -> nullptr
 * вершина стека (top) = 0
 */
struct LinkedStack final : Stack {
 private:
  // поля структуры
  int size_{0};               // кол-во элементов
  SinglyNode *top_{nullptr};  // указатель на вершину стека

 public:
  /**
   * Высвобождение выделенной стеком памяти.
   */
  ~LinkedStack() override;

  /**
   * Добавление элемента на вершину стека.
   *
   * 0 -> 1 -> nullptr   => push(e) => e -> 0 -> 1 -> nullptr
   * {size = 2, top = 0} =>         => {size = 3, top = e}
   *
   * @param e - значение добавляемого элемента
   */
  void Push(Element e) override;

  /**
   * Удаление элемента на вершине стека.
   *
   * 0 -> 1 -> nullptr   => pop() => 1 -> nullptr
   * {size = 2, top = 0} =>       => {size = 1, top = 1}
   *
   * @throws logic_error в случае применения операции над пустым стеком
   */
  void Pop() override;

  /**
   * Получение элемента на вершине стека.
   * @return значение элемента или ничего, если стек пустой
   */
  std::optional<Element> Peek() const override;

  /**
   * Удаление всех элементов стека.
   * Эквивалентно вызову деструктора.
   */
  void Clear() override;

  /**
   * Проверка является ли стек пустым.
   * @return стек пустой - true, иначе - false
   */
  bool IsEmpty() const override;

  /**
   * Количество элеметов в стеке.
   * @return неотрицательное число
   */
  int size() const override;

 private:
  // оператор вывода
  friend std::ostream &operator<<(std::ostream &, const LinkedStack &);
};

}  // namespace itis