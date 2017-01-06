#ifndef __OPTION_VALUE_H__
#define __OPTION_VALUE_H__

#include <list>

class ProcessiongValue {
public:
	ProcessiongValue() {};
	virtual ~ProcessiongValue() {};

public:
//	template <class T> void setValue(const T& val);
	template <class T> void print_vals();
	template <class T> void setValue(const T& val);

};

template <class T>
class OptionValue : public ProcessiongValue{
public:
	OptionValue();
	virtual ~OptionValue();

public:
	void setValue(const T& val);

	void print_vals();


private:
	std::list<T> m_value;
};

#endif //__OPTION_VALUE_H__