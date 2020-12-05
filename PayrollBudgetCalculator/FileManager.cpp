#include "FileManager.h"

FileManager::FileManager() {
	_vecPathsToVerify.push_back(std::filesystem::path(L"output"));
	_vecPathsToVerify.push_back(std::filesystem::path(L"saves"));
	_pathOutput = std::filesystem::path(L"output");
	_pathSaves = std::filesystem::path(L"saves");
	_ptrBudgetCalculator = NULL;
}

FileManager::FileManager(BudgetCalculator* budgetCalculator) {
	_vecPathsToVerify.push_back(std::filesystem::path(L"output"));
	_vecPathsToVerify.push_back(std::filesystem::path(L"saves"));
	_pathOutput = std::filesystem::path(L"output");
	_pathSaves = std::filesystem::path(L"saves");
	_ptrBudgetCalculator = budgetCalculator;
}

void FileManager::EnsureDirectoriesExist() {
	std::for_each(_vecPathsToVerify.begin(), _vecPathsToVerify.end(), [](std::filesystem::path const& path) {
		if (!std::filesystem::exists(path)) {
			std::filesystem::create_directory(path);
		}
	});
}

std::vector<std::filesystem::directory_entry> FileManager::GetFilesFromSaveDirectory() {
	std::vector<std::filesystem::directory_entry> vecEntries;
	for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(_pathSaves))
	{
		if (!entry.is_directory()) vecEntries.push_back(entry);
	}
	return vecEntries;
}

bool FileManager::CheckIfFileExistsInSaves(std::string fileName) {
	std::filesystem::path pathToTest = _pathSaves / fileName;
	return std::filesystem::exists(pathToTest);
}

int FileManager::ClearSavesDirectory() {
	int iNumRemoved = (int)std::filesystem::remove_all(_pathSaves);
	this->EnsureDirectoriesExist();
	return iNumRemoved;
}