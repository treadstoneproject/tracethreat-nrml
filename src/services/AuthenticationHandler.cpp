
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
<<<<<<< HEAD
		   return false;

<<<<<<< HEAD
	   rocksdbConnector.kDBPath(dbPath.c_str());
=======
	   //rocksdbConnector.kDBPath(dbPath.c_str());
>>>>>>> dev_win32
	    

	   rocksdb::Options options;
	   options.create_if_missing = true;
<<<<<<< HEAD

	   rocksdb::DB * db;

=======

	   rocksdb::DB * db;

>>>>>>> dev_win32
	   rocksdb::Status status = rocksdb::DB::Open(options, dbPath, &db); 

=======
		   return false; 
	    
	   rocksdb::DB * db;
	   rocksdb::Options  options; 
	   options.create_if_missing = true;
	   rocksdb::Status status = rocksdb::DB::Open(options, dbPath.c_str(), &db);
	    
>>>>>>> elf_structure_asm_feature
	   if (!status.ok()){
		   LOG(INFO) << " Login cannot connection to database";
		   LOG(INFO) << " Status result : " << status.code();
		   return false;
	   } 

	   std::string userName;
	   std::string password;

	   LOG(INFO) << "User login  : " << user.userName << ", Pwd : " << user.password;

	   // get user & pwd.
<<<<<<< HEAD
	   status = db->Get(ReadOptions(), std::string("user-authen"), &userName);

	   status = db->Get(ReadOptions(), std::string("pwd-authen"), &password);

=======
	   status = db->Get(rocksdb::ReadOptions(), std::string("user-authen"), &userName);

	   status = db->Get(rocksdb::ReadOptions(), std::string("pwd-authen"), &password);

>>>>>>> dev_win32
	 
	  
	   if ( (user.userName.compare(userName) == 0) && 
		    (user.password.compare(password) == 0) ){
		   LOG(INFO) << " Login success with user : " << userName;
		   delete db;
		   return true;
	   } 
		   
	    delete db; 
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
<<<<<<< HEAD
	}//logout


	void AuthenticationHandler::getMailboxTTMAT(authentication::MailboxTTMAT & mailboxTTMAL,
		const authentication::User& user,
		const std::string& date){
			LOG(INFO) << "Get message from TT-MAT...";
			//Get path
			dbPath = utils::rocksDBPath();
			if (dbPath.empty())
				//return false;

			rocksdbConnector.kDBPath(dbPath.c_str());


			rocksdb::Options options;
			options.create_if_missing = true;

			rocksdb::DB * db;

			rocksdb::Status status = rocksdb::DB::Open(options, dbPath, &db);

			if (!status.ok()){
				LOG(INFO) << " Login cannot connection to database";
				LOG(INFO) << " Status result : " << status.code();
				//return false;
			} 

			std::string * ttmatMessageError;
			// get user & pwd.
			status = db->Get(ReadOptions(), 
				std::string("ttmat-message-error-")
				.append(user.userName) //User name
				.append("-")
				.append(date),//Date (Not include time)
				ttmatMessageError);
			                                      
			//[-] Convert message to json.
		    //[-] Convert message to struct.
			
	}
	 
=======
	}//logout 
>>>>>>> dev_win32

}
