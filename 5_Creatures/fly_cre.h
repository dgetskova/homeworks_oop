#pragma once
#include "creature.h"

class flying_creature : virtual public Creature
{
protected:
	int fly_height;
	int  number_wings;
	bool in_air;

protected:
	//za naslednicite 
	//-- ako nasledqvaneto e  virtualno ot tuk konstruktora na Creature nqma da se izvika
	//-- ako ne e virtualno nasledqvaneto se vika flying -> creature
	flying_creature(int flyHeight_came, int  number_wings_came, bool inAir_came) :Creature(0,0,0)

	{
		fly_height = flyHeight_came;

		number_wings = number_wings_came;

		in_air = inAir_came;
	}


public:
	
	flying_creature(int h, int m, int d, int flyHeight_came, int  number_wings_came, bool inAir_came) : Creature(h, m, d*number_wings_came)
	{
	
		fly_height = flyHeight_came;

		number_wings = number_wings_came;

		in_air = inAir_came;

	}
	virtual ~flying_creature(){}

	bool fly()
	{
		if (mana > 20)
		{
			in_air = true;
			damage = damage *0.4 * fly_height;
			mana = mana - 20;
			return true;
		}
		return false;
	}

	void attack(Creature& other)
	{

		if (in_air == false)// na zemqta e 
		{
			if (fly())
			{
				other.set_health(other.get_h() - damage / 2); // zashtoto samiqt ukazatel ni e Derived
				damage = (damage / 0.4) / fly_height;
				in_air = false;
				return;
			}
		}
		//vyv vuzduha e 
		other.set_health(other.get_h() - damage / 2);
		damage = (damage / 0.4) / fly_height;
		in_air = false;
	}
	
};