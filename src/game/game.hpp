#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "../render/particles/particlesManipulator.hpp"
#include "../utils/macros.hpp"

/** \brief Main class of the app
 */

class Game: public sf::RenderWindow {

public:
    Game();
    ~Game();
    /** \brief Main loop of the app
    */
    void play();

protected:

    ///Internal methods
    /** \brief calls for all rendering-related method and display the frame
    */
    void rendering();

    /** \brief processes the events pile
    */
    void manageEvents();

    /** \brief calculates the next frame of the app
     */
    void update();


    ///attributes
    long m_tickCount;
    sf::Clock m_clock;
    Particles m_particles;

};

#endif // GAME_HPP_INCLUDED
