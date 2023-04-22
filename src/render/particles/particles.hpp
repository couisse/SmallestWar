#ifndef PARTICLES_HPP_INCLUDED
#define PARTICLES_HPP_INCLUDED

#include <vector>

#include <SFML/Graphics.hpp>

#include "../../utils/consts.hpp"

/** \brief Base class
 *          Used to generate a set of vertices for the particles system
 *          Returns the number of vertices created (should be a multiple of 4)
 */
class ParticleGenerator{
public:
    static void createParticleQuad(sf::VertexArray& target, sf::Vector2f pos, unsigned int particle_id); ///convenience function used to create a basic quad for a particle (centered on pos)

    virtual ~ParticleGenerator(){}
    virtual size_t generate(sf::VertexArray& target, unsigned int particle_id){return 0;}; ///main function of the generator: to overload
};

/** \brief Base class
 *          Used to update in place each vertex of a particle system
 *          Default behavior: vertices are not changed
 *          Copy constructor has to be implemented
 */
class ParticleUpdater{
public:
    virtual ~ParticleUpdater(){}
    virtual void update(sf::Vertex& vertex){} ///is called on each vertex of a partical system
    virtual ParticleUpdater* copy() {return new ParticleUpdater(*this);} //to overload
};

/** \brief Handles a fragment of the vertices contained in the Particles class
 *          Represent a "cloud" of particles with its own behavior
 */
class ParticlesSystem{

protected:
    ParticleUpdater* m_updater;
    sf::Vector2u m_range;
    sf::VertexArray* m_refHolder;

public:
    ParticlesSystem(ParticleUpdater* updater, sf::Vector2u range, sf::VertexArray* holder);
    ~ParticlesSystem();
    void update();
};

/** \brief Allows the creation and the management of multiple particle system
 *          Centralized class which handle all vertices related to particles and
 *          the movements of them.
 */
class Particles{
protected:
    sf::VertexArray m_array;
    std::vector<ParticlesSystem> m_systems;
    sf::Texture m_texture;

public:
    Particles();
    ~Particles();
    void update();

    /** \brief used to create a new system of particles
     *          pointers are used to allow derivated class call, but the updater is copied
     *          and the generator is used and not kept nor destroyed
     *          so to call this method the best is to use heap-created objects and provide
     *          a reference to objects, like:
     *
     *          ParticleGenerator gen;
     *          ParticleUpdater up;
     *          particles.addParticles(&gen, &up); ///assuming particles is already created
     */
    void addParticles(ParticleGenerator* generator, ParticleUpdater* updater, unsigned int particle_id);
    void render(sf::RenderWindow* target);
};

enum ParticleID{FIRE, WATER};

#endif // PARTICLES_HPP_INCLUDED
