#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <time.h>
#include <cmath>
#include "object.h"

const int WIDTH = 50;
const int HEIGHT = 40;
const int MAX_ENEMIES = 20;
const int ENEMY_SPEED = 1;

int main() {
    // Initialize ncurses
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    // Seed the random number generator
    srand(time(0));

    // Initialize the player
    object player(WIDTH / 2, HEIGHT - 1);

    // Initialize the missile
    object missile(WIDTH / 2, HEIGHT - 1);

    // Initialize the enemies
    object enemies[MAX_ENEMIES];
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].setX(rand() % WIDTH);
        enemies[i].setY(1);
        enemies[i].setLive(true);
    }

    // Game loop
    while (true) {
        // Clear the screen
        clear();

        // Draw the player
        mvaddch(player.getY(), player.getX(), '^');

        // Draw the enemies
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].isLive()) {
                mvaddch(enemies[i].getY(), enemies[i].getX(), 'W');
            }
        }

        // Move the enemies
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (enemies[i].isLive()) {
                enemies[i].setY(enemies[i].getY() + ENEMY_SPEED);
                if (enemies[i].getY() > HEIGHT) {
                    enemies[i].setLive(false);
                }
            }
        }

        // Check for player input
        int ch = getch();
        switch (ch) {
            case KEY_LEFT:
                player.moveLeft();
                break;
            case KEY_RIGHT:
                player.moveRight();
                break;
	    case ' ':
		if(!missile.isLive()){
			missile.setLive(true);
                	missile.setX(player.getX());
                	missile.setY(player.getY());
		}
		break;
	}


        // Boundary check for player position
        if (player.getX() < 0) {
            player.setX(0);
        }
        if (player.getX() >= WIDTH) {
            player.setX(WIDTH - 1);
        }

	if(missile.isLive())
        {
                //draw the missile
		for (int i = 0; i < MAX_ENEMIES; i++) {
            		if (enemies[i].isLive()) {
                		if (enemies[i].getY() == missile.getY() &&
					enemies[i].getX() == missile.getX()) {
                    			enemies[i].setLive(false);
					missile.setLive(false);
				}
			}
		}
		mvaddch(missile.getY(), missile.getX(), '*');
                missile.moveUp();
		if(missile.getY() < enemies[0].getY()){
			missile.setLive(false);
		}
        }

        // Refresh the screen
        refresh();

        // Sleep for a short time
        usleep(200000);
    }

    // Clean up ncursed
    endwin();

    return 0;
}
