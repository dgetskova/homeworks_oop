#include "dragon.h"

class Army
{
private:
	Creature ** army;
	int size;
	int capasity;
	void free()
	{
		delete[]army;
	}
	
	void allocate(Creature** army_came, int size_came)
	{
		army = NULL;
		capasity = size = size_came;

		try{
			army = new Creature*[size];
		}
		catch (std::bad_alloc)
		{
			free();
			throw "no object for Army.";
		}
		for (size_t i = 0; i < size; i++)
		{
			army[i] = army_came[i];
		}

	}
	void resize()
	{
		Creature** temp = NULL;
		int new_size = size * 2;
		try{
			temp = new Creature*[new_size];
		}
		catch (std::bad_alloc)
		{
			delete[]temp;
		}
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = army[i];
		}
		free();
		army = temp;
		capasity = new_size;
	}

public:

	Army(Creature** army_came, int size_came)
	{
		allocate(army_came, size_came);
	}

	virtual ~Army()
	{
		free();
	}

	void add(Creature&other)
	{
		if (size > capasity)
		{
			army[size] = &other;
		}
		else{
			resize();
			army[size] = &other;
		}
	}

	Creature& remove() // remove first element and returns it back
	{
		Creature *temp = army[0];
		
		for (size_t i = 0; i < size-1; i++)
		{
			army[i] = army[i + 1];
		}
		size = size - 1;
		return *temp;
	}

	void buffArmy()
	{
		for (size_t i = 0; i < size; i++)
		{
			army[i]->set_health(army[i]->get_h() + 10);
		}
	}

	bool battle(Army& defender)
	{
		for (size_t i = 0; i < size; i++)
		{
			defender.buffArmy();
			army[i]->attack(defender.get_elem_army(i));
		}
	}

	Creature & get_elem_army(int pos)const
	{
		if (pos<size)
		return *army[pos];
	}
};