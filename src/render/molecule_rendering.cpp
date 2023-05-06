#include "molecule_rendering.hpp"

#include "../utils/rotationMatrix.hpp"
#include "../utils/macros.hpp"

MoleculeRendereringEntity::MoleculeRendereringEntity(MoleculeRenderingModel& model, QuadsArray& verticesHolder, sf::Vector2f position){
    m_range = model.generateVertices(verticesHolder, position);
    RotationMatrix matrix(0.392698, sf::Vector2f(100, 100));
    sf::Vertex* target = verticesHolder.access(m_range);
    for (u_int i = m_range.x << 2; i < m_range.y << 2; i++){
        console_log(target[i].position.x);
        target[i].position = matrix * target[i].position;
        console_log(target[i].position.x);
        console_log("----------------");
    }
}

MoleculeRendereringEntity::~MoleculeRendereringEntity(){
}

void MoleculeRendereringEntity::update(double dt){
}

/** Model **/

struct OptionalVector2f{
    sf::Vector2f value;
    bool exist;
};

/** \brief This function is placing an atom in the molecule grid
 *
 * \param places: the array of placements of the atoms
 * \param known: the number of already placed atoms. These atoms have the
 * "known" first placements in the "places" array
 * \param origin: the pointer on the origin Atom. Atoms have to lie in a
 * contiguous memory space, to use pointer arithmetic on it. Therefore, the
 * nth considered atom should have pointer origin + n
 * \param toPlace: a pointer on the atom to place
 * \param iteration: recursive arguments that prevents looping in a pointer cycle, causing crash
 * \return The position of the atom in the molecule grid, relative to the root
 *  (If it can manage to find it). If not, then it will return (0, 0) and indicate
 *  the failure with the optional bool part of the struct.
 */
OptionalVector2f getIdx(sf::Vector2f* places, u_int known, Atom* origin, Atom* toPlace, unsigned short iteration = 0){
    if (toPlace == nullptr || iteration > 15)
        return {sf::Vector2f(0,0), false}; //fail case

    u_int atomIdx = toPlace-origin; //retrieving the Atom's index via pointer arithmetic

    if (atomIdx < known){
        return {places[atomIdx], true}; //base case: the position was already calculated
    }

    for (u_int i = 0; i < Atom::max_neighbours; i++){ //heredity: search a known atom by exploring liaisons
        OptionalVector2f result = getIdx(places, known, origin, toPlace->others[i], iteration + 1);
        if (result.exist){
            sf::Vector2f offset(i == 1 ? -1 : (i == 3 ? 1 : 0),
                                i == 0 ? 1 : (i == 2 ? -1 : 0));
            return {result.value + offset, true};
        }
    }
    return {sf::Vector2f(0,0), false}; //no path was find to a known location
}

MoleculeRenderingModel::MoleculeRenderingModel(MoleculeAtomicStructure& structure){
    m_atomsNumber = structure.composants.size();
    m_atoms = new AtomPlace[m_atomsNumber];

    //placing the atoms
    sf::Vector2f positions[m_atomsNumber];
    Atom* origin = &structure.composants[0];
    positions[0] = sf::Vector2f(0,0);
    for (u_int i = 1; i < m_atomsNumber; i++){
        OptionalVector2f result = getIdx(positions, i, origin, origin+i);
        positions[i] = result.value;
    }

    //calculating the barycenter
    sf::Vector2f barycenter;
    float divider = 0;
    for (u_int i = 0; i < m_atomsNumber; i++){
        barycenter += positions[i] * (float)MoleculeInfos::z[structure.composants[i].type];
        divider += MoleculeInfos::z[structure.composants[i].type];
    }
    barycenter /= divider;

    //generating the graphical values
    for (u_int i = 0; i < m_atomsNumber; i++){
        m_atoms[i].relativePos.x = (positions[i].x + barycenter.x) * 50.f;
        m_atoms[i].relativePos.y = (positions[i].y + barycenter.y) * 50.f;
        m_atoms[i].quadNumber = structure.composants[i].type;
    }
}

MoleculeRenderingModel::~MoleculeRenderingModel(){
    delete[] m_atoms;
}

sf::Vector2u MoleculeRenderingModel::generateVertices(QuadsArray& target, sf::Vector2f position){
    sf::Vector2u range;
    sf::FloatRect base(0,0,50,50);
    for (u_int i = 0; i < m_atomsNumber; i++){
        base.left = m_atoms[i].relativePos.x + position .x;
        base.top = m_atoms[i].relativePos.y + position.y;
        range.y = target.newRect(base, MoleculeRenderingModel::texture_quads[m_atoms[i].quadNumber]);
    }
    range.y += 1;
    range.x = range.y - m_atomsNumber;
    return range;
}

const u_int MoleculeRenderingModel::getAtomNumber() const {
    return m_atomsNumber;
}

sf::FloatRect* MoleculeRenderingModel::texture_quads;

bool MoleculeRenderingModel::init(){
    texture_quads = new sf::FloatRect[MoleculeInfos::atom_number];
    for (u_int i = 0; i < MoleculeInfos::atom_number; i++){
        texture_quads[i].left = i * 50.f;
        texture_quads[i].top = 0.f;
        texture_quads[i].height = 50;
        texture_quads[i].width = 50;
    }
    return true;
}

void MoleculeRenderingModel::unload(){
    delete[] texture_quads;
}
