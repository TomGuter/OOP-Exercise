#include "Flamingo.h"

Flamingo::Flamingo() // set the default color to GRAY and other params to 0
	: Animal(),
	  Birds(),
	  m_avgHeight(0.f)
{
}

Flamingo::Flamingo(const char *color, int childs, float avgLifetime, float incubation, float avgHeight) // init the Flamingo with a given attributes
	: Animal(color, childs, avgLifetime),
	  Birds(color, childs, avgLifetime, incubation),
	  m_avgHeight(avgHeight)
{
}

Flamingo::Flamingo(ifstream &in_file) // init the Flamingo from a binary file
	: Animal(in_file),
	  Birds(in_file)
{
	char c; // to read the '\n' that we wrote
	in_file.read((char *)&m_avgHeight, sizeof(m_avgHeight));
	in_file.read(&c, 1);
}

Flamingo::Flamingo(const Flamingo &other)
	: Animal(other),
	  Birds(other)
{
	m_avgHeight = other.m_avgHeight;
}

Flamingo::~Flamingo()
{
}

void Flamingo::Load(ifstream &in_file) // load the data from a text file
{
	Birds::Load(in_file);
	in_file >> m_avgHeight;
}

void Flamingo::Save(ofstream &out_file) const // saves the data to a text file
{
	Birds::Save(out_file);
	out_file << m_avgHeight << endl;
}

void Flamingo::SaveBin(ofstream &out_file) const // saves the data to a binary file
{
	Birds::SaveBin(out_file);
	out_file.write((char *)&m_avgHeight, sizeof(m_avgHeight));
	out_file.write("\n", 1);
}
