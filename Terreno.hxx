#ifndef __Terreno_hxx
#define __Terreno_hxx

#include <World.hxx>

namespace Engine
{
	class Simulation;
}

namespace Tutorial 
{

class TerrenoConfig;

class Terreno : public Engine::World
{
	void createRasters();
	void createAgents();
	const TerrenoConfig & _config;
	double sind(double angle);
	double cosd(double angle);

public:
	Terreno( Engine::Simulation & simulation, const TerrenoConfig & config  );
	virtual ~Terreno();
};

} // namespace Tutorial 

#endif // __Terreno_hxx

