#pragma once
#include "dateStruct.h"
#include <iomanip>
#include <string>
#include <fstream>
#include<vector>


class MoneyStruct
{
	string name1;
	string name2;
	float kurs = 0.0;
	DateStruct date;

public:
	string get_name1();
	string get_name2();
	float get_kurs();
	DateStruct& get_Date();
	void set_date(DateStruct Date);

	void setName1(const std::string& n1);
	void setName2(const std::string& n2);
	void setKurs(float k);


	void createMoneyFromFile(istream& file);
	
	void printMoney(ostream& out);

	void printVector(std::vector<MoneyStruct>& money, ostream& ost);

	void moneyData(std::istream& file, std::vector<MoneyStruct>& money);

	void correctKurs(float kurs);

	void correctName(const string& name);

};

