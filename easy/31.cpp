/*
#31 - EASY
This problem was asked by Google.

The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.

Date: 04/05/2020
Dev Time: 2h47 - 3h05 = 18min - Nonsense logic, works only with the example
		  3h08 - 3h18 = 10min - Creating a testing system that makes my code fail
*/
#include <string>

#define min_value(x,y) ((x < y) ? x : y)
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int getEditDistance(std::string s1, std::string s2)
{
	int edit_distance = 0;

	for (size_t i = 0; i < min_value(s1.size(), s2.size()); ++i)
	{
		if (s1[i] != s2[i])
		{
			++edit_distance;
		}
	}

	if (s1.size() > s2.size())
		edit_distance += (s1.size() - s2.size());
	else
		edit_distance += (s2.size() - s1.size());

	return edit_distance;
}

#ifdef _31_EASY_
void CurrentSolution()
{
	struct test_struct {
		std::string s1;
		std::string s2;
		int distance;
	} test_strings [] = { {"kitten", "sitting", 3},
						  {"cat", "gap", 2},
						  {"keep", "sweep", 2} };

	for (int i = 0; i < ARRAY_SIZE(test_strings); ++i)
	{
		std::cout << "The edit distance between '" << test_strings[i].s1 << "' and '" << test_strings[i].s2 << "' is: " << getEditDistance(test_strings[i].s1, test_strings[i].s2) << ". And it should be: " << test_strings[i].distance << std::endl;
		std::cout << "The edit distance between '" << test_strings[i].s2 << "' and '" << test_strings[i].s1 << "' is: " << getEditDistance(test_strings[i].s2, test_strings[i].s1) << ". And it should be: " << test_strings[i].distance << std::endl;
	}

}
#endif
