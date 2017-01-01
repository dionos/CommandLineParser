#ifndef __CMDPARSER_H__
#define __CMPPARSER_H__

class CMDParser {
public:
	CMDParser();
//	CMDParser(Option);
	~CMDParser();

public:
	void parser(int argc, char* argv[]);

private:
	bool isLongOption();
	bool isMultiShortOption();
	bool isLongOptionOneDesh();
	bool isShortOption();
};

#endif //__CMDPARSER_H__
