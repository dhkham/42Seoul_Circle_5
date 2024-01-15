/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:35:03 by dkham             #+#    #+#             */
/*   Updated: 2024/01/15 19:49:13 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <sstream>
#include <set>
#include <ctime>

class PmergeMe
{
    public:
        // Default constructor
        PmergeMe();
        // Copy constructor
        PmergeMe(const PmergeMe& other);
        // Copy assignment operator
        PmergeMe& operator=(const PmergeMe& other);
        // Destructor
        ~PmergeMe();

        // Validates the input from command line arguments
        void checkValidInput(int argc, char** argv);
        // Checks if a string represents a positive integer
        bool isPositiveInteger(const std::string& inputString);
        // Initiates the sorting process using the chosen container
        void runSort();

        // Creates pairs for merge-insertion sort algorithm
        void createPairs();
        // Generates Jacobsthal sequence indexes for the sorting algorithm
        void createJacobsthalIndexes(int pendingElementSize);
        // Computes the nth Jacobsthal number
        int jacobsthal(int n);
		
		// sort using vector
        double runSortForVector();
        // Implements merge-insertion sort using vector
        void fordJohnsonVector();
        // Helper function for merge sort in vector
        void mergeSortVector(int left, int right);
        // Merges two sorted halves in vector
        void mergeSortedHalves(int left, int mid, int right);
        // Splits pairs after sorting in vector
        void splitPairsToMainPendingVector();
        // Performs insertion sort on vector
        void insertionSortVector();
        // Inserts elements at Jacobsthal index positions in vector
        void insertElemWithJacobsthalIndexesVector(); 
        // Inserts the odd element in sorted vector
        void insertOddElemVector();
        // Binary search helper for vector sorting
        int binarySearchVector(int value);

		// sort using list
        double runSortForList();
        // Implements merge-insertion sort using list
        void fordJohnsonList();
        // Helper function for merge sort in list
        void mergeSortList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator right);
        // Merges two sorted halves in list
        void MergingList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator mid, std::list<std::pair<int, int> >::iterator right);
        // Splits pairs after sorting in list
        void splitPairsToMainPendingList();
        // Performs insertion sort on list
        void insertionSortList();
        // Inserts elements at Jacobsthal index positions in list
        void InsertElementsUsingJacobsthalIndexesList();
        // Inserts the odd element in sorted list
        void InsertOddElementList();
        // Binary search helper for list sorting
        int BinarySearchList(int value);

        // Prints the input sequence
        void printInput();
        // Prints the odd element in the sequence
        void printOddElement();
        // Prints Jacobsthal index sequence
        void printJacobsthalIndex();
        // Prints details of an insertion operation
        void PrintInsertionDetails(int jacobsthalIndex, int value, int position);
        // Prints processing time for a given container type
        void printTime(std::string containerType, double time);

        // Debugging functions for vector container
        void printPairsVector();
        void printAfterSplitVector();
        void printMainVector();
        void printPendingVector();

        // Debugging functions for list container
        void printPairsList();
        void printAfterSplitList();
        void printMainList();
        void PrintPendingElementsList();

    private:
        // Stores the input sequence of integers
        std::vector<int> input;
        // Stores Jacobsthal indexes for the vector container
        std::vector<int> jacobsthalIndexVector;
        // Stores the odd element in the sequence
        int oddElement;

        // Stores element pairs for vector-based sorting
        std::vector<std::pair<int, int> > elemPairsVector;
        // Stores the sorted sequence for vector
        std::vector<int> mainVector;
        // Stores pending elements for vector sorting
        std::vector<int> pendingVector;

        // Stores element pairs for list-based sorting
        std::list<std::pair<int, int> > elemPairsList;
        // Stores the sorted sequence for list
        std::list<int> sortedList;
        // Stores pending elements for list sorting
        std::list<int> pendingElementList;
};

#endif
