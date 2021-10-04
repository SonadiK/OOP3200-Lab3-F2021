#pragma once

#ifndef __EXTENDEDWORKTICKET_H__
#define __EXTENDEDWORKTICKET_H__
#include "WorkTicket.h"

class ExtendedWorkTicket : public WorkTicket
{
public:
	//Default constructor
	ExtendedWorkTicket();
	//Parameterized constructor
	ExtendedWorkTicket(int ticket_number, const std::string& client_id, int day, int month, int year, const std::string& description, bool isOpen);

	//Declaration - accessor
	bool getIsOpen() const;
	//Mutator
	void setIsOpen(bool value);

private:
	//Member variables
	bool m_IsOpen;
};

#endif
