#include <ncurses.h>
#include <unistd.h> // for usleep
#include <Player.hpp>
#include <Apple.hpp>

using namespace PlayerNS;
using namespace AppleNS;



int main() {
	// Initialize ncurses environment
	initscr();

	// Disable line buffering
	cbreak();

	// Disable echoing of typed characters
	noecho();
	nodelay(stdscr, TRUE); // Non-blocking input
	keypad(stdscr, TRUE); // Enable special keys (like arrow keys)
	curs_set(0); // Hide cursor

	Player player{};
	Apple apple{};

	start_color(); // Enable color functionality

	#define SNAKE_PAIR 1
	#define APPLE_PAIR 2
	init_pair(SNAKE_PAIR, COLOR_GREEN, COLOR_BLACK); // Player color
	init_pair(APPLE_PAIR, COLOR_RED, COLOR_BLACK); // Apple color

	

	int wallWidth = 40;
	int wallHeight = 20;
	char wallChar = '#';

	//Draw walls
	for (int x = 0; x < wallWidth; x++) {
		mvaddch(0, x, wallChar); // Top wall
		mvaddch(wallHeight - 1, x, wallChar); // Bottom wall
	}
	for (int y = 0; y < wallHeight; y++) {
		mvaddch(y, 0, wallChar); // Left wall
		mvaddch(y, wallWidth - 1, wallChar); // Right wall
	}


	while (true) {

		// Game Code
		int input = getch();

		switch (input) {
			case 'w':
				player.setMoveDirection(3); // up
				break;
			case 'a':
				player.setMoveDirection(2); // left
				break;
			case 's':
				player.setMoveDirection(1); // down
				break;
			case 'd':
				player.setMoveDirection(0); // right
				break;
			case 'q': endwin(); return 0; // Quit game
		}


		// Clear the screen, ecept for walls
		for (int y = 1; y < wallHeight - 1; y++) {
			for (int x = 1; x < wallWidth - 1; x++) {
				mvaddch(y, x, ' ');
			}
		}

		player.movePlayer();

		pair<int, int> playerPos = player.getPosition();
		//draw head
		attron(COLOR_PAIR(SNAKE_PAIR)); // Set color for player
		mvaddch(playerPos.second, playerPos.first, player.getPlayerChar());

		// Draw player body segments && Check for intersection with player head
		for (int i = 1; i < player.getBody().size(); i++) { // exclude head (index 0)
			pair<int, int> segment = player.getBody()[i];
			mvaddch(segment.second, segment.first, player.getPlayerChar());
			if (segment == playerPos) {
				mvprintw(0, 0, "Game Over! You collided with yourself.");
				refresh();
				usleep(2000000); // Wait for 2 seconds before exiting
				endwin();
				return 0;
			}
		}

		attroff(COLOR_PAIR(SNAKE_PAIR)); // Turn off player color

		// Draw apple
		attron(COLOR_PAIR(APPLE_PAIR)); // Set color for apple
		mvaddch(apple.getPosition().second, apple.getPosition().first, apple.getAppleChar());
		attroff(COLOR_PAIR(APPLE_PAIR)); // Turn off apple color

		// Check for apple collision
		if (playerPos == apple.getPosition()) {
			player.incrementLength(); // Increase player length
			apple = Apple(); // Generate new apple
		}

			// Check for wall collision
			if (playerPos.first <= 0 || playerPos.first >= wallWidth - 1 ||
				playerPos.second <= 0 || playerPos.second >= wallHeight - 1) {
				mvprintw(0, 0, "Game Over! You hit the wall.");
				

				refresh();
				usleep(2000000); // Wait for 2 seconds before exiting
				endwin();
				return 0;
			
			}
		refresh();

		usleep(150000); // Sleep for 150ms to control game speed

	}

	endwin(); // End ncurses mode

	return 0;

}
