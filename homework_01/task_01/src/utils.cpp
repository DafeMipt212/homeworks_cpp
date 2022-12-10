#include "utils.hpp"

#include <vector>
#include <string>

std::vector<std::string> SplitString(const std::string& data, const char& del) {
	std::vector <std::string> allstrings;
	std::string onestring = "";
	std::string brackets = { '(', ')' };
	bool in_brackets = 0;
	for (const char& symbol : data)
	{
		if (symbol != del && symbol != brackets[in_brackets] && symbol != '\t')
			onestring.push_back(symbol);
		else
		{
			if (in_brackets)
			{
				if (symbol == brackets[in_brackets])
				{
					onestring.push_back(symbol);
					allstrings.push_back(onestring);
					onestring = "";
					in_brackets = 0;
				}
				else
					onestring.push_back(symbol);
			}
			else
			{
				if (symbol == brackets[in_brackets])
				{
					if (onestring != "")
						allstrings.push_back(onestring);
					onestring = "";
					onestring.push_back(symbol);
					in_brackets = 1;
				}
				else
				{
					if (onestring != "")
						allstrings.push_back(onestring);
					onestring = "";
				}
			}
		}
	}
	return allstrings;
}