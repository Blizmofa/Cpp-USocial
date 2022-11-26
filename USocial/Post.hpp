/*
* Class for posting a new Post in the Social Network.
* a new Post can include some text and one Media object (a Photo, a Video or an Audio file).
*/
#ifndef _POST_HPP_
#define _POST_HPP_

#include <string>
#include "Media.hpp"

class Post
{
private:
	std::string text;
	Media* media;
public:
	Post(std::string text);
	Post(std::string text, Media* media);
	~Post();
	std::string getText() const { return text; }
	Media* getMedia() const { return media; }
};

#endif // _POST_HPP_

