/*
* Copyright 2014 Chatsiri Rattana.
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
 * -Support all test case.
 */

#include "glog/logging.h"

#include "utils/flags.hpp"

<<<<<<< HEAD
#include "connector/RocksDBConnector.hpp"
=======
>>>>>>> dev_win32

class SystemTestingEnvironment : public testing::Environment
{


public:

	explicit SystemTestingEnvironment(int argc, char **argv) {

		//intial log path write file for test case.
		gflags::ParseCommandLineFlags(&argc, &argv, true);

		LOG(INFO)<<"Initial log file : "<< utils::loggingPath();  

		LOG(INFO)<< "Initial db path : "<< utils::rocksDBPath(); 

	}//explicit SystemTestingEnvironment


};
