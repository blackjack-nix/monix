#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"
#include "MessageParser.h"
#include "Socket.h"
#include "mongo.h"

using namespace mongo;

int main(){
	//client::initialize();
	Mongo database;
    database.addUser("Nepta", 9);
	
	Socket socket;
	int end = socket.receive();
	while(!end){
		Action *action = MessageParser::getAction(socket.message());
		action->execute();
		delete action;
		end = socket.receive();
	}
	return EXIT_SUCCESS;
}
