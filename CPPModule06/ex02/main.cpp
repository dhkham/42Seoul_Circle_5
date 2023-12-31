/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:26:56 by dkham             #+#    #+#             */
/*   Updated: 2023/11/17 20:07:03 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Functions.hpp"
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(NULL))); // seeding random number generator

    // generate a random instance of Base and return it as a Base pointer
    Base* instance1 = generate();
    std::cout << "Generated instance is of type: ";
    identify(instance1);
    delete instance1;
    
    // do the same for reference
    Base& instance2 = *generate(); //Base instance2 = Base();
    std::cout << "Generated instance is of type: ";
    identify(instance2);
    delete &instance2;
    
    // check if wrong type

    return 0;
}
