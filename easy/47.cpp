/*
#47 - EASY
This problem was asked by Facebook.

Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.

Date: 21/05/2020
Dev Time: 18h40 - 19h = 20min
*/

int whenShouldIBuy(int *stocks, int size)
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

#ifdef _47_EASY_
void CurrentSolution()
{
	int myStocks[] = { 6, 9, 11, 8, 12, 5, 7, 10 };
	std::cout << whenShouldIBuy(myStocks, sizeof(myStocks)/sizeof(myStocks[0])) << std::endl;
}
#endif
