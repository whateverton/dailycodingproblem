/*
#13 - HARD

This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

Date: 29/06/2020
*/

#ifdef VS_IDE
#include "helper.h"
#endif

#include <string>

size_t longestSubstrLength(std::string string, int k)
{

	return 0;
}


#ifdef VS_IDE
void problem13()
#else
void main()
#endif
{
	std::cout << longestSubstrLength("abcba", 2);
}