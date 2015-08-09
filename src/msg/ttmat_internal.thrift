include "authenication.thrift"

namespace cpp ttmat

/* For throw and error from member function */
exception InvalidOperation{
	1: i32 what,
	2: string why
}

struct MessageTTMAT{
	1: string subject;
	2: string detail;
	3: string status;
	4: string date;
}

typedef list<MessageTTMAT> messageTTMATList

struct MailboxTTMAT{
	1: authenication.User user;
	2: messageTTMATList messageTTMAT;
}


service TTMATSystemService{

    /* get data from TT-MAT mailbox */
	MailboxTTMAT getMailboxTTMAT(1: authenication.User user, 2:string date) throws(1:InvalidOperation ouch)
	 
}