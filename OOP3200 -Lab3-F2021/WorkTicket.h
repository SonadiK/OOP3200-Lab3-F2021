#pragma once

#ifndef __WORKTICKET__
#define __WORKTICKET__

#include <string>

// class declaration section
class WorkTicket
{
public:

	//Constructor
	WorkTicket(int ticketNumber = 0, std::string clientId = "", int day = 1, int month = 1, int year = 2000,
		std::string description = "");

	//Destructor
	~WorkTicket();

	// Copy constructor
	//WorkTicket(const WorkTicket& ticket1);

	//Conversion operator
	std::string ToString() const;

	// Operator Overloads
	bool operator==(const WorkTicket& other_point) const;

	//assignment = operator
	WorkTicket operator=(const WorkTicket& assignment_point);

	//friend overloads
	// >> operator
	friend std::istream& operator>>(std::istream& in, WorkTicket& point);
	// << operator
	friend std::ostream& operator<<(std::ostream& out, const WorkTicket& point);

	//Declaration part of mutator and accessors.
	//Accessor
	int GetTicket() const;
	std::string GetClient() const;
	std::string GetDate(int day, int month, int year);
	std::string GetDescription() const;
	virtual std::string ShowWorkTicket();


	//Mutator
	void SetTicket(int ticketNumber);
	void SetClient(std::string clientId);
	void SetDate(int day, int month, int year);
	void SetDescription(std::string description);

	// Set all the attributes of the object .
	bool SetWorkTicket(int ticketNumber, std::string clientId, int day, int month, int year, std::string description);


private:
	//Private data members.
	int m_ticketNumber;
	std::string m_clientId;
	int m_ticketDay;
	int m_ticketMonth;
	int m_ticketYear;
	std::string m_issueDescription;
};


#endif