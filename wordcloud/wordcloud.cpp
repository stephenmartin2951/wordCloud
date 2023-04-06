#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include "CLI11.hpp"
#include "split.h"
#include "wordcloud.h"
#include "sha256.hpp"
#include "md5.hpp"
#include "djb2.hpp"
#include "base64/base64.hpp"
#include "base64/base64.cpp"
#include "bloomfilter.h"

using namespace std;

long long int wc_h1(string w)
{
  string hashedString = md5(w);
  string reducedString = hashedString.substr(0,9);
  long long int x = stoi(reducedString);
  return x;
}

long long int wc_h2(string w)
{
  string hashedString = sha256(w);
  string reducedString = hashedString.substr(0,9);
  long long int x = stoi(reducedString);
  return x;
}

int wc_h3(string w)
{
  return abs(hf(w));
}

string hash_lookup(string& hashvalue)
{
  int count = 0;
  fstream fin;
  vector<string> row;
  string hashLineRead, line;
  fin.open("/home/runner/Special-Team-Bloom-Filter-comp-339-439-ds/utils/hashtable.csv", ios::in);
  while(getline(fin, hashLineRead) && count == 0){
    row.clear();
    stringstream s(hashLineRead);
    string str;
    while(getline(s, str, ','))
      row.push_back(str);
    if(hashvalue == row[1])
      {
        count = 1;
        return row[0];
      }
    }
  fin.close();
  return "value not found";
}

void display_wordcount(queue<string>& wordCloud)
{
  map<string,int> wordCloudCount;
  int currentCount = 0;
  while(wordCloud.size() > 0)
    {
      cout << wordCloud.size() << endl;
      string word = wordCloud.front();
      if(wordCloudCount.contains(word))
      {
        currentCount = wordCloudCount.at(word);
        wordCloudCount[word] = currentCount + 1;
      }
      else
      {
        wordCloudCount[word] = currentCount;
      }
      wordCloud.pop();
    }

  cout << "Word Count: \n";

  for(auto const& pair : wordCloudCount)
      cout << pair.first << " : " << pair.second << endl;
}

void word_cloud()
{
  	fstream inputfile;
    queue<string> wordCloud;
  	string lineRead;	
    string fileLocation = "/home/runner/Special-Team-Bloom-Filter-comp-339-439-ds/hamlet.txt";
  	inputfile.open(fileLocation, ios::in);
    while(getline(inputfile, lineRead))
      {
          vector<string> words = line_split(lineRead);
          for(auto word: words)
            {
              if(word.find(',') != string::npos)
                word.erase(remove(word.begin(), word.end(), ','), word.end());
              size_t hash1 = wc_h1(word) % bits;
              size_t hash2 = wc_h2(word) % bits;
              size_t hash3 = wc_h3(word) % bits;
              string completehash = to_string(hash1);
              completehash += to_string(hash2);
              completehash += to_string(hash3);
              wordCloud.push(hash_lookup(completehash));
            }
      }
  inputfile.close();
  display_wordcount(wordCloud);
}

int main(int argc, char **argv) {

  word_cloud();
  return 0;

}
