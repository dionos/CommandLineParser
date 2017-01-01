#ifndef __ARGUMENT_HANDLING_EXCEPTION__
#define __ARGUMENT_HANDLING_EXCEPTION__

#include <string>
#include <exception>
/*----------- Command Line Argument Exceptions -----------*/
class ArgumentException : public std::exception {
public:
	ArgumentException(const std::string& message) { };
	virtual ~ArgumentException() throw () { }; 
	virtual int errId() const = 0;
	virtual const char* what() const throw () = 0;
protected:
	std::string m_errMsg;
	int m_errId;
};

class ArgumentWrongOption : public ArgumentException {
public:
	ArgumentWrongOption (const std::string& message);
	virtual ~ArgumentWrongOption () throw ();
	virtual int errId() const;
	virtual const char* what() const throw ();
};

class ArgumentMissingValue: public ArgumentException {
public:
	ArgumentMissingValue (const std::string& message);
	virtual ~ArgumentMissingValue () throw ();
	virtual int errId() const;
	virtual const char* what() const throw ();
};

class ArgumentExpectedOption: public ArgumentException {
public:
	ArgumentExpectedOption(const std::string& message);
	virtual ~ArgumentExpectedOption() throw ();
	virtual int errId() const;
	virtual const char* what() const throw ();
};

#endif //__ARGUMENT_HANDLING_EXCEPTION__


