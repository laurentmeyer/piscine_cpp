CC = 		clang++
CFLAGS =	-Wall -Wextra -Werror -g
BINARY =	welcomeToTheANPE
BUILDDIR =	./builds
SOURCEDIR =	./srcs
HEADERDIR = ./includes

SRCFILES =	main.cpp						\
			BureaucratClass.cpp				\
			ShrubberyCreationFormClass.cpp	\
			RobotomyRequestFormClass.cpp	\
			PresidentialPardonFormClass.cpp	\
			FormClass.cpp					\
			InternClass.cpp					\
			OfficeBlockClass.cpp			\

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