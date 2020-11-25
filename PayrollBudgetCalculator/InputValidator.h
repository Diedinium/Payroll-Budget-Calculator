#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H
class InputValidator {
private:
	// Private constructor as a reminder to myself to not create instances ;)
	InputValidator();
public:
	static int ValidateInt();
	static int ValidateInt(int maxSize);
	static double ValidateDouble();
	static double ValidateDouble(double maxSize);
	static std::string ValidateString();
	static std::string ValidateString(int maxLength);
};
#endif