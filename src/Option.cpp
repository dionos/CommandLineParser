#include <iostream>
#include "Option.h"

Option::Option(const std::string &shortOption, const std::string &longOption, OptionType type, const std::string &description)
	:m_shortOption(shortOption), m_longOption(longOption), m_optionType(type), m_description(description) {

}

Option::~Option() {

}

void Option::changeDescription(const std::string &newDescription) {
	m_description = newDescription;
}

std::string Option::getShortOption() const {
	return m_shortOption;
}

std::string Option::getLongOption() const {
	return m_longOption;
}

OptionType Option::getOptionType() const {
	return m_optionType;
}

std::string Option::getOptionDescription() const {
	return m_description;
}
