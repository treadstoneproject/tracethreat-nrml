#include <gtest/gtest.h>
#include <glog/logging.h>
#include "Flags.hpp"



class FlagTests :  public testing::Test{

public:

void SetUp() override{


}

protected:


};

TEST_F(FlagTests, call_flags_database){

  LOG(INFO)<<"RockDB path msg : "<< utils::rocksDBPath();

}
