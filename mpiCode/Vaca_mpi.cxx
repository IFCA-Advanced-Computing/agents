
#ifdef PANDORAMPI
#include "Vaca_mpi.hxx"
#include <Vaca.hxx>
#include <cstring>
#include <mpi.h>

namespace Tutorial
{

void * Vaca::fillPackage()
{
	VacaPackage * package = new VacaPackage;
	memcpy(&package->_idMpi, _id.c_str(), std::min((unsigned int)32,(unsigned int)(sizeof(char)*_id.size())));
	package->_idMpi[std::min((unsigned int)32,(unsigned int)_id.size())] = '\0';
	package->_existsMpi = _exists;
	package->_positionMpi = _position;

	return package;
}

Vaca::Vaca( void * package ) : Engine::Agent(((VacaPackage*)package)->_idMpi)
{
	VacaPackage * particularPackage = (VacaPackage*)package;
	_exists = particularPackage->_existsMpi;
	_position = particularPackage->_positionMpi;

}


void Vaca::sendVectorAttributes( int target)
{
	int sizeVector = 0;
}

void Vaca::receiveVectorAttributes( int origin)
{
	int sizeVector = 0;
	MPI_Status status;
}

} // namespace Tutorial
#endif // PANDORAMPI

