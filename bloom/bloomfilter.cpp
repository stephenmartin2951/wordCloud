#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include "bloomfilter.h"
#include "CLI11.hpp"
#include "utils.hpp"
#include "wordListGenerator.hpp"
#include "sha256.hpp"
#include "md5.hpp"
#include "djb2.hpp"
#include "averageVector.hpp"
#include "base64/base64.hpp"
#include "base64/base64.cpp"


using namespace std;

void SetParameters()
{
  if(d.length() > 0)
    WordList = utils::BloomWordListGenerator(d);
  else
  {
    WordList = utils::BloomWordListGenerator("dictionaryinput.txt");
  }

  if(!Literature.empty())
  {
    set tempSet = utils::BloomWordListGenerator(Literature);
    WordList.merge(tempSet);
  }
}

long long int h1(string w)
{
  string hashedString = md5(w);
  string reducedString = hashedString.substr(0,9);
  long long int x = stoi(reducedString);
  return x;
}

long long int h2(string w)
{
  string hashedString = sha256(w);
  string reducedString = hashedString.substr(0,9);
  long long int x = stoi(reducedString);
  return x;
}

int h3(string w)
{
  return abs(hf(w));
}

void bloomfilter_insert(string element)
{
  if(hashf == 1)
  {
    size_t hash1 = h1(element) % bits;
    if (data_bitset[hash1] == 1)
      collisions++;
      
    data_bitset[hash1] = 1;
  }
  else if(hashf == 2)
  {
    size_t hash1 = h1(element) % bits;
    size_t hash2 = h2(element) % bits;
    if (data_bitset[hash1] == 1 && data_bitset[hash2] == 1)
      collisions++;
    
    data_bitset[hash1] = 1;
    data_bitset[hash2] = 1;
  }
  else if(hashf == 3)
  {
    size_t hash1 = h1(element) % bits;
    size_t hash2 = h2(element) % bits;
    size_t hash3 = h3(element) % bits;
    if(data_bitset[hash1] == 1 && data_bitset[hash2] == 1 && data_bitset[hash3] == 1)
      collisions++;
    data_bitset[hash1] = 1;
    data_bitset[hash2] = 1;
    data_bitset[hash3] = 1;
  }
 n += 1; 
}

void bloomfilter_search(string element)
{
  if(hashf == 1)
  {
    size_t hash1 = h1(element) % bits;
    if(data_bitset[hash1] == 0)
    {
      avgprob.push_back(0.f);
      return;
    }
  }
  else if(hashf == 2)
  {
    size_t hash1 = h1(element) % bits;
    size_t hash2 = h2(element) % bits;
    if(data_bitset[hash1] == 0 || data_bitset[hash2] == 0)
    {
      avgprob.push_back(0.f);
      return;
    }
  }
  else if(hashf == 3)
  {
    size_t hash1 = h1(element) % bits;
    size_t hash2 = h2(element) % bits;
    size_t hash3 = h3(element) % bits;
    if(data_bitset[hash1] == 0 || data_bitset[hash2] == 0 || data_bitset[hash3] == 0)
    {
      avgprob.push_back(0.f);
      return;
    }
  }
  float prob = pow((1.0 - (pow((1.0 - 1.0/bits),(hashf*n)))),hashf);
  avgprob.push_back(prob);
}

void hashtable_creator()
{
  ofstream myfile;
  myfile.open("hashtable.csv");
  for (auto const& word: WordList)
    {
      size_t hash1 = h1(word) % bits;
      size_t hash2 = h2(word) % bits;
      size_t hash3 = h3(word) % bits;
      string completehash = to_string(hash1);
      completehash += to_string(hash2);
      completehash += to_string(hash3);
      myfile << word << "," << completehash << "\n";
    }
  myfile.close();
}

int main(int argc, char **argv) {

  //CLI utility implementation beginning
  CLI::App app{"Team's Bloom Filter"};

  app.add_option("-d", d, "Dictionary");
  app.add_option("--dict", d, "Dictionary");
  app.add_option("-l", Literature, "Dictionary");
  app.add_option("--lit", Literature, "Dictionary");
  app.add_option("-b", bits, "Bits");
  app.add_option("--bits", bits, "Bits");
  app.add_option("-f", hashf, "HashFunctions");
  app.add_option("--hashf", hashf, "HashFunctions");

  CLI11_PARSE(app, argc, argv);
  //CLI utility implementation ended

  SetParameters();

  data_bitset.resize(bits);

  // for (auto const& word: WordList)
  //   bloomfilter_insert(word);
  // for (auto const& word: WordList)
  //   bloomfilter_search(word);
  // float avgpr = average(avgprob);
  // cout << hashf << " hash functions :: " << bits << " bits" << endl;
  // cout << collisions << " collisions" << endl;

  hashtable_creator();

  
	return 0;
}