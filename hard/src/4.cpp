/*
#4 - HARD
This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

Date: 10/06/2020
Dev Time: 0h19 - 1h = 41min
*/

#ifdef VS_IDE
#include "helper.h"
#endif

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int findMissingInt(vector<int> *v)
{
	if (v->size() == 0)
		return -1;

	sort(v->begin(), v->end(), [](int& a, int& b) { return (a <= 0) ? (b < a) : (a < b););

	// Zero isn't the first positive integer (?) :o
	int next_greater_int = 1;

	for (size_t i = 0; i < v->size(); ++i)
	{
		if (next_greater_int == (*v)[i])
		{
			next_greater_int = (*v)[i] + 1;
		}
		else if ((next_greater_int < (*v)[i]) || ((*v)[i] <= 0))
		{
			break;
		}
	}

	return next_greater_int;
}

#ifdef VS_IDE
void problem4()
#else
void main()
#endif
{
	struct test_4{
		vector<int> my_array;
		int expected;
	}test_4[] =
	{
		{{3, 4, -1, 1}, {2}},
		{{1, 2, 0}, {3}},
		{{-1, -2, -4}, {1}},
		{{2, 3, 4}, {1}},
	};

	for (int i = 0; i < ARRAY_SIZE(test_4); ++i)
	{
		cout << "\nArray: ";
		printVector(test_4[i].my_array);
		cout << "\nExpected Int: ";
		cout << test_4[i].expected;
		cout << "\nReturned Int: ";
		cout << findMissingInt(&test_4[i].my_array);

		cout << endl;
	}
}
