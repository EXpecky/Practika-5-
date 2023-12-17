// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "pch.h"
#include "CppUnitTest.h"
#include "..\ConsoleApplication16\moneyStruct.h"
#include "..\ConsoleApplication16\dateStruct.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(validCreateMoneyFromFile)
		{
			MoneyStruct M;

			std::stringstream f("txt.txt");

			try {
				M.createMoneyFromFile(f);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(validCreateDateFromFile) {
			DateStruct D;

			std::stringstream f("txt.txt");

			try {
				D.createDateFromFile(f);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(validPrintDate) {
			DateStruct D;

			D.setDay(12);
			D.setMonth(9);
			D.setYear(2021);

			std::stringstream x;

			D.printDate(x);
			
			std::string d = "12.9.2021";

			Assert::AreEqual(x.str(), d);
		}

		TEST_METHOD(validCorrectDate) {
			DateStruct D;
			
			D.correctDate(13, 12, 11);
		}

		TEST_METHOD(validIsLeapYear) {
			DateStruct date;

			date.isLeapYear(2024);
		}

		TEST_METHOD(validDateReadTest) {
			DateStruct date;

			std::string d = "12.03.22";

			date.readDate(d);
		}

		TEST_METHOD(validCorrectKurs) {
			MoneyStruct M;

			M.correctKurs(12.3);
		}

		TEST_METHOD(validCorrectName) {
			MoneyStruct M;

			M.correctName("UAH");
		}

		TEST_METHOD(validPrintMoney) {
			MoneyStruct M;

			M.setName1("RUB");
			M.setName2("EUR");
			M.setKurs(24.1);

			std::string r = " RUB EUR 24.1 \n";

			std::stringstream x;

			M.printMoney(x);
			Assert::AreEqual(x.str(), r);
		}

		TEST_METHOD(validPrintVector) {

			MoneyStruct M;
			DateStruct D;
			vector<MoneyStruct> mvec;
			std::ostringstream ost{""};

			M.setName1("RUB");
			M.setName2("EUR");
			M.setKurs(33.3);
			

			D.setDay(12);
			D.setMonth(7);
			D.setYear(2014);
			M.set_date(D);

			mvec.push_back(M);
			
			M.printVector(mvec, ost);

			std::string str = ost.str();
			Assert::IsTrue(str == "12.7.2014 RUB EUR 33.3 \n");

		}

		TEST_METHOD(validMoneyData)
		{
			std::istringstream ist { 
				"10.09.2020 RUB UAH 12\n"
				"11.05.2021 TRY EUR 13"
			};

			MoneyStruct mStruct;
			std::vector<MoneyStruct> vec;
			mStruct.moneyData(ist, vec);
			MoneyStruct a = vec.at(0);
			DateStruct date = a.get_Date();

			Assert::IsTrue(date.getDay() == 10);
			Assert::IsTrue(date.getMonth() == 9);
			Assert::IsTrue(date.getYear() == 2020);

			Assert::IsTrue(a.get_name1() == "RUB");
			Assert::IsTrue(a.get_name2() == "UAH");
			Assert::IsTrue(a.get_kurs() >= 12.0);

			MoneyStruct a2 = vec.at(1);
			date = a2.get_Date();

			Assert::IsTrue(date.getDay() == 11);
			Assert::IsTrue(date.getMonth() == 5);
			Assert::IsTrue(date.getYear() == 2021);
			

			Assert::IsTrue(a2.get_name1() == "TRY");
			Assert::IsTrue(a2.get_name2() == "EUR");
			Assert::IsTrue(a2.get_kurs() >= 13.0);



		}

		//

		TEST_METHOD(invalidMoneyData)
		{
			auto& func = [&]()
			{
				std::istringstream ist{ "10.09,2020 as UAH -12" };
				std::vector<MoneyStruct> vec;
				MoneyStruct mStr;
				mStr.moneyData(ist, vec);
			};


			Assert::ExpectException<std::runtime_error>(func);

		}

		TEST_METHOD(invalidPrintDate) {
			DateStruct D;

			D.setDay(10);
			D.setMonth(2);
			D.setYear(2023);

			std::string r = "12.12.12";
			std::stringstream x;
			D.printDate(x);
			Assert::AreNotEqual(x.str(), r);
		}

		TEST_METHOD(invalidCorrecctDate) {
			DateStruct D;

			try {
				D.correctDate(1, 100, 2020);
			}
			catch (const std::runtime_error& Message) {
				return;
			}
			Assert::Fail();
		}

		TEST_METHOD(invalidCorrectKurs) {
			MoneyStruct M;

			try {
				M.correctKurs(-1);
			}
			catch (const std::runtime_error& Message){
				return;
			}
			Assert::Fail();
		}

		TEST_METHOD(invalidCorrectName) {
			MoneyStruct M;

			try {
				M.correctName("abc");
			}
			catch (const std::runtime_error& Message) {
				return;
			}
			Assert::Fail();
		}

		TEST_METHOD(invalidPrintMoney) {
			MoneyStruct M;

			M.setName1("RUB");
			M.setName2("EUR");
			M.setKurs(24.1);

			std::string r = " UAH EUR 24.1 \n";

			std::stringstream x;

			M.printMoney(x);
			Assert::AreNotEqual(x.str(), r);
		}
		TEST_METHOD(invalidDateReadTest) {
			DateStruct date;

			std::string d = "12.12.13";

			date.readDate(d);
		}

		TEST_METHOD(invalidIsLeapYear) {
			try {
				DateStruct date;
				date.isLeapYear(-2019);
			}
			catch (const std::runtime_error& message) {
				return;
			}

			Assert::Fail();
		}
	};
}
