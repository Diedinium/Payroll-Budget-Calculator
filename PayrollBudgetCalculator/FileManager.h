#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include "BudgetCalculator.h"

#ifndef H_FILEMANAGER
#define H_FILEMANAGER
/// <summary>
/// Class that stores references to file paths and contains utility function to write/read or otherwise interact with files related to this program.
/// </summary>
class FileManager {
	BudgetCalculator* _ptrBudgetCalculator;
	std::vector<std::filesystem::path> _vecPathsToVerify;
	std::filesystem::path _pathOutput;
	std::filesystem::path _pathSaves;
public:
	/// <summary>
	/// FileManager default constructor, sets default values.
	/// </summary>
	FileManager();

	/// <summary>
	/// FileManager parameter constructor, sets default values and stores reference to budget calculator.
	/// </summary>
	FileManager(BudgetCalculator* budgetCalculator);

	/// <summary>
	/// Ensures that necessary output directories (save, output) exist within the directory that the program is executing from.
	/// </summary>
	void EnsureDirectoriesExist();

	std::filesystem::path GetOutputPath() { return _pathOutput; }
	std::filesystem::path GetSavesPath() { return _pathSaves; }

	BudgetCalculator* GetBudgetCalculatorPtr() { return _ptrBudgetCalculator; }

	/// <summary>
	/// Gets list of all files in the saved files directory.
	/// </summary>
	/// <returns>std::vector<std::filesystem::directory_entry></returns>
	std::vector<std::filesystem::directory_entry> GetFilesFromSaveDirectory();

	/// <summary>
	/// True/false on if a file of provided name exists in the saves directory.
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns>bool</returns>
	bool CheckIfFileExistsInSaves(std::string fileName);

	/// <summary>
	/// True/false on if a file of provided name exists in the output directory.
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns>bool</returns>
	bool CheckIfFileExistsInOutput(std::string fileName);

	/// <summary>
	/// Removes entire saves directory and returns count of removed files, ensures that directory are recreated as well.
	/// </summary>
	/// <returns>int</returns>
	int ClearSavesDirectory();
};
#endif // !H_FILEMANAGER
