#include "game.hpp"

Game::Game(){
    this->create(WIN_MODE, "The Smallest War");
    m_tickCount = 0;
    //initializations
    Random::init();

    m_quads.setTexture("assets/pict/units/atoms_tileset.png");
    m_quads.newRect(sf::FloatRect(50, 50, 100, 100), sf::FloatRect(0, 0, 50, 50));
    m_quads.newRect(sf::FloatRect(200, 200, 100, 100), sf::FloatRect(50, 0, 50, 50));
}

Game::~Game(){
}

void Game::play(){
    sf::Time time;
    while (this->isOpen()){
        m_clock.restart();

        this->manageEvents();
        this->update();
        this->rendering();

        m_tickCount++;
        time=m_clock.getElapsedTime();
        if (m_tickCount%60==1){
            log("MSPT (without capping):");
            log((int)time.asMilliseconds());
        }
        sf::sleep(TIME_PER_FRAME-time);
    }
}

void Game::manageEvents(){
    sf::Event event;
    while (this->pollEvent(event)){
        if (event.type==sf::Event::Closed){
            this->close();
        }else if (event.type == sf::Event::KeyPressed){
            log(m_quads.access(sf::Vector2u(0,1))->position.x);
            m_quads.suppress(sf::Vector2u(0,1));
        }
    }
}

void Game::update(){

}

void Game::rendering(){
    this->clear();

    m_quads.draw(this);

    this->display();
}
