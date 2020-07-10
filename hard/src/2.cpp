/*
#2 - HARD
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

Date: 07/06/2020
Dev Time: 18h09min - 18h36 = 27min
*/

#ifdef VS_IDE
#include "helper.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

void changeArray(vector<int> *original, vector<int> *result)
{
	int product = 1;
	for (size_t i = 0; i < original->size(); ++i)
	{
		product *= (*original)[i];
	}

	for (size_t i = 0; i < original->size(); ++i)
	{
		(*result).push_back(product / (*original)[i]);
	}
}

#ifdef VS_IDE
void problem2()
#else
void main()
#endif
{
	struct test_2{
		vector<int> original;
		vector<int> expected;
		vector<int> result;
	}test_2[] =
	{
		{{1, 2, 3, 4, 5}, {120, 60, 40, 30, 24}, {}},
		{{3, 2, 1}, {2, 3, 6}, {}}
	};

	for (int i = 0; i < ARRAY_SIZE(test_2); ++i)
	{
		changeArray(&test_2[i].original, &test_2[i].result);

		cout << "\nOriginal: ";
		printVector(test_2[i].original);
		cout << "\nExpected: ";
		printVector(test_2[i].expected);
		cout << "\nResult:   ";
		printVector(test_2[i].result);

		cout << endl;
	}
}