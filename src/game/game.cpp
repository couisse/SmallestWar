#include "game.hpp"

Game::Game(){
    this->create(WIN_MODE, "The Smallest War");
    m_tickCount = 0;
    //initializations
    Random::init();
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
        }
    }
}

void Game::update(){

}

void Game::rendering(){
    this->clear();

    this->display();
}
