/**
 * WIP
 * For handling all registration of tracked objects, e.g. textures, etc.
 */
#pragma once

#include <string>
#include <utility>
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
}