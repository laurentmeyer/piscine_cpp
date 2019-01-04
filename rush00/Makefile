CC = 		clang++
CFLAGS =	-Wall -Wextra -Werror
BINARY =	main
BUILDDIR =	./builds
SOURCEDIR =	.
HEADERDIR = .

SRCFILES =	main.cpp

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
	./$(BINARY) "shhhhh... I think the students are asleep..."
	./$(BINARY)  Damnit " ! " "Sorry students, I thought this thing was off."
	./$(BINARY)