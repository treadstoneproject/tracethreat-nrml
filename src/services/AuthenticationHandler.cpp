
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
 * - Login from webapplication user                       R.Chatsiri       18/07/2015
 */
//#define GLOG_NO_ABBREVIATED_SEVERITIES

#include <glog/logging.h>

#include "utils/flags.hpp"

#include "services/AuthenticationHandler.hpp"

namespace services
{


	/**
	* @brief Ping data from client. (Certificate information ID)
	*
	* @param genNum Certificate Information ID
	*
	* @return True, If data correct in system.
	*/
	bool AuthenticationHandler::pingActive(const int32_t genNum)
	{ 
		LOG(INFO) << "Ping active service.";

		return true;

	}//pingActive

	/**
	* @brief Login with User struct of Thrift-DL
	*
	* @param user
	*
	* @return
	*/
	bool AuthenticationHandler::login(const authentication::User& user)
	{
	   LOG(INFO) << "Login user start service...";

	   //Get path
	   dbPath = utils::rocksDBPath();
	   if (dbPath.empty())
		   return false;

	   rocksdbConnector.kDBPath(dbPath.c_str());

	   //Set simple options.
	   rocksdbConnector.option();
	   rocksdb::Status status = rocksdbConnector.connection();

	   if (!status.ok()){
		   LOG(INFO) << " Login cannot connection to database";
		   return false;
	   } 

	   rocksdb::DB * db = rocksdbConnector.getDB();
	   std::string userName;
	   std::string password;

	   // get user & pwd.
	   status = db->Get(ReadOptions(), std::string("user-authen-").append(user.userName), &userName);

	   status = db->Get(ReadOptions(), std::string("pwd-authen-").append(user.password), &password);
	  
	   if (user.userName.compare(userName) || user.password.compare(password))
		   return true;
	    
		return false;
	}//login

	/**
	* @brief Logout from server.
	*
	* @param user
	*
	* @return
	*/
	bool AuthenticationHandler::logout(const authentication::User& user)
	{
		LOG(INFO) << "Logout user service...";
		return true;
	}//logout
	 

}
