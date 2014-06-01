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
			//�հ��У������
			block_end = true;
		}
		else 
		{
			string str = ltrim(line);//ȥ�����׿ո�
			if (str[0] == '#' || 
				str[0] == '-' || 
				str[0] == '|' && 
				str[str.size()-1] == '|')
			{
				//�����л��б��л����У������
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
	//�ļ��������������һ����
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