#pragma once
#include  "creature.h"

class flame_breathing_creature :virtual public Creature
{
protected:
	int temp_of_fire;

	flame_breathing_creature(int temp) :Creature(0, 0, 0)
	{
		temp_of_fire = temp;

	}
public:

	flame_breathing_creature(int h, int m, int d, int temp) : Creature(h,m,d)
	{
		temp_of_fire = temp;

	}
	virtual ~flame_breathing_creature(){ ; }
	bool BreatheIn()
	{
		if (mana >= 50)
		{
			damage = temp_of_fire * damage;
			mana -= 50;
			return true;
		}
		return false;
	}

	virtual void attack(Creature& other)
	{
		if (BreatheIn())
		{
			other.set_health(other.get_h() - damage);
			damage = damage / temp_of_fire;
		}
		else{
			other.set_health(other.get_h() - damage);
		}
	}
};