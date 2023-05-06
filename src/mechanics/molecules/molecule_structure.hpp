#ifndef MOLECULES_STRUCTURE_HPP_INCLUDED
#define MOLECULES_STRUCTURE_HPP_INCLUDED

#include "infos.hpp"

#include <vector>

/** \brief This file serves as the definition of a base
 *  structure for molecules. It serves only as a base and is not
 *  used by client nor server.
 */

 struct Atom{
    static const unsigned short max_neighbours = 4;
    u_int type;
    Atom* others[max_neighbours];
    Atom(u_int desiredType); //sets neighbors to nullptr
 };


class MoleculeAtomicStructure{

public:
    static const unsigned short max_children = 4;

    u_int type;
    std::vector<Atom> composants;

    /** \brief creates a empty molecule
     */
    MoleculeAtomicStructure();

    /** \brief No special action of the destructor
     */
    ~MoleculeAtomicStructure();

    /** \brief Checks if a given molecule model is valid or not, according to
     *  the combination rules of the game
     */
    bool isValid();
};


#endif // MOLECULES_STRUCTURE_HPP_INCLUDED
