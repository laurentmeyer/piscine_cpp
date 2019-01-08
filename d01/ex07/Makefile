CC = 		clang++
CFLAGS =	-Wall -Wextra -Werror
BINARY =	replace
BUILDDIR =	./builds
SOURCEDIR =	./srcs
HEADERDIR = ./includes

SRCFILES =	main.cpp				\
			ReplaceClass.cpp		\

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
	@echo "totototototititototitotitotot" > test.txt
	@./$(BINARY) test.txt toto %
	@cat -e test.txt
	@rm test.txt