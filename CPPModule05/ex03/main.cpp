/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:56:29 by dkham             #+#    #+#             */
/*   Updated: 2023/10/26 19:02:26 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

// void leaks()
// {
//     system("leaks a.out");
// }

int main() {
    //atexit(leaks);
    Bureaucrat highRanking("High Ranker", 1);
    
    Intern someRandomIntern; // create an instance of Intern

    AForm* rrf; // rrf is a pointer to AForm
    rrf = someRandomIntern.makeForm("robotomy request", "Bender"); // rrf points to a new RobotomyRequestForm instance
    // makeForm method of Intern class calls createRobotomyRequest, which returns a pointer to a new RobotomyRequestForm instance.

    AForm* ppf;
    ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

    AForm* scf;
    scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    
    highRanking.signForm(*scf);
    highRanking.executeForm(*scf);

    AForm* unknown;
    unknown = someRandomIntern.makeForm("unknown", "Bender");

    delete rrf;
    delete ppf;
    delete scf;

    return 0;
}