#include <iostream>
#include <string>
#include "Options.h"

Options::Options() {
	std::cout << "Constructor"<<std::endl;
	m_definedOptions.clear();
	m_definedOptions.insert(new Option("-h", "--help", boolOption, ""));
	m_definedOptions.insert(new Option("-v", "--version", boolOption, ""));
}

Options::~Options() {
	std::cout << "Destructor"<<std::endl;
	std::set<Option*>::iterator it_options = m_definedOptions.begin();
//	for(;it_options != m_definedOptions.end(); ++it_options){
//		delete *it_options;
//	}
}

Options &Options::getInstance() {
	static Options instance;
	return instance;
}

void Options::addOption(Option *opt) {
	m_definedOptions.insert(opt);
}

bool Options::isOptionDefined(const std::string &optionName) {
	std::set<Option*>::iterator it_option = m_definedOptions.begin();
	bool foundOption = false;
	for (; it_option != m_definedOptions.end(); ++it_option){
		if (((*it_option)->getShortOption() == optionName) || ((*it_option)->getLongOption() == optionName)){
			foundOption = true;
			break;
		}
	}
	return foundOption;
}

// test functions
void Options::printDefinedOption() {
	std::set<Option*>::iterator it_options = m_definedOptions.begin();
	for(;it_options != m_definedOptions.end(); ++it_options){
		std::cout << "Short Option: "<< (*it_options)->getShortOption() << std::endl;
		std::cout << "Long Option: " << (*it_options)->getLongOption() << std::endl;
		std::cout << "Option Type: " << (*it_options)->getOptionType() << std::endl;
		std::cout << "Option Description: " << (*it_options)->getOptionDescription() << std::endl;
	}
}
