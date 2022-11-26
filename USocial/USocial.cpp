/*
* USocial class implementation
*/

#include "USocial.hpp"
#include "User.hpp"
#include "Business_User.hpp"

User* USocial::registerUser(std::string name, bool isBusinessUser) {
	unsigned long id = users.size() + 1;
	User* newUser;
	if (!isBusinessUser) {
		newUser = new User(id, name, this);
		std::cout << newUser->getName() << " registered as a regular user." << std::endl;
	}
	else {
		newUser = new Business_User(id, name, this);
		std::cout << newUser->getName() << " registered as a business user." << std::endl;
	}
	users[id] = newUser;
	return newUser;
}

void USocial::removeUser(User* user) {
	if (users.empty()) {
		std::cout << "Social Network has no registered users." << std::endl;
	}
	auto it = users.find(user->getId());
	if (it != users.end()) {
		users.erase(it);
	}
	std::cout << user->getName() << " has been removed by admin." << std::endl;
}

User* USocial::getUserById(unsigned long id) {
	if (users.empty()) {
		std::cout << "Social Network has no registered users." << std::endl;
	}
	auto it = users.find(id);
	if (it != users.end()) {
		return (*it).second;
	}
	else {
		std::cout << "No such user in the social network." << std::endl;
	}
}

