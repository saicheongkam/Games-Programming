#include "GridWorld.h"
#include <iostream>

using namespace std;

World::World()
{
	win = false;
	quit = false;
	player = Player();

	map[0][0] = '#';
	map[0][1] = '#';
	map[0][2] = '#';
	map[0][3] = '#';
	map[0][4] = '#';
	map[0][5] = '#';
	map[0][6] = '#';
	map[0][7] = '#';

	map[1][0] = '#';
	map[1][1] = 'G';
	map[1][2] = ' ';
	map[1][3] = 'D';
	map[1][4] = '#';
	map[1][5] = 'D';
	map[1][6] = ' ';
	map[1][7] = '#';

	map[2][0] = '#';
	map[2][1] = ' ';
	map[2][2] = ' ';
	map[2][3] = ' ';
	map[2][4] = '#';
	map[2][5] = ' ';
	map[2][6] = ' ';
	map[2][7] = '#';

	map[3][0] = '#';
	map[3][1] = '#';
	map[3][2] = '#';
	map[3][3] = ' ';
	map[3][4] = '#';
	map[3][5] = ' ';
	map[3][6] = 'D';
	map[3][7] = '#';

	map[4][0] = '#';
	map[4][1] = ' ';
	map[4][2] = ' ';
	map[4][3] = ' ';
	map[4][4] = '#';
	map[4][5] = ' ';
	map[4][6] = ' ';
	map[4][7] = '#';

	map[5][0] = '#';
	map[5][1] = ' ';
	map[5][2] = '#';
	map[5][3] = '#';
	map[5][4] = '#';
	map[5][5] = '#';
	map[5][6] = ' ';
	map[5][7] = '#';

	map[6][0] = '#';
	map[6][1] = ' ';
	map[6][2] = ' ';
	map[6][3] = ' ';
	map[6][4] = ' ';
	map[6][5] = ' ';
	map[6][6] = ' ';
	map[6][7] = '#';

	map[7][0] = '#';
	map[7][1] = '#';
	map[7][2] = 'S';
	map[7][3] = '#';
	map[7][4] = '#';
	map[7][5] = '#';
	map[7][6] = '#';
	map[7][7] = '#';

	map[8][0] = '#';
	map[8][1] = '#';
	map[8][2] = '#';
	map[8][3] = '#';
	map[8][4] = '#';
	map[8][5] = '#';
	map[8][6] = '#';
	map[8][7] = '#';
}

void World::Update()
{
	if (toupper(player.input) == 'Q')
		quit = true;

	if ((player.alive == true) && (win == false))
	{
		if (map[player.PosY][player.PosX] == 'D')
		{
			player.alive = false;
			cout << "YOU HAVE DIED!" << endl;
		}
		else if (map[player.PosY][player.PosX] == 'G')
		{
			win = true;
			cout << "Wow - you've discovered a large chest filled with GOLD coins!" << endl;
			cout << "YOU WIN!" << endl;
		}
		else if ((player.input != ' ') && (toupper(player.input) != 'Q'))
		{
			cout << "You can move";

			if (map[player.PosY - 1][player.PosX] != '#')
				cout << " N";
			if (map[player.PosY][player.PosX + 1] != '#')
				cout << " E";
			if (map[player.PosY + 1][player.PosX] != '#')
				cout << " S";
			if (map[player.PosY][player.PosX - 1] != '#')
				cout << " W";
		
			cout << ": ";
			player.input = ' ';
		}
	}
}

Player::Player()
{
	alive = true;

	PosX = 2;
	PosY = 7;
}

void Player::MoveNorth()
{
	PosY--;
}

void Player::MoveEast()
{
	PosX++;
}

void Player::MoveSouth()
{
	PosY++;
}

void Player::MoveWest()
{
	PosX--;
}

