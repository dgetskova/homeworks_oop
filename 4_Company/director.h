#include "Manager.h"
#include "Secretary.h"

class Director
{
	Secretary secretary;
	Servant** all_servants;
	int count_servants;


	void allocate(Secretary & secretary_came, Servant** all_servants_came, int count_servants_came)
	{
		count_servants = count_servants_came;
		try{
			//secretary_came = new Secretary(); // dali da bude taka
			all_servants = new Servant*[count_servants];
		}
		catch (std::bad_alloc)
		{
			free();
			throw"No object Director";
		}

		secretary = secretary_came; // dali nqma da izchqzne
		for (size_t i = 0; i < count_servants; i++)
		{
			all_servants[i] = all_servants_came[i];
		}
	}

	void free()
	{
		delete []all_servants;

	}
	
public:
	Director(Secretary &secretary_came, Servant** all_servants_came, int count_servants_came)
	{
		allocate(secretary_came, all_servants_came, count_servants_came);
	}

	~Director()
	{
		free();

	}

	long double get_all_salary()
	{
		long double result = 0;
		for (size_t i = 0; i < count_servants; i++)
		{
			result += all_servants[i]->get_salary();
		}
		return result;
	}
};