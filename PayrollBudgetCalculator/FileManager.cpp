#include "FileManager.h"

FileManager::FileManager() {
	_vecPathsToVerify.push_back(std::filesystem::path(L"output"));
	_vecPathsToVerify.push_back(std::filesystem::path(L"saves"));
	_pathOutput = std::filesystem::path(L"output");
	_pathSaves = std::filesystem::path(L"saves");
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