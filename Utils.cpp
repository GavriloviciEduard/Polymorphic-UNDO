#include "Utils.h"


std::vector<std::string> split(std::string str, std::string delim)
{
	std::vector<std::string> str_s;
	char*s = (char*)str.c_str();
	char* p;

	p = strtok(s, delim.c_str());

	while (p)
	{
		str_s.push_back(p);
		p = strtok(0, delim.c_str());
	}

	return str_s;
}