
#ifndef __TerrenoConfig_hxx__
#define __TerrenoConfig_hxx__

#include <Config.hxx>

namespace Tutorial
{

class TerrenoConfig : public Engine::Config
{	
	int _numAgents;
	int _size;
public:
	TerrenoConfig();
	virtual ~TerrenoConfig();

	void extractParticularAttribs(TiXmlElement *pRoot);

	int getSize() const;

	friend class Terreno;
};

} // namespace Tutorial

#endif // __TerrenoConfig_hxx__

