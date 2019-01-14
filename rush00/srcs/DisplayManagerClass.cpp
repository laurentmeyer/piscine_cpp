#include "DisplayManagerClass.hpp"
#include "GameManagerClass.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <unistd.h>

int		DisplayManager::_rows = 0;
int		DisplayManager::_cols = 0;
std::string		DisplayManager::_quitMsg;
WINDOW	*DisplayManager::_gameWindow;
WINDOW	*DisplayManager::_scoreWindow;

DisplayManager::DisplayManager(void)
{
	return;
}

DisplayManager::~DisplayManager(void)
{
	return;
}

void		DisplayManager::pixelPut(size_t x, size_t y, chtype curse)
{
	Framebuffer::set(y * DisplayManager::_cols + x, curse);
}

void		DisplayManager::init(void)
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_GREEN, 0);
	// keypad(stdscr, TRUE);
	getmaxyx(stdscr, DisplayManager::_rows, DisplayManager::_cols);
	DisplayManager::_scoreWindow = subwin(stdscr, 3, DisplayManager::_cols, 0, 0);
	DisplayManager::_gameWindow = subwin(stdscr, DisplayManager::_rows - 3, DisplayManager::_cols, 3, 0);
	// DisplayManager::_scoreWindow = newwin(3, DisplayManager::_cols - 1, 0, 0);
	// DisplayManager::_gameWindow = newwin(DisplayManager::_rows - 3 - 1, DisplayManager::_cols - 1, 3, 0);
	DisplayManager::_rows -= 3 + 2;
	DisplayManager::_cols -= 2;
	nodelay(stdscr, TRUE);
	Framebuffer::init(DisplayManager::_rows, DisplayManager::_cols);
}

void		DisplayManager::clear(void)
{
	werase(DisplayManager::_gameWindow);
	werase(DisplayManager::_scoreWindow);
	box(DisplayManager::_scoreWindow, ACS_VLINE, ACS_HLINE);
	box(DisplayManager::_gameWindow, ACS_VLINE, ACS_HLINE);
	Framebuffer::clear();
}

void DisplayManager::update(void)
{
	int row;
	int col;
	int rows = DisplayManager::_rows;
	int cols = DisplayManager::_cols;
	chtype		c;
	std::ostringstream	stats;

	getmaxyx(stdscr, row, col);
	if (row != DisplayManager::_rows + 5 || col != DisplayManager::_cols + 2) 
		GameManager::quit("You are not allowed to resize the window !");

	stats << "TIME: " << std::setprecision(2) << std::fixed << Time::sinceStart();
	stats << " SCORE: " << std::setprecision(0) << std::fixed << GameManager::getScore();
	stats << " LIVES: " << std::setprecision(0) << std::fixed << GameManager::getLives();
	wmove(DisplayManager::_scoreWindow, 1, DisplayManager::_cols / 2 - stats.str().length() / 2);
	waddstr(DisplayManager::_scoreWindow, stats.str().c_str());
	for (int y = 0; y < rows; y++)
		for (int x = 0; x < cols; x++)
		{
			if (0 != (c = Framebuffer::getCurse(y * cols + x)))
			{
				wmove(DisplayManager::_gameWindow, y + 1, x + 1);
				waddch(DisplayManager::_gameWindow, c);
			}
		}
	wrefresh(DisplayManager::_gameWindow);
	wrefresh(DisplayManager::_scoreWindow);
}

int	DisplayManager::getCols(void) { return DisplayManager::_cols; }
int	DisplayManager::getRows(void) { return DisplayManager::_rows; }
void	DisplayManager::setQuitMsg(std::string message) { DisplayManager::_quitMsg = message; }
std::string	DisplayManager::getQuitMsg(void) { return DisplayManager::_quitMsg; }

void DisplayManager::destroy(void)
{
	int		x = DisplayManager::_rows / 2;
	int		y = DisplayManager::_cols / 2 - DisplayManager::_quitMsg.length() / 2;

	DisplayManager::clear();
	wmove(DisplayManager::_gameWindow, x, y);
	waddstr(DisplayManager::_gameWindow, DisplayManager::_quitMsg.c_str());
	wrefresh(DisplayManager::_gameWindow);
	unsigned int micro = 2000000;
	usleep(micro);
	endwin();
}