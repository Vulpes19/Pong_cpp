#* TARGET *#
TARGET = pong

#*SOURCE FILES *#
FILES = main.cpp Window.cpp Player.cpp Enemy.cpp Score.cpp itoa.c
		
SRC = $(addprefix src/, $(FILES))

#* OBJECT FILES *#
OBJS = $(SRC:%.c=%.o)

#* FLAGS *#
FLAGS = -Wall -Wextra -Werror
SDL = -lmingw32 -lSDL2main -lSDL2 
TFF = `sdl2-config --cflags`
TFFF = `sdl2-config --libs` -lSDL2_ttf 

#* HEADER FILES *#
SDL_INCLUDE = include/
INCLUDE = headers/
#* LIBRARY *#
LIB = lib/

#* DELETE *#
DEL = rm -f

all: $(TARGET)

%.o: %.c
	g++ $(FLAGS) -c -I $(INCLUDE) -I $(SDL_INCLUDE) -L $(LIB) $(TFFF) $(SDL) $< -o $@

$(TARGET): $(OBJS) $(INCLUDE)
	g++ $(FLAGS) -I $(INCLUDE) -I $(SDL_INCLUDE) -L $(LIB) $(OBJS) $(TFFF) $(SDL) -o $(TARGET)

re: fclean all

clean:
	$(DEL) $(OBJS)

fclean:	clean
	$(DEL) $(TARGET)

.PHONY: clean fclean re all