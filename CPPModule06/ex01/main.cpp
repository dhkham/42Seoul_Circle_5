/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:09:30 by dkham             #+#    #+#             */
/*   Updated: 2023/10/31 21:09:31 by dkham            ###   ########.fr       */
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

    uintptr_t serializedData = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(serializedData);

    if (&originalData == deserializedData) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Something went wrong!" << std::endl;
    }

    return 0;
}
