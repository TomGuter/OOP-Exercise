#include "Animal.h"

Animal::Animal() // set the default color to GRAY and other params to 0
	: m_childCount(0),
	  m_avgLifetime(0.f)
{
	m_color = strdup("GRAY");
}

Animal::Animal(const char *color, int childs, float avgLifetime) // init the Animal with a given attributes
	: m_childCount(childs),
	  m_avgLifetime(avgLifetime)
{
	m_color = strdup(color);
}

Animal::Animal(ifstream &in_file) // init the Animal from a binary file
{
	char c; // to read the '\n' that we wrote
	m_color = readTextFromFile(in_file);
	in_file.read((char *)&m_childCount, sizeof(m_childCount));
	in_file.read(&c, 1);
	in_file.read((char *)&m_avgLifetime, sizeof(m_avgLifetime));
	in_file.read(&c, 1);
}

Animal::Animal(const Animal &other)
{
	m_color = strdup(other.m_color);
	m_childCount = other.m_childCount;
	m_avgLifetime = other.m_avgLifetime;
}

Animal::~Animal()
{
	if (m_color)
		delete m_color;

	m_color = NULL;
}

void Animal::Load(ifstream &in_file) // load the data from a text file
{
	m_color = readTextFromFile(in_file);
	in_file >> m_childCount;
	in_file >> m_avgLifetime;
}

void Animal::Save(ofstream &out_file) const // saves the data to a text file
{
	SaveType(out_file);
	out_file << m_color << endl;
	out_file << m_childCount << endl;
	out_file << m_avgLifetime << endl;
}

void Animal::SaveType(ofstream &out_file) const // saves the type to a text file
{
	out_file << GetTypeName() << endl;
}

void Animal::SaveBin(ofstream &out_file) const // saves the data to a binary file
{
	SaveTypeBin(out_file);
	out_file.write(m_color, strlen(m_color));
	out_file.write("\n", 1);
	out_file.write((char *)&m_childCount, sizeof(m_childCount));
	out_file.write("\n", 1);
	out_file.write((char *)&m_avgLifetime, sizeof(m_avgLifetime));
	out_file.write("\n", 1);
}

void Animal::SaveTypeBin(ofstream &out_file) const // saves the type to a binary file
{
	char type[20] = {0};
	strcpy(type, GetTypeName());
	out_file.write((const char *)type, strlen(type));
	out_file.write("\n", 1);
}

char *Animal::GetTypeName() const
{
	return fixTypeName((char *)typeid(*this).name());
}

char *readTextFromFile(ifstream &in_file)
{
	char str[256] = {0};
	while (0 == strlen(str))
		in_file.getline(str, 256, '\n');

	return strdup(str);
}

char *fixTypeName(char *name)
{
	if ('0' <= name[0] && name[0] <= '9')
		return (char *)(name + 1);

	return (char *)(name + 6);
}