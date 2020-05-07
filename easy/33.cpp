/*
#33 - EASY
This problem was asked by Microsoft.

Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2

Date: 07/05/2020
Dev Time: 20h24 - 20h44 = 20 min
*/
#include <vector>
#include <algorithm>

bool isOdd(int value)
{
	return (bool)(value % 2);
}

void ComputeMedian(vector<int> sequence)
{
	vector<int> current_sequence;
	for (vector<int>::iterator it = sequence.begin(); it != sequence.end(); ++it)
	{
		current_sequence.push_back(*it);
		std::sort(current_sequence.begin(), current_sequence.end());
		
		int seq_size = current_sequence.size();
		if (isOdd(seq_size))
		{
			std::cout << current_sequence[(seq_size / 2)] << std::endl;
		}
		else
		{
			int first_num = current_sequence[(seq_size / 2)-1];
			int second_num = current_sequence[(seq_size / 2)];
			std::cout << (float)(first_num + second_num) / 2.0f << std::endl;
		}
	}
}

#ifdef _33_EASY_
void CurrentSolution()
{
	int my_ints[] = { 2, 1, 5, 7, 2, 0, 5 };
	vector<int> my_list (my_ints, my_ints + sizeof(my_ints) / sizeof(int));

	ComputeMedian(my_list);
}
#endif
