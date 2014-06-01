#include<stdio.h>
#include<string>
#include<vector>
#include<fstream>
#include<vector>
#include "io.h"
#include "handlers.h"
#include "rules.h"
#include "parser.h"

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr,"usage: Bin input_file output_file\n");
		return 1;
	}
	HtmlRenderer handler(argv[1], argv[2]);
	BasicTextParser parser(&handler);
	parser.parse();
	return 0;
}