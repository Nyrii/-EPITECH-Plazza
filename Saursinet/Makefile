##
## Makefile for makefile in /home/noboud_n/rendu/PSU_2015_philo
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Mon Feb 29 13:25:56 2016 Nyrandone Noboud-Inpeng
## Last update Mon Apr 18 18:31:20 2016 Saursinet
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

SRCXOR		= CryptXor.cpp	\
		  MainXor.cpp

# SRCSERVEUR	= ServeurSocket.cpp	\
# 		  MainServeur.cpp
#
# SRCCLIENT	= ClientSocket.cpp	\
# 		  MainClient.cpp

SRCSLOC	= ServeurSocket.cpp	\
	  ClientSocket.cpp	\
	  Sockets.cpp		\
	  MainClientLocal.cpp

#
## OBJS
#

OBJ		= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

OBJPARS		= $(addprefix $(OBJDIR), $(SRCPARS:.cpp=.o))

OBJXOR		= $(addprefix $(OBJDIR), $(SRCXOR:.cpp=.o))

# OBJSERVEUR	= $(addprefix $(OBJDIR), $(SRCSERVEUR:.cpp=.o))
#
# OBJCLIENT	= $(addprefix $(OBJDIR), $(SRCCLIENT:.cpp=.o))

OBJSLOC	= $(addprefix $(OBJDIR), $(SRCSLOC:.cpp=.o))


#
## BINARIES NAME
#

NAME		= tp

NAMEPARS	= pars

NAMEXOR		= decodexor

# NAMESERVEUR	= server
#
# NAMECLIENT	= client

NAMELOC	= loc

# NAMECLIENTLOC	= clientloc


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
		@make --no-print-directory $(NAMEXOR)
		@make --no-print-directory $(NAMELOC)

$(OBJDIR)%.o:	$(SRCDIR)%.cpp
		@mkdir -p $(MAKEOBJ)
		$(CCX) $(CXXFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): 	$(OBJ)
		$(CCX) -o $(NAME) $(OBJ) $(LDFLAGS)

$(NAMEPARS): 	$(OBJPARS)
		$(CCX) -o $(NAMEPARS) $(OBJPARS) -lboost_regex

$(NAMEXOR): 	$(OBJXOR)
		$(CCX) -o $(NAMEXOR) $(OBJXOR)

$(NAMELOC): $(OBJSLOC)
		$(CCX) -o $(NAMELOC) $(OBJSLOC)

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJPARS)
		$(RM) $(OBJXOR)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) $(NAMEXOR)
		$(RM) $(NAMEPARS)
		$(RM) $(NAMELOC)

re:		fclean all
