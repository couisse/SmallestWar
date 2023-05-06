#ifndef QUADSARRAY_HPP_INCLUDED
#define QUADSARRAY_HPP_INCLUDED

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

/** \brief This class is intended to perform batch rendering with textured (or not textured) quads
 *
 */

 typedef unsigned int u_int;


class QuadsArray {

public:
    ///Constructor and destructor
    QuadsArray();
    QuadsArray(std::string textureFileName);
    virtual ~QuadsArray();

    ///Mutators
    /** \brief allocates a new  rectangle-shaped quad and returns its position in array
     */
    u_int newRect(sf::FloatRect position, sf::FloatRect texture = sf::FloatRect(), sf::Color color = sf::Color::White);

    /** \brief suppress the range of QUAD elements (by index), with the last one not included
     */
    void suppress(sf::Vector2u range);

    /** \brief returns a pointer to the first  QUAD element of the specified range of index.
     *  Does check if the range (last not included) is valid, but getting out of the range is UB.
     *  returns nullptr in case of non-valid range
     */
    sf::Vertex* access(sf::Vector2u range);

    /** \brief sets the texture for the array.
     *  If the argument is empty, then no texture will be applied.
     *
     */
    void setTexture(std::string textureFileName);

    ///Drawing
    /** \brief standard draw function on a render target
     */
    virtual void draw(sf::RenderTarget* target) const;

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
