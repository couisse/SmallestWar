#ifndef OTHERS_HPP_INCLUDED
#define OTHERS_HPP_INCLUDED

/** \brief Checks if a pointer is not null. Useful for functions requiring predicate
 */
template<class T>
inline bool isNotNull(T* pointer){
    return pointer == nullptr;
}

#endif // OTHERS_HPP_INCLUDED
