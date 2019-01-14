CC = 		clang++
CFLAGS =	-g -Wall -Wextra -Werror
BINARY =	eval_expr
BUILDDIR =	./builds
SOURCEDIR =	./srcs
HEADERDIR = ./includes

SRCFILES =	main.cpp			\
			FixedClass.cpp		\
			# EvalClass.cpp		\

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
	# ./$(BINARY) "coucou"
	./$(BINARY)
	./$(BINARY) "0 + 0"
	./$(BINARY) "( 18.18 + 3.03 ) * 2"
	./$(BINARY) "-1.12 * -1.4"
	./$(BINARY) "(1 + (2.33 / (4.3 - 16))) * 4.2"