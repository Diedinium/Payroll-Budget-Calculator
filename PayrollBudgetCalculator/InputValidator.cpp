#include "InputValidator.h"

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

std::string InputValidator::ValidateString() {
	std::string strInput;
	std::getline(std::cin, strInput);
	return strInput;
}

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