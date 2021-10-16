# ----------------------------------------------------------------------

DIR=lab03-File-Input-Output
SOURCE_FILES=mycreate.c myappend.c mycat.c mycopy.c mycopy-test.c
EXECUTABLE_FILES=mycreate myappend mycat mycopy mycopy-test

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
