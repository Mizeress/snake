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

		erase(); // Clear the screen

		player.movePlayer();

		pair<int, int> playerPos = player.getPosition();
		//draw head
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

		// Draw apple
		mvaddch(apple.getPosition().second, apple.getPosition().first, apple.getAppleChar());

		// Check for apple collision
		if (playerPos == apple.getPosition()) {
			player.incrementLength(); // Increase player length
			apple = Apple(); // Generate new apple
		}
		
		refresh();

		usleep(100000); // Sleep for 100ms to control game speed

	}

	endwin(); // End ncurses mode

	return 0;

}
