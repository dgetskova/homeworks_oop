#pragma once
#include <iostream>

class Servant
{
private :
	char * name;
	char * address;
	char* section;
	unsigned long long id ; // max - 18446744073709551615
	double salary;

	void free();
	void allocate(char * name_came, char * address_came, char* section);

public:
	Servant();
	Servant(char * name_came, char * address_cmae, char* section, unsigned long long id_came, double salary_came);
	virtual ~Servant();
	Servant(const Servant &);
	Servant& operator=(const Servant &);

public:
	double get_salary()const;
	virtual int get_type()const; // return 1;
	char* get_section()const;


};