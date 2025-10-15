CC = gcc

PKGS = raylib


CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Isrc/include
CFLAGS += $$(pkg-config --cflags $(PKGS))

LIBS += -lm
LIBS += -lalloc
LIBS += $$(pkg-config --libs $(PKGS))


OBJS += $(CACHE)/main.o
OBJS += $(CACHE)/game_manager.o
OBJS += $(CACHE)/game_state_menu.o
OBJS += $(CACHE)/menu_button.o


$(CACHE)/main.o: src/cuboria/main.c src/cuboria/version.h
	$(CC) $(CFLAGS) -c src/cuboria/main.c -o $@


$(CACHE)/game_manager.o: src/cuboria/game_manager.c src/cuboria/version.h
	$(CC) $(CFLAGS) -c src/cuboria/game_manager.c -o $@


$(CACHE)/game_state_menu.o: src/cuboria/game_state_menu.c src/cuboria/version.h
	$(CC) $(CFLAGS) -c src/cuboria/game_state_menu.c -o $@


$(CACHE)/menu_button.o: src/cuboria/menu_button.c src/cuboria/version.h
	$(CC) $(CFLAGS) -c src/cuboria/menu_button.c -o $@


$(RELEASE)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(RELEASE)/$(TARGET)

