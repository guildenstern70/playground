## Playground makefile

# Macro
# CC = g++
OUTDIR = ./
EXENAME = playground
# CC_FLAGS_COMPILE = -m486 -c
# CC_FLAGS_LINK = -lncurses

# FOR USE WITH GJGPP
CC = gxx
CC_FLAGS_COMPILE = -march=i486 -c
CC_FLAGS_LINK = -lpdcurses


# Explicit Rule
all : randgenerator.o map.o filemanager.o logger.o omino.o gamelogic.o playground.o  ncurswrapper.o
	$(CC) -o $(OUTDIR)$(EXENAME) playground.o logger.o filemanager.o omino.o gamelogic.o ncurswrapper.o randgenerator.o map.o $(CC_FLAGS_LINK)
playground.o : playground.cpp ncurswrapper.h
	$(CC) $(CC_FLAGS_COMPILE) playground.cpp
ncurswrapper.o : ncurswrapper.cpp ncurswrapper.h logger.h
	$(CC) $(CC_FLAGS_COMPILE) ncurswrapper.cpp
gamelogic.o : gamelogic.cpp gamelogic.h pedina.h
	$(CC) $(CC_FLAGS_COMPILE) gamelogic.cpp
omino.o : omino.h omino.cpp pedina.h
	$(CC) $(CC_FLAGS_COMPILE) omino.cpp
logger.o : logger.cpp logger.h filemanager.h
	$(CC) $(CC_FLAGS_COMPILE) logger.cpp
filemanager.o : filemanager.cpp require.h filemanager.h
	$(CC) $(CC_FLAGS_COMPILE) filemanager.cpp
map.o : map.cpp map.h randgenerator.h
	$(CC) $(CC_FLAGS_COMPILE) map.cpp
randgenerator.o : randgenerator.cpp randgenerator.h
	$(CC) $(CC_FLAGS_COMPILE) randgenerator.cpp
clear :
	rm -f *.o


