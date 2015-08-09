#ifndef SERVICE_TTMATSERVICE_HANDLER_HPP
#define SERVICE_TTMATSERVICE_HANDLER_HPP

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
* - Get Message from TT-MAT                                   R.Chatsiri       
*/

#include "msg/gen-cpp/TTMATSystemService.h"
 
#include "connector/RocksDBConnector.hpp"
 
namespace service{

	class TTMATServiceHandler : public ttmat::TTMATSystemServiceIf{
	public:
		/* vitual class from TTMATSystemServiceIf*/
		void getMailboxTTMAT(ttmat::MailboxTTMAT& mbTTMATReturn,
			const  ::authentication::User& user, 
			const std::string& date);
	private:

		std::string   dbPath;
		connector::RocksDBConnector  rocksDBConnector;
	};

}


#endif /* SERVICE_TTMATSERVICE_HANDLER_HPP */