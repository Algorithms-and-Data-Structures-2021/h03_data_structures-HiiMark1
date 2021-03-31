#pragma once

#include <ostream>

#include "private/element.hpp"  // Element
#include "private/stack.hpp"    // Stack

namespace itis {

/**
 * Стек на базе динамического массива.
 * Реализует функционал интерфейса Stack.
 *
 * [0 1 2 3 4 x x x], где вершина стека (top) = 4, x = Element::UNDEFINED
 */
struct ArrayStack final : Stack {
 private:
  // поля структуры
  int size_{0};             // кол-во элементов
  int capacity_{0};         // размеры выделенного участка памяти в куче
  Element *data_{nullptr};  // указатель на выделенный участок памяти в куче

 public:
  // константы структуры
  static constexpr int kDefaultCapacity = 10;
  static constexpr int kCapacityGrowthCoefficient = 5;

 public:
  /**
   * Создание стека определенной начальной емкости.
   * При отсутствии аргумента устанавливается значение по-умолчанию.
   *
   * ArrayStack(9) => [x x x x x x x x x], где x = Element::UNDEFINED
   *               => {size = 0, capacity = 9, top = x}
   *
   * @param capacity - положительное значение емкости стека
   * @throws invalid_argument при неположительном capacity
   */
  explicit ArrayStack(int capacity = kDefaultCapacity);

  /**
   * Освобождение выделенной стеком памяти.
   */
  ~ArrayStack() override;

  /**
   * Добавление элемента на вершину стека.
   * При нехватке емкости массива осуществляется его расширение.
   *
   * [0 1 2 x x]                       => push(e) => [0 1 2 e x]
   * {size = 3, capacity = 5, top = 2} =>         => {size = 4, capacity = 5, top = e}
   *
   * @param e - значение добавляемого элемента
   */
  void Push(Element e) override;

  /**
   * Удаление элемента на вершине стека.
   *
   * [0 1 2 x x]                       => pop() => [0 1 x x x]
   * {size = 3, capacity = 5, top = 2} =>       => {size = 2, capacity = 5, top = 1}
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
   * Емкость стека сохраняется.
   *
   * [0 1 x x x]                       => clear() => [x x x x x]
   * {size = 2, capacity = 5, top = 1} =>         => {size = 0, capacity = 5, top = x}
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

  /**
   * Емкость стека.
   * @return неотрицательное число
   */
  int capacity() const;

 private:
  /**
   * Увеличение емкости стека.
   * @param new_capacity
   */
  void resize(int new_capacity);

  // оператор вывода
  friend std::ostream &operator<<(std::ostream &, const ArrayStack &);
};

}  // namespace itis