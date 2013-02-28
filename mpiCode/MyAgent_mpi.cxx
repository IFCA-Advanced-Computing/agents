
#ifdef PANDORAMPI
#include "MyAgent_mpi.hxx"
#include <MyAgent.hxx>
#include <cstring>
#include <mpi.h>

namespace Tutorial
{

void * MyAgent::fillPackage()
{
	MyAgentPackage * package = new MyAgentPackage;
	memcpy(&package->_idMpi, _id.c_str(), std::min((unsigned int)32,(unsigned int)(sizeof(char)*_id.size())));
	package->_idMpi[std::min((unsigned int)32,(unsigned int)_id.size())] = '\0';
	package->_existsMpi = _exists;
	package->_positionMpi = _position;

	return package;
}

MyAgent::MyAgent( void * package ) : Engine::Agent(((MyAgentPackage*)package)->_idMpi)
{
	MyAgentPackage * particularPackage = (MyAgentPackage*)package;
	_exists = particularPackage->_existsMpi;
	_position = particularPackage->_positionMpi;

}


void MyAgent::sendVectorAttributes( int target)
{
	int sizeVector = 0;
}

void MyAgent::receiveVectorAttributes( int origin)
{
	int sizeVector = 0;
	MPI_Status status;
}

} // namespace Tutorial
#endif // PANDORAMPI

