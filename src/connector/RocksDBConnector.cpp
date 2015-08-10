#include <iostream>
#include <glog/logging.h>

#include "connector/RocksDBConnector.hpp"

namespace connector{
	 

	bool RocksDBConnector::kDBPath(const char *path){ 
		this->path_ = path;
		if (this->path_ == NULL){
			return false;
		}
		return true;
	} 
	
 
	rocksdb::Status  RocksDBConnector::connection(){
		rocksdb::Options  options = rocksdb::Options(); 
		options.create_if_missing = true; 
		return rocksdb::DB::Open(options, path_, &db); 
	} 
	 
	rocksdb::DB * RocksDBConnector::getDB(){
		return db;
	}
}