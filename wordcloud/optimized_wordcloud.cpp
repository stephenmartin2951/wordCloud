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

void display_wordcount(vector<size_t>& countVec)
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

  //word_list_vec.size() = 31716
  word_list();
  buffer<size_t> b1{word_list_vec};
  auto N = word_list_vec.size();
  auto R = range<1>(N / windowSize);

  //Window 1
  buffer<size_t> sB1(b1, 0, range{ N / windowSize });
  buffer<short> oSB1{countVec};
  queue q1;
  // Submit the kernel to the queue
  q1.submit([&](handler& h) {
    accessor in{sB1, h, read_only};
    accessor out{oSB1, h, write_only, no_init};

    h.parallel_for(R, [=](id<1> idx) {
      out[in[idx]]++;
    });
  });

  host_accessor result1{oSB1, read_only};
  for(size_t i = 0; i != result1.size(); ++i)
    if(result1[i] > 0)
      cout << "Hash value " << i << " is counted " << result1[i] << " times. \n";

  //Window 2
  buffer<size_t> sB2(b1, 6000, range{ N / windowSize });
  buffer<short> oSB2{countVec};
  queue q2;
  // Submit the kernel to the queue
  q2.submit([&](handler& h) {
    accessor in{sB2, h, read_only};
    accessor out{oSB2, h, write_only, no_init};

    h.parallel_for(R, [=](id<1> idx) {
      out[in[idx]]++;
    });
  });

  host_accessor result2{oSB2, read_only};
  for(size_t i = 0; i != result2.size(); ++i)
    if(result2[i] > 0)
      cout << "Hash value " << i << " is counted " << result2[i] << " times. \n";

  //Window 3
  buffer<size_t> sB3(b1, 12000, range{ N / windowSize });
  buffer<short> oSB3{countVec};
  queue q3;
  // Submit the kernel to the queue
  q3.submit([&](handler& h) {
    accessor in{sB3, h, read_only};
    accessor out{oSB3, h, write_only, no_init};

    h.parallel_for(R, [=](id<1> idx) {
      out[in[idx]]++;
    });
  });

  host_accessor result3{oSB3, read_only};
  for(size_t i = 0; i != result3.size(); ++i)
    if(result3[i] > 0)
      cout << "Hash value " << i << " is counted " << result3[i] << " times. \n";  

  //Window 4
  buffer<size_t> sB4(b1, 18000, range{ N / windowSize });
  buffer<short> oSB4{countVec};
  queue q4;
  // Submit the kernel to the queue
  q4.submit([&](handler& h) {
    accessor in{sB4, h, read_only};
    accessor out{oSB4, h, write_only, no_init};

    h.parallel_for(R, [=](id<1> idx) {
      out[in[idx]]++;
    });
  });

  host_accessor result4{oSB4, read_only};
  for(size_t i = 0; i != result4.size(); ++i)
    if(result4[i] > 0)
      cout << "Hash value " << i << " is counted " << result4[i] << " times. \n";   

  //Window 5
  buffer<size_t> sB5(b1, 24000, range{ N / windowSize });
  buffer<short> oSB5{countVec};
  queue q5;
  // Submit the kernel to the queue
  q5.submit([&](handler& h) {
    accessor in{sB5, h, read_only};
    accessor out{oSB5, h, write_only, no_init};

    h.parallel_for(R, [=](id<1> idx) {
      out[in[idx]]++;
    });
  });

  host_accessor result5{oSB5, read_only};
  for(size_t i = 0; i != result5.size(); ++i)
    if(result5[i] > 0)
      cout << "Hash value " << i << " is counted " << result5[i] << " times. \n";  

  auto end_program = high_resolution_clock::now();

  auto total_runtime = duration_cast<microseconds>(end_program - start_program);

  cout << "Total run time : " << total_runtime.count() << " microseconds \n";

  return 0;

}
