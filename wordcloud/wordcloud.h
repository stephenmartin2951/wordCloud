#include <bitset>
#include <string>
#include <vector>

const int bloomBits = 95000000;
int slidingSize = 100;
void word_cloud();
std::vector<std::string> wordcloud_vec(bloomBits);
std::vector<std::string> badWords = {"value not found"};

