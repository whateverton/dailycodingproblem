/*
#40 - Hard
This problem was asked by Google.

Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.
*/
#ifdef VS_IDE
#include "helper.h"
#endif

#include <algorithm>

int getOutsider(int *data, size_t size)
{
	bool new_value = true;
	size_t i = 1;

	std::sort(data, &data[size - 1]);
	
	for (; i < size; ++i)
	{
		if ((data[i - 1] != data[i]) && new_value)
			return data[i - 1];
		else if (data[i - 1] == data[i])
			new_value = false;
		else
			new_value = true;
	}

	return 0;
}

#ifdef VS_IDE
void problem40()
#else
void main()
#endif
{
	int data[] = { 6, 1, 3, 3, 3, 6, 6 };
	int data1[] = { 13, 19, 13, 13 };
	int data2[] = { 2, 1, 1, 1 };
	int data3[] = { 5, 9, 9, 9 };

	std::cout << getOutsider(data, ARRAY_SIZE(data)) << std::endl;
	std::cout << getOutsider(data1, ARRAY_SIZE(data1)) << std::endl;
	std::cout << getOutsider(data2, ARRAY_SIZE(data2)) << std::endl;
	std::cout << getOutsider(data3, ARRAY_SIZE(data3)) << std::endl;
}