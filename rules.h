
#ifndef RULES_H
#define RULES_H

#include<string>
#include<vector>
#include "handlers.h"

class Filters
{
public:
	Filters(std::string reg, std::string name) : regex(reg), sub_name(name)
	{

	}
	std::string filter(std::string &block, HtmlRenderer *handler);
	std::string regex;
	std::string sub_name;
};

class Rules
{
public:
	virtual bool action(std::string &block, HtmlRenderer *handler)
	{
		handler->start(type);
		handler->feed(block);
		handler->end(type);
		return true;
	}
	virtual bool condition(std::string &block)
	{
		return true;
	}
	std::string type;
};

class HeadingRule: public Rules
{
public:
	HeadingRule()
	{
		type = "Heading";
	}
	bool condition(std::string &block);
};

class Paragraph: public Rules
{
public:
	Paragraph()
	{
		type = "Paragraph";
	}
};

class TitleRule: public Rules
{
public:
	TitleRule() : first(true)
	{
		type = "Title";
	}
	bool condition(std::string &block);
	bool first;
};

class ListItemRule: public Rules
{
public:
	ListItemRule()
	{
		type = "ListItem";
	}
	bool condition(std::string &block)
	{
		return block[0] == '-';
	}
	bool action(std::string &block, HtmlRenderer *handler);
};

class ListRule: public Rules
{
public:
	ListRule() : inside(false)
	{
		type = "List";
	}
	bool action(std::string &block, HtmlRenderer *handler);
	bool inside;
};

class TrRule: public Rules
{
public:
	TrRule()
	{
		type = "Tr";
	}
	bool condition(std::string &block)
	{
		return block[0] == '|' && block[block.size()-1] == '|';
	}
	bool action(std::string &block, HtmlRenderer *handler);
};

class TableRule: public Rules
{
public:
	TableRule() : inside(false)
	{
		type = "Table";
	}
	bool action(std::string &block, HtmlRenderer *handler);
	bool inside;
};

class H1Rule: public Rules
{
public:
	H1Rule()
	{
		type = "H1";
	}
	bool condition(std::string &block)
	{
		return block[0] == '#';
	}
	bool action(std::string &block, HtmlRenderer *handler);
};

class H2Rule: public Rules
{
public:
	H2Rule()
	{
		type = "H2";
	}
	bool condition(std::string &block)
	{
		return block.size() >= 3 && block[0] == '#' && block[1] == '#';
	}
	bool action(std::string &block, HtmlRenderer *handler);
};

class PreRule: public Rules
{
public:
	PreRule()
	{
		type = "Pre";
	}
	bool condition(std::string &block)
	{
		return block[0] == '\t';
	}
	bool action(std::string &block, HtmlRenderer *handler);
};

#endif
