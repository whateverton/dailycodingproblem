/*
#25 - Hard
This problem was asked by Facebook.

Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray", your function should return true. The same regular expression on the string "raymond" should return false.

Given the regular expression ".*at" and the string "chat", your function should return true. The same regular expression on the string "chats" should return false.

Date: 13/07/2020
*/
#ifdef VS_IDE
#include "helper.h"
#endif

bool RegexMatch(std::string regex, std::string str)
{
	char any_qtd_char = 0;
	char get_next = false;
	int str_index = str.size() - 1;
	bool res = true;

	for (int i = regex.size() - 1; i >= 0; --i)
	{
		if (get_next)
		{
			get_next = false;
			any_qtd_char = regex[i];
		}

		if (regex[i] == '*')
		{
			get_next = true;
			continue;
		}

		if (any_qtd_char)
		{
			while (any_qtd_char == str[str_index] || any_qtd_char == '.')
			{
				--str_index;
				if (!str_index)
					break;
			}

			any_qtd_char = 0;
		}

		if ((regex[i] != '*') && (regex[i] != '.'))
		{
			if (regex[i] == str[str_index])
			{
				--str_index;
				if (!str_index)
					break;

				continue;
			}
			else
			{
				res = false;
				break;
			}
		}

		if (regex[i] == '.')
		{
			--str_index;
			if (!str_index)
				break;

			continue;
		}
	}

	return res;
}

#ifdef VS_IDE
void problem25()
#else
void main()
#endif
{
	std::cout << RegexMatch("ra.", "rays") << std::endl;
	std::cout << RegexMatch("ra.", "ray") << std::endl;
	std::cout << RegexMatch(".*at", "chat") << std::endl;
	std::cout << RegexMatch(".*at", "chats") << std::endl;
}
