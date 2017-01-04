#include <iostream>
#include "CMDParser.h"

CMDParser::CMDParser() {

}

CMDParser::~CMDParser() {

}

void CMDParser::parser(int argc, char* argv[]) {
	for (int it_argc = 0; it_argc < argc; it_argc++){
		std::cout << "Option: "<< argv[it_argc] << std::endl;
	}
}

bool CMDParser::isLongOption() {
	return false;
}

bool CMDParser::isMultiShortOption() {
	return false;
}

bool CMDParser::isLongOptionOneDash() {
	return false;
}

bool CMDParser::isShortOption() {
	return false;
}
