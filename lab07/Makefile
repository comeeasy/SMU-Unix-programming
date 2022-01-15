# ----------------------------------------------------------------------

DIR=lab-07-Process-Control
SOURCE_FILES=pid.c fork1.c fork2.c wait1.c wait2.c exe.c mytime.c
EXECUTABLE_FILES=pid fork1 fork2 wait1 wait2 exe mytime

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
	@rm -rf a.out *.o output *.out *.pdf $(EXECUTABLE_FILES) *~

# ----------------------------------------------------------------------
