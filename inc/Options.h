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
	/*
		check is option defined. input can be short or long option name.
	*/
	bool isOptionDefined(const std::string &option);
	
	/*
	 * Change description for one of predefined Option --help or --version
	 * @param option Should be --help or --version.
	 * @param descriptoion Description of options
	 * @return none
	 */
	void changePredefinedDescription(const std::string &option, const std::string &description);
//test functions
	void printDefinedOption();

private:
	std::set<Option*> m_definedOptions;
};

#endif // __OPTIONS_H__
