#include "helper.h"

void printVector(std::vector<int> print)
{
	for (std::vector<int>::iterator it = print.begin(); it != print.end(); ++it)
	{
		std::cout << *it << ",";
	}
}
