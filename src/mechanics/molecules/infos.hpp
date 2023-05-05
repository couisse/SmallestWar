#ifndef INFOS_HPP_INCLUDED
#define INFOS_HPP_INCLUDED

/** \brief This class holds all informations on molecules specificities
 *  atoms infos are array indexed by atom enum number, cf recursive_structure.hpp
 */

 typedef unsigned int u_int;

struct MoleculeInfos{

    ///the atom number
    static u_int atom_number;

    ///atoms infos
    //the number of boundings that an atom can make
    static u_int* bounding_number;

    //the z value of the atoms
    static u_int* z;

    ///methods
    /** \brief Loads all informations from files
     * \return bool, true if success
     */
    static bool load();

    static void unload();
};

#endif // INFOS_HPP_INCLUDED
