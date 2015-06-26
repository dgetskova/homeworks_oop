#include "creature.h"
#include "fly_cre.h"
#include "flame.h"
#include "dragon.h"
#include "army.h"

int main()
{
	flame_breathing_creature flame(10, 30, 40, 1);
	flying_creature fly(1,2,3,4,5,false);
	fly.attack(flame);

	Dragon dragon(1, 2, 3, 4, 5, false, 100, "black", 8);
	Dragon dragon1(0, 0, 0, 0, 0, true, 0, "add", 0);
	dragon1 = dragon;

	Creature** creatures = new Creature*[3];
	creatures[0] = &flame;
	creatures[1] = &flame;
	creatures[2] = &fly;

	Army a(creatures, 3);
	a.add(flame);

	delete[]creatures;
	
}