# ----------------------------------------------------------------------

DIR=lab05-System-Data-Files-and-Information
SOURCE_FILES=myuser.c myuname.c mydate.c
EXECUTABLE_FILES=myuser myuname mydate

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
