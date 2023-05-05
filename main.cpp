#include <SFML/Graphics.hpp>

#include "src/render/client.hpp"
#include "src/mechanics/molecules/infos.hpp"

int main()
{
    //initialisation and loadings
    if (!MoleculeInfos::load())
        return -1;
    Random::init();

    //launching the client
    Client app;
    app.play();

    //unloading
    MoleculeInfos::unload();

    return 0;
}
