#include <curses.h>

// http://www.cs.ukzn.ac.za/~hughm/os/notes/ncurses.html
// http://www.melvilletheatre.com/articles/ncurses-extended-characters/index.html

void	init_ncurses(void)
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
}

void	destroy_ncurses(void)
{
	endwin();
}

int		play_game(void)
{
	int			ch = getch();
	static int	cursor_x = 0;
	static int	cursor_y = 0;
	int			row, col;

	werase(stdscr);
	getmaxyx(stdscr, row, col);
	switch (ch) {
	case 'q':
		return (0);
	case KEY_UP:
		if (cursor_y > 0)
			cursor_y--;
		break;
	case KEY_DOWN:
		if (cursor_y < row - 1)
			cursor_y++;
		break;
	case KEY_LEFT:
		if (cursor_x > 0)
			cursor_x--;
		break;
	case KEY_RIGHT:
		if (cursor_x < col - 1)
			cursor_x++;
		break;
	}
	wmove(stdscr, cursor_y, cursor_x);
	waddch(stdscr, ACS_UARROW | A_ALTCHARSET | A_REVERSE);
	wrefresh(stdscr);
	return (1);
}

int main(void)
{
	init_ncurses();
	while (play_game())
		;
	destroy_ncurses();
}