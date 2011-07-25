/**
 * Iliade root file program
 **/

/**
 * @file iliade.cpp
 * @brief Main file to launch the iliade game.
 */

#include <iostream>
#include <utilite/UtiLite.h>
#include "army.hpp"
#include "warrior.hpp"

int main(int argc, char** argv)
{
	// Set the logger type. The choices are kTypeConsole,
	// kTypeFile or kTypeNoLog (nothing is logged).
	ULogger::setType(ULogger::kTypeConsole);

	// Set the logger severity level (kDebug, kInfo, kWarning, kError).
	// All log entries under the severity level are not logged. Here,
	// only debug messages are not logged.
	ULogger::setLevel(ULogger::kDebug);

	std::cout << "Iliade, the game !" <<std::endl;

	Warrior soldat, archer;

	soldat.set_army_point(4);
	archer.set_army_point(1);
	//std::cout << "Army point of soldat :" << soldat.get_army_point() <<std::endl;

	ULOGGER_INFO("soldat id : %d, archer id : %d", soldat.get_id(), archer.get_id());
	//soldat.set_id(0);
	//archer.set_id(1);

	Army army;
	army.add_warrior(soldat);
	army.add_warrior(archer);

	std::cout<< "Points in army :"<< army.get_army_point() <<std::endl;

	ULOGGER_INFO("This message is logged.");
	return 0;
}

