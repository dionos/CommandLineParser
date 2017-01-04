#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include <set>
#include "Option.h"

class Options {
private:
	Options();
public:
	static Options &getInstance();
	~Options();

public:
	void addOption(Option *opt);
//test functions
	void printDefinedOption();

private:
	std::set<Option*> m_definedOptions;
};

#endif // __OPTIONS_H__
