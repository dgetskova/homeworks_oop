#pragma once
#include <iostream>
using namespace std;

class Creature
{
protected:
	int health;
	int mana;
	int damage;

public:
	Creature(int h=0, int m=0, int d=0) : health(h), mana(m), damage(d){}
	virtual ~Creature(){}

	void dealDamage(Creature & other)
	{
		health = health - other.damage;

	}

	virtual void attack(Creature& other)= 0;

	int get_demage()const
	{
		return damage;
	}
	int get_h()const
	{
		return health;
	}
	int get_m()const
	{
		return mana;
	}

	void set_health(int h)
	{
		health = h;
	}
	void set_damage(int h)
	{
		damage = h;
	}
	void set_mana(int h)
	{
		mana = h;
	}
	
};