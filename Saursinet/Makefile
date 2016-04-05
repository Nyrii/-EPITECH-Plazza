##
## Makefile for makefile in /home/noboud_n/rendu/PSU_2015_philo
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Mon Feb 29 13:25:56 2016 Nyrandone Noboud-Inpeng
## Last update Tue Apr  5 23:31:33 2016 Florian Saurs
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
		  MainPars.cpp	\
		  Core.cpp

SRCSERVEUR	= ServeurSocket.cpp	\
		  MainServeur.cpp

SRCCLIENT	= ClientSocket.cpp	\
		  MainClient.cpp

#
## OBJS
#

OBJ		= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

OBJPARS		= $(addprefix $(OBJDIR), $(SRCPARS:.cpp=.o))

OBJSERVEUR	= $(addprefix $(OBJDIR), $(SRCSERVEUR:.cpp=.o))

OBJCLIENT	= $(addprefix $(OBJDIR), $(SRCCLIENT:.cpp=.o))


#
## BINARIES NAME
#

NAME		= tp

NAMEPARS	= pars

NAMESERVEUR	= server

NAMECLIENT	= client


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
		@make --no-print-directory $(NAMESERVEUR)
		@make --no-print-directory $(NAMECLIENT)

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
		@mkdir -p $(MAKEOBJ)
		$(CCX) $(CXXFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): 	$(OBJ)
		$(CCX) -o $(NAME) $(OBJ) $(LDFLAGS)

$(NAMEPARS): 	$(OBJPARS)
		$(CCX) -o $(NAMEPARS) $(OBJPARS) -lboost_regex

$(NAMESERVEUR): $(OBJSERVEUR)
		$(CCX) -o $(NAMESERVEUR) $(OBJSERVEUR)

$(NAMECLIENT): $(OBJCLIENT)
		$(CCX) -o $(NAMECLIENT) $(OBJCLIENT)

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJPARS)
		$(RM) $(OBJSERVEUR)
		$(RM) $(OBJCLIENT)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) $(NAMEPARS)
		$(RM) $(NAMESERVEUR)
		$(RM) $(NAMECLIENT)

re:		fclean all
