/*
* Class for a Generic User in the Social Network.
*/
#ifndef _USER_HPP_
#define _USER_HPP_

#include <string>
#include <list>
#include "USocial.hpp"
#include "Message.hpp"
#include "Media.hpp"
#include "Post.hpp"

class USocial;

class User
{
	
protected:
	// class variables
	USocial* us;
	unsigned long id;
	std::string name;
	std::list<unsigned long> friends;
	std::list<Post*> posts;
	std::list<Message*> receivedMsgs;

	// class constructors and destructors.
public:
	User();
	User(unsigned long id, std::string name, USocial* us);
	~User();

	// class getters.
	unsigned long getId() const;
	std::string getName() const;
	std::list<Post*> getPosts() const;

	// adds a new friend to the friends list.
	void addFriend(User* other);

	// removes friend from the friends list.
	void removeFriend(User* other);

	// method to post a new text post.
	void post(std::string text);

	// method to post a new text post with a given media object (Photo, Audio or Video).
	void post(std::string text, Media* obj);

	// view friends posted posts from the posts list.
	void viewFriendsPosts() const;

	// adding a new received massage to the recieved messages list.
	void receivedMessage(Message* msg);

	// send a message to other user on the social network.
	void sendMessage(User* other, Message* msg);

	void sendMessageBusiness(User* other, Message* msg);

	// dispalying all the received massages to the user.
	void viewReceivedMessages() const;
};

#endif // _USER_H_

