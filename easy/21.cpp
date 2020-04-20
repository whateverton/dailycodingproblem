/*
#21 - EASY
This problem was asked by Snapchat.

Given an array of time intervals(start, end) for classroom lectures(possibly overlapping), find the minimum number of rooms required.

For example, given[(30, 75), (0, 50), (60, 150)], you should return 2.

Date: 15/04/2020
Dev Time: 18h30 - 19h24
*/
#include <iostream>
#include <vector>

typedef struct time_interval
{
	int start;
	int end;
}time_interval_t;

time_interval_t class_intervals[] = { {30,75}, {0,50}, {60,150}, {20,55}, {150, 170}, {170, 180}, {175, 185}, {185, 190}, {1, 189} };

/*
	       30---------75 - 3
	0----------50 - 2
			       60------------------150 - 4
         20-------55 - 4
		                               150----170 - 2
									          170----180 - 2
											      175--185 - 3
												       185-190 -3
    0-----------------------------------------------------189 - 1
*/

int RoomsRequired(time_interval_t* time_intervals, int array_size)
{
	int rooms_required = 1;

	if (array_size == 0 || array_size == 1)
		return array_size;

	for (int i = 1; i < array_size; ++i)
	{
		int overlaps = 0;

		for (int j = 0; j < i; ++j)
		{
			if (time_intervals[i].start < time_intervals[j].end && time_intervals[i].end > time_intervals[j].start)
			{
				++overlaps;
			}

			if (overlaps >= rooms_required)
			{
				++rooms_required;
				break;
			}
		}

	}

	return rooms_required;
}

#ifdef _21_EASY_
void CurrentSolution()
{
	std::cout << "The amount of rooms required to is: " << RoomsRequired(class_intervals, sizeof(class_intervals) / sizeof(time_interval_t)) << std::endl;
}
#endif