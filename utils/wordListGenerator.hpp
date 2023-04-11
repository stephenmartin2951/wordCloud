#include <iostream>
#include <set>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <fstream>
#include <regex>
#include <vector>
#include "split.h"
#include "utils.hpp"

using namespace std;


set<string> utils::BloomWordListGenerator(string wordListLocation)
{
	fstream inputfile;
	string lineRead;	
  set<string> result;
  string fileLocation = wordListLocation;

	inputfile.open(fileLocation, ios::in);
  while(getline(inputfile, lineRead))
    {
      vector<string> words = line_split(lineRead);
      for(auto const word: words)
        {
          if(word.find(',') != string::npos)
            break;
          else
            result.insert(word);
        }
        
    }
  return result;
}