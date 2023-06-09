#include "client.hpp"

Client::Client(){
    this->create(WIN_MODE, "The Smallest War");
    m_tickCount = 0;

    m_quads.setTexture("assets/pict/units/atoms_tileset.png");

    MoleculeAtomicStructure waterStructure;
    waterStructure.composants.emplace_back(3);
    waterStructure.composants.emplace_back(0);
    waterStructure.composants.emplace_back(0);
    waterStructure.composants[0].others[1] = &waterStructure.composants[1];
    waterStructure.composants[0].others[2] = &waterStructure.composants[2];
    waterStructure.composants[1].others[3] = &waterStructure.composants[0];
    waterStructure.composants[2].others[0] = &waterStructure.composants[0];

    MoleculeRenderingModel model(waterStructure);
    m_molecule = new MoleculeRendereringEntity(model, m_quads, sf::Vector2f(100, 100));
}

Client::~Client(){
    delete m_molecule;
}

void Client::play(){
    sf::Time time;
    while (this->isOpen()){
        m_clock.restart();

        this->manageEvents();
        this->rendering();

        m_tickCount++;
        time=m_clock.getElapsedTime();
        if (m_tickCount%60==1){
            console_log("MSPT (without capping):");
            console_log((int)time.asMilliseconds());
        }
        sf::sleep(TIME_PER_FRAME-time);
    }
}

void Client::manageEvents(){
    sf::Event event;
    while (this->pollEvent(event)){
        if (event.type==sf::Event::Closed){
            this->close();
        }
    }
}

void Client::rendering(){
    this->clear();

    m_molecule->update(TIME_PER_FRAME.asSeconds());

    m_quads.draw(this);

    this->display();
}
