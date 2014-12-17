#ifndef _FIELD_MASTER_H_
#define _FIELD_MASTER_H_

// forward declaration 
class Polyhedron;

/** 
*  Encapsualte analysis and manipulation of vector and tensor field.
*  \a Polyhedron is responsible for holding tensor data. \a FieldMaster is
*  analysis and manipulation of the field. Seperate data and manipulation into 
*  different classes to prevent the Polyhedron class becomming a huge class. 
*/
class FieldMaster
{

private:
	Polyhedron* mPoly;
	static FieldMaster* mSingle; // for singleton

	FieldMaster()
	{
		mPoly = NULL;
	}

	FieldMaster(Polyhedron* poly)
	{
		mPoly = poly;
	}

public:

	FieldMaster* getInstance() // for singleton
	{
		if(!mSingle)
			mSingle = new FieldMaster;
		return mSingle;
	}

	FieldMaster* getInstance(Polyhedron* poly) // for singleton
	{
		if(!mSingle)
			mSingle = new FieldMaster(poly);
		return mSingle;
	}

	FieldMaster* getMaster()
	{
		return mSingle;
	}

	void setPoly(Polyhedron* poly)
	{
		mPoly = poly;
	}

	/**
	*  Initialize polyhedron.
	*  Set up triangle local frame.
	*/
	void initPoly();

};

#endif//_FIELD_MASTER_H_
