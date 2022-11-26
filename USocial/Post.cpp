/*
* Post class implementation
*/

#include "Post.hpp"

Post::Post(std::string text) {
	this->text = text;
}

Post::Post(std::string text, Media* media) {
	this->text = text;
	this->media = media;
}

Post::~Post() {
	delete media;
}