#include "particlesManipulator.hpp"


///Generators

//Particle Point

ParticlePoint::ParticlePoint(sf::Vector2f pos, unsigned int number): m_pos(pos), m_number(number) {}

size_t ParticlePoint::generate(sf::VertexArray& target, unsigned int particle_id){
    for (unsigned int i=0; i<m_number; i++){
        ParticleGenerator::createParticleQuad(target, m_pos, particle_id);
    }

    return m_number*4;
}


//Particle Line

ParticleLine::ParticleLine(sf::Vector2f start, sf::Vector2f end, float spacing): m_start(start), m_end(end), m_spacing(spacing) {}

size_t ParticleLine::generate(sf::VertexArray& target, unsigned int particle_id){
    sf::Vector2f current = m_start;
    size_t count(0);
    bool shouldContinue;
    sf::Vector2f direction = normalize(m_end - m_start) * m_spacing;

    do {
        ParticleGenerator::createParticleQuad(target, current, particle_id);
        current+=direction;
        shouldContinue = ( (direction.x>0) ? current.x<=m_end.x : current.x>=m_end.x) && ( (direction.y>0) ? current.y<=m_end.y : current.y>=m_end.y);
        count+=4;
    }while (shouldContinue);
    return count;
}



///Updaters

VertexOffset::VertexOffset(sf::Vector2f offset): m_offset(offset){}

void VertexOffset::update(sf::Vertex& vertex){
    vertex.position += m_offset;
}
