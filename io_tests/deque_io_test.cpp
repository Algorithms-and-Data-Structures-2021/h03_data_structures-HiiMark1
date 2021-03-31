#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "cmd_reader.hpp"
#include "linked_dequeue.hpp"

using namespace std;
using namespace itis;

int main(int argc, char **argv) {

  // 1. reading
  vector<string> expressions = read_lines(cin);

  // 2. processing
  std::unique_ptr<LinkedDequeue> collection;

  for (const auto &line: expressions) {
    auto ss = stringstream(line);
    string command;

    ss >> command;

    if (!collection && command == "CONSTRUCT") {
      collection = std::make_unique<LinkedDequeue>();
      continue;
    }

    if (command == "ENQUEUE") {
      string elem;
      ss >> elem;
      collection->Enqueue(str2enum(elem));
    } else if (command == "ENQUEUE_FRONT") {
      string elem;
      ss >> elem;
      collection->EnqueueFront(str2enum(elem));
    } else if (command == "DEQUEUE") {
      collection->Dequeue();
    } else if (command == "DEQUEUE_BACK") {
      collection->DequeueBack();
    } else if (command == "CLEAR") {
      collection->Clear();
    } else if (command == "PRINT") {
      cout << *collection << endl;
    }
  }

  return 0;
}
