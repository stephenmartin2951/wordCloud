#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>
#include <chrono>
#include "CLI11.hpp"
#include "split.h"
#include "wordcloud.h"
#include "base64/base64.hpp"
#include "base64/base64.cpp"
#include "bloomfilter.h"

#include <sycl/sycl.hpp>
#include <cassert>
#include "spdlog/spdlog.h"



using namespace std;
using namespace std::chrono;
using namespace sycl;

void display_wordcount(vector<short>& countVec)
{
  for(size_t i = 0; i != countVec.size(); ++i)
  {
    if(countVec[i] > 0)
    {
      cout << "Hash value " << i << " is counted " << countVec[i] << " times. \n";
    }
  }   
}

void word_list()
{
  	fstream inputfile;
  	string lineRead;	
    string fileLocation = "hamlet.txt";
  	inputfile.open(fileLocation, ios::in);
    while(getline(inputfile, lineRead))
      {
          vector<string> words = line_split(lineRead);
          for(auto word: words)
            {
              size_t hash1 = hash<string>{} (word) % bits;
              word_list_vec.push_back(hash1);
            }
      }  
  inputfile.close();
}

int main(int argc, char **argv) {
  auto start_program = high_resolution_clock::now();


  //CLI utility implementation beginning
  CLI::App app{"Team's Bloom Filter"};

  app.add_option("-s", slidingSize, "Sliding Window Size");
  app.add_option("--slide", slidingSize, "Sliding Window Size");

  CLI11_PARSE(app, argc, argv);
  //CLI utility implementation ended
  auto start_wordcloud = high_resolution_clock::now();
  word_list();
  buffer<short> b1{word_list_vec};
  buffer<short> b2{countVec};

  queue q1;
    // Submit the kernel to the queue
  q1.submit([&](handler& h) {
    accessor in{b1, h};
    accessor out{b2, h};

    h.parallel_for(5545, [=](id<1> idx) {
      out[in[idx]]++;
    });
  });

  auto display_wordcloud = high_resolution_clock::now();

  display_wordcount(countVec);

  // buffer<short> b3{countVec};

  // queue q2;
  // q2.submit([&](handler& h) {
  //   accessor in{b3, h};

  //   h.parallel_for(1400000000, [=](id<1> idx) {
  //     if(in[idx] > 0)
  //       {
  //         spdlog::info("Hash value: {} is counted {} times.", idx, in[idx]);
  //       }
  //   });
  // });

  auto end_program = high_resolution_clock::now();

  auto total_runtime = duration_cast<microseconds>(end_program - start_program);
  auto wordcloud_generation = duration_cast<microseconds>(display_wordcloud - start_wordcloud);
  auto wordcloud_display = duration_cast<microseconds>(end_program - display_wordcloud);

  cout << "Total run time : " << total_runtime.count() << " microseconds \n";
  cout << "Wordcloud generation time : " << wordcloud_generation.count() << " microseconds \n";
  cout << "Wordcloud display time : " << wordcloud_display.count() << " microseconds \n";

  return 0;

}
