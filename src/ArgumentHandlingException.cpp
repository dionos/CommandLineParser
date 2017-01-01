#include "ArgumentHandlingException.h"

ArgumentWrongOption::ArgumentWrongOption(const std::string& message):ArgumentException(message) {
	m_errId = 1001;
}

ArgumentWrongOption::~ArgumentWrongOption() throw () {

}

int ArgumentWrongOption::errId() const {
	return m_errId;
}

const char* ArgumentWrongOption::what() const throw () {
	return m_errMsg.c_str();
}

ArgumentMissingValue::ArgumentMissingValue(const std::string& message):ArgumentException(message) {
	m_errId = 1002;
}

ArgumentMissingValue::~ArgumentMissingValue() throw () {

}

int ArgumentMissingValue::errId() const {
	return m_errId;
}

const char* ArgumentMissingValue::what() const throw () {
	return m_errMsg.c_str();
}

ArgumentExpectedOption::ArgumentExpectedOption(const std::string& message):ArgumentException(message) {
	m_errId = 1003;
}

ArgumentExpectedOption::~ArgumentExpectedOption() throw () {

}

int ArgumentExpectedOption::errId() const {
	return m_errId;
}

const char* ArgumentExpectedOption::what() const throw() {
	return m_errMsg.c_str();
}
