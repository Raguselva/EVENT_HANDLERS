IDIR = ../include

BINS = ../bin

CC = gcc

CFGS = -I$(IDIR)

_LIBS = receptionist.h employee.h administrator.h user.h teams.h
LIBS = $(patsubst %,$(IDIR)/%,$(_LIBS))

_OBJ = receptionist.o employee.o application.o administrator.o user.o teams.o
OBJ = $(patsubst %,$(BINS)/%,$(_OBJ))


$(BINS)/%.o: %.c $(LIBS)
	$(CC) -c -o $@ $< $(CFGS)

$(BINS)/main: $(OBJ)
	$(CC) -o $@ $^ $(CFGS) 

