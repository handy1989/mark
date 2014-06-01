#include <boost/regex.hpp>
#include <string>
#include <vector>
#include "rules.h"
#include "strtool.h"

using std::vector;
using std::string;

string Filters::filter(string &block, HtmlRenderer *handler)
{
	boost::regex reg(regex);
	string sub =  handler->sub(sub_name);
	string ret = boost::regex_replace(block, reg, sub);
	return ret;
}

bool HeadingRule::condition(string &block)
{
	size_t size = block.size();
	bool ret = block.find('\n') && size <= 70 && ! (block[size-1] == ':');
	return ret;
}

bool TitleRule::condition(string &block)
{
	size_t size = block.size();
	if (!first)
	{
		return false;
	}
	first = false;
	HeadingRule head;
	return head.condition(block);
}

bool ListItemRule::action(string &block, HtmlRenderer *handler)
{
	string data(block, 1);
	handler->start(type);
	handler->feed(data);
	handler->end(type);
	return true;
}

bool ListRule::action(string &block, HtmlRenderer *handler)
{
	ListItemRule list_item;
	if (!inside && list_item.condition(block))
	{
		handler->start(type);
		inside = true;
	}
	else if (inside && !list_item.condition(block))
	{
		handler->end(type);
		inside = false;
	}
	return false;
}

bool TrRule::action(string &block, HtmlRenderer *handler)
{
	vector<string> columns;
	string row = block.substr(1,block.size()-2); //È¥³ýÊ×Î²µÄ¡®|¡¯
	split(row, columns, "|");
	handler->start(type);
	vector<string>::iterator it;
	for (it = columns.begin(); it != columns.end(); ++it)
	{
		handler->start("Td");
		handler->feed(*it);
		handler->end("Td");
	}
	handler->end(type);
	return true;
	
}

bool TableRule::action(string &block, HtmlRenderer *handler)
{
	TrRule tr;
	if (!inside && tr.condition(block))
	{
		handler->start(type);
		inside = true;
	}
	else if (inside && !tr.condition(block))
	{
		handler->end(type);
		inside = false;
	}
	return false;
}

bool PreRule::action(string &block, HtmlRenderer *handler)
{
	handler->start(type);
	handler->feed(block);
	handler->end(type);
	return true;
}

bool H1Rule::action(string &block, HtmlRenderer *handler)
{
	string data(block, 1);
	handler->start(type);
	handler->feed(data);
	handler->end(type);
	return true;
}

bool H2Rule::action(string &block, HtmlRenderer *handler)
{
	string data(block, 2);
	handler->start(type);
	handler->feed(data);
	handler->end(type);
	return true;
}
