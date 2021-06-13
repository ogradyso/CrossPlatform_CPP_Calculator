# CMakeList.txt : CMake project for CrossPlatform_CPP_Calculator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# set the project name and version:
project(CrossPlatform_CPP_Calculator VERSION 1.0)

#specify the C++ standard:
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(CrossPlatform_CPP_Calculator.h.in CrossPlatform_CPP_CalculatorConfig.h)

# Add source to this project's executable.
# toggle to run the test suite with catch.h, you will have to comment out the main method in CrossPlatform_CPP_Calculator.cpp
#add_executable (CrossPlatform_CPP_Calculator "CrossPlatform_CPP_Calculator.cpp" "CrossPlatform_CPP_Calculator.h" "catch.h" "calculator_tests.cpp" "scientificCalculator_tests.cpp")
add_executable (CrossPlatform_CPP_Calculator "CrossPlatform_CPP_Calculator.cpp" "CrossPlatform_CPP_Calculator.h")


# TODO: Add tests and install targets if needed.


target_include_directories(CrossPlatform_CPP_Calculator PUBLIC
							"${PROJECT_BINARY_DIR}"
							)