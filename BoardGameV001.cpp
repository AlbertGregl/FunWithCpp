#include<iostream>
using namespace std;

int main()
{
	cout << "<<<<< BOARD GAME v0.0.1 >>>>>" << endl;
	cout << "<< player: \"(|)\" / enemy: \"[#]\" / treasure: \"($)\">>" << endl;
	cout << "< movement \"w\", \"s\", \"a\", \"d\" + \"enter\" >" << endl;
	cout << endl;

	// board size
	const int SIZE = 5;

	// player coordinates
	int player_x = 1;
	int player_y = 1;

	// player movement
	char move = ' ';

	// game over
	bool game = true;

	while (game)
	{
		// game coordinates, board 5x5
		int x = 1;
		int y = SIZE;

		// update game board
		while (y >= 1)
		{
			while (x <= SIZE)
			{
				// enemy
				if (x == 2 && y == 4 || x == 4 && y == 3)
				{
					cout << "[#]" << " ";
				}
				// treasure
				else if (x == 5 && y == 5)
				{
					cout << "($)" << " ";
				}
				// update player
				else if (player_x == x && player_y == y)
				{
					cout << "(|)" << " ";
				}
				else // update board
				{
					cout << " . " << " ";
				}

				x++;
			}
			x = 1;
			cout << endl;

			y--;
		}

		// player movement update
		cout << "move: ";
		cin >> move;
		cin.ignore();
		switch (move)
		{
		case 'w':
			player_x = player_x + 0;
			player_y = player_y + 1;
			break;
		case 's':
			player_x = player_x + 0;
			player_y = player_y - 1;
			break;
		case 'a':
			player_x = player_x - 1;
			player_y = player_y + 0;
			break;
		case 'd':
			player_x = player_x + 1;
			player_y = player_y + 0;
			break;
		}

		// game over
		if (player_x < 1 || player_x > 5)
		{
			game = false;
			cout << "< GAME OVER - Player fall off >" << endl;
		}
		if (player_y < 1 || player_y > 5)
		{
			game = false;
			cout << "< GAME OVER - Player fall off >" << endl;
		}
		if (player_x == 2 && player_y == 4)
		{
			game = false;
			cout << "< GAME OVER - Player has been eaten >" << endl;
		}
		if (player_x == 4 && player_y == 3)
		{
			game = false;
			cout << "< GAME OVER - Player has been eaten >" << endl;
		}
		if (player_x == 5 && player_y == 5)
		{
			game = false;
			cout << "< YOU FOUND TREASURE!!! >" << endl;
		}
	}

	return 0;
}
