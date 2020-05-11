/*
#37 - EASY
This problem was asked by Google.

The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.

Date: 10/05/2020
Dev Time: 13h ~ 13h24 = 24 min - Finished .. but it is crashing (and I googled the solution)
		  14h ~ 14h15 = 15 min - Fixing problem
*/
#include <vector>
#include <math.h>

vector<vector<int>> getPowerSet(vector<int> set)
{
	double power_set_size = pow(2, set.size());
	vector<vector<int>> power_set;

	for (int i = 0; i < power_set_size; ++i)
	{
		vector<int> subset;

		for (size_t j = 0; j < set.size(); ++j)
		{
			if(i & (1 << j))
				subset.push_back(set[j]);
		}

		power_set.push_back(subset);
	}

	return power_set;
}

#ifdef _37_EASY_
void CurrentSolution()
{
	int set_int[] = { 1, 2, 3 };
	vector<int> my_set(set_int, set_int + sizeof(set_int) / sizeof(int));
	
	vector<vector<int>> final_powerset = getPowerSet(my_set);

	std::cout << "{";
	for (size_t i = 0; i < final_powerset.size(); ++i)
	{
		if (i != 0)
			std::cout << ", {";
		else
			std::cout << "{";
		for (size_t j = 0; j < final_powerset[i].size(); ++j)
		{
			if (j != 0)
				std::cout << ", ";

			std::cout << final_powerset[i][j];
		}
		std::cout << "}";
	}
	std::cout << "}";
}
#endif
