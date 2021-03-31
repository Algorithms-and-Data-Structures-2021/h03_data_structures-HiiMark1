#pragma once

#include "private/element.hpp"  // Element

namespace itis {

/**
 * Структура односвязный "узел".
 * Обертка элементов односвязных структур данных (напр. Linked List, Linked Stack и Linked Queue).
 * P.S. ключевое слово final запрещает наследование структуры.
 */
struct SinglyNode final {
 public:
  // хранимые данные (перечисление)
  Element data;

  // указатель на следующий узел (хранит в себе адрес участка памяти)
  SinglyNode *next;

  /**
   * Создание узла с данными и указателем на следующий узел.
   *
   * @param e - данные узла
   * @param ptr указатель на следующий узел
   */
  SinglyNode(Element e, SinglyNode *ptr) : data{e}, next{ptr} {}
};

/**
 * Структура двусвязный "узел".
 * Обертка элементов двусвязных структур данных (напр. Linked Dequeue)
 */
struct DoublyNode final {
 public:
  // хранимые данные (перечисление)
  Element data;

  // указатель на следующий и предыдущий узел
  DoublyNode *next;
  DoublyNode *previous;

  /**
   * Создание узла с данными и указателем на предыдущий и следующий узел.
   *
   * @param e - данные узла
   * @param previous_ptr указатель на предыдущий узел
   * @param next_ptr указатель на следующий узел
   */
  DoublyNode(Element e, DoublyNode *previous_ptr, DoublyNode *next_ptr)
      : data{e}, next{next_ptr}, previous{previous_ptr} {}
};

}  // namespace itis