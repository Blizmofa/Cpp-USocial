/*
* Class for the Social Network representation.
*/

#ifndef _USOCIAL_HPP_
#define _USOCIAL_HPP_

#include <map>
#include <string>
#include "User.hpp"

class USocial
{
	friend class User;
private:
	std::map<unsigned long, User*> users;
	

public:
	User* registerUser(std::string name, bool isBusinessUser = false);
	void removeUser(User* user);
	User* getUserById(unsigned long id);

};

#endif // _USOCIAL_HPP_

