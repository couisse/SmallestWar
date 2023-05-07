#include "rotationMatrix.hpp"

#include <cmath>

RotationMatrix::RotationMatrix(float angle, sf::Vector2f center): m_center(center) {
    m_matrix[0][0] = cos(angle);
    m_matrix[0][1] = sin(angle);
    m_matrix[1][0] = -m_matrix[0][1];
    m_matrix[1][1] = m_matrix[0][0];
}

RotationMatrix::~RotationMatrix(){
}

const sf::Vector2f RotationMatrix::apply(const sf::Vector2f& coords) const {
    sf::Vector2f result = coords - m_center; //translating on center of rotation
    result = sf::Vector2f(
                        m_matrix[0][0] * result.x + m_matrix[1][0] * result.y,
                        m_matrix[1][0] * result.x + m_matrix[1][1] * result.y); //applying rotation
    result += m_center; //translating back
    return result;
}

const sf::Vector2f RotationMatrix::operator*(const sf::Vector2f& coords) const {
    return this->apply(coords);
}
