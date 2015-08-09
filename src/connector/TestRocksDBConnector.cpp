/*
* Copyright 2015 Chatsiri Rattana.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/*  Titles			                                          Authors	         Date
* - Test RocksDB in windows application                       R.Chatsiri         
*/


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
	
	status = db->Put(rocksdb::WriteOptions(), "user-authen", "chatsiri@treadstone.systems");
	EXPECT_EQ(status.ok(), true);

	status = db->Put(rocksdb::WriteOptions(), "pwd-authen", "12341234");
	EXPECT_EQ(status.ok(), true);
	

	std::string value;
	// get value
	status = db->Get(rocksdb::ReadOptions(), "user-authen", &value);
	EXPECT_EQ(status.ok(), true);
	EXPECT_EQ(value, "chatsiri@treadstone.systems"); 
	 
	delete db;
}


TEST_F(RocksDBConnectTest, testMultipleRecords){
	rocksdb::Status status;
	 
	rocksdb::Options options;
	options.create_if_missing = true;

	rocksdb::DB * db;

	status = rocksdb::DB::Open(options, *dbPath, &db);
	EXPECT_EQ(status.ok(), true);

	 

	status = db->Put(rocksdb::WriteOptions(), "user-authen-system-1", "chatsiri@treadstone.systems-1");
	EXPECT_EQ(status.ok(), true);

	status = db->Put(rocksdb::WriteOptions(), "user-authen", "chatsiri@treadstone.systems-2");
	EXPECT_EQ(status.ok(), true);

	status = db->Put(rocksdb::WriteOptions(), "user-authen", "chatsiri@treadstone.systems-3");
	EXPECT_EQ(status.ok(), true);


	status = db->Put(rocksdb::WriteOptions(), "ttmat-message-mailbox-08/08/2015-19:01:02",
		"{ ttmat-message-mailbox : [{ subject : Test mailbox , detail: Exception::message cannot access database , status: open, date : 08/08/2015 ] }");
	EXPECT_EQ(status.ok(), true);


	status = db->Put(rocksdb::WriteOptions(), "pwd-authen", "12341234");
	EXPECT_EQ(status.ok(), true);


	std::string value;
	// get value
	status = db->Get(rocksdb::ReadOptions(), "user-authen", &value);

	EXPECT_EQ(status.ok(), true);
	EXPECT_EQ(value, "chatsiri@treadstone.systems-3");

	std::string mbMessage;
	status = db->Get(rocksdb::ReadOptions(), "ttmat-message-mailbox-08/08/2015-19:01:02", &mbMessage);
	LOG(INFO) << "Result from db : " << mbMessage;
	EXPECT_EQ(mbMessage, "{ ttmat-message-mailbox : [{ subject : Test mailbox , detail: Exception::message cannot access database , status: open, date : 08/08/2015 ] }");

	delete db;
}