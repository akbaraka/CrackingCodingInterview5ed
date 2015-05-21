#include <Ch1.h>
#include <limits>
#include <vector>
using namespace std;
//Problem 1.1
//returns true if input string has only unique characters
//i.e. each letter is repeated only once
bool AllUniqueCharacters(const std::string& str){
	using char_type = unsigned char; //type of characters
	
	const auto num_chars = numeric_limits<char_type>::max();
	vector<bool> status(num_chars, false);

	if (str.length() > num_chars) return false;//if string is longer that character set, it cannot be all unique
	if (str.empty()) return true; //empty string has only unique chars

	for (const auto& ch : str){
		if (status[ch]) return false;//second appearance of the character
		status[ch] = true;
	}
	return true;
}