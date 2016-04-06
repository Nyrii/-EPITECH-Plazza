##
## Makefile for makefile in /home/noboud_n/rendu/PSU_2015_philo
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Mon Feb 29 13:25:56 2016 Nyrandone Noboud-Inpeng
## Last update Wed Apr  6 17:40:36 2016 Florian Saurs
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

SRCSERVEURLOC	= ServeurSocketLocal.cpp	\
		  MainServeurLocal.cpp

SRCCLIENTLOC	= ClientSocketLocal.cpp	\
		  MainClientLocal.cpp

#
## OBJS
#

OBJ		= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

OBJPARS		= $(addprefix $(OBJDIR), $(SRCPARS:.cpp=.o))

OBJSERVEUR	= $(addprefix $(OBJDIR), $(SRCSERVEUR:.cpp=.o))

OBJCLIENT	= $(addprefix $(OBJDIR), $(SRCCLIENT:.cpp=.o))

OBJSERVEURLOC	= $(addprefix $(OBJDIR), $(SRCSERVEURLOC:.cpp=.o))

OBJCLIENTLOC	= $(addprefix $(OBJDIR), $(SRCCLIENTLOC:.cpp=.o))


#
## BINARIES NAME
#

NAME		= tp

NAMEPARS	= pars

NAMESERVEUR	= server

NAMECLIENT	= client

NAMESERVEURLOC	= serverloc

NAMECLIENTLOC	= clientloc


#
## COMPILATION FLAGS
#

LDFLAGS = -lpthread

CXXFLAGS = -W -Wall -Wextra -std=c++11


#
## RULES
#

all:
		@make --no-print-directory $(NAME)
		@make --no-print-directory $(NAMEPARS)
		@make --no-print-directory $(NAMESERVEUR)
		@make --no-print-directory $(NAMECLIENT)
		@make --no-print-directory $(NAMESERVEURLOC)
		@make --no-print-directory $(NAMECLIENTLOC)

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

$(NAMESERVEURLOC): $(OBJSERVEURLOC)
		$(CCX) -o $(NAMESERVEURLOC) $(OBJSERVEURLOC)

$(NAMECLIENTLOC): $(OBJCLIENTLOC)
		$(CCX) -o $(NAMECLIENTLOC) $(OBJCLIENTLOC)

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJPARS)
		$(RM) $(OBJSERVEUR)
		$(RM) $(OBJCLIENT)
		$(RM) $(OBJSERVEURLOC)
		$(RM) $(OBJCLIENTLOC)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) $(NAMEPARS)
		$(RM) $(NAMESERVEUR)
		$(RM) $(NAMECLIENT)
		$(RM) $(NAMESERVEURLOC)
		$(RM) $(NAMECLIENTLOC)

re:		fclean all
