/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:32:09 by dkham             #+#    #+#             */
/*   Updated: 2023/12/29 16:45:25 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): input()
	, jacobsthalIndexVector()
	, oddElement(0)
	, elemPairsVector()
	, mainVector()
	, pendingVector()
	, elemPairsList()
	, sortedList()
	, pendingElementList()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
	: input(other.input)
	, jacobsthalIndexVector(other.jacobsthalIndexVector)
	, oddElement(other.oddElement)
	, elemPairsVector(other.elemPairsVector)
	, mainVector(other.mainVector)
	, pendingVector(other.pendingVector)
	, elemPairsList(other.elemPairsList)
	, sortedList(other.sortedList)
	, pendingElementList(other.pendingElementList)
{}

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
		sortedList = other.sortedList;
		pendingElementList = other.pendingElementList;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::checkValidInput(int argc, char** argv) {
	// check number of arguments
	if (argc < 2) {
		throw (std::invalid_argument("Error: No input arguments provided."));
	}

	// check if all arguments are positive integers
	for (int index = 1; index < argc; index++) {
		if (isPositiveInteger(argv[index]) == true) { // if positive integer, add to input sequence
			input.push_back(std::atoi(argv[index]));
		}
	}
}

// *** iss.fail() 필요한지 확인 ***
bool PmergeMe::isPositiveInteger(const std::string& inputString) {
	std::istringstream iss(inputString);

	int value;
	iss >> value; // try to read the value as an integer

	// check if the entire string was read (no non-numeric characters)
	if (iss.eof() == false) {
		throw std::invalid_argument("Error: \"" + inputString + "\" contains non-numeric characters.");
	}
	// check if the value is a positive integer
	if (iss.fail() == true) {
		throw std::invalid_argument("Error: \"" + inputString + "\" is not a valid integer.");
	}
	// check if the value is positive
	if (value < 0) {
		throw std::invalid_argument("Error: \"" + inputString + "\" is not a positive integer.");
	}
	return (true);
}

void PmergeMe::runSort() {
	double vectorTime = runSortForVector();
	double listTime = runSortForList();

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

void PmergeMe::createPairs() {
    // Clear any existing content in the element pairs vectors and lists
    elemPairsVector.clear();
    elemPairsList.clear();

    // Iterate over the input in steps of 2 (skip the last element if the size is odd)
    for (size_t i = 0; i < input.size() - 1; i += 2) {
        std::pair<int, int> pair;

        // Check if the current element is less than the next element
        if (input[i] < input[i + 1]) {
            // If so, create a pair with the elements in ascending order
            pair = std::make_pair(input[i + 1], input[i]);
        }
        else {
            // Otherwise, create a pair with the elements in their original order
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
        int number = jacobsthal(i); // Compute the ith Jacobsthal number
        jacobsthalNumbers.push_back(number); // Add it to the vector
        if (number > pendingElementSize) // If jacobsthal(i) is greater than pendingElementSize, stop
            break;
    }  

    // Set for tracking used numbers to avoid duplicates
    std::set<int> used;
    // Start with the first index
    jacobsthalIndexVector.push_back(1);
    used.insert(1);

    // Initialize number with the first Jacobsthal number
    int number = jacobsthalNumbers.front();
    // Populate the Jacobsthal index vector
    while (true) {
        if (used.find(number) == used.end()) {
            jacobsthalIndexVector.push_back(number);
            used.insert(number);
            number--;
        } else {
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
        currentTerm = previousTerm + 2 * twoTermsAgo;
        
        // Update terms for next iteration
        twoTermsAgo = previousTerm;
        previousTerm = currentTerm;
    }

    // Return the nth Jacobsthal number
    return currentTerm;
}

void PmergeMe::fordJohnsonVector() {
	std::cout << MAGENTA << "After: " << RESET;
	printInput();

	std::cout << BLUE << "createPairs..." << RESET << std::endl;
	createPairs();
	printPairsVector();

	std::cout << BLUE << "mergeSortVector..." << RESET << std::endl;
	mergeSortVector(0, elemPairsVector.size() - 1);
	printPairsVector();

	std::cout << BLUE << "splitPairsToMainPendingVector..." << RESET << std::endl;
    splitPairsToMainPendingVector();
	printAfterSplitVector();
	
	std::cout << BLUE << "insertionSortVector..." << RESET << std::endl;
	insertionSortVector();

	std::cout << MAGENTA << "RESULT: " << RESET;
	printMainVector();
}

void PmergeMe::splitPairsToMainPendingVector() {
	mainVector.clear();
	pendingVector.clear();

    for (size_t i = 0; i < elemPairsVector.size(); i++) {
        mainVector.push_back(elemPairsVector[i].first);
        pendingVector.push_back(elemPairsVector[i].second);
    }
}

void PmergeMe::mergeSortVector(int left, int right) {
    // Base case: if the range is zero or negative, no sorting is needed
    if (left >= right)
        return;
    
    // Calculate the middle index of the current range (divide and conquer)
	int mid = left + (right - left) / 2; // avoid overflow
	
    // Recursively apply merge sort to the left half of the range
    mergeSortVector(left, mid);

    // Recursively apply merge sort to the right half of the range
    mergeSortVector(mid + 1, right);

    // Merge the two halves together
    mergeSortedHalves(left, mid, right);
}

void PmergeMe::mergeSortedHalves(int left, int mid, int right) {
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
    while (indexLeft < leftSize && indexRight < Rightsize) {
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

void PmergeMe::insertionSortVector() {
	std::cout << BLUE << "createJacobsthalIndexes ..." << RESET << std::endl;
	// create jacobsthal indexes
	createJacobsthalIndexes(pendingVector.size());
	printJacobsthalIndex();
	
	// insert elements using jacobsthal indexes
	insertElemWithJacobsthalIndexesVector();
    insertOddElemVector();
}

void PmergeMe::insertElemWithJacobsthalIndexesVector() {
	for (size_t index = 0; index < jacobsthalIndexVector.size(); ++index)
		{
			int jacobsthalIndex = jacobsthalIndexVector[index];
			int value = pendingVector[jacobsthalIndex - 1];
			int position = binarySearchVector(value);

			PrintInsertionDetails(jacobsthalIndex, value, position);
			std::cout << "Before: " << RESET;
			printMainVector();

			mainVector.insert(mainVector.begin() + position, value);

			std::cout << "After: " << RESET;
			printMainVector();
		}
		pendingVector.clear();
}

int PmergeMe::binarySearchVector(int value) {
	int left = 0;
	int right = mainVector.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (mainVector[mid] == value) {
			return (mid);
		}
		else if (mainVector[mid] < value) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
		return (left);
}

void PmergeMe::insertOddElemVector() {
    if (input.size() % 2 != 0)
	{
        int position = binarySearchVector(oddElement);
        mainVector.insert(mainVector.begin() + position, oddElement);
    }
}

double PmergeMe::runSortForList() {
	clock_t start = clock();
	fordJohnsonList();
	clock_t end = clock();
	
	double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	return (elapsedTime);
}

void PmergeMe::fordJohnsonList() {
	std::cout << "After: " << RESET;
	printInput();

	std::cout << BLUE << "createPairs..." << RESET << std::endl;
	createPairs();
	printPairsList();

	std::cout << BLUE << "mergeSortList..." << RESET << std::endl;
	mergeSortList(elemPairsList.begin(), elemPairsList.end());
	printPairsList();

	std::cout << BLUE << "splitPairsToMainPendingList..." << RESET << std::endl;
    splitPairsToMainPendingList();
	printAfterSplitList();

	insertionSortList();

	std::cout << "RESULT: " << RESET;
	printMainList();
}

void PmergeMe::splitPairsToMainPendingList() {
	sortedList.clear();
	pendingElementList.clear();
	for (std::list<std::pair<int, int> >::iterator it = elemPairsList.begin(); it != elemPairsList.end(); ++it) {
		sortedList.push_back(it->first);
		pendingElementList.push_back(it->second);
	}
}

void PmergeMe::mergeSortList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator right) {
	std::list<std::pair<int, int> >::iterator nextLeft = left;
    nextLeft++;

    if (left == right || nextLeft == right) {
        return;
    }

	std::list<std::pair<int, int> >::iterator mid = left;
	std::advance(mid, std::distance(left, right) / 2);

	mergeSortList(left, mid);
	mergeSortList(mid, right);
	MergingList(left, mid, right);
}

void PmergeMe::MergingList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator mid, std::list<std::pair<int, int> >::iterator right) {
	std::list<std::pair<int, int> > tempList;

	std::list<std::pair<int, int> >::iterator leftPair = left;
	std::list<std::pair<int, int> >::iterator rightPair = mid;

	while (leftPair != mid && rightPair != right) {
		if (leftPair->first <= rightPair->first) {
			tempList.push_back(*leftPair);
			leftPair++;
		}
		else {
			tempList.push_back(*rightPair);
			rightPair++;
		}
	}

	while (leftPair != mid) {
		tempList.push_back(*leftPair);
		leftPair++;
	}

	while (rightPair != right) {
		tempList.push_back(*rightPair);
		rightPair++;
	}
	std::copy(tempList.begin(), tempList.end(), left);
}

void PmergeMe::insertionSortList() {
	std::cout << BLUE << "createJacobsthalIndexes ..." << RESET << std::endl;
	createJacobsthalIndexes(pendingElementList.size());
		printJacobsthalIndex();

	InsertElementsUsingJacobsthalIndexesList();
    InsertOddElementList();
}

void PmergeMe::InsertElementsUsingJacobsthalIndexesList() {
    for (size_t index = 0; index < jacobsthalIndexVector.size(); ++index) 
    {
        int jacobsthalIndex = jacobsthalIndexVector[index];

        std::list<int>::iterator valueIt = pendingElementList.begin();
        std::advance(valueIt, jacobsthalIndex - 1);
        int value = *valueIt;

        int position = BinarySearchList(value);

        PrintInsertionDetails(jacobsthalIndex, value, position);
		
		std::cout << "Before: " << RESET;
		printMainList();

        std::list<int>::iterator it = sortedList.begin();
        std::advance(it, position);
        sortedList.insert(it, value);

		std::cout << "After: " << RESET;
		printMainList();
    }

    pendingElementList.clear();
}


void PmergeMe::InsertOddElementList() {
    if (input.size() % 2 != 0)
	{
        int position = BinarySearchList(oddElement);

        std::list<int>::iterator it = sortedList.begin();
        std::advance(it, position);
        sortedList.insert(it, oddElement);

    }
}

int PmergeMe::BinarySearchList(int value) {
    if (sortedList.empty()) {
        return (0);
    }

    std::list<int>::iterator left = sortedList.begin();
    std::list<int>::iterator right = sortedList.end();
    right--; 
    std::list<int>::iterator mid;
    
    int remainingElements = std::distance(left, right) + 1;

    while (remainingElements > 0 && left != sortedList.end() && std::distance(left, right) >= 0)
    {
        int moveDistance = remainingElements / 2;
        mid = left;
        std::advance(mid, moveDistance);

        if (*mid == value)
        {
            return std::distance(sortedList.begin(), mid);
        }
        else if (*mid < value)
        {
            std::advance(left, moveDistance + 1);
            remainingElements -= (moveDistance + 1);
        }
        else
        {
            if (mid == sortedList.begin()) {
				break;
			}
            right = mid;
            right--;
            remainingElements = moveDistance;
        }
    }
    return std::distance(sortedList.begin(), left);
}

void PmergeMe::printInput() {
    std::cout << "input : [";
    for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
        if (it != input.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;
}

void PmergeMe::printTime(std::string containerType, double time) {
	std::cout << "Time to process a range of ";
	std::cout << input.size();
	std::cout << " elements with std::" << containerType << " ";
	std::cout << time;
	std::cout << RESET;
	std::cout << " us" << std::endl;
}

void PmergeMe::printPairsVector() {
	std::cout << " *** Pairs Vector *** " << std::endl;
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

void PmergeMe::printPairsList() {
    std::cout << " *** Pairs List *** " << std::endl;

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

void PmergeMe::printAfterSplitVector() {
	printMainVector();
	printPendingVector();
	printOddElement();
}

void PmergeMe::printAfterSplitList() {
	printMainList();
	PrintPendingElementsList();
	printOddElement();
}

void PmergeMe::printMainVector() {
    std::cout << "SortedSequence (Vector): [";
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
    std::cout << "PendingElements (Vector): [";
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

void PmergeMe::PrintInsertionDetails(int jacobsthalIndex, int value, int position) {
	std::cout << BLUE << "Insert..." << RESET << std::endl;
    std::cout << CYAN << "Processing Jacobsthal Index: " << jacobsthalIndex << RESET << std::endl; 
    std::cout << MAGENTA << "Value to insert: " << value << RESET << std::endl; 
	std::cout << CYAN << "Position to insert in SortedSequence: " << position << RESET << std::endl;
}

void PmergeMe::printMainList() {
    std::cout << "SortedSequence (List): NULL <-> ";
    for (std::list<int>::iterator it = sortedList.begin(); it != sortedList.end(); ++it)
    {
        std::cout << "[" << *it << "] <-> ";
    }
    std::cout << "NULL" << std::endl;
    std::cout << std::endl;
}

void PmergeMe::PrintPendingElementsList() {
    std::cout << "PendingElements (List): NULL <-> ";
    for (std::list<int>::iterator it = pendingElementList.begin(); it != pendingElementList.end(); ++it)
    {
        std::cout << "[" << *it << "] <-> ";
    }
    std::cout << "NULL" << std::endl;
    std::cout << std::endl;
}
