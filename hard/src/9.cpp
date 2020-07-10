/*
#9 - HARD
Good morning! Here's your coding interview problem for today.

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?

*/

#ifdef VS_IDE
#include "helper.h"
#endif

int maxSum(int * arr, size_t n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    size_t i;

    for (i = 1; i < n; i++)
    {
        /* current max excluding i */
        excl_new = (incl > excl) ? incl : excl;

        /* current max including i */
        incl = excl + arr[i];
        excl = excl_new;
    }

    /* return max of incl and excl */
    return ((incl > excl) ? incl : excl);
}

#ifdef VS_IDE
void problem9()
#else
void main()
#endif
{
    int a[] = { 2, 4, 6, 2, 5 };
    int sizeA = ARRAY_SIZE(a);

    int b[] = { 5, 1, 1, 5 };
    int sizeB = ARRAY_SIZE(b);

    int c[] = { 0, 1, 1, 5 };
    int sizeC = ARRAY_SIZE(c);

    int d[] = { 5, 1, 1, 5, 7 }; //13?? -->17
    int sizeD = ARRAY_SIZE(d);

    int e[] = { 5, 1, 1, 5, 7, 2, 3, 10 }; //23?? - 22 --> 30
    int sizeE = ARRAY_SIZE(e);

    int f[] = { 1, 1000, 2, 3, 1000, 1, 3, 2000 }; //4000 -->4000
    int sizeF = ARRAY_SIZE(f);

    int g[] = { -1, 5, -1, -5, 7, 2, 3, 10 }; //18 -->21
    int sizeG = ARRAY_SIZE(g);

    std::cout << "Max Sum of A: " << maxSum(a, sizeA) << std::endl;
    std::cout << "Max Sum of B: " << maxSum(b, sizeB) << std::endl;
    std::cout << "Max Sum of C: " << maxSum(c, sizeC) << std::endl;
    std::cout << "Max Sum of D: " << maxSum(d, sizeD) << std::endl;
    std::cout << "Max Sum of E: " << maxSum(e, sizeE) << std::endl;
    std::cout << "Max Sum of F: " << maxSum(f, sizeF) << std::endl;
    std::cout << "Max Sum of G: " << maxSum(g, sizeG) << std::endl;
}