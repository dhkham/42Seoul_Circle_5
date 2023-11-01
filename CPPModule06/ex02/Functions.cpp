/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:26:35 by dkham             #+#    #+#             */
/*   Updated: 2023/11/01 20:50:02 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Base* generate(void) {
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
/*
It randomly instanciates A, B or C and returns the instance as a Base pointer.
Feel free to use anything you like for the random choice implementation.
*/

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl; // if dynamic cast succeeds, it returns a non-null pointer
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
    else std::cout << "Unknown type" << std::endl;
}
// It prints the actual type of the object pointed to by p: "A", "B" or "C".

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
        catch (std::exception&) {
            cnt++;
        }
    }
    if (cnt == 3)
        std::cout << "Unknown type" << std::endl;
}

// void identify(Base& p) {
//     try {
//         A& a = dynamic_cast<A&>(p); // if dynamic cast failes, it throws an exception
//         std::cout << "A" << std::endl;
//         (void)a; // Avoid unused variable warning
//     } catch (std::exception&) {
//         try {
//             B& b = dynamic_cast<B&>(p);
//             std::cout << "B" << std::endl;
//             (void)b; // Avoid unused variable warning
//         } catch (std::exception&) {
//             std::cout << "C" << std::endl;
//         }
//     }
// }
/*
It prints the actual type of the object pointed to by p: "A", "B" or "C".
Using a pointer inside this function is forbidden.
*/