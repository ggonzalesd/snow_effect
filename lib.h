#include <ncurses.h>

char KEY = -1;
int MX, MY;
int MXL, MYL;

int XR = -1;
int YR = -1;
bool SCREEN_SIZE = true;

bool RESIZED;
long TIME = 0;

void GInit(){
    initscr();
	cbreak();
	// keypad(stdscr, TRUE);
    noecho(); // No repetir Getch
    curs_set(0); // Ocultar El Cursor
	timeout(0);
}

void GEnd(){
	endwin();
}

void Gloop(int sleep_){
	
	MXL = MX;
	MYL = MY;
	
	getmaxyx(stdscr, MY, MX);

	RESIZED = (MXL!=MX) + (MYL!=MY);

	SCREEN_SIZE = false;
	if(XR == -1 && YR == -1 ) SCREEN_SIZE = true;
	else if(MY>=YR && MX>=XR) SCREEN_SIZE = true;

	refresh();
	napms(sleep_);
	TIME++;

	KEY = getch();
}
