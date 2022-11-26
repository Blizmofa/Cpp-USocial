/*
* Class representation of a new Message.
* a new Message must include text.
*/
#ifndef _MESSAGE_HPP_
#define _MESSAGE_HPP_

#include <string>

class Message
{
private:
	std::string text;
public:
	Message(std::string text) { this->text = text; }
	std::string getText() const { return text; }
};

#endif // _MESSAGE_HPP_

