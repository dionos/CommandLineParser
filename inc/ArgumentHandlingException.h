#ifndef __ARGUMENT_HANDLING_EXCEPTION__
#define __ARGUMENT_HANDLING_EXCEPTION__

#include <string>
#include <exception>

class ArgumentException : public std::exception {
public:
	ArgumentException(const std::string& message);
	virtual ~ArgumentException() throw (); 
	virtual int errNumber() const;
	virtual const char* what() const throw ();
protected:
	std::string m_errMsg;
	int m_errNum;
};

class ArgumentWrongOption : public ArgumentException {
public:
	ArgumentWrongOption (const std::string& message);
	virtual ~ArgumentWrongOption () throw ();
	virtual int errNumber() const;
	virtual const char* what() const throw ();
};

#endif //__ARGUMENT_HANDLING_EXCEPTION__


