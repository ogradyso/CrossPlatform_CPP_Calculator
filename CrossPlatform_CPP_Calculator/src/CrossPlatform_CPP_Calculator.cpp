// CrossPlatform_CPP_Calculator.cpp : Defines the entry point for the application.
//



#include "../include/Calculator.h"
#include "../lib/Calculator.cpp"
#include <iostream>
#include "./CrossPlatform_CPP_CalculatorConfig.h"

//#define CATCH_CONFIG_MAIN
//#include "..\test\catch.h"

using namespace std;

int main()
{
	Calculator<int> addCalc{};

	int operand1 = 3;
	int operand2 = 2;

	addCalc.setOperand(operand1);
	addCalc.setOperand(operand2);
	addCalc.setOperation(Operation::add);

	//print the version number:
	std::cout << " Version " << CrossPlatform_CPP_Calculator_VERSION_MAJOR << "."
	<< CrossPlatform_CPP_Calculator_VERSION_MINOR << std::endl;

	cout << "The calculator result is: " << addCalc.calculate();
	return 0;
}

