/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:09:30 by dkham             #+#    #+#             */
/*   Updated: 2023/11/01 19:21:41 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
    Data originalData;
    originalData.intMember = 42;
    originalData.doubleMember = 3.14;
    originalData.charMember = 'A';
    
    // Serialize and deserialize the data
    uintptr_t serializedData = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(serializedData);
    
    // Check if the original data and the deserialized data are the same
    if (&originalData == deserializedData) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Something went wrong!" << std::endl;
    }

    return 0;
}
