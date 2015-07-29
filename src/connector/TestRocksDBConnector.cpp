#include "gtest/gtest.h"
#include "gflags/gflags.h"
#include "utils/Flags.hpp"
#include "connector/RocksDBConnector.hpp"

class RocksDBConnectTest : public ::testing::Test
{


protected:

	virtual void SetUp(){
		dbPath = &utils::rocksDBPath();

	}

	const std::string * dbPath;
	connector::RocksDBConnector rocksdbConnector;
};


TEST_F(RocksDBConnectTest, connectionCheck){


	EXPECT_EQ(rocksdbConnector.kDBPath(dbPath->c_str()), true);

	rocksdbConnector.option();
	rocksdb::Status status = rocksdbConnector.connection();
	EXPECT_EQ(status.ok(), true);

	// Put key-value
	rocksdb::DB * db = rocksdbConnector.getDB();
	status = db->Put(WriteOptions(), "key1", "value");
	EXPECT_EQ(status.ok(), true);
	std::string value;
	// get value
	status = db->Get(ReadOptions(), "key1", &value);
	EXPECT_EQ(status.ok(), true);
	EXPECT_EQ(value, "value");

}