/*
#1-EASY
This problem was recently asked by Google.

Given a list of numbersand a number k, return whether any two numbers from the list add up to k.

For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass ?

Proposed by: Everton
Date: 06/04/2020
Dev Time: 22h40 - 23h28
*/

#include <iostream>
#include <list>

using namespace std;

typedef list<int> MY_LIST_T;

MY_LIST_T given_list({ 10, 15, 3, -7 , 7});

const int MAGIC_NUMBER = 17;

MY_LIST_T anyTwoAddUp(MY_LIST_T* local_list, int k)
{
    MY_LIST_T ret_list;
    int list_size = local_list->size();

    for (MY_LIST_T::iterator it = local_list->begin(); it != local_list->end(); ++it)
    {
        // k = a + b | b = k - a
        int diff = k - (*it);

        local_list->remove(diff);

        if (list_size != local_list->size())
        {
            ret_list.push_back(*it);
            ret_list.push_back(diff);

            break;
        }
    }

    return ret_list;
}

#ifdef _1_EASY_
void CurrentSolution()
{
    MY_LIST_T res_list = anyTwoAddUp(&given_list, MAGIC_NUMBER);

    if(res_list.empty())
        cout << "No two members add up to " << MAGIC_NUMBER << ".\n";
    else
    {
        cout << "These numbers add up to " << MAGIC_NUMBER << ":\n";
        for(MY_LIST_T::iterator it = res_list.begin(); it != res_list.end(); ++it)
            cout << *it << endl;
    }
}
#endif
