#include "recursive_structure.hpp"
#include "../../utils/others.hpp"

#include <algorithm>

RecursiveMolecule::RecursiveMolecule(u_int desired_type): type(desired_type){
    for (short i = 0; i < 4; i++){
        below[i] = nullptr;
    }
}

RecursiveMolecule::~RecursiveMolecule(){
}

///validity checking

bool check_bounds(RecursiveMolecule* target, bool has_parent){
    u_int boundings = 1 ? has_parent : 0;
    if (boundings != MoleculeInfos::bounding_number[target->type])
        return false;
    for (u_int i = 0; i < RecursiveMolecule::max_children; i++){
        if (target->below[i] == nullptr)
            continue;
        boundings++;
        if (!check_bounds(target->below[i], true))
            return false;
    }
    return true;
}

bool RecursiveMolecule::is_valid(bool has_parent){
    return check_bounds(this, has_parent);
}
