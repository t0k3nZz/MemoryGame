#include "drand.h"
#include<string>
#include <sstream>


#ifndef LICENSE_H
#define LICENSE_H

class License
{
private:
	std::string s;
	int n;
public:
	License();
	License(std::string);
	License(int);
	~License();

	std::string randLicence(void);
	long randNum(void);
	std::string randAlpha(void);

	std::string getString(void) { return s; };
	void setString(std::string str){ s = str; };
	int getNum(void) { return n; };
	void setNum(int num) { n = num; };
	std::string randPhoneNum(void);
};

#endif // !LICENSE_H

