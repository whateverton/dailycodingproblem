/*
#32 - Hard
This problem was asked by Jane Street.

Suppose you are given a table of currency exchange rates, represented as a 2D array. Determine whether there is a possible arbitrage: that is, whether there is some sequence of trades you can make, starting with some amount A of any currency, so that you can end up with some amount greater than A of that currency.

There are no transaction costs and you can trade fractional quantities.

Date: 15/07/2020
*/
#ifdef VS_IDE
#include "helper.h"
#endif

// same as easy 47 ??

int whenShouldIBuy(int* stocks, int size)
{
	int min = stocks[0];
	int max = stocks[0];
	int gain = max - min;

	for (int i = 1; i < size; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if ((stocks[i] - stocks[j]) > gain)
			{
				gain = stocks[i] - stocks[j];

				max = stocks[i];
				min = stocks[j];
			}
		}
	}

	std::cout << "Compra: " << min << std::endl;
	std::cout << "Venda:  " << max << std::endl;
	std::cout << "Lucro:  " << gain << std::endl;

	return min;
}

#ifdef VS_IDE
void problem32()
#else
void main()
#endif
{
	int myStocks[] = { 6, 9, 11, 8, 12, 5, 7, 10 };
	std::cout << whenShouldIBuy(myStocks, ARRAY_SIZE(myStocks)) << std::endl;
}