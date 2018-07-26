/*
*
*@author£ºAver Jing
*@description£ºWrite your own version of a function that uses a shared_ptr to manage a
*  connection.
*@date£ºJuly 25, 2018
*
*/

#include<iostream>
#include "base_tool.h"

using namespace std;

struct connection {
	std::string ip;
	int port;
	connection(std::string ip_, int port_) : ip(ip_), port(port_) {}
};

struct destination {
	std::string ip;
	int port;
	destination(std::string ip_, int port_) : ip(ip_), port(port_) {}
};

connection connect(destination* pDest)
{
	std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	std::cout << "creating connection(" << pConn.use_count() << ")"
		<< std::endl;
	return *pConn;
}

void disconnect(connection pConn)
{
	std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")"
		<< std::endl;
}

void end_connection(connection* pConn)
{
	disconnect(*pConn);
}

void f(destination& d)
{
	connection conn = connect(&d);
	std::shared_ptr<connection> p(&conn, end_connection);
	std::cout << "connecting now(" << p.use_count() << ")" << std::endl;

	//ex12_15 Rewrite the first exercise to use a lambda (10.3.2, p.388) in place of the
	//end_connection function.
	std::shared_ptr<connection> p(&conn, [](connection* pConn) {disconnect(*pConn); });
}

int main() {
	destination dest("202.118.176.67", 3316);
	f(dest);

	return 0;
}