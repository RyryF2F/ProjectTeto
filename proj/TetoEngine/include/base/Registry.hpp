/**
 * WIP
 * For handling all registration of tracked objects, e.g. textures, etc.
 */
#pragma once

#include "pch.h"
//#include <memory>
#include <unordered_map>

namespace teto
{
    
    /**
     * Used with a tracked enum, etc.
     */
    template<typename K, typename T>
    class Registry
    {
        public:
            virtual T& get(K);
            virtual void clear(); //= 0
            virtual void add(K key, T val);
        protected:
            std::unordered_map<K,T> registry;
    };


    template<typename T>
    class KeyedRegistry : public Registry<std::string,T>
    {
    };

    template<typename T>
    class IndexRegistry : public Registry<int,T>
    {
    };
}

template <typename K, typename T>
void teto::Registry<K,T>::clear()
{
    registry.clear();
}

template <typename K, typename T>
T& teto::Registry<K,T>::get(K val)
{
    return registry.at(val);
}

template <typename K, typename T>
void teto::Registry<K,T>::add(K key, T val)
{
    registry.insert(key,val);
}
