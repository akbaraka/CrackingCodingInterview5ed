#include <Ch1.h>
#include <limits>
#include <vector>
#include <utility>
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

//Problem 1.2
//reverses the input string
void reverse(char* str)
{
	auto end = str;
	auto tmp = *str;

	if (str){ //nothing to do for empty string
		while (*end) end++; //go to the end
		end--; //go to the last character

		while (str < end)	
			swap(*str++, *end--);
	}
}

//Problem 1.3
//Given two strings, write a method to decide if one is a permutation of the other
bool isPermutation(const std::string& one, const std::string& two)
{
	if (one.length() != two.length()) return false;//must be same length to be permutation
	if (0 == one.length()) return true; //two empty strings are permutation
	
	using char_type = remove_reference<decltype(one)>::type::value_type;
	vector<size_t> char_count(numeric_limits<char_type>::max(),0);

	for (const auto& ch : one)
		char_count[ch]++;

	for (const auto& ch : two)
		if (--char_count[ch] < 0) //since the strings are same length, ate least one element will go negative
			return false;

	return true;
}

//Problem 1.4 
//Write a method to replace all spaces with '%20'
//You may assume that the string has sufficient 
//space at the end of the string to hold the additional characters
//and you are given the "true" length of the string
void replace20(char* str, size_t len)
{
	auto p = str;
	size_t space_count = 0;
	while (*p)
		if (*p++ == ' ')
			space_count++;
	if (0 == space_count) return;//nothing to do

	//replacing ' ' with '%20' requires two extra chars for each
	auto p2 = str + len + 2 * space_count;
	*p2-- = '\0';
	p = str + len - 1;
	while (space_count){
		if (' ' == *p){
			*p2 = '0'; p2--;
			*p2 = '2'; p2--;
			*p2 = '%'; p2--;
			space_count--;
		}
		else{
			*p2 = *p;
			p2--;
		}
		p--;
	}
}