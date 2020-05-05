/*
#31 - EASY
This problem was asked by Google.

The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.

Date: 04/05/2020
Dev Time: 2h47 - 3h05 = 18min - Nonsense logic, works only with the example
		  3h08 - 3h18 = 10min - Creating a testing system that makes my code fail
		  3h18 - 3h41 = 23min - Optmizing to get containing cases

Possible improvement: use Levenshtein distance
*/
#include <string>

#define min_value(x,y) ((x < y) ? x : y)
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int getEditDistance(std::string s1, std::string s2)
{
	int edit_distance = 0;

	// If some of the string is contains the other, just calculate the size difference
	if ((s1.find(s2) >= string::npos) && (s2.find(s1) >= string::npos))
	{
		for (size_t i = 0; i < min_value(s1.size(), s2.size()); ++i)
		{
			if (s1[i] != s2[i])
			{
				++edit_distance;
			}
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
	} test_strings [] =
	{
		{"kitten", "sitting", 3},	// original test case
		{"cat", "gap", 2},			// some random test
		{"car", "scared", 3},		// s2 contains s1, not from the start
		{"keep", "sweep", 2},		// the end is the same, should add to the begining
		{"keep", "sweeper", 4}		// middle is equal
	};

	for (int i = 0; i < ARRAY_SIZE(test_strings); ++i)
	{
		std::cout << "The edit distance between '" << test_strings[i].s1 << "' and '" << test_strings[i].s2 << "' is: " << getEditDistance(test_strings[i].s1, test_strings[i].s2) << ". And it should be: " << test_strings[i].distance << std::endl;
		std::cout << "The edit distance between '" << test_strings[i].s2 << "' and '" << test_strings[i].s1 << "' is: " << getEditDistance(test_strings[i].s2, test_strings[i].s1) << ". And it should be: " << test_strings[i].distance << std::endl;
	}

}
#endif
