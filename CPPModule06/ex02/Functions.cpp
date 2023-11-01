/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:26:35 by dkham             #+#    #+#             */
/*   Updated: 2023/11/01 20:00:32 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

/*
It randomly instanciates A, B or C and returns the instance as a Base pointer.
Feel free to use anything you like for the random choice implementation.
*/
Base* generate(void) {
    switch (rand() % 3) {
        case 0: return new A;
        case 1: return new B;
        default: return new C;
    }
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

/*
It prints the actual type of the object pointed to by p: "A", "B" or "C".
Using a pointer inside this function is forbidden.
*/
void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a; // Avoid unused variable warning
    } catch (std::bad_cast&) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)b; // Avoid unused variable warning
        } catch (std::bad_cast&) {
            std::cout << "C" << std::endl;
        }
    }
}
