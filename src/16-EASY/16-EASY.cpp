/*
This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.

Proposed by: Arderson
Date: 08/04/2020
Dev Time: 18h34 - 19h03 = 29min (fiz sem considerar N)
*/

#include <iostream>

using namespace std;

class OrderIdLog
{
public:
    OrderIdLog()
    {
        log = NULL;
        log_size = 0;
    }

    ~OrderIdLog()
    {
        if (log != NULL)
            free(log);
    }

    void print()
    {
        if (log_size == 0)
            cout << "No Order ID to show!\n";
        else
        {
            cout << "Complete Order ID Log (in order of insertion):\n";

            for (int i = 0; i < log_size; ++i)
            {
                cout << log[i];

                if (i < (log_size - 1))
                    cout << ", ";
                else
                    cout << endl;
            }
        }
    }

    bool record(int order_id)
    {
        int *temp_log = (int*)realloc(log, (log_size + 1) * sizeof(int));

        if (temp_log == NULL)
            return false;

        log = temp_log;

        log[log_size++] = order_id;

        return true;
    }

    bool get_last(int* last)
    {
         if ((log_size == 0) || (last == NULL))
            return false;

        *last = log[log_size - 1];
        
        return true;
    }

private:
    unsigned int log_size;
    int* log;
};

int main()
{
    OrderIdLog my_log;
    int last;

    my_log.record(11);

    for(int i = 0; i < 5; ++i)
        my_log.record(i);

    my_log.record(47);

    my_log.print();

    if (my_log.get_last(&last))
        cout << "Last logged element: " << last << endl;
    else
        cout << "Log is empty!\n";
}
