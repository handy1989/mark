#include<string>
#include<vector>
#include<map>
#include "handlers.h"

using std::string;
using std::map;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::endl;


funcVoid HtmlRenderer::getVoidFunc(string funcname)
{
	map<string, funcVoid>::iterator it = func_void_map.find(funcname);
	if (it != func_void_map.end())
	{
		return it->second;
	}
	return NULL;
}

funcString HtmlRenderer::getStringFunc(string funcname)
{
	map<string, funcString>::iterator it = func_string_map.find(funcname);
	if (it != func_string_map.end())
	{
		return it->second;
	}
	return NULL;
}

void HtmlRenderer::callVoidFunc(string funcname)
{
	funcVoid funcp = getVoidFunc(funcname);
	if (funcp)
	{
		return (this->*funcp)();
	}
}

string HtmlRenderer::callStringFunc(string funcname)
{
	funcString funcp = getStringFunc(funcname);
	if (funcp)
	{
		return (this->*funcp)();
	}
	return "";
}

void HtmlRenderer::start(string func_suffix)
{
	string func_prefix("start");
	callVoidFunc(func_prefix + func_suffix);
}

void HtmlRenderer::end(string func_suffix)
{
	string func_prefix("end");
	callVoidFunc(func_prefix + func_suffix);
}

string HtmlRenderer::sub(string func_suffix)
{
	string func_prefix("sub");
	return callStringFunc(func_prefix + func_suffix);
}


void HtmlRenderer::initFile(string &in, string &out)
{
	infile.open(in.c_str());
	outfile.open(out.c_str());
	if (!infile || !outfile)
	{
		fprintf(stderr, "open file %s or %s failed!\n", in.c_str(), out.c_str());
		exit(1);
	}
}

void HtmlRenderer::initMap()
{
	func_void_map["startDocument"] = &HtmlRenderer::startDocument;
	func_void_map["endDocument"] = &HtmlRenderer::endDocument;
	func_void_map["startParagraph"] = &HtmlRenderer::startParagraph;
	func_void_map["endParagraph"] = &HtmlRenderer::endParagraph;
	func_void_map["startHeading"] = &HtmlRenderer::startHeading;
	func_void_map["endHeading"] = &HtmlRenderer::endHeading;
	func_void_map["startList"] = &HtmlRenderer::startList;
	func_void_map["endList"] = &HtmlRenderer::endList;
	func_void_map["startListItem"] = &HtmlRenderer::startListItem;
	func_void_map["endListItem"] = &HtmlRenderer::endListItem;
	func_void_map["startTitle"] = &HtmlRenderer::startTitle;
	func_void_map["endTitle"] = &HtmlRenderer::endTitle;
	func_void_map["startH1"] = &HtmlRenderer::startH1;
	func_void_map["endH1"] = &HtmlRenderer::endH1;
	func_void_map["startH2"] = &HtmlRenderer::startH2;
	func_void_map["endH2"] = &HtmlRenderer::endH2;
	func_void_map["startPre"] = &HtmlRenderer::startPre;
	func_void_map["endPre"] = &HtmlRenderer::endPre;
	func_void_map["startTable"] = &HtmlRenderer::startTable;
	func_void_map["endTable"] = &HtmlRenderer::endTable;
	func_void_map["startTr"] = &HtmlRenderer::startTr;
	func_void_map["endTr"] = &HtmlRenderer::endTr;
	func_void_map["startTd"] = &HtmlRenderer::startTd;
	func_void_map["endTd"] = &HtmlRenderer::endTd;

	func_string_map["subEmphasis"] = &HtmlRenderer::subEmphasis;
	func_string_map["subStrong"] = &HtmlRenderer::subStrong;
	func_string_map["subHref"] = &HtmlRenderer::subHref;
	func_string_map["subImage"] = &HtmlRenderer::subImage;
}
