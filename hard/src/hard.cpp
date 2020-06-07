#include <iostream>
#include <stdlib.h>

#include "problems.h"

int main(int argc, char **argv)
{
    void (*current_problem)();
    int index;

    if (argc > 1)
    {
        index = atoi(argv[1]);
    }
    else
    {
        std::cout << "Digite o problema desejado [HARD]: " << std::endl;

        std::cin >> index;
    }

    current_problem = problem_func[index];

    if (current_problem != nullptr)
        (*current_problem)();
}