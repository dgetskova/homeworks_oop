//#include "Manager.h" // izlishno e da vkliuchvam cqloto
#pragma once

class Secretary
{
private:
	char** languages;
	int count_languages;
	void free()
	{
		for (size_t i = 0; i < count_languages; i++)
			delete languages[i];
		delete[]languages;
	}
	void allocate(char**languages_came, int count_languages_came)
	{
		languages = NULL;
		count_languages = count_languages_came;
		try{
			languages = new char*[count_languages];

			for (size_t i = 0; i < count_languages; i++)
			{
				languages[i] = NULL;
				int size_elem = strlen(languages_came[i]) + 1;
				languages[i] = new char[size_elem];
				strncpy_s(languages[i], size_elem, languages_came[i], size_elem);
			}
		}
		catch (std::bad_alloc)
		{
			free();
			throw"No allocate object Secretary";
		}
	}

public:
	Secretary()
	{
		languages = NULL;
		count_languages = 0;
	}
	Secretary(char**languages_came, int count_languages_came)
	{
		allocate(languages_came, count_languages_came);
	}

	Secretary(const Secretary& other)
	{
		allocate(other.languages,other.count_languages);
	}
	~Secretary()
	{
		free();
	}
	Secretary& operator = (const Secretary& other)
	{
		if (this != &other)
		{
			free();
			allocate(other.languages, other.count_languages);
		}
		return *this;
	}
	
};