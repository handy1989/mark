#ifndef HANDLER_H
#define HANDLER_H

#include<fstream>
#include<string>
#include<map>
#include <stdlib.h>

class HtmlRenderer;
typedef void(HtmlRenderer::*funcVoid)();
typedef std::string(HtmlRenderer::*funcString)();
/*
class Handler
{
public:
	Handler();
	~Handler();
	void callFunc(std::string&);
	funcVoid getFunc(std::string&);
	void start(std::string);
	void end(std::string);
	void initMap();
	std::map<std::string, funcVoid>func_map;
};
*/
class HtmlRenderer
{
public:
	HtmlRenderer(std::string in, std::string out)
	{
		initFile(in, out);
		initMap();
	}
	~HtmlRenderer()
	{
		if (infile)
		{
			infile.close();
		}
		if (outfile)
		{
			outfile.close();
		}
	}
	void callVoidFunc(std::string);
	std::string callStringFunc(std::string);
	funcVoid getVoidFunc(std::string);
	funcString getStringFunc(std::string);
	void start(std::string);
	void end(std::string);
	std::string sub(std::string);
	void feed(std::string &block)
	{
		outfile << block << std::endl;
	}
	std::map<std::string, funcVoid>func_void_map;
	std::map<std::string, funcString>func_string_map;
	void initMap();
	void initFile(std::string&, std::string&);
	std::ifstream infile;
	std::ofstream outfile;
	
	inline void startDocument()
	{
		outfile << "<html><head><title>...</title></head><body>" << std::endl;
	}
	inline void endDocument()
	{
		outfile << "</body></html>" << std::endl;
	}
	inline void startParagraph()
	{
		outfile << "<p>" << std::endl;
	}
	inline void endParagraph()
	{
		outfile << "</p>" << std::endl;
	}
	inline void startHeading()
	{
		outfile << "<h2>" << std::endl;
	}
	inline void endHeading()
	{
		outfile << "</h2>" << std::endl;
	}
	inline void startList()
	{
		outfile << "<ul>" << std::endl;
	}
	inline void endList()
	{
		outfile << "</ul>" << std::endl;
	}
	inline void startListItem()
	{
		outfile << "<li>" << std::endl;
	}
	inline void endListItem()
	{
		outfile << "</li>" << std::endl;
	}
	inline void startTitle()
	{
		outfile << "<h1>" << std::endl;
	}
	inline void endTitle()
	{
		outfile << "</h1>" << std::endl;
	}
	inline void startH1()
	{
		outfile << "<h1>" << std::endl;
	}
	inline void endH1()
	{
		outfile << "</h1>" << std::endl;
	}
	inline void startH2()
	{
		outfile << "<h2>" << std::endl;
	}
	inline void endH2()
	{
		outfile << "</h2>" << std::endl;
	}
	inline void startPre()
	{
		outfile << "<pre><code>" << std::endl;
	}
	inline void endPre()
	{
		outfile << "</code></pre>" << std::endl;
	}
	inline void startTable()
	{
		outfile << "<table border=\"1\">" << std::endl;
	}
	inline void endTable()
	{
		outfile << "</table>" << std::endl;
	}
	inline void startTr()
	{
		outfile << "<tr>" << std::endl;
	}
	inline void endTr()
	{
		outfile << "</tr>" << std::endl;
	}
	inline void startTd()
	{
		outfile << "<td>" << std::endl;
	}
	inline void endTd()
	{
		outfile << "</td>" << std::endl;
	}
	inline std::string subEmphasis()
	{
		return "<em>$1</em>";
	}
	inline std::string subStrong()
	{
		return "<strong>$1</strong>";
	}
	inline std::string subHref()
	{
		return "<a target=\"_blank\" href=\"$2\">$1</a>";
	} 
	inline std::string subImage()
	{
		return "<img alt=\"$1\" src=\"$2\">";
	}
};



#endif
