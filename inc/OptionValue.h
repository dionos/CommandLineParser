#ifndef __OPTION_VALUE_H__
#define __OPTION_VALUE_H__

#include <list>

class ProcessiongValue {
public:
	ProcessiongValue() {};
	virtual ~ProcessiongValue() {};

public:
	template <class T> void print_vals();
	template <class T> void pushValue(const T& val);
	template <class T> T popValue();
	template <class T> std::list<T> getValues() const;

};

template <class T>
class OptionValue : public ProcessiongValue{
public:
	OptionValue();
	virtual ~OptionValue();

public:
	void print_vals();
	void pushValue(const T& val);
	T popValue();
	std::list<T> getValues() const;

private:
	std::list<T> m_value;
};

#endif //__OPTION_VALUE_H__
