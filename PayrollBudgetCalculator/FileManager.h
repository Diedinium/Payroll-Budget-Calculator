#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include "BudgetCalculator.h"

#ifndef H_FILEMANAGER
#define H_FILEMANAGER
class FileManager {
	BudgetCalculator* _ptrBudgetCalculator;
	std::vector<std::filesystem::path> _vecPathsToVerify;
	std::filesystem::path _pathOutput;
	std::filesystem::path _pathSaves;
public:
	FileManager();
	FileManager(BudgetCalculator* budgetCalculator);
	void EnsureDirectoriesExist();
	std::vector<std::filesystem::directory_entry> GetFilesFromSaveDirectory();

	std::filesystem::path GetOutputPath() { return _pathOutput; }
	std::filesystem::path GetSavesPath() { return _pathSaves; }

	BudgetCalculator* GetBudgetCalculatorPtr() { return _ptrBudgetCalculator; }
	bool CheckIfFileExistsInSaves(std::string fileName);
	bool CheckIfFileExistsInOutput(std::string fileName);
	int ClearSavesDirectory();
};
#endif // !H_FILEMANAGER
