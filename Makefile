##
## Makefile for Makefile in /Users/noboud_n/rendu/cpp_plazza
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Tue Apr 12 14:58:00 2016 Nyrandone Noboud-Inpeng
## Last update Wed Apr 20 17:33:07 2016 guillaume wilmot
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
	  ParseAv.cpp			\
	  Parsing.cpp			\
	  Pipes.cpp			\
	  PipeOut.cpp			\
	  PipeIn.cpp			\
	  Process.cpp			\
	  ReadAndFind.cpp		\
          Search.cpp			\
	  ServeurSocket.cpp		\
	  ServeurSocketLocal.cpp	\
	  Sockets.cpp			\
          SocketsLocal.cpp		\
	  Thread.cpp			\
	  ThreadPool.cpp		\
	  Timer.cpp			\
	  TimerError.cpp		\
          Regex.cpp			\
	  RegexError.cpp		\
	  UsageError.cpp

ifeq ($(ui), yes)
SRC	+= Gui.cpp
SRC	+= MainGui.cpp
SRC	+= MenuFiles.cpp
SRC	+= MenuTasks.cpp
SRC	+= DisplayerGui.cpp
LDFLAGS += -lmenu -lncurses
else
SRC	+= Main.cpp
SRC	+= Displayer.cpp
endif


OBJ	= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

RM	= rm -f

CXX	= g++ -std=c++11

NAME	= plazza

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I inc/

MAKEOBJ	= obj

LDFLAGS 	+= -lpthread -lboost_regex -lrt
CXXFLAGS	+= -W -Wall -Wextra -Werror

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(MAKEOBJ)
	$(CXX) $(CXXFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

all:
	@make --no-print-directory $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
