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
* - TTMATServiceHandler support message from TTMAT            R.Chatsiri       
*/

#include <rocksdb/db.h>
#include <rocksdb/slice.h>
#include <rocksdb/options.h>


#include <glog/logging.h>

#include "utils/flags.hpp"

#include "services/TTMATServiceHandler.hpp"

namespace service{

	void TTMATServiceHandler::getMailboxTTMAT(ttmat::MailboxTTMAT& mbTTMATReturn, 
		const  ::authentication::User& user, 
		const std::string& date){

		LOG(INFO) << "Get message from TT-MAT...";
		//Get path
		dbPath = utils::rocksDBPath();
		if (dbPath.empty())
			LOG(INFO) << "Path is empty";

		rocksDBConnector.kDBPath(utils::rocksDBPath().c_str()); 


		rocksdb::Status status = rocksDBConnector.connection();

		if (!status.ok()){
			LOG(INFO) << " Login cannot connection to database";
			LOG(INFO) << " Status result : " << status.code();
			//return false;
		}
		 
		rocksdb::DB * db = rocksDBConnector.getDB();

		std::string ttmatMessageError;
		// get user & pwd.
		status = db->Get(rocksdb::ReadOptions(),
			std::string("ttmat-message-mailbox") 
			.append("-")
			.append(date),//Date (Not include time)
			&ttmatMessageError); 

		LOG(INFO) << "Result get mailbox : " << ttmatMessageError; 
		//[-] Convert message to json.
		//[-] Convert message to struct.

		//Message format of TTMAT
		ttmat::MessageTTMAT msgTTMAT;
	
		//Push back information to container
		std::vector<ttmat::MessageTTMAT> messageTTMAT;
		messageTTMAT.push_back(msgTTMAT);

	    //setMessage before return message to external
		mbTTMATReturn.__set_messageTTMAT(messageTTMAT);

		delete db;

	}
}