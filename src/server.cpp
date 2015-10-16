#include <signal.h>
#include "Network/Server.hpp"

DrawAttack::Server* server;

void sighandler(int sig)
{
	std::cout << "Shutting down server..." << std::endl;
	server->exit();
}

int main(int argc, char** argv)
{
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " {port} {word file}" << std::endl;
		return 0;
	}
	server = new DrawAttack::Server(atoi(argv[1]), argv[2]);
	signal(SIGTERM, &sighandler);
	signal(SIGINT,  &sighandler);
	server->run();
	delete server;
	return 0;
}
