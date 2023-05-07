#include "quads_operations.hpp"

#include "../utils/macros.hpp"

typedef unsigned int u_int;

QuadTransform::QuadTransform(sf::Vector2f translation, sf::Vector2f rotationCenter, float rotationAngle)
    : m_rotator(rotationAngle, rotationCenter), m_translation(translation) {
}

QuadTransform::~QuadTransform(){
}

const void QuadTransform::apply(sf::Vertex* target, bool isRectangle = false) const {
    sf::Vector2f deltas[4];
    sf::Vector2f center(0,0);
    //retrieving center
    if (isRectangle){
        center.x = (target[0].position.x + target[1].position.x) * 0.5;
        center.y = (target[0].position.y + target[3].position.y) * 0.5;
    }else {
        for (unsigned short i = 0; i < 4; i++){
            center += target[i].position;
        }
        center *= 0.25f;
    }
    //getting the relative positions of the points to the center
    for (unsigned short i = 0; i < 4; i++){
            deltas[i] = target[i].position - center;
    }
    //transforming center
    center += m_translation;
    console_log(center.x);
    console_log(center.y);
    console_log("---------");
    center = m_rotator * center;
    //putting back the points
    for (unsigned short i = 0; i < 4; i++){
        target[i].position = center + deltas[i];
    }
}

const void QuadTransform::applyOnMultiple(sf::Vertex* target, size_t number, bool areRectangles) const{
    for (u_int i = 0; i < number; i++){
        this->apply(target + (i << 2), areRectangles);
    }
}
