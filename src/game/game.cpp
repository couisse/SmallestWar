#include "game.hpp"

Game::Game(){
    this->create(WIN_MODE, "Forgery");
    m_tickCount = 0;
    //initializations
    Random::init();
    //ParticleLine gen(sf::Vector2f(50,50), sf::Vector2f(0, 139), 20);
    ParticlePoint gen(sf::Vector2f(100,100), 10);
    VertexOffset up(sf::Vector2f(0,0.1));
    m_particles.addParticles(&gen, &up, WATER);
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
    m_particles.update();
}

void Game::rendering(){
    this->clear();
    m_particles.render(this);
    this->display();
}
