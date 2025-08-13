#ifndef PARALLELIO_H
#define PARALLELIO_H

#include "cmdLineOptions.h"

#include "hdf5.h"

class ParallelIO
{
public:
  ParallelIO();
  ~ParallelIO() {}
  void h5writer(CmdLineOptions& cmd);
  void MPIIOwriter(CmdLineOptions& cmd);
  void add_attribute(hid_t id, const char* descript, const char* value);
  double rate()             { return m_rate;}
  double time()             { return m_t;}
  double totalTime()        { return m_totalTime;}
  double totalSz()          { return m_totalSz;}
  int    numvar()           { return m_numvar;}

private:
  double m_t;
  double m_totalTime;
  double m_rate;
  double m_totalSz;
  int    m_numvar;
};

#endif // PARALLELIO_H

