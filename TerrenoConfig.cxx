
#include <TerrenoConfig.hxx>

namespace Tutorial
{

TerrenoConfig::TerrenoConfig() : _numAgents(0), _size(0)
{
}

TerrenoConfig::~TerrenoConfig()
{
}

void TerrenoConfig::extractParticularAttribs(TiXmlElement * root)
{
	TiXmlElement * element = root->FirstChildElement("numAgents");
	retrieveAttributeMandatory( element, "value", _numAgents);
	element = root->FirstChildElement("size");
	retrieveAttributeMandatory( element, "value", _size);
}
	
int TerrenoConfig::getSize() const
{
	return _size;
}

} // namespace Tutorial

