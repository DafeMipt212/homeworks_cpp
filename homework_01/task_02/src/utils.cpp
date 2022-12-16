#include "utils.hpp"

int Calculate(const std::string& data)
{
	int i = 0;
	int a = 0;
	while (isdigit(data[i])&& i < data.length())
	{
		a *= 10;
		a += int(data[i]) - 48;
		i++;
	}
	std::string operation = "";
	while (!isdigit(data[i]) && i < data.length())
	{
		operation += data[i];
		i++;
	}
	int b = 0;
	while (isdigit(data[i]) && i < data.length())
	{
		b *= 10;
		b += int(data[i]) - 48;
		i++;
	}
	if (operation == "+")
		return a + b;
	else if (operation == "-")
		return a - b;
	else if (operation == "*")
		return a * b;
	else if (operation == "/")
		return a / b;
	else
		return 36606;
}