/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:26:35 by dkham             #+#    #+#             */
/*   Updated: 2023/11/17 20:08:59 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Base* generate(void) { // generate a random instance of Base and return it as a Base pointer
    switch (rand() % 3) {
        // print the type of the instance created
        case 0: {
            std::cout << "A instance created" << std::endl;
            return new A;
        }
        case 1: {
            std::cout << "B instance created" << std::endl;
            return new B;
        }
        default: {
            std::cout << "C instance created" << std::endl;
            return new C;
        }
    }
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl; // if dynamic cast succeeds, it returns a non-null pointer
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
    else std::cout << "Unknown type" << std::endl;
}
/*
Dynamic_cast is used to convert a pointer or reference of a base class to a pointer or reference of a derived class (for safe downcasting).
Unlike static_cast, which performs the cast at compile time without checks, dynamic_cast performs a runtime check.
*/


void identify(Base& p) {
    int cnt = 0;

    for (int i = 0; i < 3; i++) {
        try {
            switch (i) {
                case 0:
                    (void)dynamic_cast<A&>(p);
                    std::cout << "A" << std::endl;
                    break;
                case 1:
                    (void)dynamic_cast<B&>(p);
                    std::cout << "B" << std::endl;
                    break;
                case 2:
                    (void)dynamic_cast<C&>(p);
                    std::cout << "C" << std::endl;
                    break;
            }
        }
        catch (std::exception&) { // if dynamic cast throws an exception, it means that the type is wrong
            cnt++;
        }
    }
    if (cnt == 3) // if all dynamic casts throw an exception, it means that the type is unknown
        std::cout << "Unknown type" << std::endl;
}
/*
Dynamic_cast throws a std::bad_cast exception when used with "references" and the cast is invalid.
This behavior provides a way to enforce type safety in a polymorphic class hierarchy.
When used with "pointers", it provides a safer mechanism by returning nullptr for invalid casts, allowing the programmer to handle such cases gracefully.
*/