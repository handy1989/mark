#ifndef READ_H
#define READ_H

#include<fstream>

void readBlock(std::ifstream &, std::vector<std::string> &);
int writeBlock(std::ofstream &, std::vector<std::string> &);

#endif