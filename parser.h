#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "handlers.h"
#include "rules.h"

class Parser
{
public:
	void addRule(Rules *rule)
	{
		rules.push_back(rule);
	}
	void addFilter(Filters *filter)
	{
		filters.push_back(filter);
	}
	void parse();

	HtmlRenderer *handler;
	std::vector<Rules*> rules;
	std::vector<Filters*> filters;
};

class BasicTextParser: public Parser
{
public:
	BasicTextParser(HtmlRenderer *han)
	{
		handler = han;
//		(*this).addRule(new PreRule);
		(*this).addRule(new H2Rule);
		(*this).addRule(new H1Rule);
		(*this).addRule(new TableRule);
		(*this).addRule(new TrRule);
		(*this).addRule(new ListRule);
		(*this).addRule(new ListItemRule);
		(*this).addRule(new Paragraph);

		(*this).addFilter(new Filters("!\\[(.*?)\\]\\((.+?)\\)", "Image"));
		(*this).addFilter(new Filters("\\[(.+?)\\]\\((.+?)\\)", "Href"));
		(*this).addFilter(new Filters("\\*\\*(.+?)\\*\\*", "Strong"));
		(*this).addFilter(new Filters("\\*(.+?)\\*", "Emphasis"));
	}
};

#endif