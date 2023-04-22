#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <cmath>

#include <SFML/System.hpp>

template<class T>
inline float dot(const sf::Vector2<T>& a, const sf::Vector2<T>& b){
    return a.x * b.x + a.y + b.y;
}

template<class T>
inline float lenght(const sf::Vector2<T>& source){
    return sqrt(source.x * source.x + source.y * source.y);
}

template<class T>
inline sf::Vector2<T> normalize(const sf::Vector2<T>& source){
    return source/lenght(source);
}

#endif // VECTOR_HPP_INCLUDED
