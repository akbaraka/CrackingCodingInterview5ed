#include <Ch1.h>
#include <limits>
#include <vector>
#include <utility>
#include <sstream>
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

//Problem 1.5
//Implement a method to perform basic string compression
//using counts of repeated characters. For example the string
//'aabcccccaaa' would become a2b1c5a3
//if the compressed string would become smallerthan original string, your method should return original string
///////////////////////////////////////////
//algorithm used differs from the one used in the book
//to prevent compression that does not decrease length, we don't compress up to 2 chars
//so so the test string would become aabc5a3 which is even shorter
std::string compress(const std::string& str)
{
	if (!str.length()) return "";
	stringstream res;
	
	remove_reference<decltype(str)>::type::value_type last_ch = str[0];
	size_t count = 1;//first char is counted
	res << last_ch;
	for (auto p = str.begin() + 1; p != str.end(); ++p){
		if (*p == last_ch){
			count++;
			continue;
		}
		if (count == 2)
			res << last_ch;
		if (count > 2)
			res << count;
		last_ch = *p;
		count = 1;
		res << last_ch;
	}
	//take care of last char
	if (count == 2)
		res << last_ch;
	if (count > 2)
		res << count;

	return res.str();
}

//decompressor for the above function
std::string decompress(const std::string& str)
{
	if (!str.length()) return "";
	stringstream res;
	stringstream in;
	in<<str;
	remove_reference<decltype(str)>::type::value_type last_ch,ch;
	size_t count;
	while (in.get(ch)){
		if (ch >= '1' && ch <= '9'){
			in.unget();
			in >> count;
			res << string(count - 1, last_ch);
		}
		else{
			last_ch = ch;
			res << last_ch;
		}
	}
	return res.str();
}