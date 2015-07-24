#include <gtest/gtest.h>


class RocksDBConnectTest : public ::testing::test
{


    public:


		protected:
	
			virtual void SetUp(){

			dbPath = rocksDBPath();


			}

			const std::string * dbPath;
	
};


TEST_F(RocksDBConnectTest, connectionCheck){

	utils::RocksDBConnector rocksdbConnector;	

}
