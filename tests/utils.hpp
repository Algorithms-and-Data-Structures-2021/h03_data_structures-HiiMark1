#pragma once

#include <vector>
#include <random>  // random_device, mt19937, uniform_int_distribution

#include "private/element.hpp"  // Element

namespace utils {

/**
 * Генерация псевдо-случайного массива перечислителей определенного размера и емкости.
 *
 * @param num_samples - кол-во элементов (размер массива)
 * @return сгенерированный массив
 */
inline std::vector<itis::Element> generate_elements(int num_samples) {
  // устройство генерации 32-битных псевдо-случайных чисел
  auto engine = std::mt19937(std::random_device{}());

  // оболочка над устройством для генерации равновероятных значений в указанном диапозоне
  // dist ~ distribution ~ распределение
  auto dist = std::uniform_int_distribution<>(0, static_cast<int>(itis::Element::UNDEFINED) - 1);

  std::vector<itis::Element> elements;
  elements.reserve(num_samples);

  for (int index = 0; index < num_samples; index++) {
    const int enum_id = dist(engine);                      // генерация числа
    elements.push_back(static_cast<itis::Element>(enum_id));
  }

  return elements;
}

}  // namespace utils