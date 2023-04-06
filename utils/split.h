#include <vector>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;

vector<string> line_split(string const& input)
{
	istringstream buffer(input);
	vector<string> ret{ istream_iterator<string>(buffer), {} };

	return ret;
}