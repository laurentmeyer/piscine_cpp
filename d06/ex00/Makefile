CC = 		clang++
CFLAGS =	-Wall -Wextra -Werror -g
BINARY =	convert
BUILDDIR =	./builds
SOURCEDIR =	./srcs
HEADERDIR = ./includes

SRCFILES =	main.cpp					\
			ConverterClass.cpp			\

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
	./$(BINARY) 0
	@echo "================"
	./$(BINARY) "+"
	@echo "================"
	./$(BINARY) nan
	@echo "================"
	./$(BINARY) 42.f
	@echo "================"
	./$(BINARY) 42f
	@echo "================"
	./$(BINARY) 42ff
	@echo "================"
	./$(BINARY) 42.
	@echo "================"
	./$(BINARY) 42.0f
	@echo "================"
	./$(BINARY) -420.024f
	@echo "================"
	./$(BINARY) --420+.024f
	@echo "================"
	./$(BINARY) -4300000000f
	@echo "================"
	./$(BINARY) -inff
	@echo "================"
	./$(BINARY) "  salut les losers "