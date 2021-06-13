#include "catch.h"
#include "Calculator.h"
#include "Calculator.cpp"

TEST_CASE("Scientific calculator operations") {
	SECTION("Square a value") {
		ScientificCalculator<int> SciCalc{};
		ScientificCalculator<double> dblSciCalc{};
		ScientificCalculator<float> fltSciCalc{};

		double dblVal = 5;
		float fltVal = 5;

		SciCalc.setOperand(5);
		dblSciCalc.setOperand(dblVal);
		fltSciCalc.setOperand(fltVal);
		
		REQUIRE(SciCalc.squareValue() == 25);
		REQUIRE(dblSciCalc.squareValue() == 25);
		REQUIRE(fltSciCalc.squareValue() == 25);

	}
	SECTION("Constant values, pi, e") {
		ScientificCalculator<int> SciCalc{};

		REQUIRE(SciCalc.getPi() == 3.14159265358);
		REQUIRE(SciCalc.getE() == 2.71828182);
	}
	SECTION("One divided by X") {
		ScientificCalculator<double> dblSciCalc{};
		double dblVal = 5;
		double dblVal2 = 2;

		dblSciCalc.setOperand(dblVal);

		REQUIRE(std::abs(dblSciCalc.oneDivX() - 0.2) < 1e-15);

		dblSciCalc.setOperand(dblVal2);

		REQUIRE(std::abs(dblSciCalc.oneDivX() - 0.5) < 1e-15);
	}

	SECTION("Absolute value") {
		ScientificCalculator<double> dblSciCalc{};
		double dblVal = -5;
		double dblVal2 = 2;

		dblSciCalc.setOperand(dblVal);

		REQUIRE(std::abs(dblSciCalc.absVal() - 5) < 1e-15);

		dblSciCalc.setOperand(dblVal2);

		REQUIRE(std::abs(dblSciCalc.absVal() - 2) < 1e-15);

	}
	SECTION("Powers of 10 value") {
		ScientificCalculator<double> dblSciCalc{};
		double dblVal = -5;
		double dblVal2 = 2;

		dblSciCalc.setOperand(dblVal);

		REQUIRE(std::abs(dblSciCalc.expVal(2) + 500) < 1e-15);

		dblSciCalc.setOperand(dblVal2);

		REQUIRE(std::abs(dblSciCalc.expVal(2) - 200) < 1e-15);
	}
	SECTION("Modulo value") {
		ScientificCalculator<double> dblSciCalc{};
		double dblVal = 5;
		double dblVal2 = 2;

		dblSciCalc.setOperand(dblVal);

		REQUIRE(std::abs(dblSciCalc.modVal(2) - 1) < 1e-15);

		dblSciCalc.setOperand(dblVal2);

		REQUIRE(std::abs(dblSciCalc.modVal(3) - 2) < 1e-15);
	}
	SECTION("Square root value") {
		ScientificCalculator<double> dblSciCalc{};
		double dblVal = 4;
		double dblVal2 = -2;

		dblSciCalc.setOperand(dblVal);

		REQUIRE(std::abs(dblSciCalc.sqrtVal() - 2) < 1e-15);

		dblSciCalc.setOperand(dblVal2);

		REQUIRE_THROWS(dblSciCalc.sqrtVal());
	}
	SECTION("Factorial value") {
		ScientificCalculator<double> dblSciCalc{};
		double dblVal = 4;
		double dblVal2 = -2;
		double dblVal3 = 1.123;

		dblSciCalc.setOperand(dblVal);

		REQUIRE(std::abs(dblSciCalc.factorialVal() - 24) < 1e-15);

		dblSciCalc.setOperand(dblVal2);

		REQUIRE_THROWS(dblSciCalc.factorialVal());

		dblSciCalc.setOperand(dblVal3);

		REQUIRE_THROWS(dblSciCalc.factorialVal());
	}
	SECTION("Power value") {
		ScientificCalculator<double> dblSciCalc{};
		double dblVal = 4;
		double dblVal2 = 2;
		double dblVal3 = -2;
		
		dblSciCalc.setOperand(dblVal);
		dblSciCalc.setOperand(dblVal2);
		dblSciCalc.setOperation(Operation::power);

		REQUIRE(std::abs(dblSciCalc.calculate() - 16) < 1e-15);

		dblSciCalc.setOperand(dblVal3);
		REQUIRE_THROWS(dblSciCalc.calculate());

	}
	SECTION("Power of 10 value") {
		ScientificCalculator<double> dblSciCalc{};
		double dblVal = 4;
		double dblVal2 = 2;

		dblSciCalc.setOperand(dblVal);
		
		REQUIRE(std::abs(dblSciCalc.powerOfTenVal() - 10'000) < 1e-15);

		dblSciCalc.setOperand(dblVal2);

		REQUIRE(std::abs(dblSciCalc.powerOfTenVal() - 100) < 1e-15);

	}
	SECTION("Log value") {
		ScientificCalculator<double> dblSciCalc{};
		double dblVal = 4;
		double dblVal2 = 2;

		dblSciCalc.setOperand(dblVal);

		REQUIRE(std::abs(dblSciCalc.logVal() - 0.60205999132796239042747778944899) < 1e-15);

		dblSciCalc.setOperand(dblVal2);

		REQUIRE(std::abs(dblSciCalc.logVal() - 0.30102999566398119521373889472449) < 1e-15);

		REQUIRE(std::abs(dblSciCalc.logNVal() - 0.69314718055994530941723212145818) < 1e-15);

	}
	
}
