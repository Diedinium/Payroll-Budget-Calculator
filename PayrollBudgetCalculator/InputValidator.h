#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"

#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H
/// <summary>
/// Class containing static input validation methods.
/// </summary>
class InputValidator {
private:
	// Private constructor as a reminder to myself to not create instances ;)
	InputValidator();
public:
	/// <summary>
	/// Static function. Default ValidateInt, does not allow user to proceed until they enter a value that converts to an int.
	/// </summary>
	/// <returns>int</returns>
	static int ValidateInt();

	/// <summary>
	/// Static function. Does not allow user to proceed until value that is valid int is entered, and one that is below or equal to the max size.
	/// </summary>
	/// <param name="maxSize"></param>
	/// <returns>int</returns>
	static int ValidateInt(int maxSize);

	/// <summary>
	/// Static function. Does not allow user to proceed until value that is valid double value (1, 2.52 etc) is entered.
	/// </summary>
	/// <returns>double</returns>
	static double ValidateDouble();

	/// <summary>
	/// Static function. Does not allow user to proceed until a value that is a valid double value (1, 52.52 etc) is entered, and it is below the max size.
	/// </summary>
	/// <param name="maxSize"></param>
	/// <returns>double</returns>
	static double ValidateDouble(double maxSize);

	/// <summary>
	/// Static function. Does not allow user to proceed until they enter value that is between max and min values, and is valid double value.
	/// </summary>
	/// <param name="minSize"></param>
	/// <param name="maxSize"></param>
	/// <returns>double</returns>
	static double ValidateDouble(double minSize, double maxSize);

	/// <summary>
	/// Static function. Simply a shorthand to get user input, does not really perform any validation on the provided string, since technically any combination of characters is a valid string...
	/// </summary>
	/// <returns>std::string</returns>
	static std::string ValidateString();

	/// <summary>
	/// Static function. Does not allow user to proceed until they enter string that is below or equal to the max length.
	/// </summary>
	/// <param name="maxLength"></param>
	/// <returns>std::string</returns>
	static std::string ValidateString(int maxLength);
};
#endif