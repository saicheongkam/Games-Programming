#pragma once

class Player
{
private:
	

public:
	Player();

	bool alive;

	char input;

	int PosX;
	int PosY;

	void MoveNorth();
	void MoveEast();
	void MoveSouth();
	void MoveWest();
};


class World
{
private:
	bool win;
	
public:
	World();	

	char map[9][8];/*= { { '#', '#', '#', '#', '#', '#', '#', '#' },
						{ '#', 'G', ' ', 'D', '#', 'D', ' ', '#' },
						{ '#', ' ', ' ', ' ', '#', ' ', ' ', '#' },
						{ '#', '#', '#', ' ', '#', ' ', 'D', '#' },
						{ '#', ' ', ' ', ' ', '#', ' ', ' ', '#' },
						{ '#', ' ', '#', '#', '#', '#', ' ', '#' },
						{ '#', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
						{ '#', '#', 'S', '#', '#', '#', '#', '#' },
						{ '#', '#', '#', '#', '#', '#', '#', '#' } };*/
	Player player;

	bool quit;

	void Update();
};

