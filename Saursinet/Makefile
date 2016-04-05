##
## Makefile for makefile in /home/noboud_n/rendu/PSU_2015_philo
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Mon Feb 29 13:25:56 2016 Nyrandone Noboud-Inpeng
## Last update Tue Apr  5 01:25:14 2016 Florian Saurs
##

#
## BASIC COMMAND
#

CCX		= g++ -g

RM		= rm -f

MAKEOBJ		= obj


#
## DIRECTORIES
#

OBJDIR		= obj/

SRCDIR		= src/

INCDIR		= -I inc/


#
## SRCS
#

SRC		= Thread.cpp

SRCPARS		= Parsing.cpp	\
		  MainPars.cpp


#
## OBJS
#

OBJ		= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

OBJPARS		= $(addprefix $(OBJDIR), $(SRCPARS:.cpp=.o))


#
## BINARIES NAME
#

NAME		= tp

NAMEPARS	= pars


#
## COMPILATION FLAGS
#

LDFLAGS = -lpthread

CXXFLAGS = -W -Wall -Wextra -Werror -std=c++11


#
## RULES
#

all:
		@make --no-print-directory $(NAME)
		@make --no-print-directory $(NAMEPARS)

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
		@mkdir -p $(MAKEOBJ)
		$(CCX) $(CXXFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): 	$(OBJ)
		$(CCX) -o $(NAME) $(OBJ) $(LDFLAGS)

$(NAMEPARS): 	$(OBJPARS)
		$(CCX) -o $(NAMEPARS) $(OBJPARS) -lboost_regex

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJPARS)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) $(NAMEPARS)

re:		fclean all
