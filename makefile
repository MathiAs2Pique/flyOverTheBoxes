# Project: FlyOverBoxes
#--- Sources files -------------------------------------------------------------
FILES=sources/drawing/drawing.c \
      sources/game/game.c \
      sources/menu/menu.c \
      sources/objects/bomb.c \
      sources/objects/histogram.c \
      sources/objects/image.c \
      sources/objects/plane.c \
      sources/scores/scores.c \
      sources/utils/commandParsing.c \
      sources/utils/log.c \
      sources/utils/options.c \
      main.c

#--- Executable name -----------------------------------------------------------
EXECUTABLE=flyOverTheBoxes

#--- Building ------------------------------------------------------------------
$(EXECUTABLE):$(FILES)
	gcc $^ -o $@

#--- Cleaning ------------------------------------------------------------------
clean:
	rm -f $(EXECUTABLE)

#--- Building and cleaning -----------------------------------------------------
all: clean $(EXECUTABLE)


