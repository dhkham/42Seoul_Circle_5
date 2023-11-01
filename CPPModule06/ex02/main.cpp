/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:26:56 by dkham             #+#    #+#             */
/*   Updated: 2023/11/01 20:00:53 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Functions.hpp"
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(NULL))); // seeding random number generator

    for (int i = 0; i < 10; i++) {
        Base* instance = generate();
        std::cout << "Generated instance is of type: ";
        identify(instance);
        delete instance;
    }

    return 0;
}
