#include "Vaca.hxx"
#include <iostream>
#include <Point2D.hxx>
#include <GeneralState.hxx>
#include <Statistics.hxx>

namespace Tutorial
{

Vaca::Vaca( const std::string & id ) : Agent(id), _llegado(false), _count(0)
{
}

Vaca::~Vaca()
{
}

//El primer cuarto de los pasos totales los dedica a acercarse al embalse únicamente
//Come hierba durante 10 pasos. Una vez terminado se mueve una posicion que no sea agua.
//Abona a las casillas adyacentes un vez terminado.
void Vaca::updateState()
{
	if (getId()=="Vaca_0") {
		std::cout << "step num: " << _world->getCurrentStep() << std::endl;
    }
	Engine::Point2D<int> newPosition = getPosition();
	//comprueba si está en el primer cuarto de los pasos totales y aún no ha llegado al embalse
	if (_world->getCurrentStep()<_world->getSimulation().getNumSteps()*0.25 && !_llegado) {
		do {
			newPosition = getPosition();
			// se mueve una serie de pasos positivos (acercándose al embalse)
			newPosition._x += Engine::GeneralState::statistics().getUniformDistValue(-4,10);
			newPosition._y -= Engine::GeneralState::statistics().getUniformDistValue(0,5);
		} while (_world->checkPosition(newPosition)==false);
		//comprueba si ha llegado al embalse
		if (_world->getValueStr("gis", newPosition)!=210) {
			_llegado=true;
		} else {
			setPosition(newPosition);
		}		
	} else {
		//std::cout << "updating state for agent: " << this << std::endl;
		// comprueba si lleva menos de 10 pasos en esa posición y si aún queda hierba
		if(_count<10 && _world->getValueStr("hierba", _position)>5) {
			int restante=_world->getValueStr("hierba", _position);
			//come hierba de esa casilla
			_world->setValueStr("hierba", _position, restante-5);
			_count++;
		} else {
			//se mueve 3 casillas aleatoriamente una vez ha terminado de comer
			do {
				newPosition = getPosition();
				newPosition._x += Engine::GeneralState::statistics().getUniformDistValue(-3,3);
				newPosition._y += Engine::GeneralState::statistics().getUniformDistValue(-3,3);
			//comprueba que se puede mover a esa casilla
			} while (_world->checkPosition(newPosition)==false || _world->getValueStr("gis", newPosition)!=210);
			//abona las posiciones adyacentes aumentando el valor de la capa abono
			Engine::Point2D<int> arriba (_position._x,_position._y-1); 
			Engine::Point2D<int> abajo (_position._x,_position._y+1); 
			Engine::Point2D<int> izquierda (_position._x-1,_position._y); 
			Engine::Point2D<int> derecha (_position._x+1,_position._y); 
			_world->setMaxValue("abono", _position, _world->getValueStr("abono", _position)+1 );
			if (_world->checkPosition(arriba))
				_world->setMaxValue("abono", _position, _world->getValueStr("abono", arriba)+1 );
			if (_world->checkPosition(abajo))
				_world->setMaxValue("abono", _position, _world->getValueStr("abono", abajo)+1 );
			if (_world->checkPosition(izquierda))
				_world->setMaxValue("abono", _position, _world->getValueStr("abono", izquierda)+1 );
			if (_world->checkPosition(derecha))
				_world->setMaxValue("abono", _position, _world->getValueStr("abono", derecha)+1 );
			setPosition(newPosition);
			_count=0;	
	 	}
	}
}

void Vaca::serialize()
{
	//serializeAttribute("resources", _gatheredResources);
}

void Vaca::registerAttributes()
{
	//registerIntAttribute("resources");
}

} // namespace Tutorial
