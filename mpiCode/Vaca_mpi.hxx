
#ifdef PANDORAMPI
#ifndef __Vaca_mpi_hxx
#define __Vaca_mpi_hxx

#include <Point2D.hxx>

typedef struct
{
	char _idMpi[32];
	bool _existsMpi;
	Engine::Point2D<int> _positionMpi;

} VacaPackage;

#endif // __Vaca_mpi_hxx
#endif // PANDORAMPI

