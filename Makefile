##
## Makefile for Makefile in /Users/noboud_n/rendu/cpp_plazza
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Tue Apr 12 14:58:00 2016 Nyrandone Noboud-Inpeng
## Last update Fri Apr 15 16:34:32 2016 guillaume wilmot
##

SRC	= ClientSocket.cpp		\
	  ClientSocketLocal.cpp		\
	  CommunicationError.cpp	\
	  CondThread.cpp		\
	  CondVar.cpp			\
	  Core.cpp			\
	  CryptCaesar.cpp		\
	  CryptXor.cpp			\
	  Errors.cpp			\
	  Listener.cpp			\
	  Main.cpp			\
	  NamedPipe.cpp			\
	  Parsing.cpp			\
	  Process.cpp			\
	  ReadAndFind.cpp		\
          Search.cpp			\
	  ServeurSocket.cpp		\
	  ServeurSocketLocal.cpp	\
	  Thread.cpp			\
	  ThreadPool.cpp

OBJ	= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

RM	= rm -f

CXX	= g++ -g -std=c++11

NAME	= plazza

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I inc/

MAKEOBJ	= obj

LDFLAGS 	= -lpthread -lboost_regex
CXXFLAGS	= -W -Wall -Wextra -Werror

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(MAKEOBJ)
	$(CXX) $(CXXFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
