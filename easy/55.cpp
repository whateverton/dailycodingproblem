/*
#55 - EASY
This problem was asked by Microsoft.

Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
Hint: What if we enter the same URL twice?

Date: 21/05/2020
Dev Time: 23h53 - 1h10 = 1h17min
*/
#include <string>
#include <map>

class UrlShortener {
public:
	UrlShortener() {}
	~UrlShortener() {}

	std::string shorten(std::string url)
	{
		last_short_url = getNextShortUrl();
		data[last_short_url] = url;

		return last_short_url;
	}

	std::string restore(std::string short_url)
	{
		std::map<std::string, std::string>::iterator it;
		it = data.find(short_url);

		if (it != data.end())
		{
			return it->second;
		}
		else
		{
			return "";
		}
	}

private:
	#define INITAL_STRING "000000"
	#define FINAL_STRING  "zzzzzz"

	std::map<std::string, std::string> data;
	std::string last_short_url;

	std::string getNextShortUrl()
	{
		if (last_short_url.empty())
		{
			return "zLg6wl"; // Just to look nice, could be anything
		}
		else
		{
			char final_url[6 + 1];

			strncpy_s(final_url, last_short_url.c_str(), sizeof(final_url));

			incrementUrlChar(final_url, sizeof(final_url) - 1);

			return std::string(final_url);
		}
	}

	void incrementUrlChar(char* url, int size)
	{
		char index = size - 1;
		char increment = 1;

		if (!strcmp(url, FINAL_STRING))
		{
			strcpy_s(url, sizeof(INITAL_STRING), INITAL_STRING);
			return;
		}

		if (url[index] == '9')
		{
			increment = 8; // Skip to A
		}
		else if (url[index] == 'Z')
		{
			increment = 7; // Skip to a
		}
		else if (url[index] == 'z')
		{
			url[index] = '0'; // Get back 0
			incrementUrlChar(url, index);
			return;
		}

		url[index] += increment;
	}
};

#ifdef _55_EASY_
void CurrentSolution()
{
	UrlShortener url_shortener;

	for (int i = 0; i < 5; ++i)
	{
		std::string s_url = url_shortener.shorten("url_test_" + std::string(1, (char)(i + 0x30)));

		std::cout << "Short: " <<s_url << " - Long: " << url_shortener.restore(s_url) << std::endl;
	}
}
#endif