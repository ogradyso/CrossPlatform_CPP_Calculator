
#include "catch.h"
#include "../include/Calculator.h"
#include "../src/Calculator.cpp"


TEST_CASE("Simple Calculator Operations") {
	SECTION("Simple math operations with integers") {
		Calculator<int> addCalc{};
		Calculator<int> subCalc{};
		Calculator<int> multCalc{};
		Calculator<int> divCalc{};

		int operand1 = 3;
		int operand2 = 2;
		
		addCalc.setOperand(operand1);
		addCalc.setOperand(operand2);
		addCalc.setOperation(Operation::add);

		REQUIRE(addCalc.calculate() == 5);

		subCalc.setOperand(operand2);
		subCalc.setOperand(operand1);
		subCalc.setOperation(Operation::subtract);

		REQUIRE(subCalc.calculate(operand1, operand2) == 1);

		divCalc.setOperand(operand2);
		divCalc.setOperand(operand1);
		divCalc.setOperation(Operation::divide);

		REQUIRE(divCalc.calculate(operand1, operand2) == 1);

		multCalc.setOperand(operand2);
		multCalc.setOperand(operand1);
		multCalc.setOperation(Operation::multiply);

		REQUIRE(multCalc.calculate(operand1, operand2) == 6);
	}
	SECTION("Simple math operations with float") {
		Calculator<float> addCalc{};
		Calculator<float> subCalc{};
		Calculator<float> multCalc{};
		Calculator<float> divCalc{};

		float operand1 = 2.1;
		float operand2 = 3.2;
		float operand3 = 10;
		float operand4 = 3;

		subCalc.setOperation(Operation::subtract);
		multCalc.setOperation(Operation::multiply);
		divCalc.setOperation(Operation::divide);

		REQUIRE(addCalc.calculate(operand1, operand2) == static_cast<float>(5.3));
		REQUIRE((subCalc.calculate(operand1, operand2) - static_cast<float>(-1.1)) < 1e-15);
		REQUIRE((multCalc.calculate(operand1, operand2) - 6.72) < 1e-15);
		REQUIRE(divCalc.calculate(operand3, operand4) - static_cast<float>(3.333333333333333333) < 1e-15);
	}
	SECTION("Simple math operations with doubles") {
		Calculator<double> addCalc{};
		Calculator<double> subCalc{};
		Calculator<double> multCalc{};
		Calculator<double> divCalc{};

		double operand1 = 2.1;
		double operand2 = 3.2;
		double operand3 = 10;
		double operand4 = 3;

		subCalc.setOperation(Operation::subtract);
		multCalc.setOperation(Operation::multiply);
		divCalc.setOperation(Operation::divide);

		REQUIRE(std::abs(addCalc.calculate(operand1, operand2) - 5.3) < 1e-15);
		REQUIRE(subCalc.calculate(operand1, operand2) == -1.1);
		REQUIRE(std::abs(multCalc.calculate(operand1, operand2) - 6.72) < 1e-15);
		REQUIRE(divCalc.calculate(operand3, operand4) == 3.333333333333333333333333333333333333333333333333333333);
	}
	SECTION("Arithmetic errors") {

		Calculator<int> divCalc{};

		divCalc.setOperation(Operation::divide);

		REQUIRE_THROWS(divCalc.calculate(2, 0));

	}
}

TEST_CASE("Calculator memory operations") {
	SECTION("Store value in calculator memory") {
		Calculator<double> addCalc{};
		Calculator<double> subCalc{};
		Calculator<float> multCalc{};
		Calculator<int> divCalc{};

		REQUIRE(addCalc.memStore(5) == 5);
		REQUIRE(std::abs(addCalc.memStore(5.123) - 5.123) < 1e-15);
		REQUIRE(std::abs(addCalc.memStore(3.14159) - 3.14159) < 1e-15);
		REQUIRE(addCalc.memStore(5.1) == 5.1);
	}
	SECTION("Retrieve memory operand") {
		Calculator<int> addCalc{};
		addCalc.memStore(5);

		REQUIRE(addCalc.memRecall() == 5);

	}
	SECTION("Erase memory") {
		Calculator<int> subCalc{};
		subCalc.memStore(5);
		subCalc.memClear();

		REQUIRE(subCalc.memRecall() == NULL);
	}
	SECTION("Add to memory") {
		Calculator<int> subCalc{};
		subCalc.memStore(5);
		subCalc.memAdd(5);

		REQUIRE(subCalc.memRecall() == 10);
	}
}