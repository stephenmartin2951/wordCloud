#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>
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
  fin.open("hashtable.csv", ios::in);
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

void display_wordcount(queue<string> wordCloud)
{
  map<string,int> wordCloudCount;
  while(wordCloud.size() > 0)
    {
      int currentCount = 1;
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

  vector<std::pair<string, int>> wordCloudVec;
  for(auto itr = wordCloudCount.begin(); itr != wordCloudCount.end(); ++itr)
      wordCloudVec.push_back(*itr);
      
  sort(wordCloudVec.begin(), wordCloudVec.end(), [=](std::pair<string, int>&a, std::pair<string, int>&b) {return a.second > b.second;});    

  cout << wordCloudVec[0].first << " : " << wordCloudVec[0].second << ", ";
  cout << wordCloudVec[1].first << " : " << wordCloudVec[1].second << ", ";
  cout << wordCloudVec[2].first << " : " << wordCloudVec[2].second << ", ";
  cout << wordCloudVec[3].first << " : " << wordCloudVec[3].second << ", ";
  cout << wordCloudVec[4].first << " : " << wordCloudVec[4].second << ", ";
  cout << wordCloudVec[5].first << " : " << wordCloudVec[5].second << ", ";
  cout << wordCloudVec[6].first << " : " << wordCloudVec[6].second << ", ";
  cout << wordCloudVec[7].first << " : " << wordCloudVec[7].second << ", ";
  cout << wordCloudVec[8].first << " : " << wordCloudVec[8].second << ", ";
  cout << wordCloudVec[9].first << " : " << wordCloudVec[9].second << endl;
  
}

void display_wordcount()
{
  for(size_t i = 0; i != countVec.size(); ++i)
  {
    if(countVec[i] > 0)
    {
      cout << "Hash value " << i << " is counted " << countVec[i] << " times. \n";
    }
  }   
}

void word_cloud()
{
  	fstream inputfile;
    queue<string> wordCloud;
  	string lineRead;	
    string fileLocation = "hamlet.txt";
  	inputfile.open(fileLocation, ios::in);
    while(getline(inputfile, lineRead))
      {
          vector<string> words = line_split(lineRead);
          for(auto word: words)
            {
              if(word.length() <= 5)
                break;   
              if(word.find(',') != string::npos)
                word.erase(remove(word.begin(), word.end(), ','), word.end());
              size_t hash1 = hash<string>{} (word) % bits;
              cout << word << endl;
              cout << hash1 << endl;
              countVec[hash1]++;
              // if(wordCloud.size() >= slidingSize)
              // {
              //   display_wordcount(wordCloud);
              //   wordCloud.pop();
              // }   
            }
      }  
  inputfile.close();
}

int main(int argc, char **argv) {

  //CLI utility implementation beginning
  CLI::App app{"Team's Bloom Filter"};

  app.add_option("-s", slidingSize, "Sliding Window Size");
  app.add_option("--slide", slidingSize, "Sliding Window Size");

  CLI11_PARSE(app, argc, argv);
  //CLI utility implementation ended

  word_cloud();
  display_wordcount();
  return 0;

}
