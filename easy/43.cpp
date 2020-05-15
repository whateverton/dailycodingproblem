/*
#43 - EASY
This problem was asked by Amazon.

Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.

Each method should run in constant time.

Date: 14/05/2020
Dev Time: 21h26 - 22h20 ~= 1h - Actual implementation took 15min. Didn't know how to handle error properly
*/
#include <vector>

namespace e43
{
	class Stack
	{
	public:
		Stack() { max_value = INT_MIN; }
		~Stack() {}

		void push(int val)
		{
			if (stack.empty() || val > max_value)
			{
				stack.resize(total_items);
				max_value = val;
				std::cout << "New Max: " << val << std::endl;
			}

			stack.resize(++total_items);
			stack[total_items - 1] = val;

			std::cout << "+Pushed " << val << std::endl;
		}
		
		int pop()
		{
			try
			{
				if (stack.empty())
					throw INT_MIN;
			}
			catch (int e)
			{
				std::cerr << "The stack is empty, nothing to return" << std::endl;

				return e;
			}

			int value = stack[--total_items];
			stack.resize(total_items);

			std::cout << "-Popped: " << value << std::endl;

			return value;
		}

		int max()
		{
			try
			{
				if (stack.empty())
				{
					throw INT_MIN;
				}

			}
			catch (int e)
			{
				std::cerr << "The stack is empty, nothing to return" << std::endl;

				return e;
			}

			return max_value;
		}
	private:
		std::vector<int> stack;
		int max_value;
		unsigned int total_items;
	};
}

#ifdef _43_EASY_
void CurrentSolution()
{
	e43::Stack myStack;

	std::cout << "Empty Max: " << myStack.max() << std::endl;
	std::cout << "Empty Pop: " << myStack.pop() << std::endl;

	myStack.push(1);
	myStack.push(2);
	myStack.push(8);
	myStack.push(4);
	myStack.push(5);

	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();
}
#endif
