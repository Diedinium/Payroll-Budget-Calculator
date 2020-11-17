#pragma once

#include <iostream>
#include <string>

#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H
class InputValidator {
private:
	// Private constructor as a reminder to myself to not create instances ;)
	InputValidator();
public:
	static int ValidateInt();
	static double ValidateDouble();
};
#endif