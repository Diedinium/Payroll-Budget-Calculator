#include "InputValidator.h"

/// <summary>
/// Static function. Default ValidateInt, does not allow user to proceed until they enter a value that converts to an int.
/// </summary>
/// <returns>int</returns>
int InputValidator::ValidateInt() {
	std::string strInput;
	int iInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			iInput = std::stoi(strInput);
			return iInput;
		}
		catch (std::exception) {
			std::cout << "Not a valid whole number: ";
		}
	}
}

/// <summary>
/// Static function. Does not allow user to proceed until value that is valid int is entered, and one that is below or equal to the max size.
/// </summary>
/// <param name="maxSize"></param>
/// <returns>int</returns>
int InputValidator::ValidateInt(int maxSize) {
	std::string strInput;
	int iInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			iInput = std::stoi(strInput);

			if (util::is_more_than(iInput, maxSize)) {
				std::cout << "To large, max size is " << std::setprecision(2) << maxSize << ": ";
			}
			else {
				return iInput;
			}
		}
		catch (std::exception) {
			std::cout << "Not a valid whole number: ";
		}
	}
}

/// <summary>
/// Static function. Does not allow user to proceed until value that is valid double value (1, 2.52 etc) is entered.
/// </summary>
/// <returns>double</returns>
double InputValidator::ValidateDouble() {
	std::string strInput;
	double dInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			dInput = std::stod(strInput);
			return dInput;
		}
		catch (std::exception) {
			std::cout << "Not a valid number: ";
		}
	}
}

/// <summary>
/// Static function. Does not allow user to proceed until a value that is a valid double value (1, 52.52 etc) is entered, and it is below the max size.
/// </summary>
/// <param name="maxSize"></param>
/// <returns>double</returns>
double InputValidator::ValidateDouble(double maxSize) {
	std::string strInput;
	double dInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			dInput = std::stod(strInput);

			if (util::is_more_than(dInput, maxSize)) {
				std::cout << "To large, max size is " << std::setprecision(2) << maxSize << ": ";
			}
			else {
				return dInput;
			}
		}
		catch (std::exception) {
			std::cout << "Not a valid number: ";
		}
	}
}

/// <summary>
/// Static function. Does not allow user to proceed until they enter value that is between max and min values, and is valid double value.
/// </summary>
/// <param name="minSize"></param>
/// <param name="maxSize"></param>
/// <returns>double</returns>
double InputValidator::ValidateDouble(double minSize, double maxSize) {
	std::string strInput;
	double dInput;

	while (true) {
		std::getline(std::cin, strInput);
		try {
			dInput = std::stod(strInput);

			if (!util::is_between(minSize, maxSize, dInput)) {
				std::cout << "Input not within valid range (" << minSize << " to " << maxSize << ") : ";
			}
			else {
				return dInput;
			}
		}
		catch (std::exception) {
			std::cout << "Not a valid number: ";
		}
	}
}

/// <summary>
/// Static function. Simply a shorthand to get user input, does not really perform any validation on the provided string, since technically any combination of characters is a valid string...
/// </summary>
/// <returns>std::string</returns>
std::string InputValidator::ValidateString() {
	std::string strInput;
	std::getline(std::cin, strInput);
	return strInput;
}

/// <summary>
/// Static function. Does not allow user to proceed until they enter string that is below or equal to the max length.
/// </summary>
/// <param name="maxLength"></param>
/// <returns>std::string</returns>
std::string InputValidator::ValidateString(int maxLength) {
	std::string strInput;

	while (true) {
		std::string strMessage = "Not a valid number";
		std::getline(std::cin, strInput);

		if (util::is_more_than(strInput.length(), (size_t)maxLength)) {
			strMessage = "To long, max length is " + std::to_string(maxLength);
			std::cout << strMessage << ", try again: ";
		}
		else {
			return strInput;
		}
	}
}