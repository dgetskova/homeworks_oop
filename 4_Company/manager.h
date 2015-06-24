#pragma once
#include "Specialist.h"

class Manager : public Specialist
{
private:
	char* info_section;
	Servant** servants;
	int size_servants;
	
	void free();
	void allocate(char *info_section_came, Servant** servants_came, int size_servants_came);

public:
	Manager(char * name_came, char * address_came, char* section_came, unsigned long long id_came, double salary_came, char* specialty_came,
		char *info_section_came, Servant** servants_came, int size_servants_came);

	virtual ~Manager();
	Manager(const Manager&);
	Manager& operator=(const Manager&);

public:
	
	virtual int get_type()const;//return 3
	char* get_section()const;

};