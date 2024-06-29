#include "Horse.h"

Horse::Horse() // set the default color to GRAY and other params to 0-
	: Animal(),
	  Mammals(),
	  m_type(NULL)
{
}
Horse::Horse(const char *color, int childs, float avgLifetime, float preg, float milk, const char *type) // init the Horse with a given attributes
	: Animal(color, childs, avgLifetime),
	  Mammals(color, childs, avgLifetime, preg, milk)
{
	m_type = strdup(type);
}

Horse::Horse(ifstream &in_file) // init the Horse from a binary file
	: Animal(in_file),
	  Mammals(in_file)
{
	m_type = readTextFromFile(in_file);
}

Horse::Horse(const Horse &other)
	: Animal(other),
	  Mammals(other)
{
	m_type = strdup(other.m_type);
}

Horse::~Horse()
{
	if (m_type)
		delete m_type;

	m_type = NULL;
}

void Horse::Load(ifstream &in_file) // load the data from a text file
{
	Mammals::Load(in_file);
	m_type = readTextFromFile(in_file);
}

void Horse::Save(ofstream &out_file) const // saves the data to a text file
{
	Mammals::Save(out_file);
	out_file << m_type << endl;
}

void Horse::SaveBin(ofstream &out_file) const // saves the data to a binary file
{
	Mammals::SaveBin(out_file);
	out_file.write(m_type, strlen(m_type));
	out_file.write("\n", 1);
}
