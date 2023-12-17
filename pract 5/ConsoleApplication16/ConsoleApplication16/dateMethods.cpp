// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "dateStruct.h"
#include "pch.h"

#include <iomanip>
#include <fstream>
#include <string>

void DateStruct::readDate(std::string& dateStr) {
	if (dateStr[2] == '.' && dateStr[5] == '.') {
		int d = stoi(dateStr.substr(0, 2));
		int m = stoi(dateStr.substr(3, 5));
		int y = stoi(dateStr.substr(6, 10));

		correctDate(d, m, y);

		day = d;
		month = m;
		year = y;
	}
	else throw std::runtime_error("Invalid SEPARATOR! Check the correctness of the data entered.");
}


void DateStruct::createDateFromFile(istream& file)
{
	

	std::string Date;

	file >> Date;

	readDate(Date);
}

void DateStruct::printDate(ostream& out)
{
	out << day << "." << month << "." << year;
}

bool DateStruct::isLeapYear(int Year) {
	if (Year < 0) throw std::runtime_error("YEAR must be positive!");
	return (Year % 4 == 0 && year % 100 != 0) || (Year % 400 == 0);
}

void DateStruct::correctDate(int d, int m, int y) 
{
	int maxDaysInMonth = 31;
	switch (m) {
	case 2:
		maxDaysInMonth = isLeapYear(y) ? 29 : 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		maxDaysInMonth = 30;
		break;
	}

	if (d < 1 or !(d <= maxDaysInMonth)) throw std::runtime_error("Error! The wrong DAY was entered ");
	if (m < 1 or m > 12) throw std::runtime_error("Error! The wrong MONTH was entered ");
	if (y < 1) throw std::runtime_error("Error! The wrong YEAR was entered ");
}

void DateStruct::setDay(int value) {
	correctDate(value, 1, 1);
	day = value;
}

void DateStruct::setMonth(int value) {
	correctDate(1, value, 1);
	month = value;
}

void DateStruct::setYear(int value) {
	correctDate(1, 1, value);
	year = value;
}

int DateStruct::getDay(){
	return day;
}

int DateStruct::getMonth() {
	return month;
}

int DateStruct::getYear(){
	return year;
}
