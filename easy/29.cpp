/*
#29 - EASY
This problem was asked by Amazon.

Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.

Date: 28/04/2020
Dev Time: 19h38 - 20h22 = 44min + 20min (optimizing)
*/
#include <string>

std::string encodeString(std::string s)
{
	if (s.empty())
		return "";

	std::string final_string;
	char temp_buffer[10 + 1];
	char current_char = s[0];
	char total_char = 1;

	for (size_t i = 1; i < s.length(); ++i)
	{
		if ((s[i] != current_char))
		{
			sprintf_s(temp_buffer, "%d%c", total_char, current_char);
			final_string += temp_buffer;

			current_char = s[i];
			total_char = 1;
		}
		else
		{
			++total_char;
		}

	}

	// Needs to save the last character count
	sprintf_s(temp_buffer, "%d%c", total_char, current_char);
	final_string += temp_buffer;

	return final_string;
}

std::string decodeString(std::string s)
{
	if (s.empty())
		return "";

	std::string final_string;
	std::string temp_string;

	for (size_t i = 0; i < s.length(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			temp_string += s[i];
		else
		{
			int total_char = atoi(temp_string.c_str());
			temp_string = std::string(total_char, s[i]);
			final_string += temp_string;
			temp_string = "";
		}
	}

	return final_string;
}

#ifdef _29_EASY_
void CurrentSolution()
{
	// Testing string that when decoded gets 2 digits char amount (12 Z's)
	// Checking if the lone last character won't be a problem
	std::string OriginalString("AAAABBBCCDAAZZZZZZZZZZZZL");
	std::cout << "Original String: " << OriginalString << std::endl;

	std::string EncodedString = encodeString(OriginalString);
	std::cout << "Original String: " << EncodedString << std::endl;

	std::string DecodedString = decodeString(EncodedString);
	std::cout << "Original String: " << DecodedString << std::endl;

	if (OriginalString == DecodedString)
	{
		std::cout << "SUCESS!" << std::endl;
	}
	else
	{
		std::cout << "FAIL!" << std::endl;
	}

}
#endif