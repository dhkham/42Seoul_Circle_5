/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:32:09 by dkham             #+#    #+#             */
/*   Updated: 2024/01/26 16:40:07 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe(): input()
	, jacobsthalIndexVector()
	, oddElement(0)
	, elemPairsVector()
	, mainVector()
	, pendingVector()
	, elemPairsList()
	, mainList()
	, pendingList()
{}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other)
	: input(other.input)
	, jacobsthalIndexVector(other.jacobsthalIndexVector)
	, oddElement(other.oddElement)
	, elemPairsVector(other.elemPairsVector)
	, mainVector(other.mainVector)
	, pendingVector(other.pendingVector)
	, elemPairsList(other.elemPairsList)
	, mainList(other.mainList)
	, pendingList(other.pendingList)
{}

// Copy assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	
	if (this != &other)
	{
		input = other.input;
		jacobsthalIndexVector = other.jacobsthalIndexVector;
		oddElement = other.oddElement;
		elemPairsVector = other.elemPairsVector;
		mainVector = other.mainVector;
		pendingVector = other.pendingVector;
		elemPairsList = other.elemPairsList;
		mainList = other.mainList;
		pendingList = other.pendingList;
	}
	return (*this);
}

// Destructor
PmergeMe::~PmergeMe()
{}

/*
    check valid input
*/
void PmergeMe::checkValidInput(int argc, char** argv) {
	// check number of arguments
	if (argc < 2) {
		throw (std::invalid_argument("Error: No input arguments provided."));
	}

	// check if all arguments are positive integers
	for (int i = 1; i < argc; i++) {
		if (isPositiveInteger(argv[i]) == true) { // if positive integer, add to input sequence
			input.push_back(std::atoi(argv[i]));
		}
	}
    
    // check for duplicates (error when duplicate elements are found)
    std::set<int> set;
    for (size_t i = 0; i < input.size(); i++) {
        if (set.find(input[i]) == set.end()) {
            set.insert(input[i]);
        }
        else {
            throw std::invalid_argument("Error: Duplicate elements found in the input sequence.");
        }
    }
}

bool PmergeMe::isPositiveInteger(const std::string& inputString) {
	std::istringstream iss(inputString);

	int value;
	iss >> value; // try to read the value as an integer

	// check if the entire string was read (no non-numeric characters)
	if (iss.eof() == false) {
		throw std::invalid_argument("Error: \"" + inputString + "\" contains non-integer values.");
	}
	// check if the value is positive
	if (value < 0) {
		throw std::invalid_argument("Error: \"" + inputString + "\" is not a positive integer.");
	}
	return (true);
}

/*
    run sort for vector and list
*/
void PmergeMe::runSort() {
	double vectorTime = runSortForVector();
	double listTime = runSortForList();
    
    // print input values e.g., Before: 3 5 9 7 4
    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
    
    // print sorted values e.g., After: 3 4 5 7 9
    std::cout << "After:  ";
    for (size_t i = 0; i < mainVector.size(); i++) {
        std::cout << mainVector[i] << " ";
    }
    std::cout << std::endl;
    
    // print time spent for sorting 
	printTime("vector", vectorTime);
	printTime("list", listTime);
}

double PmergeMe::runSortForVector() {
	clock_t start = clock();	// clock() returns the number of clock ticks elapsed since the program was launched
	fordJohnsonVector(); 		// Sort the input sequence using merge-insertion sort
	clock_t end = clock();		// get the number of clock ticks elapsed since the start of the sorting process
	
	double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000; // convert clock ticks to microseconds
	return (elapsedTime);
}

double PmergeMe::runSortForList() {
	clock_t start = clock();
	fordJohnsonList();
	clock_t end = clock();
	
	double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	return (elapsedTime);
}

/*
    fordJohnson for vector
*/
void PmergeMe::fordJohnsonVector() {
    std::cout << "|     VECTOR     |" << std::endl;
	std::cout << "*** createPairsInDescending ***" << std::endl;
	createPairsInDescending(); // create pairs so that each pair is in descending order
	printVectorPairs();

	std::cout << "*** mergeSortVector ***" << std::endl;
	mergeSortVector(0, elemPairsVector.size() - 1); // merge sort base on the first element of the pair
	printVectorPairs();

	std::cout << "*** splitPairsToMainPendingVector ***" << std::endl;
    splitPairsToMainPendingVector(); // split pairs to main and pending vector
	printAfterSplitingMainPendingVector();
	
	std::cout << "*** insertionSortVector ***" << std::endl;
	insertionSortVector();

	std::cout << "RESULT: " << std::endl;
	printMainVector();
}

// create pairs in descending order
void PmergeMe::createPairsInDescending() {
    // Clear any existing content in the element pairs vectors and lists
    elemPairsVector.clear();    // vector that stores pairs of elements
    elemPairsList.clear();      // list that stores pairs of elements

    // Iterate over the input in steps of 2 (skip the last element if the size is odd)
    for (size_t i = 0; i < input.size() - 1; i += 2) {
        std::pair<int, int> pair;
        
        // Create a pair of elements in descending order
        if (input[i] < input[i + 1]) {
            pair = std::make_pair(input[i + 1], input[i]);
        }
        else {
            pair = std::make_pair(input[i], input[i + 1]);
        }
        // Add this pair to both the vector and list containers
        elemPairsVector.push_back(pair);
        elemPairsList.push_back(pair);
    }
    
    // Check if the size of the input is odd
    if (input.size() % 2 != 0) {
        oddElement = input[input.size() - 1]; // If so, store the last element as the odd element
    }
}

// print vector pairs
void PmergeMe::printVectorPairs() {
	for (size_t i = 0; i < elemPairsVector.size(); i++) {
		std::cout << "(" << elemPairsVector[i].first;
		std::cout << ", " << elemPairsVector[i].second << ")";
		std::cout << std::endl;
	}

	if (input.size() % 2 != 0) {
		std::cout << "(" << oddElement <<  ")" <<std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// run merge sort based on first element of vector
void PmergeMe::mergeSortVector(int left, int right) {
    // Base case: no sorting is needed if the range is zero or negative (stop recursion when only one element is left)
    if (left >= right)
        return;
    
    // Calculate the middle index of the current range (divide and conquer)
	int mid = left + (right - left) / 2; // avoid overflow
	
    // Recursively apply merge sort to the left half of the range
    mergeSortVector(left, mid);

    // Recursively apply merge sort to the right half of the range
    mergeSortVector(mid + 1, right);

    // Merge the two halves together
    mergeSortedHalvesVector(left, mid, right);
}

void PmergeMe::mergeSortedHalvesVector(int left, int mid, int right) {
    // Calculate sizes of two sub-vectors to be merged
    int leftSize = mid - left + 1;
    int Rightsize = right - mid;

    // Create temporary vectors for left and right halves
    std::vector<std::pair<int, int> > leftPair(leftSize);
    std::vector<std::pair<int, int> > rightPair(Rightsize);

    // Copy data to temporary vectors
    for (int i = 0; i < leftSize; i++) {
        leftPair[i] = elemPairsVector[left + i];
    }
    for (int i = 0; i < Rightsize; i++) {
        rightPair[i] = elemPairsVector[mid + 1 + i];
    }

    // Indices for traversing the temporary vectors and the merge index for the original vector
    int indexLeft = 0, indexRight = 0, mergeIndex = left;

    // Merge the temporary vectors back into elemPairsVector
    while (indexLeft < leftSize && indexRight < Rightsize) { // while there are elements in both vectors
        if (leftPair[indexLeft].first <= rightPair[indexRight].first) { // compare the first elements of the pairs
            elemPairsVector[mergeIndex] = leftPair[indexLeft++]; // if the left element is smaller, copy it to elemPairsVector
        } else { 
            elemPairsVector[mergeIndex] = rightPair[indexRight++]; // otherwise, copy the right element to elemPairsVector
        }
        mergeIndex++;
    }

    // Copy the remaining elements of leftPair, if any
    while (indexLeft < leftSize) {	// if there are any elements left in the leftPair vector, copy them to elemPairsVector
        elemPairsVector[mergeIndex++] = leftPair[indexLeft++];
    }

    // Copy the remaining elements of rightPair, if any
    while (indexRight < Rightsize) { // if there are any elements left in the rightPair vector, copy them to elemPairsVector
        elemPairsVector[mergeIndex++] = rightPair[indexRight++];
    }
}

// split pairs to main and pending vector
void PmergeMe::splitPairsToMainPendingVector() {
	mainVector.clear();
	pendingVector.clear();

    for (size_t i = 0; i < elemPairsVector.size(); i++) {
        mainVector.push_back(elemPairsVector[i].first);
        pendingVector.push_back(elemPairsVector[i].second);
    }
}

/*
    insertion sort for vector
*/
void PmergeMe::insertionSortVector() {
	// create jacobsthal indexes
	createJacobsthalIndexes(pendingVector.size());
	printJacobsthalIndex();
	
	// insert elements using jacobsthal indexes
	insertElemWithJacobsthalIndexesVector(); // binarySearchVector() is used here to find the position to insert
    insertOddElemVector(); // insert the odd element in sorted vector
}

void PmergeMe::createJacobsthalIndexes(int pendingElementSize) {
    // Clear the existing Jacobsthal index vector
    jacobsthalIndexVector.clear();

    // If pendingElementSize is less than 1, no indexes are needed
    if (pendingElementSize < 1)
        return;

    // Generate Jacobsthal numbers greater than pendingElementSize
    std::vector<int> jacobsthalNumbers;
    int i = 1;
    while (true) {
        i++;
        int number = jacobsthal(i); // Compute the ith Jacobsthal number (starting from i=2)
        jacobsthalNumbers.push_back(number); // Add it to the vector
        if (number > pendingElementSize) // If jacobsthal(i) is greater than pendingElementSize, stop
            break;
    }

    // Set for tracking used numbers to avoid duplicates
    std::set<int> usedNum;
    // Start with the first index
    jacobsthalIndexVector.push_back(1);
    usedNum.insert(1);

    // Initialize number with the first Jacobsthal number
    int number = jacobsthalNumbers.front(); // .front() returns the first element of the vector
    // Populate the Jacobsthal index vector
    while (true) {
        if (usedNum.find(number) == usedNum.end()) { // If the number is not used, add it to the jacobsthalIndexVector (also to usedNum set)
            jacobsthalIndexVector.push_back(number);
            usedNum.insert(number);
            number--;
        } else {    // If the number is used, find the next Jacobsthal number
            // If no more Jacobsthal numbers, break the loop
            if (jacobsthalNumbers.empty())
                break;
            // Update number to the next Jacobsthal number
            number = jacobsthalNumbers.front();
            if (number > pendingElementSize) {
                number = pendingElementSize;
            }
            jacobsthalNumbers.erase(jacobsthalNumbers.begin());
        }
    }
}

int PmergeMe::jacobsthal(int n) {
    // Base cases: return the first two numbers of Jacobsthal sequence
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;
    
    // Variables for storing previous and current terms in the sequence
    int twoTermsAgo = 0;
    int previousTerm = 1;
    int currentTerm = 0;

    // Iteratively calculate the Jacobsthal number up to n
    for (int index = 2; index <= n; index++) {
        currentTerm = previousTerm + 2 * twoTermsAgo; // Jacobsthal sequence: ak = ak-1 + 2 * ak-2
        
        // Update terms for next iteration
        twoTermsAgo = previousTerm;
        previousTerm = currentTerm;
    }

    // Return the nth Jacobsthal number
    return currentTerm;
}

void PmergeMe::insertElemWithJacobsthalIndexesVector() {
	for (size_t index = 0; index < jacobsthalIndexVector.size(); ++index)
		{
			int jacobsthalIndex = jacobsthalIndexVector[index];
			int value = pendingVector[jacobsthalIndex - 1];
			int position = binarySearchVector(value); // get the position to insert thru binary search

			printInsertionDetails(jacobsthalIndex, value, position);
			std::cout << "Before: " << std::endl;
			printMainVector();

			mainVector.insert(mainVector.begin() + position, value);

			std::cout << "After: " << std::endl;
			printMainVector();
		}
		pendingVector.clear();
}

// binary search for vector in order to find the position to insert
int PmergeMe::binarySearchVector(int value) { // value is the element from the pending vector (bk)
	int left = 0;
	int right = mainVector.size() - 1;
    int correspondingAk;
    
    // find element in elemPairsVector, which corresponds to the "value" (= bk)
    for (size_t i = 0; i < elemPairsVector.size(); i++) {
        if (elemPairsVector[i].second == value) { // find bk in pendingVector
            correspondingAk = elemPairsVector[i].first; // then, find corresponding ak in mainVector
            break;
        }
    }
    
    // find the position of ak in mainVector, and set it as right
    for (size_t i = 0; i < mainVector.size(); i++) {
        if (mainVector[i] == correspondingAk) {
            right = i;
            break;
        }
    }
    
    // binary search: find the position of bk in mainVector
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (mainVector[mid] < value) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
		return (left);
}

// insert the odd element to sorted vector
void PmergeMe::insertOddElemVector() {
    std::cout << "insert odd element" << std::endl;
    if (input.size() % 2 != 0)
	{
        int position = binarySearchVector(oddElement);
        mainVector.insert(mainVector.begin() + position, oddElement);
    }
}

/*
    fordJohnson for list
*/
void PmergeMe::fordJohnsonList() {
    std::cout << "|     LIST     |" << std::endl;
	std::cout << "*** createPairsInDescending ***" << std::endl;
	createPairsInDescending();
	printListPairs();

	std::cout << "*** mergeSortList ***" << std::endl;
	mergeSortList(elemPairsList.begin(), elemPairsList.end());
	printListPairs();

	std::cout << "*** splitPairsToMainPendingList ***" << std::endl;
    splitPairsToMainPendingList();
	printAfterSplitingMainPendingList();

    std::cout << "*** insertionSortList ***" << std::endl;
	insertionSortList();

	std::cout << "RESULT: " << std::endl;
	printMainList();
}

// split pairs to main and pending list
void PmergeMe::splitPairsToMainPendingList() {
	mainList.clear();
	pendingList.clear();
	for (std::list<std::pair<int, int> >::iterator it = elemPairsList.begin(); it != elemPairsList.end(); ++it) {
		mainList.push_back(it->first);
		pendingList.push_back(it->second);
	}
}

// merge sort for list
void PmergeMe::mergeSortList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator right) {
	// nextLeft is the next element after left
    std::list<std::pair<int, int> >::iterator nextLeft = left;
    nextLeft++;
    
    // if the range is zero or negative, no sorting is needed
    if (left == right || nextLeft == right) {
        return;
    }
    
    // calculate the middle index of the current range (divide and conquer)
	std::list<std::pair<int, int> >::iterator mid = left;
	std::advance(mid, std::distance(left, right) / 2); // advance: move iterator to the middle of the range

	mergeSortList(left, mid);   // recursively apply merge sort to the left half of the range
	mergeSortList(mid, right);  // recursively apply merge sort to the right half of the range
	mergeSortedHalvesList(left, mid, right); // merge the two halves together
}

// merge two sorted halves in list
void PmergeMe::mergeSortedHalvesList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator mid, std::list<std::pair<int, int> >::iterator right) {
    // Create a temporary list to store the merged elements.
    std::list<std::pair<int, int> > tempList;
    
    // Initialize iterators for the left and right halves.
    std::list<std::pair<int, int> >::iterator leftPair = left;
    std::list<std::pair<int, int> >::iterator rightPair = mid;
    
    // Merge the two halves into tempList. Continue until one of the halves is exhausted.
    while (leftPair != mid && rightPair != right) {
        // Compare the elements from each half and add the smaller one to tempList.
        if (leftPair->first <= rightPair->first) {
            tempList.push_back(*leftPair);
            leftPair++;
        }
        else {
            tempList.push_back(*rightPair);
            rightPair++;
        }
    }

    // If there are remaining elements in the left half, add them to tempList.
    while (leftPair != mid) {
        tempList.push_back(*leftPair);
        leftPair++;
    }

    // If there are remaining elements in the right half, add them to tempList.
    while (rightPair != right) {
        tempList.push_back(*rightPair);
        rightPair++;
    }

    // Copy the merged elements back to the original list starting from the left iterator.
    std::copy(tempList.begin(), tempList.end(), left);
}

// insertion sort for list
void PmergeMe::insertionSortList() {
	createJacobsthalIndexes(pendingList.size());
	printJacobsthalIndex();

	insertElementsWithJacobsthalIndexesList();
    insertOddElementList();
}

// insert elements at Jacobsthal index positions in list
void PmergeMe::insertElementsWithJacobsthalIndexesList() {
    for (size_t index = 0; index < jacobsthalIndexVector.size(); ++index) 
    {
        int jacobsthalIndex = jacobsthalIndexVector[index];

        std::list<int>::iterator valueIt = pendingList.begin();
        std::advance(valueIt, jacobsthalIndex - 1);
        int value = *valueIt;

        int position = binarySearchList(value);

        printInsertionDetails(jacobsthalIndex, value, position);
		
		std::cout << "Before: " << std::endl;
		printMainList();

        std::list<int>::iterator it = mainList.begin();
        std::advance(it, position);
        mainList.insert(it, value);

		std::cout << "After: " << std::endl;
		printMainList();
    }

    pendingList.clear();
}

// insert the odd element in sorted list
void PmergeMe::insertOddElementList() {
    std::cout << "insert odd element" << std::endl;
    if (input.size() % 2 != 0)
	{
        int position = binarySearchList(oddElement);

        std::list<int>::iterator it = mainList.begin();
        std::advance(it, position);
        mainList.insert(it, oddElement);

    }
}

int PmergeMe::binarySearchList(int value) {
    // Check if the sorted list is empty. If it is, there's no place to search, so return 0
    if (mainList.empty()) {
        return 0;
    }

    int correspondingAk;
    // Iterate through elemPairsList to find the pair where the second element matches 'value'
    for (std::list<std::pair<int, int> >::const_iterator it = elemPairsList.begin(); it != elemPairsList.end(); ++it) {
        if (it->second == value) {
            correspondingAk = it->first; // When found, store the first element of the pair
            break; // Break the loop as we have found the element
        }
    }

    // Initialize iterators for the start (left) and end (right) of the search range
    std::list<int>::iterator left = mainList.begin();
    std::list<int>::iterator right = mainList.end();

    // Iterate through mainList to find the position of correspondingAk
    std::list<int>::iterator correspondingIt;
    for (correspondingIt = mainList.begin(); correspondingIt != mainList.end(); ++correspondingIt) {
        if (*correspondingIt == correspondingAk) {
            break; // Break the loop when the correspondingAk is found
        }
    }

    // If we find correspondingAk in the mainList, set 'right' to its position
    if (correspondingIt != mainList.end()) {
        right = correspondingIt;
    }

    // Declare an iterator 'mid' to represent the middle of the current search range
    std::list<int>::iterator mid;
    // Calculate the number of elements in the current search range
    int remainingElements = std::distance(left, right);

    // Perform binary search within the range defined by 'left' and 'right'
    while (remainingElements > 0 && left != right) {
        int moveDistance = remainingElements / 2; // Calculate the distance to the middle
        mid = left; // Start from 'left'
        std::advance(mid, moveDistance); // Move 'mid' to the middle position

        // If the middle element is less than the value, adjust the left boundary
        if (*mid < value) {
            std::advance(left, moveDistance + 1); // Move left to the right of 'mid'
            remainingElements -= (moveDistance + 1); // Update the count of remaining elements
        }
        else {
            // If the middle element is greater or equal, adjust the right boundary
            right = mid;
            // Update the count of remaining elements to the left half
            remainingElements = moveDistance;
        }
    }

    // Return the position (as a distance from the beginning) where 'value' should be inserted
    return std::distance(mainList.begin(), left);
}

// print time spent for sorting
void PmergeMe::printTime(std::string containerType, double time) {
	std::cout << "Time to process a range of ";
	std::cout << input.size();
	std::cout << " elements with std::" << containerType << " ";
	std::cout << time;
	std::cout << " us" << std::endl;
}

// debugging functions for vector
void PmergeMe::printListPairs() {
	std::list<std::pair<int, int> >::iterator it;
	for (it = elemPairsList.begin(); it != elemPairsList.end(); it++) {
        std::cout << "(" << it->first;
        std::cout << ", " << it->second << ")";
        std::cout << std::endl;
	}

    if (input.size() % 2 != 0) {
        std::cout << "(" << oddElement <<  ")" <<std::endl;
        std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PmergeMe::printAfterSplitingMainPendingVector() {
	printMainVector();
	printPendingVector();
	printOddElement();
}

void PmergeMe::printAfterSplitingMainPendingList() {
	printMainList();
	PrintPendingElementsList();
	printOddElement();
}

void PmergeMe::printMainVector() {
    std::cout << "Main Vector: [";
    for (std::vector<int>::iterator it = mainVector.begin(); it != mainVector.end(); ++it)
    {
        if (it != mainVector.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;

}

void PmergeMe::printPendingVector() {
    std::cout << "Pending Vector: [";
    for (std::vector<int>::iterator it = pendingVector.begin(); it != pendingVector.end(); ++it)
    {
        if (it != pendingVector.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;
}

void PmergeMe::printOddElement() {
	if (input.size() % 2 != 0)
	{
		std::cout << "OddElement: ";
		std::cout << oddElement << std::endl;
		std::cout << std::endl;
	}
}

void PmergeMe::printJacobsthalIndex() {
    std::cout << "Jacobsthal Index: [";
    for (size_t index = 0; index < jacobsthalIndexVector.size(); ++index)
    {
        if (index != 0)
        {
            std::cout << ", ";
        }
        std::cout << jacobsthalIndexVector[index];
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;
}

void PmergeMe::printInsertionDetails(int jacobsthalIndex, int value, int position) {
    std::cout << "Jacobsthal Index: " << jacobsthalIndex << std::endl; 
    std::cout << "Insert value: " << value << std::endl; 
	std::cout << "Position to insert in Main: " << position << std::endl;
}

void PmergeMe::printMainList() {
    std::cout << "Main List: NULL <-> ";
    for (std::list<int>::iterator it = mainList.begin(); it != mainList.end(); ++it)
    {
        std::cout << "[" << *it << "] <-> ";
    }
    std::cout << "NULL" << std::endl;
    std::cout << std::endl;
}

void PmergeMe::PrintPendingElementsList() {
    std::cout << "Pending List: NULL <-> ";
    for (std::list<int>::iterator it = pendingList.begin(); it != pendingList.end(); ++it)
    {
        std::cout << "[" << *it << "] <-> ";
    }
    std::cout << "NULL" << std::endl;
    std::cout << std::endl;
}
