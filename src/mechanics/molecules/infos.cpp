#include "infos.hpp"

//static allocation
u_int MoleculeInfos::atom_number = 0;
u_int* MoleculeInfos::bounding_number = nullptr;
u_int* MoleculeInfos::z = nullptr;

bool MoleculeInfos::load(){

    MoleculeInfos::atom_number = 5;

    MoleculeInfos::bounding_number = new u_int[5];
    MoleculeInfos::bounding_number[0] = 1;
    MoleculeInfos::bounding_number[1] = 0;
    MoleculeInfos::bounding_number[2] = 4;
    MoleculeInfos::bounding_number[3] = 2;
    MoleculeInfos::bounding_number[4] = 3;

    MoleculeInfos::z = new u_int[5];
    MoleculeInfos::z[0] = 1;
    MoleculeInfos::z[1] = 2;
    MoleculeInfos::z[2] = 6;
    MoleculeInfos::z[3] = 8;
    MoleculeInfos::z[4] = 7;
    return true;
}

void MoleculeInfos::unload(){
    delete[] MoleculeInfos::bounding_number;
    delete[] MoleculeInfos::z;
}
