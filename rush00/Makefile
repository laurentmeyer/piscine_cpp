CC = 		clang++
CFLAGS =	-Wall -Wextra -Werror -std=c++98
BINARY =	ft_retro
BUILDDIR =	./builds
SOURCEDIR =	./srcs
HEADERDIR = ./includes

SRCFILES =	main.cpp 					\
			TimeClass.cpp				\
			GameManagerClass.cpp		\
			InputManagerClass.cpp		\
			DisplayManagerClass.cpp		\
			FramebufferClass.cpp		\
			AGameObjectClass.cpp			\
			PlayerClass.cpp				\
			EnemyClass.cpp				\
			ProjectileClass.cpp			\
			BackgroundClass.cpp			\
			GameObjectManagerClass.cpp	\

CCHEADERS = -I./$(HEADERDIR)
CCFRAMEWORKS = -lncurses

SOURCES = $(SRCFILES:%.cpp=$(SOURCEDIR)/%.cpp)
OBJECTS = $(SOURCES:$(SOURCEDIR)/%.cpp=$(BUILDDIR)/%.o)

.PHONY: all clean fclean re

all : $(BINARY)

$(BINARY) : $(OBJECTS)
	$(CC) $(CCHEADERS) $(OBJECTS) $(CCFRAMEWORKS) -o $(BINARY)

$(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CCHEADERS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(BINARY)

re: fclean all

test: all
	./$(BINARY)
