/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:09:30 by dkham             #+#    #+#             */
/*   Updated: 2023/11/17 19:39:03 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
    Data originalData; // create a Data structure and initialize its members
    originalData.intMember = 42;
    originalData.doubleMember = 3.14;
    originalData.charMember = 'A';
    
    // Serialize and deserialize the data
    uintptr_t serializedData = Serializer::serialize(&originalData); // &originalData is a pointer to the originalData structure
    Data* deserializedData = Serializer::deserialize(serializedData);
    
    // Check if the original data and the deserialized data are the same
    if (&originalData == deserializedData) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Orig intMember: " << originalData.intMember << " vs Deserialized intMember: " << deserializedData->intMember << std::endl;
        std::cout << "Orig doubleMember: " << originalData.doubleMember << " vs Deserialized doubleMember: " << deserializedData->doubleMember << std::endl;
        std::cout << "Orig charMember: " << originalData.charMember << " vs Deserialized charMember: " << deserializedData->charMember << std::endl;
    } else {
        std::cout << "Something went wrong!" << std::endl;
    }

    return 0;
}
