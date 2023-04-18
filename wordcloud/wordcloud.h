#include <string>
#include <vector>
#include <set>

const int bloomBits = 1400000000;
int slidingSize = 100;
void word_cloud();
std::vector<short> countVec(1400000000);
std::vector<std::string> wordcloud_vec(bloomBits);
std::vector<std::string> badWords = {"value not found"};
std::set<std::string> uniqWords;
std::vector<size_t> word_list_vec;

