#pragma once
#include <iomanip>
#include <fstream>
using namespace std;
class DateStruct 
{
	int day = 0;
	int month = 0;
	int year = 0;

public:
	void createDateFromFile(istream& file);
	void printDate(ostream& out);
	void correctDate(int d, int m, int y);
	bool isLeapYear(int year);
	void readDate(std::string &date);

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	int getDay();
	int getMonth();
	int getYear();

};
