#include <gtest/gtest.h>
#include <glog/logging.h>
#include <gflags/gflags.h>

#include "ReadELFTest.hpp"

#include <iostream>															   
int main(int argc, char **argv){

	::testing::InitGoogleTest(&argc, argv);
        FLAGS_log_dir = ".";
	google::InitGoogleLogging(argv[0]);
	return RUN_ALL_TESTS();
}
