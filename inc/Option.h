#ifndef __OPTION_H__
#define __OPTION_H__

#include <string>

typedef enum {
	boolOption = 1,
	floatOption = 2,
	intOption = 3,
	stringOption = 4,
	coma_floatOption = 5,
	coma_intOption = 6,
	coma_stringOption = 7
}OptionType;

class Option {
public:
	Option(const std::string &shortOption, const std::string &longOption, OptionType type, const std::string &description);
	virtual ~Option();
public:
	void changeDescription(const std::string &newDescription); //Use for chenging --help and --version

public:
	std::string getShortOption() const;
	std::string getLongOption() const;
	OptionType getOptionType() const;
	std::string getOptionDescription() const;
private:
	std::string m_shortOption;
	std::string m_longOption;
	OptionType m_optionType;
	std::string m_description;
};

namespace std{
template <>
struct less<Option*> {
	bool operator() (const Option *opt1, const Option *opt2){
		if ((opt1->getShortOption() < opt2->getShortOption()) && (opt1->getLongOption() < opt2->getLongOption()))
			return true;
		return false;
	}
};
}

#endif //__OPTION_H__
