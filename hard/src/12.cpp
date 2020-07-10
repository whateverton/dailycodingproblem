/*
#12 - HARD
This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
1, 1, 2
1, 2, 1
2, 1, 1
2, 2

What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.

Date: 24/06/2020
*/

#ifdef VS_IDE
#include "helper.h"
#endif

int uniqueClimbs(int steps, int *possible_steps, size_t size)
{
	int total = 0;
	std::vector<int> steps_left(size, steps);

	// Open how many branches are needed
	for (size_t i = 0; i < size; ++i)
	{
		steps_left[i] -= possible_steps[i];

		// When zero, it means it was a possibility
		if (steps_left[i] == 0)
			return total+1;
		else if (steps_left[i] < 0) // Negative, not possible
			return total;

		// There's still some steps to go
		total += uniqueClimbs(steps_left[i], possible_steps, size);
	}

	return total;
}

#ifdef VS_IDE
void problem12()
#else
void main()
#endif
{
	int possible_steps[] = { 1, 2 };

	std::cout << "\nQuantida de passos: "<< uniqueClimbs(4, possible_steps, ARRAY_SIZE(possible_steps));
}