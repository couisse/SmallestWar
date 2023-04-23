#include "quadsarray.hpp"

QuadsArray::QuadsArray(){
}

QuadsArray::QuadsArray(std::string textureFileName){
    this->setTexture(textureFileName);
}

QuadsArray::~QuadsArray(){
}


void QuadsArray::newRect(sf::FloatRect position, sf::FloatRect texture, sf::Color color){
    m_vertices.reserve(m_vertices.size()+4);

    m_vertices.emplace_back(    sf::Vector2f(position.left, position.top),
                                color,
                                sf::Vector2f(texture.left, texture.top)
                            );

    m_vertices.emplace_back(    sf::Vector2f(position.left + position.width, position.top),
                                color,
                                sf::Vector2f(texture.left + texture.width, texture.top)
                            );

    m_vertices.emplace_back(    sf::Vector2f(position.left + position.width, position.top + position.height),
                                color,
                                sf::Vector2f(texture.left + texture.width, texture.top + texture.height)
                            );

    m_vertices.emplace_back(    sf::Vector2f(position.left, position.top + position.height),
                                color,
                                sf::Vector2f(texture.left, texture.top + texture.height)
                            );
}


void QuadsArray::suppress(sf::Vector2u range){
    m_vertices.erase(m_vertices.begin() + (range.x << 2) , m_vertices.begin() + (range.y << 2));
}


sf::Vertex* QuadsArray::access(sf::Vector2u range){
    if (range.y > range.x && (range.y << 2) <= m_vertices.size()){
        return &m_vertices[range.x];
    }
    return nullptr;
}

void QuadsArray::setTexture(std::string textureFileName){
    m_isTextured = textureFileName != "";
    if (m_isTextured && !m_texture.loadFromFile(textureFileName)){
        //use lazy evaluation to perform the texture loading only if the argument is not empty
        m_isTextured = false; //in case of texture loading failure
    }
    m_state.texture = &m_texture;
}

void QuadsArray::draw(sf::RenderTarget* target) const {
    if (m_isTextured){
        target->draw(&m_vertices[0], m_vertices.size(), sf::Quads, m_state);
    }else {
        target->draw(&m_vertices[0], m_vertices.size(), sf::Quads);
    }
}
