export CC = g++
INCPATH = 
LIBS = 
DEFINES =
export FLAGS = -g -std=c++0x -o3 $(INCPATH) $(LIBS) $(DEFINES)
export EXEC = PLSCC

.cpp.o:
	$(CC) $(FLAGS) -o $@ -c $^;

.c.o :
	$(CC) $(FLAGS) -o $@ -c $^;

$(EXEC): algo.o
	$(CC) $^ $(FLAGS) -o $@


clean: 
	@rm -f *.o
	@rm -f $(EXEC)
