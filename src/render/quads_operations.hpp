#ifndef QUADS_OPERATIONS_HPP_INCLUDED
#define QUADS_OPERATIONS_HPP_INCLUDED

#include "../utils/rotationMatrix.hpp"

#include <SFML/Graphics.hpp>


/** \brief This class performs a defined translation and
 *  rotation on Quads. It affects only the position of the center
 *  of the Quad, and neither its dimension nor rotation.
 */
class QuadTransform{
public:
    QuadTransform(sf::Vector2f translation, sf::Vector2f rotationCenter, float rotationAngle);
    ~QuadTransform();

    /** \brief Performs the operation on the Quad (4 vertices), wich has
     *  for first vertex the one passed by pointer. If the quad is rectangle,
     *  specifying it will improve performances.
     */
    const void apply(sf::Vertex* target, bool isRectangle) const;

    /** \brief Applies the above function on the first "number" quads in the targeted
     *  array, assuming it is contiguous memory.
     */
    const void applyOnMultiple(sf::Vertex* target, size_t number, bool areRectangle) const;

protected:
    RotationMatrix m_rotator;
    sf::Vector2f m_translation;
};

#endif // QUADS_OPERATIONS_HPP_INCLUDED
