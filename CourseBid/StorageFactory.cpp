#include "StorageFactory.h"

IStorage* StorageFactory::DataStorage(db_type storage_type, string db_name){
	IStorage* db = NULL;
	switch (storage_type){
		case FILE_STORAGE: 
			db = new FileStorage(db_name);
			break;
		default:
			//db = NULL;
			break;
	}
	return db;
}