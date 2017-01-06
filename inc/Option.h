#ifndef __OPTION_H__
#define __OPTION_H__

#include <list>
#include <string>

#include "OptionValue.h"

typedef enum {
	boolOption = 1,
	floatOption = 2,
	intOption = 3,
	stringOption = 4,
	coma_floatOption = 5,
	coma_intOption = 6,
	coma_stringOption = 7
}OptionType;

class Options;

class Option {
friend class Options;
friend struct std::less<Option*>;

public:

	Option(const std::string &shortOption, const std::string &longOption, OptionType type, const std::string &description, int size);
	virtual ~Option();

public:
	void changeDescription(const std::string &newDescription); //Use for chenging --help and --version

protected:
	std::string getShortOption() const;
	std::string getLongOption() const;
	OptionType getOptionType() const;
	std::string getOptionDescription() const;

private:
	void init(int type, int size);
private:
	std::string m_shortOption;
	std::string m_longOption;
	OptionType m_optionType;
	std::string m_description;
	ProcessiongValue *m_value;
};

namespace std{
template <>
struct less<Option*> {
	bool operator() (const Option *opt1, const Option *opt2){
		if ((opt1->m_shortOption < opt2->m_shortOption) && (opt1->m_longOption < opt2->m_longOption))
			return true;
		return false;
	}
};
}

#endif //__OPTION_H__
