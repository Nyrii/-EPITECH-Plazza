##
## Makefile for Makefile in /Users/noboud_n/rendu/cpp_plazza
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Tue Apr 12 14:58:00 2016 Nyrandone Noboud-Inpeng
## Last update Apr 13 12:0:30 2016
##

SRC	= ClientSocket.cpp		\
	  ClientSocketLocal.cpp		\
	  Core.cpp			\
	  CommunicationError.cpp	\
	  CryptCaesar.cpp		\
	  CryptXor.cpp			\
	  Errors.cpp			\
	  Main.cpp			\
	  NamedPipe.cpp			\
	  Parsing.cpp			\
	  Process.cpp			\
	  ServeurSocket.cpp		\
	  ServeurSocketLocal.cpp	\
          Search.cpp

OBJ	= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

RM	= rm -f

CC	= g++ -std=c++11

NAME	= plazza

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I inc/

MAKEOBJ	= obj

CFLAGS	= -W -Wall -Wextra -Werror

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(MAKEOBJ)
	$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lboost_regex

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
