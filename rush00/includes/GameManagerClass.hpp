#ifndef GAMEMANAGERCLASS_HPP
# define GAMEMANAGERCLASS_HPP

# include <iostream>
# include "TimeClass.hpp"
# include "InputManagerClass.hpp"
# include "DisplayManagerClass.hpp"
# include "GameObjectManagerClass.hpp"

// # define GAME_PLAY 0
// # define GAME_PAUSE 1
// # define GAME_STOP 2

class GameManager {

public: 

	GameManager(void); 
	~GameManager(void); 

	enum Status { Play, Pause, Stop };

	GameManager &		operator=(GameManager const & rhs);

	std::string const	toString(void) const;
	static void			init(void);
	static void			display(void);
	static void			quit(std::string message);
	static void			destroy(void);
	static void			update(void);
	static Status		status;
	static void			loseOneLife(void);
	static void			increaseScore(int points);
	static int 			getScore(void);
	static int 			getLives(void);


private:
	GameManager(GameManager const & src); 
	static int			_score;
	static int const	_maxLives;
	static int			_lives;

};

std::ostream &	operator<< (std::ostream & o, GameManager const & rhs);

#endif