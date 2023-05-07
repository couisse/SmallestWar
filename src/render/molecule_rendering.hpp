#ifndef MOLECULE_RENDERING_HPP_INCLUDED
#define MOLECULE_RENDERING_HPP_INCLUDED

#include "quadsarray.hpp"
#include "../mechanics/molecules/molecule_structure.hpp"

class MoleculeRenderingModel;

/** \brief This class is managing the vertices of one molecule
 *  It is in charge of rotation, animation, translation...
 *  It can't be created by itself, it must be generated via a model.
 */
class MoleculeRendereringEntity{

public:
    /** \brief The entity can only be created with a rendering model to determinated
     *  its shape.
     */
    MoleculeRendereringEntity(MoleculeRenderingModel& model, QuadsArray& verticesHolder, sf::Vector2f position);

    ~MoleculeRendereringEntity();

    /** \brief Causes the update of animation and position;
     */
    void update(float dt);

protected:
    sf::Vector2u m_range;
    QuadsArray& m_verticesHolder;
    sf::Vector2f m_position;
    float m_angle;
    float m_angularSpeed;
};


/** \brief This class holds the information of how creating a specific
 *  molecule. It is in charge of creating the Renderers, allocate vertices...
 */

class MoleculeRenderingModel{

public:

    /** \brief The model is created from a structure. It is converted in rendering data
     */
    MoleculeRenderingModel(MoleculeAtomicStructure& structure);

    ~MoleculeRenderingModel();

    /** \brief Generates all the vertices to represent the molecule corresponding
     *  to the model, centered at the given position.
     *  returns the range [first, last) of new Quads.
     */
    sf::Vector2u generateVertices(QuadsArray& target, sf::Vector2f position);

    /** \brief Simple accessor to retrieve number of atoms in this model
     */
    const u_int getAtomNumber() const;

    /** \brief Generates / releases ressources all Models have in common
     *
     */
    static bool init();
    static void unload();

protected:

    static sf::FloatRect* texture_quads;

    struct AtomPlace{
        sf::Vector2f relativePos;
        u_int quadNumber;
    };

    AtomPlace* m_atoms;
    size_t m_atomsNumber;
};

#endif // MOLECULE_RENDERING_HPP_INCLUDED
