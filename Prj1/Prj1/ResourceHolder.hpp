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
