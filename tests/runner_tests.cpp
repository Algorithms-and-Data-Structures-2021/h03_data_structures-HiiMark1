#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "private/element.hpp"

using namespace itis;

CATCH_REGISTER_ENUM(Element, Element::UNDEFINED, Element::BMW, Element::BUGATTI, Element::FERRARI,
                    Element::MASERATI, Element::MERCEDES)

// This file provides with unit tests runner
