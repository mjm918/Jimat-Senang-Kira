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

void JSK(std::string); //function declaration

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
		ss << std::fixed << std::setprecision(2) << totalBill; //formatting input to 2 decimal places
		std::string stringTotalBill = ss.str(); //converting double to string, this approach is to get the second decimal places easily (to decide round up or down)

	JSK(stringTotalBill);
}

//function implementation
void JSK(std::string stringTotalBill)
{
	long double totalBill;
	std::string status;
	int flag = 0; //whether the function got round up or round down the total bill or not, 0 means no, 1 means yes

	/*
	getting the last number of the total bill
	Input : RM 4.56
	stringTotalBill[3] = 6
	*/

	char lastValue = stringTotalBill.at( stringTotalBill.length() - 1 );
	int intLastValue = lastValue - '0'; //converting char to int

	long double tempTotalBill = stold(stringTotalBill);
	

	if(intLastValue == 1 || intLastValue == 2 || intLastValue == 6 || intLastValue == 7) //round down operation
	{
		if(intLastValue < 5) //if the last value is less than 5
		{
			stringTotalBill[stringTotalBill.length() - 1] = '0';
		}

		else
		{
			stringTotalBill[stringTotalBill.length() - 1] = '5';
		}
		totalBill = stold(stringTotalBill);
		status = "down";
		flag = 1;
	}

	else if(intLastValue == 3 || intLastValue == 4 || intLastValue == 8 || intLastValue == 9) //round up operation
	{
		if(intLastValue < 5)
		{
			stringTotalBill[stringTotalBill.length() - 1] = '5';
			totalBill = stold(stringTotalBill);
		}

		else
		{
			stringTotalBill[stringTotalBill.length() - 1] = '0';

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