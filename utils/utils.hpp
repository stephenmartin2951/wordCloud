#pragma once
#include <string>
#include <set>

namespace utils{
std::set<std::string> BloomWordListGenerator(std::string wordListLocation);
const char* WordListLocation = "aspell -l en dump master | tr '[:lower:]' '[:upper:]' | tr -d '[:punct:]' | sort | uniq";
}