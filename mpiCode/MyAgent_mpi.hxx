
#ifdef PANDORAMPI
#ifndef __MyAgent_mpi_hxx
#define __MyAgent_mpi_hxx

#include <Point2D.hxx>

typedef struct
{
	char _idMpi[32];
	bool _existsMpi;
	Engine::Point2D<int> _positionMpi;

} MyAgentPackage;

#endif // __MyAgent_mpi_hxx
#endif // PANDORAMPI

