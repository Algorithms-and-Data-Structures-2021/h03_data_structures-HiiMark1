#include <catch2/catch.hpp>

#include <memory>

#include "utils.hpp"
#include "linked_stack.hpp"

using namespace std;
using namespace itis;
using namespace Catch::Matchers;

SCENARIO("create empty linked stack") {

  WHEN("creating empty stack") {
    const auto stack = make_unique<LinkedStack>();

    THEN("stack should be empty") {
      CHECK(stack->IsEmpty());
    }

    AND_THEN("stack size should be zero") {
      CHECK(stack->size() == 0);
    }

    AND_THEN("top of the stack should be empty") {
      CHECK_FALSE(stack->Peek());
    }
  }
}

SCENARIO("push elements into linked stack") {

  GIVEN("empty stack") {
    const auto stack = make_unique<LinkedStack>();

    REQUIRE(stack->IsEmpty());
    REQUIRE_FALSE(stack->Peek());

    WHEN("pushing multiple elements to the top") {
      const int num_pushed_elements = GENERATE(range(1, 10));
      const auto elements = utils::generate_elements(num_pushed_elements);

      CAPTURE(num_pushed_elements, elements);

      for (const auto e: elements) {
        stack->Push(e);
      }

      THEN("stack size should increase") {
        CHECK(stack->size() == num_pushed_elements);
      }

      AND_THEN("top of the stack should point to the last added element") {
        CHECK(stack->Peek() == elements[elements.size() - 1]);
      }
    }
  }
}

SCENARIO("pop elements from linked stack") {

  GIVEN("stack with multiple elements") {
    const int stack_size = GENERATE(range(1, 10));
    const auto stack_elements = utils::generate_elements(stack_size);
    const auto stack = make_unique<LinkedStack>();

    for (const auto e : stack_elements) {
      stack->Push(e);
    }

    REQUIRE(stack->size() == stack_size);
    REQUIRE(stack->Peek() == stack_elements[stack_elements.size() - 1]);

    CAPTURE(stack_elements);

    WHEN("popping out multiple elements") {
      const int num_pop_elements = GENERATE_COPY(range(0, stack_size)) + 1;

      CAPTURE(stack_size, num_pop_elements);

      for (int index = 0; index < num_pop_elements; index++) {
        CHECK_NOTHROW(stack->Pop());
      }

      THEN("stack size should decrease") {
        CHECK(stack->size() == stack_size - num_pop_elements);
      }

      AND_THEN("top of the stack should be correct") {
        if (num_pop_elements == stack_size) {
          CHECK_FALSE(stack->Peek());
        } else {
          CHECK(stack->Peek() == stack_elements[stack_elements.size() - num_pop_elements - 1]);
        }
      }
    }
  }

  AND_GIVEN("empty stack") {
    const auto stack = make_unique<LinkedStack>();

    REQUIRE(stack->IsEmpty());
    REQUIRE_FALSE(stack->Peek());

    WHEN("popping out elements") {

      THEN("exception should be thrown") {
        CHECK_THROWS(stack->Pop(), StartsWith("cannot pop out") && EndsWith("from empty stack"));
      }
    }
  }
}

SCENARIO("clear linked stack") {

  GIVEN("stack with multiple elements") {
    const int stack_size = GENERATE(range(1, 10));
    const auto stack_elements = utils::generate_elements(stack_size);
    const auto stack = make_unique<LinkedStack>();

    for (const auto e : stack_elements) {
      stack->Push(e);
    }

    REQUIRE(stack->size() == stack_size);
    REQUIRE(stack->Peek() == stack_elements[stack_elements.size() - 1]);

    WHEN("clearing out the stack") {
      stack->Clear();

      THEN("stack should become empty") {
        CHECK(stack->IsEmpty());
      }

      AND_THEN("top of the stack should be empty") {
        CHECK_FALSE(stack->Peek());
      }
    }
  }
}
