/*
* Class for a Business User in the Social Network.
*/

#ifndef _BUSINESS_USER_HPP_
#define _BUSINESS_USER_HPP_

#include "User.hpp"
#include "USocial.hpp"

class Business_User : public User
{
	friend class USocial;
public:
	using User::User;
	void sendMessage(User* other, Message* msg);
};

#endif // _BUSINESS_USER_HPP_
