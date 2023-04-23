#ifndef QUADSARRAY_HPP_INCLUDED
#define QUADSARRAY_HPP_INCLUDED

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

/** \brief This class is intended to perform batch rendering with textured (or not textured) quads
 *
 */


class QuadsArray {

public:
    ///Constructor and destructor
    QuadsArray();
    QuadsArray(std::string textureFileName);
    virtual ~QuadsArray();

    ///Mutators
    void newRect(sf::FloatRect position, sf::FloatRect texture = sf::FloatRect(), sf::Color color = sf::Color::White); //allocates a new  rectangle-shaped quad

    void suppress(sf::Vector2u range); //suppress the range of QUAD elements (by index), with the last one not included

    sf::Vertex* access(sf::Vector2u range); //returns a pointer to the first  QUAD element of the specified range of index.
    //Does check if the range (last not included) is valid, but getting out of the range is UB.
    //returns nullptr in case of non-valid range

    void setTexture(std::string textureFileName); //sets the texture for the array.
    //If the argument is empty, then no texture will be applied.
    //If the texture filename is invalid, no texture will be applied

    ///Drawing
    virtual void draw(sf::RenderTarget* target) const; //standard draw function on a render target

private:

    ///Attributes
    //vertices storage
    std::vector<sf::Vertex> m_vertices;
    //texture related stuff
    sf::Texture m_texture;
    sf::RenderStates m_state;
    bool m_isTextured;

};

#endif // QUADSARRAY_HPP_INCLUDED
