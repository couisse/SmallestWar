#ifndef MOLECULES_STRUCTURE_HPP_INCLUDED
#define MOLECULES_STRUCTURE_HPP_INCLUDED

#include "infos.hpp"

/** \brief This file serves as the definition of a recursive
 *  definition of molecules. It serves only as a base and is not
 *  used by client nor server.
 */


class RecursiveMolecule{

public:
    static const unsigned short max_children = 4;

    u_int type;
    RecursiveMolecule* below[max_children];

    /** \brief creates a single atom with no neighbors
     */
    RecursiveMolecule(u_int desired_type);

    /** \brief The destructor calls delete on the owned pointers
     *  So if sub-atoms is destroyed by another process, the parent
     *  has to be set to nullptr.
     */
    ~RecursiveMolecule();

    /** \brief Checks if a given molecule model is valid or not, according to
     *  the combination rules of the game
     *  \arg has parent notices the RecursiveMolecule if this method is called
     *  from upper atom.
     */
    bool is_valid(bool has_parent = false);
};



bool is_valid(RecursiveMolecule molecule);

#endif // MOLECULES_STRUCTURE_HPP_INCLUDED
