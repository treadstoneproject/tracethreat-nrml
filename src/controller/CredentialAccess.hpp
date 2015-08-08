#ifndef CONTROLLER_CREDENTIAL_ACCESS_HPP
#define CONTROLLER_CREDENTIAL_ACCESS_HPP

namespace controller{

	class CredentialAccess{

	public:

		const char * genNouncePerRequest() const;

		bool  checkNouncePerRequest(const char * nounce);

	private:

	};

}

#endif /* CONTROLLER_CREDENTIAL_ACCESS_HPP */
