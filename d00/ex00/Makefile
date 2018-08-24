CC = 		clang++
CFLAGS =	-Wall -Wextra -Werror
BINARY =	megaphone
BUILDDIR =	./builds
SOURCEDIR =	.
HEADERDIR = .

SRCFILES =	megaphone.cpp

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
	./$(BINARY) "shhhhh... I think the students are asleep..."
	./$(BINARY)  Damnit " ! " "Sorry students, I thought this thing was off."
	./$(BINARY)