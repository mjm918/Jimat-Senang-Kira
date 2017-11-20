/*
Simple function for the rounding mechanism to the nearest multiple of 5 sen.
This function shall have one input parameter and one output result

Total amount of a bill which ends in 1, 2, 6, 7 will be rounded down
3, 4, 8, 9 will be rounded up to the nearest multiple of 5 sen.

5.01 will be rounded down to RM5.00
1.23 will be rounded up to 1.25

g++ main.cpp -std=c++11 -o jimat && ./jimat

*/
#include <iostream>
#include <sstream> //data type conversion
#include <string> //to_string
#include <iomanip> //accuracy
#include <stdlib.h> //system()

void JSK(std::string);

int main()
{
	system("clear"); //flush terminal
	long double totalBill; //user input	

	std::cout << "*********Senang & Jimat Kira*********" << std::endl;
	std::cout << "\n\nPlease enter the amount of the total bill: RM ";
	std::cin >> totalBill;
		while(totalBill <= 0 || std::cin.fail() || !std::cin) //input validation, is still "vulnerable" to input like 1/12, 4.4.4. will be fixed on next commit
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "You have entered an invalid entry for \"Total Bill\". Please enter again!" << std::endl;
			std::cout << "Please enter the amount of the total bill: RM ";
			std::cin >> totalBill;
		}
		std::ostringstream ss;
		ss << std::fixed << std::setprecision(2) << totalBill;
		std::string stringTotalBill = ss.str();

	JSK(stringTotalBill);
}

void JSK(std::string stringTotalBill)
{
	long double tempTotalBill, totalBill;
	std::string status;
	int flag = 0;

		//getting the last number of the total bill
		char lastValue = stringTotalBill[3];
		int intLastValue = lastValue - '0'; //converting char to int

	if(stringTotalBill[3] == '1' || stringTotalBill[3] == '2' || stringTotalBill[3] == '6' || stringTotalBill[3] == '7')
	{

		if(intLastValue < 5)
		{
			tempTotalBill = stold(stringTotalBill);
			stringTotalBill[3] = '0';
			totalBill = stold(stringTotalBill);
		}

		else
		{
			tempTotalBill = stold(stringTotalBill);
			stringTotalBill[3] = '5';
			totalBill = stold(stringTotalBill);
		}
		status = "down";
		flag = 1;
	}

	else if(stringTotalBill[3] == '3' || stringTotalBill[3] == '4' || stringTotalBill[3] == '8' || stringTotalBill[3] == '9')
	{

		if(intLastValue < 5)
		{
			tempTotalBill = stold(stringTotalBill);
			stringTotalBill[3] = '5';
			totalBill = stold(stringTotalBill);
		}

		else
		{
			tempTotalBill = stold(stringTotalBill);
			stringTotalBill[3] = '0';
			totalBill = stold(stringTotalBill);
			totalBill = totalBill + 0.1;
		}
		status = "up";
		flag = 1;
	}

		if(flag == 1)
		{
			std::cout << "\nRM " <<  tempTotalBill << " has been rounded " << status << " to RM " << std::fixed << std::setprecision(2) << totalBill << std::endl;
		}

		else
		{
			std::cout << "\nJSK function was not called because the last value is a 0 or 5!" << std::endl;
		}
}