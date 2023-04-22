#ifndef CONSTS_HPP_INCLUDED
#define CONSTS_HPP_INCLUDED

#include <SFML/System.hpp>

///Window managment
const sf::VideoMode WIN_MODE(200,200);
const sf::Time TIME_PER_FRAME = sf::milliseconds(33);

///Particles managment
const sf::Vector2f PARTICLE_SIZE(15,15);
const sf::Vector2f HALF_PARTICLE = 0.5f*PARTICLE_SIZE;

#endif // CONSTS_HPP_INCLUDED
