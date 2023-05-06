#include "molecule_structure.hpp"
#include "../../utils/others.hpp"

#include <algorithm>

Atom::Atom(u_int desiredType): type(desiredType) {
    for (u_int i = 0; i < Atom::max_neighbours; i++){
        others[i] = nullptr;
    }
}



MoleculeAtomicStructure::MoleculeAtomicStructure(){
}

MoleculeAtomicStructure::~MoleculeAtomicStructure(){
}

///validity checking

bool check_atoms(MoleculeAtomicStructure* target){
    for (u_int i = 0; i < target->composants.size(); i++){
        if (target->composants[i].type > MoleculeInfos::atom_number){
            return false;
        }
    }
    return true;
}

bool check_bounds(MoleculeAtomicStructure* target){
    u_int boundings;
    for (u_int i = 0; i < target->composants.size(); i++){
        boundings = 0;
        for (u_int j = 0; j < Atom::max_neighbours; j++){
            if (target->composants[i].others[j] != nullptr)
                boundings++;
        }
        if (boundings != MoleculeInfos::bounding_number[target->composants[i].type])
            return false;
    }
    return true;
}

bool MoleculeAtomicStructure::isValid(){
    return check_atoms(this) && check_bounds(this);
}
