#include <iostream>
#include <stdlib.h>

#include "problems.h"

int main(int argc, char **argv)
{
    void (*current_problem)();
    int index = -1;

    if (argc > 1)
    {
        index = atoi(argv[1]);
    }
    
    do
    {
        if (index == -1)
        {
            std::cout << "Digite o problema desejado [HARD]: " << std::endl;

            std::cin >> index;
        }

        current_problem = problem_func[index];

        if (current_problem != nullptr)
        {
            (*current_problem)();
        }
        else
        {
            index = -1;
            std::cout << "Funcao nao encontrada!" << std::endl;
        }
    } while (index == -1);
}