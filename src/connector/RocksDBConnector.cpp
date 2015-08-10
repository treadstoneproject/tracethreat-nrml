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
	
	/*
	rocksdb::Status  RocksDBConnector::connection(rocksdb::DB *  db){
		rocksdb::Options  options = rocksdb::Options();
		options.IncreaseParallelism();
		options.OptimizeLevelStyleCompaction();
		options.create_if_missing = true;
		LOG(INFO) << " Path : " << path_;
		return rocksdb::DB::Open(options, path_, &db);
		 
	}
	/* */
	 
}