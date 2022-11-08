#* TARGET *#
TARGET = pong

#*SOURCE FILES *#
FILES = main.cpp Window.cpp
		
SRC = $(addprefix src/, $(FILES))

#* OBJECT FILES *#
OBJS = $(SRC:%.c=%.o)

#* FLAGS *#
FLAGS = -std=c++17 #-Wall -Wextra -Werror
SDL = -lmingw32 -lSDL2main -lSDL2

#* HEADER FILES *#
INCLUDE = include/

#* LIBRARY *#
LIB = lib/

#* DELETE *#
DEL = rm -f

all: $(TARGET)

%.o: %.c
	g++ $(FLAGS) -c -I $(INCLUDE) -L $(LIB) $(SDL) $< -o $@

$(TARGET): $(OBJS) $(INCLUDE)
	g++ $(FLAGS) -I $(INCLUDE) -L $(LIB) $(OBJS) $(SDL) -o $(TARGET)

re: fclean all

clean:
	$(DEL) $(OBJS)

fclean:	clean
	$(DEL) $(TARGET)

.PHONY: clean fclean re all