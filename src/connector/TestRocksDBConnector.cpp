#include <exception>

#include "gtest/gtest.h"
#include "gflags/gflags.h" 
#include <glog/logging.h>

#include <rocksdb/db.h>
#include <rocksdb/slice.h>
#include <rocksdb/options.h>

#include "utils/Flags.hpp" 
#include "connector/RocksDBConnector.hpp"

class RocksDBConnectTest : public ::testing::Test
{


protected:

	virtual void SetUp(){
		dbPath = &utils::rocksDBPath();

	}

	const std::string * dbPath;
	//connector::RocksDBConnector rocksdbConnector;
};


TEST_F(RocksDBConnectTest, connectionCheck){

	
	
	rocksdb::Status status;
	 
	//Set simple options.
	//rocksdbConnector.option();
	
	rocksdb::Options options;
	options.create_if_missing = true;

	rocksdb::DB * db;

	status = rocksdb::DB::Open(options, *dbPath, &db);
	EXPECT_EQ(status.ok(), true);
	

	/*
	try{
		//rocksdbConnector.option();
		//status = rocksdbConnector.connection();
		//EXPECT_EQ(status.ok(), true);
	}
	catch (std::exception ex){
		LOG(INFO)<<ex.what();
	}*/
	

	//Put key-value
	//rocksdb::DB * db = rocksdbConnector.getDB();
	
	status = db->Put(WriteOptions(), "user-authen", "chatsiri@treadstone.systems");
	EXPECT_EQ(status.ok(), true);

	status = db->Put(WriteOptions(), "pwd-authen", "12341234");
	EXPECT_EQ(status.ok(), true);
	

	std::string value;
	// get value
	status = db->Get(ReadOptions(), "user-authen", &value);
	EXPECT_EQ(status.ok(), true);
	EXPECT_EQ(value, "chatsiri@treadstone.systems"); 
	 
	delete db;
}