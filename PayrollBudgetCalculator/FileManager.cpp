#include "FileManager.h"

/// <summary>
/// FileManager default constructor, sets default values.
/// </summary>
FileManager::FileManager() {
	_vecPathsToVerify.push_back(std::filesystem::path(L"output"));
	_vecPathsToVerify.push_back(std::filesystem::path(L"saves"));
	_pathOutput = std::filesystem::path(L"output");
	_pathSaves = std::filesystem::path(L"saves");
	_ptrBudgetCalculator = NULL;
}

/// <summary>
/// FileManager parameter constructor, sets default values and stores reference to budget calculator.
/// </summary>
FileManager::FileManager(BudgetCalculator* budgetCalculator) {
	_vecPathsToVerify.push_back(std::filesystem::path(L"output"));
	_vecPathsToVerify.push_back(std::filesystem::path(L"saves"));
	_pathOutput = std::filesystem::path(L"output");
	_pathSaves = std::filesystem::path(L"saves");
	_ptrBudgetCalculator = budgetCalculator;
}

/// <summary>
/// Ensures that necessary output directories (save, output) exist within the directory that the program is executing from.
/// </summary>
void FileManager::EnsureDirectoriesExist() {
	std::for_each(_vecPathsToVerify.begin(), _vecPathsToVerify.end(), [](std::filesystem::path const& path) {
		if (!std::filesystem::exists(path)) {
			std::filesystem::create_directory(path);
		}
	});
}

/// <summary>
/// Gets list of all files in the saved files directory.
/// </summary>
/// <returns>std::vector<std::filesystem::directory_entry></returns>
std::vector<std::filesystem::directory_entry> FileManager::GetFilesFromSaveDirectory() {
	std::vector<std::filesystem::directory_entry> vecEntries;
	for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(_pathSaves))
	{
		if (!entry.is_directory()) vecEntries.push_back(entry);
	}
	return vecEntries;
}

/// <summary>
/// True/false on if a file of provided name exists in the saves directory.
/// </summary>
/// <param name="fileName"></param>
/// <returns>bool</returns>
bool FileManager::CheckIfFileExistsInSaves(std::string fileName) {
	std::filesystem::path pathToTest = _pathSaves / fileName;
	return std::filesystem::exists(pathToTest);
}

/// <summary>
/// True/false on if a file of provided name exists in the output directory.
/// </summary>
/// <param name="fileName"></param>
/// <returns>bool</returns>
bool FileManager::CheckIfFileExistsInOutput(std::string fileName) {
	std::filesystem::path pathToTest = _pathOutput / fileName;
	return std::filesystem::exists(pathToTest);
}

/// <summary>
/// Removes entire saves directory and returns count of removed files, ensures that directory are recreated as well.
/// </summary>
/// <returns>int</returns>
int FileManager::ClearSavesDirectory() {
	int iNumRemoved = (int)std::filesystem::remove_all(_pathSaves);
	this->EnsureDirectoriesExist();
	return iNumRemoved;
}