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
			std::cout << "Not a valid whole number, try again: ";
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
			std::cout << "Not a valid number, try again: ";
		}
	}
}

std::string InputValidator::ValidateString() {
	std::string strInput;
	std::getline(std::cin, strInput);
	return strInput;
}