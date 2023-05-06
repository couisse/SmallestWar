#ifndef CLIENT_HPP_INCLUDED
#define CLIENT_HPP_INCLUDED

#include "molecule_rendering.hpp"
#include "../utils/random.hpp"
#include "../utils/macros.hpp"
#include "../utils/consts.hpp"

/** \brief This class is intended to manage the window and the rendering.
    It has no effect on the gameplay, except the task of collection user events
    and sending it to the server via ClientServerInteraction
 */

class Client: public sf::RenderWindow {

public:
    Client();
    ~Client();
    /** \brief Main loop of the client
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


    ///attributes
    long m_tickCount;
    sf::Clock m_clock;
    QuadsArray m_quads;

};

#endif // CLIENT_HPP_INCLUDED
