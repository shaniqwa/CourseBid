#pragma once
#include "IStorage.h"
#include "file_storage.h"
enum db_type{ FILE_STORAGE, INVALID };
class StorageFactory {
public:
	IStorage* DataStorage(db_type storage_type, string db_name);
};