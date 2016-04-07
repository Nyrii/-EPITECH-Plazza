##
## Makefile for makefile in /home/noboud_n/rendu/PSU_2015_philo
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Mon Feb 29 13:25:56 2016 Nyrandone Noboud-Inpeng
## Last update Thu Apr  7 18:16:11 2016 guillaume wilmot
##

SRC	= Main.cpp		\
	  Thread.cpp		\
	  CondThread.cpp	\
	  Process.cpp		\
	  Listener.cpp		\
	  ThreadPool.cpp

OBJ	= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

RM	= rm -f

CCX	= g++

NAME	= tp

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I inc/

MAKEOBJ	= obj

LDFLAGS = -lpthread
CXXFLAGS = -W -Wall -Wextra -Werror

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(MAKEOBJ)
	$(CCX) $(CXXFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CCX) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
