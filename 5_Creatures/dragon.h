#pragma once
#include "flame.h"
#include "fly_cre.h"

class Dragon : public flying_creature, public flame_breathing_creature
{
	char * color; 
	double armor;

	void free()
	{
		delete []color;
		color = NULL;
	}
	void allocate(char *color_came, int armor_came)
	{
		color = NULL;
		int size_color = strlen(color_came) + 1;
		try{
			color = new char[size_color];
		}
		catch (bad_alloc)
		{
			free();
		}
		strncpy_s(color, size_color, color_came, size_color);
		armor = armor_came;
	}

public:

	Dragon(int h, int m, int d, int  fly_height, int  number_wings,	bool in_air,int temp_flame, char * color, int armor): Creature(h, m, d),
		flame_breathing_creature(temp_flame), flying_creature(fly_height, number_wings, in_air)
	{
		allocate(color, armor);

		if (strcmp(color, "black"))
			damage = d + 10;
		else
			damage = d;
		if (strcmp(color, "white"))
			health = h + 10;
		else
			health = h;
		if (strcmp(color, "white"))
			mana = m + 10;
		else
			mana = m;

	}

	Dragon(const Dragon& other) : Creature(other.health, other.mana, other.damage),
		flying_creature(other.fly_height, other.number_wings, other.in_air),
		flame_breathing_creature(other.temp_of_fire)
	{

		allocate(other.color, other.armor);
	}

	Dragon& operator= (const Dragon& other)
	{
		if (this != &other)
		{
			flying_creature::operator=(other);
			flame_breathing_creature::operator=(other);

			free();
			allocate(other.color, other.armor);
		}
		return*this;
	}

	virtual ~Dragon()
	{
		free();
	}

	virtual void attack(Creature& other)
	{
		other.set_health(other.get_h() - damage);
	}
};