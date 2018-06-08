#pragma once
/*
*
*@author£ºAver Jing
*@description£º
*
*@date£ºJune 7, 2018
*
*/

#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

class Folder;

class Message {
	friend class Folder;
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
public:
	// folder is implicitly initialized to the empty set
	explicit Message(const string &str = "") :contents(str) {}
	// copy control to manage pointer to this Message
	Message(const Message&);	//copy constructor
	Message& operator=(const Message&);	//copy assignment
	~Message();	//destructor
	// add/remove this Message from the specified Folder's set of messages
	void save(Folder&);
	void remove(Folder&);
	void print_debug() {
		cout << contents << endl;
	}
private:
	string contents;	//actual message text
	set<Folder*> folders;	//Folders that have this Message
	// utility function used by copy constructor, assignment, and destructor
	// add this Message to the Folders that point to the parameter
	void add_to_Folders(const Message&);
	// remove this Message from every Folder in folders
	void remove_from_Folders();

	void remFldr(Folder *f) {
		folders.erase(f);
	}
	void addFldr(Folder *f) {
		folders.insert(f);
	}
};

class Folder {
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Message;
public:
	Folder() = default;
	Folder(Message& m) { message.insert(&m); }
	Folder(const Folder& f) : message(f.message) {
		add_to_message(f);
	}
	Folder& operator=(const Folder &f) {
		remove_from_message();
		message = f.message;
		add_to_message(f);
		return *this;
	}
	~Folder() {
		remove_from_message();
	}
	void print_debug() {
		for (auto m : message) cout << m->contents << " ";
		cout << endl;
	}
private:
	set<Message*> message;
	void remove_from_message();
	void add_to_message(const Folder&);

	void addMsg(Message* m) { message.insert(m); }
	void remMsg(Message* m) { message.erase(m); }
};

void Folder::remove_from_message() {
	for (auto e : message)
		e->remFldr(this);
}

void Folder::add_to_message(const Folder &rhs) {
	for (auto e : rhs.message)
		e->addFldr(this);
}


Message::Message(const Message &m):contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);		//add this Message to the Folders that point to m
}

inline Message & Message::operator=(const Message &rhs)
{
	// handle self-assignment by removing pointers before inserting them
	remove_from_Folders();		// update existing Folders
	contents = rhs.contents;	// copy message contents from rhs
	folders = rhs.folders;		// copy Folder pointers from rhs
	add_to_Folders(rhs);		// add this Message to those Folders 
	return *this;
}

inline Message::~Message()
{
	remove_from_Folders();
}

inline void Message::save(Folder &f)
{
	folders.insert(&f);  //add the given Folder to our list of Folders
	f.addMsg(this);		//add this Message to f's set of Messages
}

inline void Message::remove(Folder &f)
{
	folders.erase(&f);		//take the given Folder out of our list of Folders
	f.remMsg(this);			//remove this Message to f's set of Messages
}

inline void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

inline void swap(Folder &lhs, Folder &rhs)
{
	using std::swap;
	lhs.remove_from_message();
	rhs.remove_from_message();

	swap(lhs.message, rhs.message);

	lhs.add_to_message(lhs);
	rhs.add_to_message(rhs);

}

inline void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)		//for each Folder that holds m
		f->addMsg(this);		//add a pointer to this Message to that Folder
}

inline void Message::remove_from_Folders()
{
	for (auto f : folders)		//for each pointer in folders
		f->remMsg(this);		//remove this Message from that Folder
}

#endif