#ifndef __Vaca_hxx__
#define __Vaca_hxx__

#include <Agent.hxx>
#include <string>

namespace Tutorial
{

class Vaca : public Engine::Agent
{
	bool _llegado;
	int _count;
public:
	Vaca( const std::string & id );
	virtual ~Vaca();
	
	void updateState();
	void serialize();
	void registerAttributes();

	////////////////////////////////////////////////
	// This code has been automatically generated //
	/////// Please do not modify it ////////////////
	////////////////////////////////////////////////
#ifdef PANDORAMPI
	Vaca ( void * );
	void * fillPackage();
	void sendVectorAttributes(int);
	void receiveVectorAttributes(int);
#endif // PANDORAMPI
	////////////////////////////////////////////////
	//////// End of generated code /////////////////
	////////////////////////////////////////////////

};

} // namespace Tutorial

#endif // __Vaca_hxx__
