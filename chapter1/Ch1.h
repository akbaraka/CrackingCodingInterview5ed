#include <string>

//Problem 1.1
//returns true if input string has only unique characters
//i.e. each letter is repeated only once
bool AllUniqueCharacters(const std::string& str);

//Problem 1.2
//reverses the input string
void reverse(char* str);

//Problem 1.3
//Given two strings, write a method to decide if one is a permutation of the other
bool isPermutation(const std::string& one, const std::string& two);

//Problem 1.4 
//Write a method to replace all spaces with '%20'
//You may assume that the string has sufficient 
//space at the end of the string to hold the additional characters
//and you are given the "true" length of the string
void replace20(char* str, size_t len);

//Problem 1.5
//Implement a method to perform basic string compression
//using counts of repeated characters. For example the string
//'aabcccccaa' would become a2b1c5a3
//if the compressed string would become smallerthan original string, your method should return original string
std::string compress(const std::string& str);

//decompressor for the above function
std::string decompress(const std::string& str);