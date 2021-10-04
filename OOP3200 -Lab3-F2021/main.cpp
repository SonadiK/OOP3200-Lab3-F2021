// OOP3200-Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Authors: Devanshi Patel (#100805084) and Sonadi Kannangara (#100778336)
// Date:    01 October, 2021
// Last Modified Date: 03 October, 2021
// Activity Type:    Lab 3
// Resources:  MyConsoleInput.h & MyconsoleInput.cpp from ICE1 and Lab1 and WorkTicket.h & WorkTicket.cpp from Lab 2.
//

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range

#include "ExtendedWorkTicket.h"
#include "MyConsoleInput.h"
#include "WorkTicket.h"

using namespace std;

int main()
{
	//Calling the default constructor.
	ExtendedWorkTicket testTicket1;
	//Calling the parameterized constructor.
	ExtendedWorkTicket testTicket2(1, "AMCE_123", 1, 7, 2014, "Password Reset", true);

	std::cout << std::endl << "As Initialized: " << std::endl;
	//Calling the overloaded ShowWorkTicket()
	std::cout << testTicket1.ShowWorkTicket() << std::endl;
	std::cout << testTicket2.ShowWorkTicket() << std::endl;

	// Calling the overloaded SetWorkTicket().
	if (!testTicket1.SetWorkTicket(2, "MACDONALD-001", 10, 3, 2012, "User cannot locate \'any\' key.", true))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl;
	//output operator (ostream).
	std::cout << std::endl << "Ticket 1: " << testTicket1 << std::endl;

	// Calling the overloaded SetWorkTicket().
	if (!testTicket2.SetWorkTicket(-1, "BLAGO-042", 13, 32, 11, "", false))
		std::cout << "\nErrors! No changes to the ticket made." << std::endl;
	//output operator (ostream).
	std::cout << std::endl << "Ticket 2: " << testTicket2 << std::endl;
	//calling the CloseTicket() mutator
	testTicket2.CloseTicket();
	//output operator (ostream).
	std::cout << std::endl << "After Ticket 2 closed: " << testTicket2 << std::endl;

	std::cout << std::endl << std::endl;
	return 0;
	//end of main function.
}
