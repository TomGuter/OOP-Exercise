#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"

class Zoo
{
public:
	Zoo();//default c'tor  - all to 0 or null
	Zoo( const char* name, const char* address, float ticket, const char* open, const char* close );//c'tor with data - init class
	Zoo( ifstream& in_file );//c'tor that gets a binary file and loads the data of the zoo from the file
	Zoo( const Zoo& other );//copy c'tor that loads the data from the other (deep way)
	virtual ~Zoo();//d'tor

public:
	const char*		GetName() const { return m_name; }//return the name of the zoo
	const char*		GetAddress() const { return m_address; }//return the address of the zoo
	float			GetTicketPrice() const { return m_ticketPrice; }//return the ticket price of the zoo
	const char*		GetOpenHour() const { return m_openHours; }//return the open hour of the zoo
	const char*		GetCloseHour() const { return m_closeHours; }//return the close hour of the zoo
	int				GetNumOfAnimals() const { return m_numOfAnimals; }//return the num of animals in the zoo
	Animal**		GetAnimals() const { return m_animals; }//return the animals array of the zoo

public:
	void AddAnimal( Animal* an );//creates a copy of "an" (deep copy) and adds an animal to the array

public:
	Zoo& operator+( Animal* an );//adds an animal (only pointer, no copy needed) to the class and returns this with the change
	Zoo operator+( const Zoo& other ) const; //returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
	Zoo& operator=( const Zoo& other );//operator = that copies the data from other to this and returns this
	Zoo& operator+=( Animal* an );//adds an animal (only pointer, no copy needed) to the class and returns this with the change

public:
	friend ofstream& operator<<( ofstream& out, const Zoo& z );//operator to write the zoo to a text file
	friend ifstream& operator >> ( ifstream& in, Zoo& z );//operator to read the zoo from a text file

public:
	void Save( ofstream& ofs ) const;//method to save the info to a text file
	void Load( ifstream& ifs );//method to load the info from a text file
	void SaveBin( ofstream& ofs ) const;//method to save the info to a binary file

private:
	Animal* createAnimalBin( ifstream& in_file );
	Animal* createAnimalTxt( ifstream& in_file );

private:
	char*		m_name;
	char*		m_address;
	float		m_ticketPrice;
	char*		m_openHours;
	char*		m_closeHours;
	int			m_numOfAnimals;
	Animal**	m_animals;
};

ofstream& operator<<( ofstream& out, const Zoo& z );
ifstream& operator >> ( ifstream& in, Zoo& z );

#endif // ifndef