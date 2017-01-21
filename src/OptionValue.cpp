#include <iostream>
#include "OptionValue.h"

template <class T>
void ProcessiongValue::pushValue(const T& val){
//	dynamic_cast<OptionValue<T>&>(*this).setValue(val);
	std::cout << "setValue" << std::endl;
	dynamic_cast<OptionValue<T>&>(*this).setValue(val);
}

template <class T>
void ProcessiongValue::print_vals(){
	dynamic_cast<OptionValue<T>&>(*this).print_vals();
	std::cout << "ptinr_vals" << std::endl;
}

template <class T>
T ProcessiongValue::popValue() {
	return dynamic_cast<OptionValue<T>&>(*this).popValue();
}

template <class T>
std::list<T> ProcessiongValue::getValues() const {
	return dynamic_cast<const OptionValue<T>&>(*this).getValues();
}

template <class T>
OptionValue<T>::OptionValue() {

}
template <class T>
OptionValue<T>::~OptionValue() {

}
template <class T>
void OptionValue<T>::pushValue(const T& val) {
	m_value.push_back(val);
}
template <class T>
void OptionValue<T>::print_vals() {
		typename std::list<T>::iterator it_val = m_value.begin();
		for(;it_val != m_value.end(); ++it_val) {
			std::cout << *it_val << std::endl;
		}
}

template <class T>
T OptionValue<T>::popValue() {
	T result;
	result = m_value.back();
	m_value.pop_back();
	return result;
}

template <class T>
std::list<T> OptionValue<T>::getValues() const {
	return m_value;
}
