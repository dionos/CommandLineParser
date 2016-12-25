#include "ArgumentHandlingException.h"

ArgumentException::ArgumentException(const std::string& message):m_errMsg(message){

}

ArgumentException::~ArgumentException() throw() {

}

int ArgumentException::errNumber() const {
	return m_errNum;
}

const char* ArgumentException::what() const throw() {
	return m_errMsg.c_str();
}

ArgumentWrongOption::ArgumentWrongOption(const std::string& message):ArgumentException(message) {
	m_errNum = 1001;
}

ArgumentWrongOption::~ArgumentWrongOption() throw () {

}
int ArgumentWrongOption::errNumber() const{
	return m_errNum;
}

const char* ArgumentWrongOption::what() const throw () {
	return m_errMsg.c_str();
}

