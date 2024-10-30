#include "Aircraft.hpp"

Aircraft::Aircraft(Type type, const TextureHolder& textures) : 
	mType(type), 
	mSprite(textures.get(toTextureID(type))) 
{
	/*constructor*/
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);

}