/*
This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.


Date: 10/07/2020
*/
#ifdef VS_IDE
#include "helper.h"
#endif

#include <algorithm>

std::vector<int> getMaxSubArray(int *v, size_t size, size_t k)
{
	size_t total_sub_sets = size - (k - 1);
	std::vector<int> max_values;
	std::vector <std::vector<int>> sub_sets;
	sub_sets.resize(total_sub_sets);

	if (k < 1 || k > size)
	{
		std::cerr << "Problem!";
		return { 0 };
	}

	for (size_t i = 0; i < total_sub_sets; ++i)
	{
		for (size_t j = i; j < i+k; ++j)
		{
			sub_sets[i].push_back(v[j]);
		}

		std::sort(sub_sets[i].begin(), sub_sets[i].end());

		max_values.push_back(sub_sets[i][k-1]);
	}

	return max_values;
}

#ifdef VS_IDE
void problem18()
#else
void main()
#endif
{
	int my_array[] = { 10, 5, 2, 7, 8, 7 };
	
	std::vector<int> result = getMaxSubArray(my_array, ARRAY_SIZE(my_array), 3);
	for(size_t i = 0; i < result.size(); ++i)
		std::cout << result[i] << ", ";
}
