#ifndef SCENENODE_HPP
#define SCENENODE_HPP

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <memory>
#include <vector>
#include <cassert>

class SceneNode : public sf::Transformable, public sf::Drawable,
				  public sf::NonCopyable {
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode();
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);


private:
	virtual void			draw(sf::RenderTarget& target, sf::RenderStates& states) const;
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Ptr>	mChildren;
	SceneNode*			mParent;
};

#endif //SCENENODE_HPP