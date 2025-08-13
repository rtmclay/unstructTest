#define OMPI_SKIP_MPICXX  1
#define MPICH_SKIP_MPICXX 1
#include "comm.h"
#include <stdio.h>
#include "cmdLineOptions.h"
#include "h5test.h"
#include "parallel_io.h"
Comm P;


void outputResults(CmdLineOptions& cmd, ParallelIO& pio);


int main(int argc, char* argv[])
{

  P.init(&argc, &argv, MPI_COMM_WORLD);

  CmdLineOptions cmd(argc, argv);
  CmdLineOptions::state_t state = cmd.state();
  if (state != CmdLineOptions::iGOOD)
    {
      MPI_Finalize();
      return (state == CmdLineOptions::iBAD);
    }
  
  ParallelIO pio;

  if (cmd.h5slab || cmd.h5chunk)
    pio.h5writer(cmd);

  if (cmd.romio)
    pio.MPIIOwriter(cmd);

  if (P.myProc == 0)
    outputResults(cmd, pio);

  P.fini();

  return 0;
}

void outputResults(CmdLineOptions& cmd, ParallelIO& pio)
{
  double fileSz       = pio.totalSz()/(1024.0 * 1024.0 * 1024.0);

  if (cmd.luaStyleOutput)
    {
      printf("%%%% { nprocs = %d, lSz = %ld, wrtStyle = \"%s\","
             " xferStyle = \"%s\", fileSzGB = %15.7g, time = %15.7g, totalTime = %15.7g,"
             " rate = %15.7g },\n",
             P.nProcs, cmd.localSz, cmd.wrtStyle.c_str(), cmd.xferStyle.c_str(), 
             fileSz, pio.time(), pio.totalTime(), pio.rate());
    }
  if (cmd.tableStyleOutput)
    {
      printf("\nunstructTest:\n"
             "-------------------\n\n"
             " Nprocs:           %12d\n"  
             " lSz:              %12ld\n"
             " Numvar:           %12d\n"
             " fileSz (GB):      %12.3f\n"
             " time (sec):       %12.3f\n"
             " totalTime (sec):  %12.3f\n"
             " rate (MB/s):      %12.3f\n"
             " wrtStyle:         %12s\n"
             " xferStyle:        %12s\n",
             P.nProcs, cmd.localSz, pio.numvar(), fileSz, pio.time(), pio.totalTime(),
             pio.rate(), cmd.wrtStyle.c_str(), cmd.xferStyle.c_str());
    }
}
