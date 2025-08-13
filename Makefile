EXEC 	 := unstructTest
SRC  	 := main.C cmdLineOptions.C comm.C measure.C parallel_io.C
OBJ  	 := main.o cmdLineOptions.o comm.o measure.o parallel_io.o
CXX  	 := mpicxx
CXXFLAGS := -I$(TACC_HDF5_INC)

all: $(EXEC) 

$(EXEC): $(OBJ)
	mpicxx -o $@ $^ -L$(TACC_HDF5_LIB) -lhdf5 -lz


neat:
	$(RM) *~

clean: neat
	$(RM) $(OBJ)
clobber: clean
	$(RM) $(EXEC)

main.o: main.C comm.h cmdLineOptions.h h5test.h parallel_io.h
cmdLineOptions.o: cmdLineOptions.C comm.h cmdLineOptions.h h5test.h
comm.o: comm.C comm.h
measure.o: measure.C measure.h
parallel_io.o: parallel_io.C h5test.h parallel_io.h comm.h cmdLineOptions.h measure.h
