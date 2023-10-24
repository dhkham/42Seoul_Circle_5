/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:56:29 by dkham             #+#    #+#             */
/*   Updated: 2023/10/24 21:33:18 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

/*
Intern 내부 parameterized constructor 확인

*/

int main() {
    Intern someRandomIntern;

    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
    AForm* ppf;
    ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
    
    AForm* scf;
    scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    
    AForm* unknown;
    unknown = someRandomIntern.makeForm("unknown", "Bender");
    
    return 0;
}