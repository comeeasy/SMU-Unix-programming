# ----------------------------------------------------------------------

DIR=lab04-Files-and-Directories
SOURCE_FILES=mytype.c mymode.c myugid.c mysize.c myrm.c 
EXECUTABLE_FILES=mytype mymode myugid mysize myrm mymv

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
	@rm -rf a.out *.o *.out *.pdf $(EXECUTABLE_FILES) *~

# ----------------------------------------------------------------------
