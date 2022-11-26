# Cpp-USocial
Basic framework for Social Network named USocial.\
Written and compiled in Visual Studio 2022 on Windows 11.

# Project Description
| Class Name | Class Description |
| --- | --- |
| USocial | Describes A Social Network |
| Media | Pure abstract class, Describes Media object |
| Photo | Inherits from Media, Represents Photo Object |
| Audio | Inherits from Media, Represents Audio Object |
| Video | Inherits from Media, Represents Video Object |
| Post | Represents a new Post, A Post must include text and only one Media object |
| User | Represents a User, User can send messages only to users in his friend list |
| Business User | Represents a Business User, Business User can send messages to anyone on the social network |
| Message | Represents A Message, A Message must include text |

# Project Architecture
```mermaid
classDiagram
    class USocial{
      + User* RegisterUser(string, bool)
      + void removeUser(User*) 
      + User* getUserById(unsigned long)
     }
    USocial : - map~unsigned long, User*~ users

    class User{
      # User()
      # ~User()
      + unsigned long getId()
      + string getName()
      + void addFriend(User*)
      + void removeFriend(User*)
      + void post(string)
      + void post(string, Media*)
      + list~Post*~ getPosts()
      + void viewFriendsPosts()
      + void receiveMessage(Message*)
      + void sendMessage(User*, Message*)
      + void viewReceivedMessages()
     }
    User : # Usocial* us
    User : # unsigned long id
    User : # string name
    User : # list~unsigned long~ friends
    User : # list~Post*~ posts
    User : # list~Message*~ receivedMsgs
    
    class Business User{
      + void SendMessage(User*, Message*)
    }
    
    class Message{
      + string getText()
    }
    Message : - string text
    
    class Post{
      + Post(string)
      + Post(string, Media*)
      + ~Post()
      + string getText()
      + Media* getMedia()
    }
    Post: - string text
    Post: - Media media*
    
    class Media{
      + void display()
    }
    
    class Photo{
      + void display()
    }
    
    class Audio{
      + void display()
    }
    
    class Video{
      + void display()
    }
    
    USocial *-- User
    USocial ..> User : (friend class)
    User <|-- Business User
    User *-- Message
    User *-- Post
    Post *-- Media
    Media <|-- Photo
    Media <|-- Audio
    Media <|-- Video
    
```
