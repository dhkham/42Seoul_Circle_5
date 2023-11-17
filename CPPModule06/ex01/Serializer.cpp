/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:09:08 by dkham             #+#    #+#             */
/*   Updated: 2023/11/17 19:41:18 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr); // takes a pointer and returns an unsigned integer type uintptr_t
}

/*
reinterpret_cast performs a conversion between pointer types or between pointer and integer types, without doing any safety checks. 
This kind of cast is quite low-level and can be dangerous because it allows you to perform almost any cast, 
even those that are not meaningful or safe.

The function is casting a pointer (of type Data*) to an unsigned integer type uintptr_t. 
The uintptr_t type is an integral type that's guaranteed to be large enough to hold a pointer without loss of information, 
which makes it useful when you need to perform integer operations on pointers.

The reinterpret_cast is used to directly interpret the bit-pattern of the pointer as an integer. 
In simpler terms, it treats the memory address that the pointer ptr is holding as a number.
*/

Data* Serializer::deserialize(uintptr_t raw) { // takes an uintptr_t and returns a pointer to Data
    return reinterpret_cast<Data*>(raw);
}

/*
While serialize converted a Data* pointer into an unsigned integer type uintptr_t, the deserialize function does the reverse: 
it takes an uintptr_t (which should ideally be a value previously obtained from serialize) 
and converts it back to a Data* pointer.
*/
