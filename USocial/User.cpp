/*
* User class implementation
*/

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include "User.hpp"
#include "Post.hpp"

User::User() 
	: id{ 0 }, name{ NULL }, us{ NULL } {
}

User::User(unsigned long id, std::string name, USocial* us)
	: id{ id }, name{ name }, us{ us } {
}

User::~User() {
	for (auto const& user : us->users) {
		delete user.second;
	}
	for (auto const& post : posts) {
		delete post;
	}
	for (auto const& msg : receivedMsgs) {
		delete msg;
	}
	friends.clear();
	posts.clear();
	receivedMsgs.clear();
}

unsigned long User::getId() const { 
	return id; 
}

std::string User::getName() const { 
	return name; 
}

void User::addFriend(User* other) {
	if (other == this) { // add self check
		std::cout << "You cannot add yourself as a friend" << std::endl;
		return;
	}
	if (other == NULL) {
		return;
	}
	// add both sides to friend list
	friends.push_back(other->getId());
	other->friends.push_back(this->getId());
	std::cout << other->getName() << " is now your friend. " << std::endl;
}

void User::removeFriend(User* other) {
	if (other == this) { // remove self check
		std::cout << "You cannot remove yourself" << std::endl;
		return;
	}
	if (other == NULL) {
		return;
	}
	auto it = std::find(friends.begin(), friends.end(), other->getId()); // iterator to find the wanted id.
	friends.erase(it);
	std::cout << other->getName() << " has been removed from friend list " << std::endl;
}

void User::post(std::string text) {
	Post* post = new Post(text);
	posts.push_back(post);
}

void User::post(std::string text, Media* obj) {
	Post* post = new Post(text, obj);
	posts.push_back(post);
}

std::list<Post*> User::getPosts() const {
	if (posts.size() == 0) {
		std::cout << "No posts to view" << std::endl;
	}
	return posts;

}

void User::viewFriendsPosts() const {
	if (friends.size() == 0) {
		std::cout << "Friend list is empty, no posts to display." << std::endl;
		return;
	}
	for (auto const& fr : friends) {
		// check if both users are friends
		if (fr == us->getUserById(fr)->getId()) {
			for (auto const& post : us->getUserById(fr)->getPosts()) {
				// for posts with media file
				if (post->getMedia() != NULL) {
					std::cout << post->getText() << ", ";
					post->getMedia()->display();
				}
				// for posts with text only
				else {
					std::cout << post->getText() << std::endl;
				}
			}
		}
	}
}

void User::receivedMessage(Message* msg) {
	if (receivedMsgs.size() == 0) {
		return;
	}
	std::cout << "You have a new massage" << std::endl;
	this->receivedMsgs.push_back(msg);
}

void User::sendMessage(User* other, Message* msg) {
	bool isAFriend = false;
	if (other == this) { // send to self check
		std::cout << "You cannot send a message to yourself" << std::endl;
		return;
	}
	if (friends.size() == 0) { 
		std::cout << "You can send a message only to your friends" << std::endl;
		return;
	}
	auto it = std::find(friends.begin(), friends.end(), other->getId());
	if (friends.end() != it) {
		isAFriend = true; // the given user is a friend
	}
	if (isAFriend) {
		other->receivedMsgs.push_back(new Message(msg->getText()));
	}
	else {
		std::cout << other->getName() << " is NOT your friend, you can send messages only to your friends." << std::endl;
	}	
}

void User::sendMessageBusiness(User* other, Message* msg) {
	if (other == this) { // sent to self check
		std::cout << "You cannot send yourself a message" << std::endl;
		return;
	}
	other->receivedMsgs.push_back(new Message(msg->getText()));
}

void User::viewReceivedMessages() const {
	if (receivedMsgs.size() == 0) {
		std::cout << "You got no received messages." << std::endl;
	}
	for (auto const &msg : receivedMsgs) {
		std::cout << msg->getText() << std::endl;
	}
}

