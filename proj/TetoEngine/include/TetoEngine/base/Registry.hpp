#pragma once

#include <unordered_map>
namespace teto
{
    template<typename K, typename T>
    class Registry
    {
        public:
            virtual T& get(K);
            virtual void clear();
            virtual void add(K key, T val);

        protected:
            std::unordered_map<K,T> registry;
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
    //registry.emplace(std::make_pair<K,T>(key,val));
    //registry[key] = val;
    //registry.emplace(std::make_pair<K,T>(key, val));
}
