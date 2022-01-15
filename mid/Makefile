# ----------------------------------------------------------------------

DIR=mid
SOURCE_FILES=2-ls.c 3-find.c 4-time.c
EXECUTABLE_FILES=2-ls 3-find 4-time

# ----------------------------------------------------------------------

CC=gcc
CFLAGS=-O2 -Wall

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
	@rm -rf a.out *.o out1 bigfile *.pdf $(EXECUTABLE_FILES) *~

# ----------------------------------------------------------------------
