#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

//#define CATCH_CONFIG_MAIN
//#include "..\test\catch.h"

enum class Operation { add, subtract, multiply, divide, power };

template <class T>
class Calculator
{
protected:
	Operation calcOperation;
	T operand1;
	T operand2;
	T memoryOperand;
	T getMemoryOperand();
	void setMemoryOperand(T operand1);
private:
public:
	Calculator();
	~Calculator();
	void setOperand(T operand);
	void setOperation(Operation calcOperation);
	T calculate(T operand1, T operand2);
	virtual T calculate();
	T memStore(T operand1);
	void memClear();
	T memRecall();
	void memAdd(T operand1);
};

template <class T>
class ScientificCalculator : public Calculator<T>
{
private:
	double piVal;
	double eVal;
public:
	ScientificCalculator();
	~ScientificCalculator();
	T squareValue();
	T calculate() override;
	double getPi();
	double getE();
	double oneDivX();
	T absVal();
	double expVal(T operand);
	double modVal(T operand);
	double sqrtVal();
	T factorialVal();
	double powerOfTenVal();
	double logVal();
	double logNVal();
	long long fact(long n);
};


#endif