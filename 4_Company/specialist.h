#pragma once
#include "servant.h"

class Specialist : public Servant
{
	char * specialty;

	//no need of virtual because they are used from methods in this class
	void free();
	void allocate(char * specialty);


public:
	Specialist(char * name_came, char * address_cmae,char* section_came, unsigned long long id_came, double salary_came, char* specialty_came);
	Specialist(const Specialist &);
	Specialist& operator= (const Specialist&);
	virtual ~Specialist();

public:
	char* get_specialty()const;
	virtual int get_type()const; // return 2;


};