#include "ExtendedWorkTicket.h"
#include<iostream>

//Default constructor
ExtendedWorkTicket::ExtendedWorkTicket()
{
	SetTicket(0);
	SetClient("");
	SetDate(1, 1, 2000);
	SetDescription("");
	setIsOpen(true);
}

//Parameterized constructor
ExtendedWorkTicket::ExtendedWorkTicket(const int ticket_number, const std::string& client_id, const int day, const int month, const int year, const std::string& description, bool is_open)
	:WorkTicket(ticket_number, client_id, day, month, year, description), m_IsOpen(is_open)
{

}

//Definition 
bool ExtendedWorkTicket::getIsOpen() const
{
	return m_IsOpen;
}

void ExtendedWorkTicket::setIsOpen(const bool value)
{
	m_IsOpen = true;
}

//Definition 
bool ExtendedWorkTicket::SetWorkTicket(int ticket_number, std::string client_id, int day, int month, int year,
	std::string description, bool is_open)
{
	//MyDate workingDate;
	const auto min_year = 2000;
	const auto max_year = 2099;
	auto valid = true; // flag for if parameters are valid
	//
	// check numeric parameters
	if (ticket_number < 0 || year < min_year || year > max_year)
		valid = false;
	// check string parameters     
	else if (client_id.length() < 1 || description.length() < 1)
		valid = false;
	else
	{
		try
		{
			// sets the date (may throw an exception even if rules are met)
			SetDate(day, month, year);
		}
		catch (...)
		{
			valid = false;
		}
	}

	if (valid) // all parameters are valid
	{
		// set the workticket date         
		SetDate(day, month, year);

		// set atributes to parameter values
		SetTicket(ticket_number);
		SetClient(client_id);
		SetDescription(description);
		setIsOpen(true);

	}
	// return true or false based on parameter validity
	return valid;
}

// Definition of ShowWorkTicket
std::string ExtendedWorkTicket::ShowWorkTicket()
{
	//Call base class version of ShowWorkTicket()
	std::cout << WorkTicket::ShowWorkTicket();
	//Check IsOpen is true or false
	if (getIsOpen() == true)
	{
		//If IsOpen is true
		std::cout << "Is the ticket open?" << " True";
		std::cout << std::endl;
	}
	else
	{
		//If IsOpen is false
		std::cout << "Is the ticket open?" << " False";
		std::cout << std::endl;
	}
	return {};
}

//Defining CloseTicket() mutator
void ExtendedWorkTicket::CloseTicket()
{
	m_IsOpen = false;
}

// Defining the output << operator.
std::ostream& operator<<(std::ostream& out, const ExtendedWorkTicket& ticket)
{
	//Call the base version of ostream (output operator)
	out << (WorkTicket)ticket;
	//Check IsOpen is true or false
	if (ticket.getIsOpen() == true)
	{
		//If IsOpen is true
		std::cout << "Is the ticket open?" << " True";
		std::cout << std::endl;
	}
	else
	{
		//If IsOpen is false
		std::cout << "Is the ticket open?" << " False";
		std::cout << std::endl;
	}
	return out;
}