#include <asm-generic/ioctls.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

unsigned int WIDTH;
unsigned int HEIGHT;
unsigned int C_X;
unsigned int C_Y;

void clearScreen();
void fillScreen(int r, int g, int b);
void pollKeys();

int main() {
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	printf("Width: %d, Height: %d\n", w.ws_col, w.ws_row);
	WIDTH = w.ws_col;
	HEIGHT = w.ws_row;
	C_X = 0;
	C_Y = 0;
	clearScreen();
	fillScreen(120, 0, 120);
	printf("\x1b[%d;%dH", C_X, C_Y);
	// 	pollKeys();
	// printf("\x1b[31mHello World!\n");
	// while(1){
	// 	clearScreen();
	// 	fillScreen(120, 0, 120);
	// 	printf("\x1b[1A");
	// 	pollKeys();
	// }
	return 0;
}

void clearScreen() {
	printf("\x1b[2J");
}

void fillScreen(int r, int g, int b) {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			printf("\x1b[48;2;%d;%d;%dm", r, g, b);
		}
		if (i < WIDTH - 1) {
			printf("\n");
		}
	}
}

void pollKeys() {

}
