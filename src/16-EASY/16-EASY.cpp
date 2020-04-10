/*
This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.

Proposed by: Arderson
Date: 08/04/2020
Dev Time: 18h34 - 19h03 = 29min (fiz sem considerar N)
          19h09 - 19h50 = 41min (solucao completa)
*/

#include <iostream>

using namespace std;

class OrderIdLog
{
public:
    OrderIdLog(int N)
    {
        log = (int*)malloc (N * sizeof(int));

        log_size = N;
        head = -1;
        tail = 0;
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

            for (int i = 0, elem = tail; i < log_size; ++i, ++elem)
            {
                if (elem >= log_size)
                    elem = 0;

                cout << log[elem];

                if (elem != head)
                    cout << ", ";
                else
                {
                    cout << endl;
                    break;
                }
            }
        }
    }

    bool record(int order_id)
    {
        if (tail != 0)
        {
            if (++tail >= log_size)
                tail = 0;
        }

        if ((++head >= log_size))
        {
            head = 0;

            if (log_size > 1)
                ++tail;
        }

        log[head] = order_id;

        return true;
    }

    int get_last(int i_last)
    {
        int elem;

        if ((log_size == 0) || (i_last > log_size) || (i_last == 0))
           return -1;

        elem = head - i_last + 1;

        if ((elem) < 0)
            elem += log_size;

        return log[elem];
    }

private:
    int log_size;
    int head;
    int tail;
    int* log;
};

int main()
{
    OrderIdLog my_log(2);
    int last;

    my_log.record(1);

    for(int i = 0; i < 5; ++i)
        my_log.record(i);

    my_log.record(47);

    my_log.print();

    last = my_log.get_last(2);

    if (last != -1)
        cout << "Last logged element: " << last << endl;
    else
        cout << "Log is empty!\n";
}
