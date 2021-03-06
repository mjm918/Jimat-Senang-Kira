/*
	Teo Shin Jiat

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
	//these system commands is to clear the terminal/command prompt 
	system("cls"); //if windows platform
	
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
	return 0;
}

//function definition
void JSK(std::string stringTotalBill)
{
	long double totalBill;
	std::string status;
	int flag = 0; //whether the function got round up or round down the total bill or not, 0 means no, 1 means yes

	long double tempTotalBill = stold(stringTotalBill);

	char lastValue = stringTotalBill.at( stringTotalBill.length() - 1 );
	int intLastValue = lastValue - '0'; //converting char to int
	/*
		this approach is to get the last index of the total bill
		Input : RM 4.56
		intLastValue is 6, from here we can do simple comparison to decide round up or down and to which multiple of 5sen
	*/
	
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
		status = "down";
		flag++; //if JSK has taken place, @increment instead to make @81 works
	}

	else if(intLastValue == 3 || intLastValue == 4 || intLastValue == 8 || intLastValue == 9) //round up operation
	{
		if(intLastValue < 5)
		{
			stringTotalBill[stringTotalBill.length() - 1] = '5';
		}

		else
		{
			stringTotalBill[stringTotalBill.length() - 1] = '0';
			flag++; //to indicate the value need to be added by 0.1, so if flag is 2, increase total bill by 0.1 and then display it(when flag is not null)
		}
		status = "up";
		flag++; //if JSK has taken place
	}

		totalBill = stold(stringTotalBill); //@moved to main scope

		if(flag > 1) //to add 0.1 to the total bill (because total bill rounded up to 0)
		{
			totalBill += 0.1;
		}

		if(flag) //if JSK taken place
		{
			std::cout << "\nRM " <<  tempTotalBill << " has been rounded " << status << " to RM " << std::fixed << std::setprecision(2) << totalBill << std::endl;
		}

		else //when (flag == 0), it means JSK hadn't taken place
		{
			std::cout << "\nJSK function had not taken place because the last value is a 0 or 5!" << std::endl;
		}
}
