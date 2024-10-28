#pragma once
#include <SFML/Graphics.hpp>
#include <cassert>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    void                    load(Identifier id, const std::string& filename);

    template <Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& secondParam);


    Resource&               get(Identifier id);
    const Resource&         get(Identifier id) const;

private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "ResourceHolder.inl"


//This block below is the initial implementation in case the resource is TextureHolder
#ifdef 0

namespace Textures
{
    enum ID
    {
        Landscape,
        Airplane,
        Missile
    };
}


class TextureHolder
{
private:
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
public:
    void                    load(Textures::ID id, const std::string& filename);
    sf::Texture& get(Textures::ID id);
    const sf::Texture& get(Textures::ID id) const;
};

/*
TextureHolder::load() is used to load a resource into the map
Parameters:
- id: identifier used as a key to store the resource in the map
- filename: path to texture(i.e. image)
- return: void
*/
void TextureHolder::load(Textures::ID id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    if (!texture->loadFromFile(filename))
        throw std::runtime_error("TextureHolder::load() -- Failed to load " + filename);

    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);
}

/*
TextureHolder::get() method is used to find an id in the map
Parameters:
- id: identifier of the texture in the map
return:
*/
sf::Texture& TextureHolder::get(Textures::ID id)
{
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());

    return *found->second;
}

const sf::Texture& TextureHolder::get(Textures::ID id) const
{
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());

    return *found->second;
}

#endif