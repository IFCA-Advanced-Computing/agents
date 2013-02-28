#include "Terreno.hxx"
#include "Vaca.hxx"
#include "TerrenoConfig.hxx"
#include <Simulation.hxx>
#include <GeneralState.hxx>
#include <math.h>
#include <stdlib.h>

namespace Tutorial 
{

Terreno::Terreno( Engine::Simulation & simulation, const TerrenoConfig & config ) : World(simulation, 1, false, config._resultsFile), _config(config)
{
}

Terreno::~Terreno()
{
}

// Crea las capas de nuestro Terreno
void Terreno::createRasters()
{
	// lee dos datos del gis y los vuelca en un raster
	registerStaticRaster("gis", true);
	Engine::GeneralState::rasterLoader().fillGDALRaster(getStaticRasterStr("gis"),"gis2.jpg",this);
	std::cout << "create rasters" << std::endl;
	//registra la capa que representa la hierba del terreno
	registerDynamicRaster("hierba", true);
	getDynamicRasterStr("hierba").setInitValues(0, 100, 100);
	
	registerDynamicRaster("abono", true);
	//registra la capa que representa el abono
	//se pone el maximo inicial a 0 para que no aumente en cada paso
	//se irá aumentando manualmente a medida que las vacas acaban de pastar
	getDynamicRasterStr("abono").setInitValues(0, 0, 0);
	getDynamicRasterStr("abono").setMaxValue(100);
}

// Crea los Agentes del modelo
void Terreno::createAgents()
{
	std::cout << "create agents" << std::endl;
	//posición del establo de donde parten las Vacas
	Engine::Point2D<int> lugar;
	lugar._x=70;
	lugar._y=280;	
	//recorre todos los agentes
	for(int i=0; i<_config._numAgents; i++)
	{
		//comprueba que la tarea actual contiene el agente
		if((i%_simulation.getNumTasks())==_simulation.getId())
		{
			std::ostringstream oss;
			oss << "Vaca_" << i;
			Vaca * agent = new Vaca(oss.str());
			addAgent(agent);
			agent->setPosition(lugar);
			//prepara la posición de la siguiente Vaca
			lugar._x=lugar._x+1;
			std::cout << "creating agent in " << lugar << std::endl;
			//salta de "linea" para que el establo adquiera forma rectangular
			if (lugar._x> 80) {
				lugar._x=70;
				lugar._y=lugar._y+1;
			}			
		}
	}
}

//Función seno auxiliar para la elipse
double Terreno::sind(double angle)
{
    double angleradians = angle * M_PI / 180.0f;
    return sin(angleradians);
}

//Función coseno auxiliar para la elipse
double Terreno::cosd(double angle)
{
    double angleradians = angle * M_PI / 180.0f;
    return cos(angleradians);
}

} // namespace Tutorial 



