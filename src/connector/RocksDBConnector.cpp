#include <iostream>
#include <glog/logging.h>
#include "connector\RocksDBConnector.hpp"

namespace connector{

	

	bool RocksDBConnector::kDBPath(const char *path){ 
		path_ = path;
		if (path_ == NULL){
			return false;
		}
		return true;
	}
	/*
	rocksdb::Options & RocksDBConnector::option(){
<<<<<<< HEAD
		rocksdb::Options options;
		options.create_if_missing = true;
		return options;
	}*/

	/*
	rocksdb::Status  RocksDBConnector::connection(){
		return  rocksdb::DB::Open(options, path_, &db);
	}*/

	/*
	rocksdb::DB * RocksDBConnector::getDB(){
		return db;
	}*/
=======
		
		return options;
	}*/

	
	rocksdb::Status  RocksDBConnector::connection(){
		rocksdb::Options options;
		options.create_if_missing = true;
		return  rocksdb::DB::Open(options, path_, &db);
	}

	
	rocksdb::DB * RocksDBConnector::getDB(){
		return db;
	}
>>>>>>> dev_win32
	
}