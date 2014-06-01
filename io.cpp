#include<vector>
#include<fstream>
#include<string>
#include "io.h"
#include "strtool.h"

using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;

void readBlock(ifstream& in, vector<string>& blocks)
{
	string line;
	string block = "";
	bool block_end = false;
	while (getline(in, line))
	{
		block_end = false;
		string::size_type size = line.size();
		string tmp = trim(line);
		if (trim(line).size() <= 0)
		{
			//空白行，块结束
			block_end = true;
		}
		else 
		{
			string str = ltrim(line);//去除行首空格
			if (str[0] == '#' || 
				str[0] == '-' || 
				str[0] == '|' && 
				str[str.size()-1] == '|')
			{
				//标题行或列表行或表格行，块结束
				block_end = true;
				block = block + trim(line);
			}
		}
		if (block_end)
		{
			if (block.size() > 0)
			{
				blocks.push_back(block);
			}
			block = "";
		}
		else
		{
			if (line[line.size()-1] == ' ')
			{
				line = trim(line) + "</br>";
			}
			block = block + line;
		}
	}
	//文件结束，处理最后一个块
	if (block.size() > 0)
	{
		blocks.push_back(block);
	}
}

int writeBlock(ofstream& out, vector<string>& block)
{
	vector<string>::iterator it;
	for(it = block.begin(); it != block.end(); ++it)
	{
		out << *it;
	}
	return 0;
}