/*
* Social Network main function.
*/

#include "User.hpp"
#include "USocial.hpp"

int main()
{
	
	// USocial check
	USocial us;

	User* u1 = us.registerUser("Liron");
	User* u2 = us.registerUser("Yahav");
	User* u3 = us.registerUser("Shachaf");
	User* u4 = us.registerUser("Tsur", true);
	User* u5 = us.registerUser("Elit");
	User* uu1 = us.registerUser("Marco");
	User* uu2 = us.registerUser("Lior", true);
	us.removeUser(uu1);
	us.removeUser(uu2);

	// post check
	u1->post("Hello World!");
	u2->post("I'm having a great time here :)", new Audio());
	u3->post("This is awesome!", new Photo());

	// add friend check
	u5->addFriend(u1); 
	u5->addFriend(u2); 
	u4->sendMessage(u5, new Message("Test"));
	u5->viewReceivedMessages();
	u5->addFriend(u4); 

	// view friends posts check
	u5->viewFriendsPosts();

	// remove friend check
	u5->removeFriend(u2);
	u5->viewFriendsPosts();

	// message check
	u4->sendMessage(u5, new Message("Buy Falafel!"));
	Message* msg = new Message("Message received Test");
	u5->receivedMessage(msg);
	u5->viewReceivedMessages();
	u3->sendMessage(u5, new Message("All your base are belong to us"));
	u3->addFriend(u5);
	u3->sendMessage(u5, new Message("All your base are belong to us"));
	u5->viewReceivedMessages();

	// debug check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}