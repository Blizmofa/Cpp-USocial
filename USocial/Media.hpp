/*
* Pure abstract class for media object.
*/
#ifndef _MEDIA_HPP_
#define _MEDIA_HPP_

#include <iostream>

class Media
{
	
public:
	virtual void display() const = 0; // pure virtual function.
	virtual ~Media() {}
};

class Audio: public Media
{

public:
	virtual void display() const { std::cout << "This is an Audio file" << std::endl; } // Audio representation.
	virtual ~Audio() {};

};

class Photo : public Media
{
public:
	virtual void display() const { std::cout << "This is a Photo" << std::endl; } // photo representation.
	virtual ~Photo() {};

};

class Video : public Media
{
public:
	virtual void display() const { std::cout << "This is a Video" << std::endl; } // video representation.
	virtual ~Video() {};

};

#endif // _MEDIA_HPP_

