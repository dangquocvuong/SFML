#include "Aircraft.hpp"

Aircraft::Aircraft(Type type) : mType{ type } {/*constructor*/ }

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);

}