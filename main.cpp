#include <SFML/Graphics.hpp>

#include "src/render/client.hpp"
#include "src/mechanics/molecules/infos.hpp"

int main()
{
    //initialization and loadings
    if (! (MoleculeInfos::load() && MoleculeRenderingModel::init()) )
        return -1;
    Random::init();

    //launching the client
    Client app;
    app.play();

    //unloading
    MoleculeInfos::unload();
    MoleculeRenderingModel::unload();

    return 0;
}
