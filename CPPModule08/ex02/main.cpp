/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:42:07 by dkham             #+#    #+#             */
/*   Updated: 2023/12/13 20:42:08 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // [...]
    mstack.push(0);     // 5 3 5 737 0

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack); // Copying the MutantStack to a standard stack (copy constructor)
    
    // std::list<int> lst;
    // lst.push_back(5);
    // lst.push_back(17);

    // std::cout << lst.back() << std::endl;
    // lst.pop_back();
    // std::cout << lst.size() << std::endl;

    // lst.push_back(3);
    // lst.push_back(5);
    // lst.push_back(737);
    // lst.push_back(0);

    // for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    //     std::cout << *it << std::endl;
    // }

    return 0;
}
