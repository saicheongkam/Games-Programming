#include "GridWorld.h"
#include <iostream>
#include <thread>

using namespace std;

static World world;

void Update()
{
	while (!world.quit)
		world.Update();
}

void Input()
{
	while (!world.quit)
	{
		cin >> world.player.input;

		switch (toupper(world.player.input))
		{
		case 'N':
			if (world.map[world.player.PosY - 1][world.player.PosX] != '#')
				world.player.MoveNorth();
			break;
		case 'E':
			if (world.map[world.player.PosY][world.player.PosX + 1] != '#')
				world.player.MoveEast();
			break;
		case 'S':
			if (world.map[world.player.PosY + 1][world.player.PosX] != '#')
				world.player.MoveSouth();
			break;
		case 'W':
			if (world.map[world.player.PosY][world.player.PosX - 1] != '#')
				world.player.MoveWest();
			break;
		}
	}
}

int main()
{
	World world = World();

	cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for You!" << endl;
	cout << "Valid commands: N, E, S and W for direction. Q to quit the game." << endl;

	cout << endl << "Map:" << endl;
	for (int j = 0; j <= 7; j++)
	{
		for (int i = 0; i <= 7; i++)
			cout << world.map[j][i];

		cout << endl;
	}
	cout << endl;

	thread inputThread(Input);
	thread updateThread(Update);
	
	
	inputThread.join();
	updateThread.join();

	/*char input = ' ';

	while (toupper(input) != 'Q')
	{
		world.Update();

		cin >> input;

		switch (toupper(input))
		{
		case 'N':
			if (world.map[world.player.PosY - 1][world.player.PosX] != '#')
				world.player.MoveNorth();
			break;
		case 'E':
			if (world.map[world.player.PosY][world.player.PosX + 1] != '#')
				world.player.MoveEast();
			break;
		case 'S':
			if (world.map[world.player.PosY + 1][world.player.PosX] != '#')
				world.player.MoveSouth();
			break;
		case 'W':
			if (world.map[world.player.PosY][world.player.PosX - 1] != '#')
				world.player.MoveWest();
			break;
		}
	}*/
}