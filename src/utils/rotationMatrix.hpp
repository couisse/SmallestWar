#ifndef ROTATIONMATRIX_HPP_INCLUDED
#define ROTATIONMATRIX_HPP_INCLUDED

#include <SFML/System/Vector2.hpp>

class RotationMatrix{
public:
    RotationMatrix(float angle, sf::Vector2f center);
    ~RotationMatrix();
    const sf::Vector2f apply(const sf::Vector2f& coords) const;
    const sf::Vector2f operator*(const sf::Vector2f& coords) const;

protected:
    float m_matrix[2][2];
    sf::Vector2f m_center;
};

#endif // ROTATIONMATRIX_HPP_INCLUDED
