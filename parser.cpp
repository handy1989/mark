#include <string>
#include <vector>
#include "rules.h"
#include "handlers.h"
#include "parser.h"
#include "io.h"

using std::vector;
using std::string;

void Parser::parse()
{
	vector<string> blocks;
	vector<string>::iterator it_block;
	vector<Rules*>::iterator it_rule;
	vector<Filters*>::iterator it_filter;
	readBlock(handler->infile, blocks);
	handler->start("Document");
	for (it_block = blocks.begin(); it_block != blocks.end(); ++it_block)
	{
		string block_normalize = *it_block;
		for (it_filter = filters.begin(); it_filter != filters.end(); ++it_filter)
		{
			block_normalize = (*it_filter)->filter(block_normalize, handler);
		}
		for (it_rule = rules.begin(); it_rule != rules.end(); ++it_rule)
		{
			if ((*it_rule)->condition(block_normalize))
			{
				if ((*it_rule)->action(block_normalize, handler))
				{
					break;
				}
			}
		}
	}
	handler->end("Document");
}