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
        head = 0;
        tail = 0;
    }

    ~OrderIdLog()
    {
        if (log != NULL)
            free(log);
    }

    bool record(int order_id)
    {
        if (++head >= log_size)
        {
            head = 0;

            if (log_size > 1)
                ++tail;
        }
        
        if (tail != 0)
        {
            if (++tail >= log_size)
                tail = 0;
        }

        log[tail] = order_id;

        return true;
    }

    bool get_last(int* last)
    {
         if ((log_size == 0) || (last == NULL))
            return false;

        *last = log[tail];
        
        return true;
    }

private:
    unsigned int log_size;
    unsigned int head;
    unsigned int tail;
    int* log;
};

int main()
{
    OrderIdLog my_log(1);
    int last;

    my_log.record(1);

    for(int i = 0; i < 5; ++i)
        my_log.record(i);

    my_log.record(47);

    if (my_log.get_last(&last))
        cout << "Last logged element: " << last << endl;
    else
        cout << "Log is empty!\n";
}
