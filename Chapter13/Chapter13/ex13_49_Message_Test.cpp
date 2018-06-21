/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include "Message.h"


int main()
{
	Message firstMail("hello");
	Message signInMail("welcome to cppprimer");
	Folder mailBox;

	firstMail.save(mailBox);
	signInMail.save(mailBox);
	mailBox.print_debug();

	firstMail = std::move(signInMail);
	mailBox.print_debug();
}