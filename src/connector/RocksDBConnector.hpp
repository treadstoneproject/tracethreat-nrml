#ifndef CONNECTOR_ROCKSDBCONNECTOR_HPP
#define CONNECTOR_ROCKSDBCONNECTOR_HPP

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
 * - Support rocksDB                                      R.Chatsiri
 */

#include <rocksdb/db.h>
#include <rocksdb/slice.h>
#include <rocksdb/options.h>



namespace connector
{

	class RocksDBConnector
	{

	public:

		RocksDBConnector(){ }
		 
		bool kDBPath(const char *path); 
		
		rocksdb::Status  RocksDBConnector::connection();
		 
		//rocksdb::Options & RocksDBConnector::option();

		rocksdb::DB *getDB();
		

	private:  
		
		rocksdb::DB* db;
		rocksdb::Options options;
		rocksdb::Status status;
		const char *path_;
	};

}

#endif /* CONNECTOR_ROCKSDB_CONNECTOR */
