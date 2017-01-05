#include <vector>

#include <gtest/gtest.h>

#include <glog/logging.h>

#include <rapidjson/document.h>

#include "services/TTMATServiceHandler.hpp"
#include "msg/gen-cpp/Authentication.h"


TEST(TTMATServiceHandler, jsonMbTTMAT){ 
	const char mbTTMAT[] = "{ \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] } ";
	rapidjson::Document document;  
	EXPECT_EQ(document.Parse(mbTTMAT).HasParseError(), false);
	EXPECT_EQ(document.HasMember("hello"), true);
}

TEST(TTMATServiceHandler, getMailboxTTMAT){
	service::TTMATServiceHandler ttmatServiceHandler;
	authentication::User  user;
	std::vector<ttmat::MessageTTMAT> messageTTMAT;

	ttmat::MailboxTTMAT *   mbTTMATReturn = new ttmat::MailboxTTMAT(); 
	mbTTMATReturn->__set_user(user);
	mbTTMATReturn->__set_messageTTMAT(messageTTMAT);
	
	std::string date("08/08/2015-19:01:02");
	ttmatServiceHandler.getMailboxTTMAT(*mbTTMATReturn, user, date);

	typedef std::vector<ttmat::MessageTTMAT>::iterator iterMessageTTMATType;
	for (iterMessageTTMATType iterMessageTTMAT = messageTTMAT.begin();
		iterMessageTTMAT != messageTTMAT.end();
		++iterMessageTTMAT){

	}
	
}