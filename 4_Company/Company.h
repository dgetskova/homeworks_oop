#pragma once
#include "manager.h"

const int type_servant = 1;
const int type_specilist = 2;
const int type_manager = 3;

class Company
{
	/*int* servants_salary;
	int servats_size;
	int servants_need;
	Servant ** company_new;*/
	Servant** company_old;
	int company_old_size;


	void free()
	{
		delete[] company_old;
		//delete[] company_new;
	}
	void allocate(Servant** company, int company_size)
	{
		//company_new = NULL;
		company_old = NULL;

		company_old_size = company_size;
		try{
			company_old = new Servant*[company_old_size];
		} catch (std::bad_alloc)
		{
			free();
			throw;
		}
		for (size_t i = 0; i < company_old_size; i++)
		{
			company_old[i] = company[i];
		}
	}
	bool check_servant(int count_servants_need);
	bool chech_specialists(int count_specialist, char* want_specialist);
	bool Company::chech_section(int count_section, char* section_want);

public:
	Company(Servant** company, int company_size)
	{
		allocate(company, company_size);
	}
	bool can_make_company(int count_servants_need, int count_specialists, char* want_specialist, int count_section,char* section_want)
	{
		if (check_servant(count_servants_need) && chech_specialists(count_specialists, want_specialist) &&
			chech_section(count_section, section_want))
			return true;
		return false;
	}
};


bool Company::check_servant(int count_servants_need)
{
	bool check_servant_return = false;
	int count_servants_current = 0;
	for (size_t i = 0; i < company_old_size; i++)
	{
		if (company_old[i]->get_type() == type_servant)
		{
			count_servants_current++;
		}
	}
	// zadelqm si masiv ot int za da si pazq poziciite za elementite, v koito imam servants
	count_servants_current = 0;

	for (size_t i = 0; i < company_old_size; i++)
	{
		if (company_old[i]->get_type() == type_servant)
		{
			count_servants_current++;
			if (count_servants_current >= count_servants_need)
				check_servant_return = true;
			//da si pazq poziciite v masiv za poziciite za servants 
		}
	}
	return check_servant_return;
}


bool Company::chech_specialists(int count_specialist, char* want_specialist)
{
	int current_cpunt_spec = 0;
	Specialist* pointer_spec = NULL;
	for (size_t i = 0; i < company_old_size; i++)
	{
		if (company_old[i]->get_type() == type_specilist)
		{
			pointer_spec = (Specialist*)company_old[i];
			if (!strcmp(pointer_spec->get_specialty(), want_specialist))
			{
				current_cpunt_spec++;
				if (current_cpunt_spec >= count_specialist)
					return true;
			}
		}
	}
	return false;
}

bool Company::chech_section(int count_section, char* section_want)
{
	int current_count_sections = 0;
	Manager* pointer_manager = NULL;
	for (size_t i = 0; i < company_old_size; i++)
	{
		if (company_old[i]->get_type() == type_manager)
		{
			pointer_manager = (Manager*)company_old[i];
			if (!strcmp(pointer_manager->get_section(), section_want))
			{
				current_count_sections++;
				if (current_count_sections >= count_section)
					return true;
			}
		}
	}
	return false;
}