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