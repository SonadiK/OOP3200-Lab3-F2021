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

	//Overload SetWorkTicket()
	bool SetWorkTicket(int ticket_number, std::string client_id, int day, int month, int year, std::string description, bool is_open = true);

	//Override ShowWorkTicket()
	std::string ShowWorkTicket() override;

	//Mutator - CloseTicket()
	void CloseTicket();

	//Overload the << operator 
	friend std::ostream& operator<<(std::ostream& out, const ExtendedWorkTicket& ticket);
private:
	//Member variables
	bool m_IsOpen;
};



#endif
