#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "cmd_reader.hpp"
#include "array_stack.hpp"
#include "linked_stack.hpp"

using namespace std;
using namespace itis;

int main(int argc, char **argv) {

  // 1. reading
  vector<string> expressions = read_lines(cin);

  // 1.5 stack type
  const bool use_linked_stack = expressions.at(0).rfind("LINKED") != string::npos;

  // 2. processing
  std::unique_ptr<Stack> collection;

  for (const auto &line: expressions) {
    auto ss = stringstream(line);
    string command;

    ss >> command;

    if (!collection && command == "CONSTRUCT") {
      if (use_linked_stack) {
        collection = std::make_unique<LinkedStack>();
      } else {
        if (line.rfind(' ') != string::npos) {
          int capacity;
          ss >> capacity;

          collection = std::make_unique<ArrayStack>(capacity);
        } else {
          collection = std::make_unique<ArrayStack>();
        }
      }
      continue;
    }

    if (command == "PUSH") {
      string elem;
      ss >> elem;
      collection->Push(str2enum(elem));
    } else if (command == "POP") {
      collection->Pop();
    } else if (command == "CLEAR") {
      collection->Clear();
    } else if (command == "PRINT") {
      if (use_linked_stack) {
        cout << *dynamic_cast<LinkedStack *>(collection.get()) << endl;
      } else {
        cout << *dynamic_cast<ArrayStack *>(collection.get()) << endl;
      }
    }
  }

  return 0;
}
