#include "License.h"
#include <sstream>
#include<iostream>
#include<algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

std::string SSTR(int Number)
{
	std::ostringstream ss;
     ss << Number;
     return ss.str();
}

License::License()
{
	s = "";
	n = 0;
}
License::License(std::string old)
{
	s = old;
	n = 0;
}
License::License(int old)
{
	s = "";
	n = old;
}
License::~License()
{
	s = "";
	n = 0;
}
std::string License::randLicence(void)
{
	for (int i = 0; i < abs((lrand() % 100)); i++)
	{
		randNum();
		randAlpha();
	}
	std::srand(unsigned(std::time(0)));
	std::string s = "";
	for (int i = 0; i<4; ++i) s += (48 + (randNum() % 10));
	std::random_shuffle(s.begin(), s.end());
	std::srand(unsigned(std::time(0)));
	std::string t = "";
	for (int i = 0; i < 3; ++i) t += randAlpha();
	std::random_shuffle(t.begin(), t.end());
	s.insert(1, t);
	return s;
}
long License::randNum(void)
{
	long i, l = 0;
	for (i = 0; i < 20000; i++, l += lrand());
	return  abs((lrand()));
}
std::string License::randAlpha(void)
{
	std::string j[26] = { "A", "B", "C", "D", "E", "F", "G", "H",
		"I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S",
		"T", "U", "V", "W", "X", "Y", "Z" };
	long i, l = 0;
	for (i = 0; i < 20000; i++, l += lrand());
	return j[abs((lrand() % 26))];
}
std::string License::randPhoneNum(void)
{
	std::string NPA[9] = {"(415)", "(707)","(916)","(510)","(925)","(650)","(408)","(209)","(831)"};

	std::string NXX = "";
	NXX += SSTR(randNum() % 1000);
	while (NXX.size() < 3)
		NXX += SSTR(randNum() % 10);
	std::srand(unsigned(std::time(0)));
	std::random_shuffle(NXX.begin(), NXX.end());
	while ((NXX[0] - '0') < 2 ) ++NXX[0];
	if (NXX[1] == '1' && NXX[2] == '1') ++NXX[2];

	std::string xxxx = "";
	xxxx += SSTR(randNum() % 10000);
	while (xxxx.size() < 4)
		xxxx += SSTR(randNum() % 10);
	std::srand(unsigned(std::time(0)));
	std::random_shuffle(xxxx.begin(), xxxx.end());

	return (NPA[randNum() % 9] + " " + NXX + "-" + xxxx);
}

