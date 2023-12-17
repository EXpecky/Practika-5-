// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "moneyStruct.h"
#include <vector>
#include <iostream>
#include <vld.h>



int main()
{
	setlocale(LC_ALL, "RU");
	ifstream file("txt.txt");
	
	try {
		if (file.is_open())
		{
			std::vector <MoneyStruct> money;
			MoneyStruct zal;

			zal.moneyData(file, money);
			zal.printVector(money, std::cout);
		}
	}

	catch (std::runtime_error& Message) {
		std::cout << Message.what();
	}
}

