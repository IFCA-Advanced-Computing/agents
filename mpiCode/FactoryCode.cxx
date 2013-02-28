
#ifdef PANDORAMPI
#include <MpiFactory.hxx>
#include <Exceptions.hxx>
#include <sstream>

#include <Vaca.hxx>
#include "Vaca_mpi.hxx"

namespace Engine
{

MPI_Datatype * createVacaType()
{
	VacaPackage package;

	int blockLengths[4];
	MPI_Datatype typeList[4];
	// block lengths and types
	// _id
	blockLengths[0] = 32;
	typeList[0] = MPI_CHAR;
	// _position._x
	blockLengths[1] = 1;
	typeList[1] = MPI_INT;
	// _position._y
	blockLengths[2] = 1;
	typeList[2] = MPI_INT;
	// _exists
	blockLengths[3] = 1;
	typeList[3] = MPI_INT;

	MPI_Aint displacements[4];
	MPI_Aint startAddress;
	MPI_Aint address;
	// id
	MPI_Address(package._idMpi, &startAddress);
	displacements[0] = 0;
	// _position._x
	MPI_Address(&package._positionMpi._x, &address);
	displacements[1] = address-startAddress;
	// _position._y
	MPI_Address(&package._positionMpi._y, &address);
	displacements[2] = address-startAddress;
	// _exists
	MPI_Address(&package._existsMpi, &address);
	displacements[3] = address-startAddress;

	MPI_Datatype * newDataType = new MPI_Datatype;
	MPI_Type_struct(4, blockLengths, displacements, typeList, newDataType);
	MPI_Type_commit(newDataType);
	return newDataType;
}

void MpiFactory::registerTypes()
{
	_types.insert( std::make_pair( "Vaca", createVacaType()));
}

void * MpiFactory::createDefaultPackage( const std::string & type )
{
	if(type.compare("Vaca")==0)
	{
		return new VacaPackage;
	}

	std::stringstream oss;
	oss << "MpiFactory::createDefaultPackage - unknown agent type: " << type;
	throw Engine::Exception(oss.str());
	return 0;
}

Agent * MpiFactory::createAndFillAgent( const std::string & type, void * package )
{
	if(type.compare("Vaca")==0)
	{
		return new Tutorial::Vaca(package);
	}

	std::stringstream oss;
	oss << "MpiFactory::createDefaultPackage - unknown agent type: " << type;
	throw Engine::Exception(oss.str());
	return 0;
}

} // namespace Engine
#endif // PANDORAMPI

