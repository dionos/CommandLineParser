#include <iostream>
#include "Option.h"

Option::Option(const std::string &shortOption, const std::string &longOption, OptionType type, const std::string &description, int size = 1)
	:m_shortOption(shortOption), m_longOption(longOption), m_optionType(type), m_description(description) {
		// m_value = new ArgumentValue(type, size);
		
}

Option::~Option() {

}
void Option::init(int type, int size) {
	switch (type) {
			case boolOption: 
					m_value = new OptionValue<bool>();
			 	break;
			case floatOption:
					m_value = new OptionValue<float>();
				break;
			case intOption:
					m_value = new OptionValue<int>();
				break;
			// case stringOption:
					// m_value = new ArgumentValue<std::string>(size);
			default:
				break;
		}
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
