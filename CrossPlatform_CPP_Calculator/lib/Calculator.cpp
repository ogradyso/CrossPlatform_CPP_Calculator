#include "Calculator.h"
#include <cmath>

template <typename T>
Calculator<T>::Calculator() {
	this->calcOperation = Operation::add;
	this->operand1 = NULL;
	this->operand2 = NULL;
	this->memoryOperand = NULL;
}

template <typename T>
Calculator<T>::~Calculator() {

}

template <typename T>
void Calculator<T>::setOperand(T operand) {
	if (this->operand1 == NULL) {
		this->operand1 = operand;
	}
	else {
		this->operand2 = operand;
	}
}

template <typename T>
T Calculator<T>::calculate(T operand1, T operand2) {
	switch (this->calcOperation) {
		case Operation::add:
			return operand1 + operand2;
			break;
		case Operation::subtract:
			return operand1 - operand2;
			break;
		case Operation::multiply:
			return operand1 * operand2;
			break;
		case Operation::divide:
			if (operand2 == 0) {
				throw("Cannot divide by zero");
			}
			return operand1 / operand2;
			break;
	}
}

template <typename T>
T Calculator<T>::calculate() {
	switch (this->calcOperation) {
	case Operation::add:
		return this->operand1 + this->operand2;
		break;
	case Operation::subtract:
		return this->operand1 - this->operand2;
		break;
	case Operation::multiply:
		return this->operand1 * this->operand2;
		break;
	case Operation::divide:
		if (this->operand2 == 0) {
			throw("Cannot divide by zero");
		}
		return this->operand1 / this->operand2;
		break;
	}
}

template <typename T>
void Calculator<T>::setOperation(Operation calcOperation) {
	this->calcOperation = calcOperation;
}

template <typename T>
void Calculator<T>::setMemoryOperand(T operand1) {
	this->memoryOperand = operand1;
}

template <typename T>
T Calculator<T>::getMemoryOperand() {
	return this->memoryOperand;
}

template <typename T>
T Calculator<T>::memStore(T operand1) {
	this->setMemoryOperand(operand1);
	return this->getMemoryOperand();
}

template <typename T>
void Calculator<T>::memClear() {
	this->setMemoryOperand(NULL);
}

template <typename T>
T Calculator<T>::memRecall() {
	return this->getMemoryOperand();
}

template <typename T>
void Calculator<T>::memAdd(T operand1) {
	T storedVal = getMemoryOperand();
	return this->setMemoryOperand(storedVal + operand1);
}

//
// Scientific Calculator functions:
//

template <typename T>
ScientificCalculator<T>::ScientificCalculator() : Calculator<T>::Calculator() {
	this->calcOperation = Operation::add;
	this->operand1 = NULL;
	this->operand2 = NULL;
	this->memoryOperand = NULL;
	const double piVal = 3.14159265358;
	const double eVal = exp(0);
}

template <typename T>
T ScientificCalculator<T>::calculate() {
	switch (this->calcOperation) {
	case Operation::add:
		return this->operand1 + this->operand2;
		break;
	case Operation::subtract:
		return this->operand1 - this->operand2;
		break;
	case Operation::multiply:
		return this->operand1 * this->operand2;
		break;
	case Operation::divide:
		if (this->operand2 == 0) {
			throw("Cannot divide by zero");
		}
		return this->operand1 / this->operand2;
		break;
	case Operation::power:
		if (this->operand2 < 0) {
			throw("Cannot calculate a negative exponent.");
		}
		return std::pow(this->operand1, this->operand2);
		break;
	}
}


template <typename T>
ScientificCalculator<T>::~ScientificCalculator() {

}

template <typename T>
T ScientificCalculator<T>::squareValue() {
	return this->operand1 * this->operand1;
}

template <typename T>
double ScientificCalculator<T>::getPi() {
	return 3.14159265358;
}

template <typename T>
double ScientificCalculator<T>::getE() {
	return 2.71828182;
}

template <typename T>
double ScientificCalculator<T>::oneDivX() {
	if (this->operand1 == NULL) {
		throw("Cannot divide by zero");
	}
	else if (this->operand2 == NULL) {
		return 1 / this->operand1;
	}
	else {
		return 1 / this->operand2;
	}
}

template <typename T>
T ScientificCalculator<T>::absVal() {
	if (this->operand1 == NULL) {
		return 0;
	}
	else if (this->operand2 == NULL) {
		return std::abs(this->operand1);
	}
	else {
		return std::abs(this->operand2);
	}
}

template <typename T>
double ScientificCalculator<T>::expVal(T operand) {
	if (this->operand1 == NULL) {
		return 0;
	}
	else if (this->operand2 == NULL) {
		return this->operand1 * std::pow(10,operand);
	}
	else {
		return this->operand2 * std::pow(10, operand);
	}
}

template <typename T>
double ScientificCalculator<T>::modVal(T operand) {
	if (this->operand1 == NULL) {
		return 0;
	}
	else if (this->operand2 == NULL) {
		return std::fmod(this->operand1, operand);
	}
	else {
		return std::fmod(this->operand2, operand);
	}
}

template <typename T>
double ScientificCalculator<T>::sqrtVal() {
	double operandVal;
	if (this->operand1 == NULL) {
		operandVal = 0;
	}
	else if (this->operand2 == NULL) {
		operandVal = this->operand1;
	}
	else {
		operandVal = this->operand2;
	}
	if (operandVal < 0) {
		throw("Cannot take the square root of a negative number");
	}
	else {
		return std::sqrt(operandVal);
	}

}

template <typename T>
T ScientificCalculator<T>::factorialVal() {
	double operandVal;
	int intOperand;
	if (this->operand1 == NULL) {
		operandVal = 0;
	}
	else if (this->operand2 == NULL) {
		operandVal = this->operand1;
		intOperand = operandVal;
		if (operandVal - intOperand > 0) {
			throw("Cannot calculate the factorial of a floating point number");
		}
		operandVal = this->fact(this->operand1);
	}
	else {
		operandVal = this->operand2;
		intOperand = operandVal;
		if (operandVal - intOperand > 0) {
			throw("Cannot calculate the factorial of a floating point number");
		}
		operandVal = this->fact(this->operand2);
	}
	if (operandVal < 0) {
		throw("Cannot calculate the factorial of a negative number");
	}
	else {
		return operandVal;
	}
}

template <typename T>
long long ScientificCalculator<T>::fact(long n) {
	if (n < 0) {
		return n;
	}
	else if ((n == 0) || (n == 1)) {
		return 1;
	}
	else {
		return n * fact(n - 1);
	}
}

template <typename T>
double ScientificCalculator<T>::powerOfTenVal() {
	if (this->operand1 == NULL) {
		return 1;
	}
	else if (this->operand2 == NULL) {
		return std::pow(10, this->operand1);
	}
	else {
		return std::pow(10, this->operand2);
	}
}

template <typename T>
double ScientificCalculator<T>::logVal() {
	if (this->operand1 == NULL || this->operand1 <= 0) {
		throw("Cannot take the log of 0 or less");
	}
	else if (this->operand2 == NULL) {
		return log10(this->operand1);
	}
	else {
		return log10(this->operand2);
	}
}

template <typename T>
double ScientificCalculator<T>::logNVal() {
	if (this->operand1 == NULL || this->operand1 <= 0) {
		throw("Cannot take the log of 0 or less");
	}
	else if (this->operand2 == NULL) {
		return log(this->operand1);
	}
	else {
		return log(this->operand2);
	}
}