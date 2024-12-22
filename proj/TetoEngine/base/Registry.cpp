#include "base/Registry.hpp"

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
