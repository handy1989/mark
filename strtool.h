#ifndef STRTOOL_H
#define STRTOOL_H

#include <string>
#include <vector>

std::string ltrim(const std::string &str);
std::string rtrim(const std::string &str);
std::string trim(const std::string &str);
int split(const std::string &str, std::vector<std::string> &ret, const std::string sep);

#endif
