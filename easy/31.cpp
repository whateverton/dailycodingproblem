/*
#31 - EASY
This problem was asked by Google.

The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.

Date: 04/05/2020
Dev Time: 2h47 - 3h05 = Nonsense logic, works only with the example
*/
#include <string>

#define min_value(x,y) ((x < y) ? x : y)

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
	std::cout << "The edit distance is: " << getEditDistance("kitten", "sitting") << std::endl;

}
#endif
