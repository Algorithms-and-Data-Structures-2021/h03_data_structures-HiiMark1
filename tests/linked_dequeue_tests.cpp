#include <catch2/catch.hpp>

#include <memory>

#include "utils.hpp"
#include "linked_dequeue.hpp"

using namespace std;
using namespace itis;
using namespace Catch::Matchers;

SCENARIO("create empty linked deque") {

  WHEN("creating queue") {
    const auto queue = make_unique<LinkedDequeue>();

    THEN("queue should be empty") {
      CHECK(queue->IsEmpty());
    }

    AND_THEN("queue size should be zero") {
      CHECK(queue->size() == 0);
    }

    AND_THEN("front and back of the queue should be empty") {
      CHECK_FALSE(queue->front());
      CHECK_FALSE(queue->back());
    }
  }
}

SCENARIO("enqueue linked deque") {

  GIVEN("empty queue") {
    const auto queue = make_unique<LinkedDequeue>();

    REQUIRE(queue->IsEmpty());
    REQUIRE_FALSE(queue->front());
    REQUIRE_FALSE(queue->back());

    WHEN("enqueueing multiple elements") {
      const int num_elements = GENERATE(range(1, 10));
      const auto elements = utils::generate_elements(num_elements);

      CAPTURE(num_elements, elements);

      for (const auto e: elements) {
        queue->Enqueue(e);
      }

      THEN("queue size should increase") {
        CHECK(queue->size() == num_elements);
      }

      AND_THEN("front and back of the queue should be correct") {
        CHECK(*queue->front() == elements[0]);
        CHECK(*queue->back() == elements[elements.size() - 1]);
      }
    }
  }
}

SCENARIO("dequeue linked deque") {

  GIVEN("queue with multiple elements") {
    const int queue_size = GENERATE(range(1, 10));
    const auto elements = utils::generate_elements(queue_size);
    const auto queue = make_unique<LinkedDequeue>();

    for (const auto e : elements) {
      queue->Enqueue(e);
    }

    REQUIRE(queue->size() == queue_size);
    REQUIRE(*queue->front() == elements[0]);
    REQUIRE(*queue->back() == elements[elements.size() - 1]);

    CAPTURE(elements);

    WHEN("dequeing elements") {
      const int num_elements = GENERATE_COPY(range(0, queue_size)) + 1;

      CAPTURE(queue_size, num_elements);

      for (int index = 0; index < num_elements; index++) {
        CHECK_NOTHROW(queue->Dequeue());
      }

      THEN("queue size should decrease") {
        CHECK(queue->size() == queue_size - num_elements);
      }

      AND_THEN("front and back of the queue should be correct") {
        if (num_elements == queue_size) {
          CHECK_FALSE(queue->front());
          CHECK_FALSE(queue->back());
        } else {
          CHECK(*queue->front() == elements[0 + num_elements]);
          CHECK(*queue->back() == elements[elements.size() - 1]);
        }
      }
    }
  }

  AND_GIVEN("empty queue") {
    const auto queue = make_unique<LinkedDequeue>();

    REQUIRE(queue->IsEmpty());
    REQUIRE_FALSE(queue->front());
    REQUIRE_FALSE(queue->back());

    WHEN("dequeing elements") {

      THEN("exception should be thrown") {
        CHECK_THROWS(queue->Dequeue(), StartsWith("cannot dequeue") && EndsWith("empty queue"));
      }
    }
  }
}

SCENARIO("enqueue front linked deque") {

  GIVEN("empty queue") {
    const auto queue = make_unique<LinkedDequeue>();

    REQUIRE(queue->IsEmpty());
    REQUIRE_FALSE(queue->front());
    REQUIRE_FALSE(queue->back());

    WHEN("enqueueing multiple elements to the front") {
      const int num_elements = GENERATE(range(1, 10));
      const auto elements = utils::generate_elements(num_elements);

      CAPTURE(num_elements, elements);

      for (const auto e: elements) {
        queue->EnqueueFront(e);
      }

      THEN("queue size should increase") {
        CHECK(queue->size() == num_elements);
      }

      AND_THEN("front and back of the queue should be correct") {
        CHECK(*queue->front() == elements[elements.size() - 1]);
        CHECK(*queue->back() == elements[0]);
      }
    }
  }
}

SCENARIO("dequeue back linked deque") {

  GIVEN("queue with multiple elements") {
    const int queue_size = GENERATE(range(1, 10));
    const auto elements = utils::generate_elements(queue_size);
    const auto queue = make_unique<LinkedDequeue>();

    for (const auto e : elements) {
      queue->Enqueue(e);
    }

    REQUIRE(queue->size() == queue_size);
    REQUIRE(*queue->front() == elements[0]);
    REQUIRE(*queue->back() == elements[elements.size() - 1]);

    CAPTURE(elements);

    WHEN("dequeing elements from the back") {
      const int num_elements = GENERATE_COPY(range(0, queue_size)) + 1;

      CAPTURE(queue_size, num_elements);

      for (int index = 0; index < num_elements; index++) {
        CHECK_NOTHROW(queue->DequeueBack());
      }

      THEN("queue size should decrease") {
        CHECK(queue->size() == queue_size - num_elements);
      }

      AND_THEN("front and back of the queue should be correct") {
        if (num_elements == queue_size) {
          CHECK_FALSE(queue->front());
          CHECK_FALSE(queue->back());
        } else {
          CHECK(*queue->front() == elements[0]);
          CHECK(*queue->back() == elements[elements.size() - num_elements - 1]);
        }
      }
    }
  }

  AND_GIVEN("empty queue") {
    const auto queue = make_unique<LinkedDequeue>();

    REQUIRE(queue->IsEmpty());
    REQUIRE_FALSE(queue->front());
    REQUIRE_FALSE(queue->back());

    WHEN("dequeing elements") {

      THEN("exception should be thrown") {
        CHECK_THROWS(queue->DequeueBack(), StartsWith("cannot dequeue") && EndsWith("empty queue"));
      }
    }
  }
}

SCENARIO("clear linked deque") {

  GIVEN("queue with no or multiple elements") {
    const int queue_size = GENERATE(range(0, 10));
    const auto elements = utils::generate_elements(queue_size);
    const auto queue = make_unique<LinkedDequeue>();

    for (const auto &e: elements) {
      queue->Enqueue(e);
    }

    REQUIRE(queue->size() == queue_size);

    if (queue_size == 0) {
      REQUIRE_FALSE(queue->front());
      REQUIRE_FALSE(queue->back());
    } else {
      REQUIRE(*queue->front() == elements[0]);
      REQUIRE(*queue->back() == elements[elements.size() - 1]);
    }

    WHEN("clearing out the queue") {
      queue->Clear();

      THEN("queue size should become zero") {
        CHECK(queue->IsEmpty());
        CHECK(queue->size() == 0);
      }

      AND_THEN("front and back of the queue should be empty") {
        CHECK_FALSE(queue->front());
        CHECK_FALSE(queue->back());
      }
    }
  }
}
