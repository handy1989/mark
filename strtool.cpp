#include "strtool.h"

using std::string;
using std::vector;

string ltrim(const string &str)
{
	if (str.empty())
	{
		return str;
	}
	string::size_type pos = str.find_first_not_of(" ");
	if (pos == string::npos)
	{
		return str;
	}
	if (str[0] == ' ')
	{
		return "";//全部是空格
	}
	return str.substr(pos);
}

string rtrim(const string &str)
{
	if (str.empty())
	{
		return str;
	}
	string::size_type pos = str.find_last_not_of(" ");
	if (pos != string::npos)
	{
		return str.substr(0, pos+1);
	}
	if (str[str.size()-1] == ' ')
	{
		return "";  //全部是空格
	}
	return str;
}

string trim(const string &str)
{
	return ltrim(rtrim(str));
}

int split(const string &str, vector<string> &ret, const string sep=" ")
{
	if (str.empty())
	{
		return 0;
	}
	string tmp;
	string::size_type sub_begin = 0;
	string::size_type sub_end = str.find(sep);
	while (sub_end != string::npos)
	{
		tmp = str.substr(sub_begin, sub_end - sub_begin);
		ret.push_back(tmp);
		sub_begin = sub_end + 1;
		sub_end = str.find(sep, sub_begin);
	}
	tmp = str.substr(sub_begin, sub_end - sub_begin);
	ret.push_back(tmp);
	return 0;
}
