#ifndef SERVICES_AUTHENTICATION_HANDLER
#define SERVICES_AUTHENTICATION_HANDLER
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
 * - Login from webapplication user                       R.Chatsiri       18/07/2015
 */

#include "msg/gen-cpp/Authentication.h"

#include "connector/RocksDBConnector.hpp"

namespace services
{

	class AuthenticationHandler : public authentication::AuthenticationIf
	{

	public:

		AuthenticationHandler(){ 
		
		} 

		bool pingActive(const int32_t genNum);
		/* Login user to system.*/
		bool login(const authentication::User& user);
<<<<<<< HEAD
		/* Get mesage from TTMAT */
		void getMailboxTTMAT(authentication::MailboxTTMAT & mailboxTTMAL, 
			const authentication::User& user, 
			const std::string& date);
=======
		 
>>>>>>> dev_win32
		/* Logout user from system*/
		bool logout(const authentication::User& user);

	private:
		const authentication::User *user;

		std::string   dbPath; 
		connector::RocksDBConnector rocksdbConnector;
	};

}

#endif /* SERVICES_AUTHENTICATION_HANDLER */
