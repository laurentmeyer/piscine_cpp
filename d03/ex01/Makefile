CC = 		clang++
CFLAGS =	-Wall -Wextra -Werror -std=c++98
BINARY =	fragtrap
BUILDDIR =	./builds
SOURCEDIR =	./srcs
HEADERDIR = ./includes

SRCFILES =	main.cpp				\
			FragTrapClass.cpp		\
			ScavTrapClass.cpp		\

CCHEADERS = -I./$(HEADERDIR)

SOURCES = $(SRCFILES:%.cpp=$(SOURCEDIR)/%.cpp)
OBJECTS = $(SOURCES:$(SOURCEDIR)/%.cpp=$(BUILDDIR)/%.o)

.PHONY: all clean fclean re

all : $(BINARY)

$(BINARY) : $(OBJECTS)
	$(CC) $(CCHEADERS) $(OBJECTS) -o $(BINARY)

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