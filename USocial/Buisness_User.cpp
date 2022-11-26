/*
* Business User class implementation
*/

#include <iostream>
#include <list>
#include "Business_User.hpp"


void Business_User::sendMessage(User* other, Message* msg) {
	if (other == this) { // sent to self check
		std::cout << "You cannot send yourself a message" << std::endl;
		return;
	}
	this->sendMessageBusiness(other, new Message(msg->getText()));
}


