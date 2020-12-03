#pragma once

#include <string>
#include <vector>
#include <filesystem>

#ifndef H_FILEMANAGER
#define H_FILEMANAGER
class FileManager {
	std::vector<std::filesystem::path> _vecPathsToVerify;
	std::filesystem::path _pathOutput;
	std::filesystem::path _pathSaves;
public:
	FileManager();
	void EnsureDirectoriesExist();
	std::vector<std::filesystem::directory_entry> GetFilesFromSaveDirectory();

	std::filesystem::path GetOutputPath() { return _pathOutput; }
	std::filesystem::path GetSavesPath() { return _pathSaves; }
};
#endif // !H_FILEMANAGER
