##
## Makefile for Makefile in /Users/noboud_n/rendu/cpp_plazza
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Thu Apr  7 13:52:42 2016 Nyrandone Noboud-Inpeng
## Last update Fri Apr  8 18:35:59 2016 Nyrandone Noboud-Inpeng
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
	  ServeurSocket.cpp		\
	  ServeurSocketLocal.cpp

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
