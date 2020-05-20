/*
#45 - EASY
This problem was asked by Two Sigma.

Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability, implement a function rand7() that returns an integer from 1 to 7 (inclusive).

Date: 19/05/2020
Dev Time: 20min - 1 and 7 apper more than the other numbers (1=16077, 2=12122, 3=11931, 4=12015, 5=12055, 6=15881, 7=19919)
22h - 22h30 = 30min - worked, but I googled it
*/
#include <stdlib.h>

int rand5()
{
	return ((rand() % 5) + 1);
}

int rand7()
{
	int value = 0;

	for (int i = 0; i < 7; ++i)
	{
		value += rand5();
	}

	value = ((value % 7) + 1);

	return value;
}

#ifdef _45_EASY_
void CurrentSolution()
{
	const int total_runs = 200000;
	int pesos[7] = {0};

	for (int i = 0; i < total_runs; ++i)
	{
		int valor = rand7();
		std::cout << valor << ", ";

		++pesos[valor - 1];
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Pesos:" << std::endl;

	for (int i = 0; i < 7; ++i)
	{
		std::cout << i + 1 << "=" << pesos[i] << ", ";
	}
}
#endif
