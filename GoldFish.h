#ifndef GOLDFISH_H
#define GOLDFISH_H

#include "MammalsFish.h"

class GoldFish : public MammalsFish
{
public:
	GoldFish();//set the default color to GRAY and other params to 0
	GoldFish( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL );//init the GoldFish with a given attributes
	GoldFish( ifstream& in_file );//init the GoldFish from a binary file
	GoldFish( const GoldFish& other );
	virtual ~GoldFish();

public:
	float		GetWeight() const { return m_avgWeight; }//return the avg weight of the gold fish
	float		GetLength() const { return m_avgLength; }//return the avg length of the gold fish

public:
	virtual void Load( ifstream& in_file );//load the data from a text file
	virtual void Save( ofstream& out_file ) const;//saves the data to a text file

public:
	virtual void SaveBin( ofstream& out_file ) const;//saves the data to a binary file

protected:
	float m_avgWeight;
	float m_avgLength;
};

#endif // ifndef