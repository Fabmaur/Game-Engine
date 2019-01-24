#include <Vector>
#include "graphics/renderer/Sprite.h"


class 2DRenderer
{
public:
	virtual void Push() = 0;
	virtual void Flush() = 0;
private:
	std::vector<Sprite> sprites;
}