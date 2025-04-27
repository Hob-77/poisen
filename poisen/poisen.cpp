#include <iostream>
#include <random>


int poisenDamage(int health)
{

	return health - 5;

}

int medKit(int health)
{

	return health + 10;

}


int main()
{
	int playerHealth{ 50 };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> chance(1, 100);

	
	while (playerHealth > 0)
	{
		playerHealth = poisenDamage(playerHealth);
		std::cout << "you took poisen damage, your health is now: " << playerHealth << "\n";

		int roll = chance(gen);
		if (roll >= 80)
		{
			std::cout << "you found a medkit" << "\n";
			playerHealth = medKit(playerHealth);
		}
		else
		{
			std::cout << "no medkit for you" << "\n";
		}
	}

	std::cout << "you have died from poisen. yeah mhmm" << "\n";

	return 0;

}