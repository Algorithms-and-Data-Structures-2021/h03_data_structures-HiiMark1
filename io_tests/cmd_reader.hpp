#pragma once

#include <istream>
#include <string>
#include <string_view>
#include <vector>

namespace itis {

inline constexpr auto kSourceDir = std::string_view{CURRENT_SOURCE_DIR};

inline auto read_lines(std::istream &is, const std::string &stop_token = "") -> std::vector<std::string> {
  std::vector<std::string> lines;
  lines.reserve(30);

  for (std::string line; std::getline(is, line); /* ... */) {
    if (line == stop_token) break;
    if (line.empty()) continue;
    lines.emplace_back(line);
  }

  return lines;
}

}  // namespace itis