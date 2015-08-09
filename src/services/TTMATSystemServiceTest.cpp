#include <vector>

#include "gtest/gtest.h"


#include "services/TTMATServiceHandler.hpp"
#include "msg/gen-cpp/Authentication.h"

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