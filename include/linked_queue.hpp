#pragma once

#include <ostream>

#include "private/node.hpp"   // SinglyNode, Element
#include "private/queue.hpp"  // Queue

namespace itis {

/**
 * Очередь на базе связного списка.
 * Реализует функционал интерфейса Queue.
 *
 * 0 -> 1 -> 2 -> 3 -> nullptr
 * начало очереди (front) = 0
 * конец очереди (back)   = 3
 */
struct LinkedQueue final : Queue {
 private:
  // поля структуры
  int size_{0};                 // кол-во элементов
  SinglyNode *front_{nullptr};  // начало очереди
  SinglyNode *back_{nullptr};   // конец очереди

 public:
  /**
   * Высвобождение выделенной очередью памяти.
   */
  ~LinkedQueue() override;

  /**
   * Добавление элемента в конец очереди.
   *
   * 0 -> 1 -> nullptr               => enqueue(e) => 0 -> 1 -> e -> nullptr
   * {size = 2, front = 0, back = 1} =>            => {size = 3, front = 0, back = e}
   *
   * @param e - значение добавляемого элемента
   */
  void Enqueue(Element e) override;

  /**
   * Удаление элемента из начала очереди.
   *
   * 0 -> 1 -> 2 -> nullptr          => dequeue() => 1 -> 2 -> nullptr
   * {size = 3, front = 0, back = 2} =>           => {size = 2, front = 1, back = 2}
   *
   * @throws logic_error при выполнении операции над пустой очередью
   */
  void Dequeue() override;

  /**
   * Удаление всех элементов очереди.
   * Эквивалентно деструктуру.
   */
  void Clear() override;

  /**
   * Получение элемента в начале очереди.
   * @return значение элемента или ничего, если очередь пустая
   */
  std::optional<Element> front() const override;

  /**
   * Получение элемента в конце очереди.
   * @return значение элемента или ничего, если очередь пустая
   */
  std::optional<Element> back() const override;

  /**
   * Проверка является ли очередь пустой.
   * @return очередь пустая - true, иначе - false.
   */
  bool IsEmpty() const override;

  /**
   * Количество элементов в очереди.
   * @return неотрицательное число
   */
  int size() const override;

 private:
  // оператор вывода
  friend std::ostream &operator<<(std::ostream &, const LinkedQueue &);
};

}  // namespace itis