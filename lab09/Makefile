# ----------------------------------------------------------------------

DIR=lab09-Threads
SOURCE_FILES=thread.c terminate.c share.c synchro.c
EXECUTABLE_FILES=thread terminate share synchro

# ----------------------------------------------------------------------

CC=gcc
CFLAGS=-Wall -pthread

# ----------------------------------------------------------------------

all:	$(EXECUTABLE_FILES)

# ----------------------------------------------------------------------

indent:	$(SOURCE_FILES)
	indent -i2 -kr $(SOURCE_FILES)
	@rm -rf *~

# ----------------------------------------------------------------------

pdf:	$(SOURCE_FILES)
	ls -l $(SOURCE_FILES) > $(DIR)
	a2ps --medium=A4 --line-numbers=1 $(DIR) $(SOURCE_FILES) -o $(DIR).ps
	ps2pdf -sPAPERSIZE=a4 $(DIR).ps $(DIR).pdf
	@rm -f $(DIR) $(DIR).ps

# ----------------------------------------------------------------------

clean:
	@rm -rf a.out *.o *.out *.pdf $(EXECUTABLE_FILES) *~

# ----------------------------------------------------------------------
