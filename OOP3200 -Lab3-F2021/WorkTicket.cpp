#include "WorkTicket.h";

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			//stringstream 
#include <limits>			// INT_MAX
#include <stdexcept>

#include "MyConsoleInput.h"


//Class definition section


/// <summary>
/// Constructor definition
/// </summary>
/// <param name="ticketNumber"></param>
/// <param name="clientId"></param>
/// <param name="day"></param>
/// <param name="month"></param>
/// <param name="year"></param>
/// <param name="description"></param>
WorkTicket::WorkTicket(int ticketNumber, std::string clientId, int day, int month, int year, std::string description)
{
	SetTicket(ticketNumber);
	SetClient(clientId);
	SetDate(day, month, year);
	SetDescription(description);
}

/// <summary>
/// Destructor 
/// </summary>
WorkTicket::~WorkTicket() = default;


///// <summary>
///// Copy constructor
///// </summary>
///// <param name="ticket1"></param>
//WorkTicket::WorkTicket(const WorkTicket & ticket1)
//{
//	SetTicket(ticket1.GetTicket());
//	SetClient(ticket1.GetClient());
//	SetDate(ticket1.m_ticketDay, ticket1.m_ticketMonth, ticket1.m_ticketYear);
//	SetDescription(ticket1.GetDescription());
//
//	std::cout << "\nA WorkTicket object was COPIED.\n\n";
//}


/// <summary>
/// Conversion Operator
/// </summary>
/// <returns></returns>
std::string WorkTicket::ToString() const
{

	// declare a stringstream object
	std::stringstream strOut;

	// build the string
	strOut << "Work Ticket # " << m_ticketNumber << " - " << m_clientId << "  (" << m_ticketDay << "/" << m_ticketMonth << "/" << m_ticketYear << ")  " << m_issueDescription << "\n";

	// return the string
	return strOut.str();

}


/// <summary>
/// Equality Operator
/// </summary>
/// <param name="other_point"></param>
/// <returns></returns>
bool WorkTicket::operator==(const WorkTicket & other_point) const
{
	bool isEqual;
	if (GetTicket() == other_point.GetTicket() && GetClient() == other_point.GetClient() &&
		GetDescription() == other_point.GetDescription())
	{
		std::cout << "\nTickets are the same." << std::endl;
		isEqual = true;
	}
	else
	{
		std::cout << "\nTickets are not the same." << std::endl;
		isEqual = false;
	}
	return isEqual;
}


/// <summary>
/// Assignment Operator
/// </summary>
/// <param name="assignment_point"></param>
/// <returns></returns>
WorkTicket WorkTicket::operator=(const WorkTicket & assignment_point)
{
	SetTicket(assignment_point.GetTicket());
	SetClient(assignment_point.GetClient());
	SetDate(assignment_point.m_ticketDay, assignment_point.m_ticketMonth, assignment_point.m_ticketYear);
	SetDescription(assignment_point.GetDescription());

	std::cout << "\nA workTicket object was ASSIGNED.\n";

	return *this;
}


/// <summary>
///  A mutator method to set all the attributes of the object to the parameters. 
/// </summary>
/// <param name="ticketNumber"></param>
/// <param name="clientId"></param>
/// <param name="day"></param>
/// <param name="month"></param>
/// <param name="year"></param>
/// <param name="description"></param>
bool WorkTicket::SetWorkTicket(int ticketNumber, std::string clientId, int day, int month, int year, std::string description)
{
	SetTicket(ticketNumber);
	SetClient(clientId);
	SetDate(day, month, year);
	SetDescription(description);

	return {};
}


//Defining mutator section


/// <summary>
/// This method takes one integer parameter, ticketNumber, and sets the m_ticketNumber variable to its value
/// </summary>
/// <param name="ticketNumber"></param>
void WorkTicket::SetTicket(int ticketNumber)
{
	m_ticketNumber = ticketNumber;
}

/// <summary>
/// This method takes one string parameter, clientId, and sets the m_clientId variable to its value
/// </summary>
/// <param name="clientId"></param>
void WorkTicket::SetClient(std::string clientId)
{
	m_clientId = clientId;
}

/// <summary>
/// This method takes three integer parameter, day, month, year and sets the m_ticketDay, m_ticketMonth
/// and m_ticketYear variables respectively to its value
/// </summary>
/// <param name="day"></param>
/// <param name="month"></param>
/// <param name="year"></param>
void WorkTicket::SetDate(int day, int month, int year)
{
	m_ticketDay = day;
	m_ticketMonth = month;
	m_ticketYear = year;
}

/// <summary>
/// This method takes one string parameter, description, and sets the m_issueDescription variable to its value
/// </summary>
/// <param name="description"></param>
void WorkTicket::SetDescription(std::string description)
{
	m_issueDescription = description;
}


//Defining accessors section.


/// <summary>
/// This method returns the value of the m_ticketNumber member variable
/// </summary>
/// <returns></returns>
int WorkTicket::GetTicket() const
{
	return m_ticketNumber;
}

/// <summary>
/// This method returns the value of the m_clientId member variable
/// </summary>
/// <returns></returns>
std::string WorkTicket::GetClient() const
{
	return m_clientId;
}

/// <summary>
/// This method returns the value of the day, month, year as a string
/// </summary>
/// <param name="day"></param>
/// <param name="month"></param>
/// <param name="year"></param>
/// <returns></returns>
std::string WorkTicket::GetDate(int day, int month, int year)
{
	// Declare stringstream object
	std::stringstream strOut;
	// Build the string
	strOut << day << "/" << month << "/" << year;
	// Return the string
	return strOut.str();
}

/// <summary>
/// This method returns the value of the m_issueDescription member variable
/// </summary>
/// <returns></returns>
std::string WorkTicket::GetDescription() const
{
	return m_issueDescription;
}


// Accessor to display all the attributes of the object in a formatted string.
std::string WorkTicket::ShowWorkTicket()
{
	std::cout << "Work Ticket Information" << std::endl;
	std::cout << std::endl
		<< "The work ticket number is: " << GetTicket() << std::endl
		<< "The client Id is: " << GetClient() << std::endl
		<< "The work ticket date is " << GetDate(m_ticketDay, m_ticketMonth, m_ticketYear) << std::endl
		<< "The issue description is: " << GetDescription() << std::endl << std::endl;

	return {};
}

/// <summary>
/// >> operator
/// </summary>
/// <param name="in"></param>
/// <param name="point"></param>
/// <returns></returns>
std::istream& operator>>(std::istream & in, WorkTicket & point)
{
	std::cout << "\nWork ticket number: ";
	point.m_ticketNumber = ConsoleInput::ReadInteger(1);
	in.ignore();

	std::cout << "Client ID: ";
	point.m_clientId = ConsoleInput::ReadString();
	in.ignore();

	std::cout << "Day: ";
	point.m_ticketDay = ConsoleInput::ReadInteger(1, 31);
	in.ignore();

	std::cout << "Month: ";
	point.m_ticketMonth = ConsoleInput::ReadInteger(1, 12);
	in.ignore();

	std::cout << "Year:  ";
	point.m_ticketYear = ConsoleInput::ReadInteger(2000, 2099);
	in.ignore();

	std::cout << "Description:  ";
	point.m_issueDescription = ConsoleInput::ReadString();

	return in;
}

/// <summary>
/// << operator
/// </summary>
/// <param name="out"></param>
/// <param name="point"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream & out, const WorkTicket & point)
{
	out << "\nThe work ticket number is: " << point.GetTicket()
		<< "\nThe client Id is: " << point.GetClient()
		<< "\nThe work ticket date is " << point.m_ticketDay << "/" << point.m_ticketMonth << "/" << point.m_ticketYear
		<< "\nThe issue description is: " << point.GetDescription() << std::endl << std::endl;
	return out;
}
