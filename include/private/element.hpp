#pragma once

#include <array>
#include <string_view>

namespace itis {

enum class Element {
  BMW,
  BUGATTI,
  FERRARI,
  MASERATI,
  MERCEDES,
  UNDEFINED
};

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

inline constexpr std::array<std::string_view, static_cast<int>(Element::UNDEFINED) + 1> kElementNameDict = {
    "BMW",
    "BUGATTI",
    "FERRARI",
    "MASERATI",
    "MERCEDES",
    "UNDEFINED"
};

inline constexpr std::string_view enum2str(const Element &e) {
  return kElementNameDict[static_cast<int>(e)];
}

inline constexpr Element str2enum(std::string_view str) {
  if (str == "BMW") return Element::BMW;
  if (str == "BUGATTI") return Element::BUGATTI;
  if (str == "FERRARI") return Element::FERRARI;
  if (str == "MASERATI") return Element::MASERATI;
  if (str == "MERCEDES") return Element::MERCEDES;
  return Element::UNDEFINED;
}

static_assert(static_cast<int>(Element::UNDEFINED) == 5, "number of Element enumerations must be 5");

}  // namespace itis