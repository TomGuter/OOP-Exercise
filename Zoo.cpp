#include "Zoo.h"
#include "Horse.h"
#include "Flamingo.h"
#include "GoldFish.h"
#include "Mermaid.h"

Zoo::Zoo() // default c'tor  - all to 0 or null
{
	m_name = NULL;
	m_address = NULL;
	m_ticketPrice = 0;
	m_openHours = NULL;
	m_closeHours = NULL;
	m_numOfAnimals = 0;
	m_animals = NULL;
}

Zoo::Zoo(const char *name, const char *address, float ticket, const char *open, const char *close) // c'tor with data - init class
	: m_ticketPrice(ticket),
	  m_numOfAnimals(0),
	  m_animals(NULL)
{
	m_name = strdup(name);
	m_address = strdup(address);
	m_openHours = strdup(open);
	m_closeHours = strdup(close);
}

Zoo::Zoo(ifstream &in_file) // c'tor that gets a binary file and loads the data of the zoo from the file
{
	m_name = readTextFromFile(in_file);
	m_address = readTextFromFile(in_file);

	in_file.read((char *)&m_ticketPrice, sizeof(m_ticketPrice));

	m_openHours = readTextFromFile(in_file);
	m_closeHours = readTextFromFile(in_file);

	in_file.read((char *)&m_numOfAnimals, sizeof(m_numOfAnimals));

	m_animals = new Animal *[m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals; ++i)
	{
		Animal *a = createAnimalBin(in_file);
		m_animals[i] = a;
	}
}

Zoo::Zoo(const Zoo &other) // copy c'tor that loads the data from the other (deep way)
{
	*this = other;
}

Zoo::~Zoo() // d'tor
{
	if (m_name)
		delete m_name;

	m_name = NULL;

	if (m_address)
		delete m_address;

	m_address = NULL;

	if (m_openHours)
		delete m_openHours;

	m_openHours = NULL;

	if (m_closeHours)
		delete m_closeHours;

	m_closeHours = NULL;

	if (m_numOfAnimals)
	{
		for (int i = 0; i < m_numOfAnimals; ++i)
			delete m_animals[i];

		delete[] m_animals;

		m_animals = NULL;
	}
}

void Zoo::AddAnimal(Animal *an) // adds an animal to the array
{
	// first expand the array of animals and keep the old data
	++m_numOfAnimals;
	Animal **newArr = new Animal *[m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals - 1; ++i)
		newArr[i] = m_animals[i];

	// delete the old array
	delete[] m_animals;

	// set the array to the new one
	m_animals = newArr;

	// now determine the type of the added animal and add it to the last place in the array
	char *type = an->GetTypeName();
	if (0 == strcmp(type, fixTypeName((char *)typeid(Horse).name())))
		m_animals[m_numOfAnimals - 1] = new Horse(*(dynamic_cast<Horse *>(an)));
	else if (0 == strcmp(type, fixTypeName((char *)typeid(Flamingo).name())))
		m_animals[m_numOfAnimals - 1] = new Flamingo(*(dynamic_cast<Flamingo *>(an)));
	else if (0 == strcmp(type, fixTypeName((char *)typeid(GoldFish).name())))
		m_animals[m_numOfAnimals - 1] = new GoldFish(*(dynamic_cast<GoldFish *>(an)));
	else if (0 == strcmp(type, fixTypeName((char *)typeid(Mermaid).name())))
		m_animals[m_numOfAnimals - 1] = new Mermaid(*(dynamic_cast<Mermaid *>(an)));
	else
		m_animals[m_numOfAnimals - 1] = NULL;
}

Zoo &Zoo::operator+(Animal *an) // adds an animal to the class and returns this with the change
{
	// first expand the array of animals and keep the old data
	++m_numOfAnimals;
	Animal **newArr = new Animal *[m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals - 1; ++i)
		newArr[i] = m_animals[i];

	// delete the old array
	delete[] m_animals;

	// set the array to the new one
	m_animals = newArr;

	// now add the new Animal to the array
	m_animals[m_numOfAnimals - 1] = an;

	return *this;
}

Zoo Zoo::operator+(const Zoo &other) const // returns a new Zoo with the properties of this and animals of this and other
{
	Zoo z(*this);
	for (int i = 0; i < other.m_numOfAnimals; ++i)
		z.AddAnimal(other.m_animals[i]);

	return z;
}

Zoo &Zoo::operator+=(Animal *an)
{
	*this + an;
	return *this;
}

Zoo &Zoo::operator=(const Zoo &other) // operator = that copies the data from other to this and returns this
{
	m_name = strdup(other.m_name);
	m_address = strdup(other.m_address);
	m_ticketPrice = other.m_ticketPrice;
	m_openHours = strdup(other.m_openHours);
	m_closeHours = strdup(other.m_closeHours);

	m_numOfAnimals = 0;
	for (int i = 0; i < other.m_numOfAnimals; ++i)
		AddAnimal(other.m_animals[i]);

	return *this;
}

void Zoo::Save(ofstream &ofs) const // method to save the info to a text file
{
	ofs << m_name << endl;
	ofs << m_address << endl;
	ofs << m_ticketPrice << endl;
	ofs << m_openHours << endl;
	ofs << m_closeHours << endl;
	ofs << m_numOfAnimals << endl;

	for (int i = 0; i < m_numOfAnimals; ++i)
		m_animals[i]->Save(ofs);
}

void Zoo::Load(ifstream &ifs) // method to load the info from a text file
{
	m_name = readTextFromFile(ifs);
	m_address = readTextFromFile(ifs);
	ifs >> m_ticketPrice;
	m_openHours = readTextFromFile(ifs);
	m_closeHours = readTextFromFile(ifs);
	ifs >> m_numOfAnimals;

	m_animals = new Animal *[m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals; ++i)
	{
		Animal *a = createAnimalTxt(ifs);
		a->Load(ifs);
		m_animals[i] = a;
	}
}

void Zoo::SaveBin(ofstream &ofs) const // method to save the info to a binary file
{
	ofs.write(m_name, strlen(m_name));
	ofs.write("\n", 1);
	ofs.write(m_address, strlen(m_address));
	ofs.write("\n", 1);
	ofs.write((char *)&m_ticketPrice, sizeof(m_ticketPrice));
	ofs.write("\n", 1);
	ofs.write(m_openHours, strlen(m_openHours));
	ofs.write("\n", 1);
	ofs.write(m_closeHours, strlen(m_closeHours));
	ofs.write("\n", 1);
	ofs.write((char *)&m_numOfAnimals, sizeof(m_numOfAnimals));
	ofs.write("\n", 1);

	for (int i = 0; i < m_numOfAnimals; ++i)
		m_animals[i]->SaveBin(ofs);
}

Animal *Zoo::createAnimalBin(ifstream &in_file)
{
	Animal *retVal = NULL;
	char *type = readTextFromFile(in_file);

	if (0 == strcmp(type, fixTypeName((char *)typeid(Horse).name())))
		retVal = new Horse(in_file);

	if (0 == strcmp(type, fixTypeName((char *)typeid(Flamingo).name())))
		retVal = new Flamingo(in_file);

	if (0 == strcmp(type, fixTypeName((char *)typeid(GoldFish).name())))
		retVal = new GoldFish(in_file);

	if (0 == strcmp(type, fixTypeName((char *)typeid(Mermaid).name())))
		retVal = new Mermaid(in_file);

	delete type;

	return retVal;
}

Animal *Zoo::createAnimalTxt(ifstream &in_file)
{
	Animal *retVal = NULL;
	char *type = readTextFromFile(in_file);

	if (0 == strcmp(type, fixTypeName((char *)typeid(Horse).name())))
		retVal = new Horse();

	if (0 == strcmp(type, fixTypeName((char *)typeid(Flamingo).name())))
		retVal = new Flamingo();

	if (0 == strcmp(type, fixTypeName((char *)typeid(GoldFish).name())))
		retVal = new GoldFish();

	if (0 == strcmp(type, fixTypeName((char *)typeid(Mermaid).name())))
		retVal = new Mermaid();

	delete type;

	return retVal;
}

ofstream &operator<<(ofstream &out, const Zoo &z)
{
	z.Save(out);
	return out;
}

ifstream &operator>>(ifstream &in, Zoo &z)
{
	z.Load(in);
	return in;
}
