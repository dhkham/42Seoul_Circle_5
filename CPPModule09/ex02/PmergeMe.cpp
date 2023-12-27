/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:32:09 by dkham             #+#    #+#             */
/*   Updated: 2023/12/27 20:32:10 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: mInputSequence()
	, mJacobsthalIndexVector()
	, mOddElement(0)
	, mElementPairsVector()
	, mSortedSVector()
	, mPendingElementVector()
	, mElementPairsList()
	, mSortedList()
	, mPendingElementList()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: mInputSequence(other.mInputSequence)
	, mJacobsthalIndexVector(other.mJacobsthalIndexVector)
	, mOddElement(other.mOddElement)
	, mElementPairsVector(other.mElementPairsVector)
	, mSortedSVector(other.mSortedSVector)
	, mPendingElementVector(other.mPendingElementVector)
	, mElementPairsList(other.mElementPairsList)
	, mSortedList(other.mSortedList)
	, mPendingElementList(other.mPendingElementList)
{
} 

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		mInputSequence = other.mInputSequence;
		mJacobsthalIndexVector = other.mJacobsthalIndexVector;
		mOddElement = other.mOddElement;
		mElementPairsVector = other.mElementPairsVector;
		mSortedSVector = other.mSortedSVector;
		mPendingElementVector = other.mPendingElementVector;
		mElementPairsList = other.mElementPairsList;
		mSortedList = other.mSortedList;
		mPendingElementList = other.mPendingElementList;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::IsValidInput(int argc, char** argv)
{
	if (argc == 1)
	{
		throw (std::invalid_argument("Error: No input arguments provided."));
	}

	for (int index = 1; index < argc; index++)
	{
		if (IsPositiveInteger(argv[index]) == true)
		{
			mInputSequence.push_back(std::atoi(argv[index]));
		}
	}
}

bool PmergeMe::IsPositiveInteger(const std::string& inputString)
{
	std::istringstream iss(inputString);

	int value;

	iss >> value;

	if (iss.eof() == false)
	{
		throw std::invalid_argument("Error: \"" + inputString + "\" contains non-numeric characters.");
	}

	if (iss.fail() == true)
	{
		throw std::invalid_argument("Error: \"" + inputString + "\" is not a valid integer.");
	}

	if (value < 0)
	{
		throw std::invalid_argument("Error: \"" + inputString + "\" is not a positive integer.");
	}
	return (true);
}

void PmergeMe::SortUsingContainer()
{
	double vecTime = MeasureTimeForVector();
	double listTime = MeasureTimeForList();

	PrintProcessingTime("vector", vecTime);
	PrintProcessingTime("list", listTime);
}

double PmergeMe::MeasureTimeForVector()
{
	clock_t start = clock();
	MergeInsertionSortVector();
	clock_t end = clock();
	
	double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	return (elapsedTime);
}

void PmergeMe::MakePairs()
{
	mElementPairsVector.clear();
	mElementPairsList.clear();

	for(size_t index = 0; index < mInputSequence.size() - 1; index += 2)
	{
		if(mInputSequence[index] < mInputSequence[index + 1])
		{
			std::pair<int, int> pair = std::make_pair(mInputSequence[index + 1], mInputSequence[index]);
			mElementPairsVector.push_back(pair);
			mElementPairsList.push_back(pair);
		}
		else
		{
			std::pair<int, int> pair = std::make_pair(mInputSequence[index], mInputSequence[index + 1]);
			mElementPairsVector.push_back(pair);
			mElementPairsList.push_back(pair);
		}
	}

	if (mInputSequence.size() % 2 != 0)
	{
		mOddElement = mInputSequence[mInputSequence.size() - 1];
	}
}

void PmergeMe::GenerateJacobsthalIndexes(int pendingElementSize)
{
	mJacobsthalIndexVector.clear();

    if (pendingElementSize < 1)
    {
        return ; 
    }

    std::vector<int> jacobsthalNumbers;
    int index = 1;
    while(true) 
    {	
		index++;
        int number = Jacobsthal(index);
        jacobsthalNumbers.push_back(number);
        if(number > pendingElementSize)
			break;
    }  

    std::set<int> used;
    mJacobsthalIndexVector.push_back(1);
    used.insert(1);

    int number = jacobsthalNumbers.front();
    while(true)
    {
        if (used.find(number) == used.end())
        {
            mJacobsthalIndexVector.push_back(number);
            used.insert(number);
            number--;
        }
        else
        {
            if(jacobsthalNumbers.empty())
			{
                break;
			}
			number = jacobsthalNumbers.front();
            if(number > pendingElementSize)
			{
                number = pendingElementSize;
			}
			jacobsthalNumbers.erase(jacobsthalNumbers.begin());
        }
    }
}

int PmergeMe::Jacobsthal(int n)
{
    if (n == 0)
    {
        return (0);
    }
    if (n == 1)
    {
        return (1);
    }
    
    int twoTermsAgo = 0;
    int previousTerm = 1;
    int currentTerm = 0;

    for (int index = 2; index <= n; index++) 
    {
        currentTerm = previousTerm + 2 * twoTermsAgo;
        
        twoTermsAgo = previousTerm;
        previousTerm = currentTerm;
    }

    return (currentTerm);
}

void PmergeMe::MergeInsertionSortVector()
{
	std::cout << MAGENTA << "After: " << RESET;
	PrintInPutSequence();

	std::cout << BLUE << "MakePairs..." << RESET << std::endl;
	MakePairs();
		PrintPairVector();

	std::cout << BLUE << "MergeSortVector..." << RESET << std::endl;
	MergeSortVector(0, mElementPairsVector.size() - 1);
		PrintPairVector();

	std::cout << BLUE << "SplitElementPairsVector..." << RESET << std::endl;
    SplitElementPairsVector();
		PrintAfterSplitVector();

	InsertSortVector();

	std::cout << MAGENTA << "RESULT: " << RESET;
		PrintSortedSequenceVector();
}

void PmergeMe::SplitElementPairsVector()
{
	mSortedSVector.clear();
	mPendingElementVector.clear();

    for (size_t index = 0; index < mElementPairsVector.size(); index++)
	{
        mSortedSVector.push_back(mElementPairsVector[index].first);
        mPendingElementVector.push_back(mElementPairsVector[index].second);
    }
}

void PmergeMe::MergeSortVector(int left, int right)
{
	if (left >= right)
	{
		return ;
	}
	
	int mid = (left + right) / 2;

	MergeSortVector(left, mid);
	MergeSortVector(mid + 1, right);
	MergingVector(left, mid, right);
}

void PmergeMe::MergingVector(int left, int mid, int right)
{
	int sizeLeft = mid - left + 1;
	int sizeRight = right - mid;

	std::vector<std::pair<int, int> > leftPair(sizeLeft);
	std::vector<std::pair<int, int> > rightPair(sizeRight);

	for (int index = 0; index < sizeLeft; index++)
	{
		leftPair[index] = mElementPairsVector[left + index];
	}
	for (int index = 0; index < sizeRight; index++)
	{
		rightPair[index] = mElementPairsVector[mid + 1 + index];
	}

    int indexLeft = 0;
    int indexRight = 0;
    int mergeIndex = left;

    while (indexLeft < sizeLeft && indexRight < sizeRight)
    {
        if (leftPair[indexLeft].first <= rightPair[indexRight].first)
        {
            mElementPairsVector[mergeIndex] = leftPair[indexLeft];
            indexLeft++;
        }
        else
        {
            mElementPairsVector[mergeIndex] = rightPair[indexRight];
            indexRight++;
        }
        mergeIndex++;
    }

    while (indexLeft < sizeLeft)
    {
        mElementPairsVector[mergeIndex] = leftPair[indexLeft];
        indexLeft++;
        mergeIndex++;
    }

    while (indexRight < sizeRight)
    {
        mElementPairsVector[mergeIndex] = rightPair[indexRight];
        indexRight++;
        mergeIndex++;
    }
}

void PmergeMe::InsertSortVector()
{
	std::cout << BLUE << "GenerateJacobsthalIndexes ..." << RESET << std::endl;
	GenerateJacobsthalIndexes(mPendingElementVector.size());
		PrintJacobsthalIndex();
	
	InsertElementsUsingJacobsthalIndexesVector();
    InsertOddElementVector();
}

void PmergeMe::InsertElementsUsingJacobsthalIndexesVector()
{
	for (size_t index = 0; index < mJacobsthalIndexVector.size(); ++index)
		{
			int jacobsthalIndex = mJacobsthalIndexVector[index];
			int value = mPendingElementVector[jacobsthalIndex - 1];
			int position = BinarySearchVector(value);

			PrintInsertionDetails(jacobsthalIndex, value, position);
			std::cout << GREEN << "Before: " << RESET;
			PrintSortedSequenceVector();

			mSortedSVector.insert(mSortedSVector.begin() + position, value);

			std::cout << GREEN << "After: " << RESET;
			PrintSortedSequenceVector();
		}
		mPendingElementVector.clear();
}

int PmergeMe::BinarySearchVector(int value)
{
	int left = 0;
	int right = mSortedSVector.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (mSortedSVector[mid] == value)
		{
			return (mid);
		}
		else if (mSortedSVector[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
		return (left);
}

void PmergeMe::InsertOddElementVector()
{
    if (mInputSequence.size() % 2 != 0)
	{
        int position = BinarySearchVector(mOddElement);
        mSortedSVector.insert(mSortedSVector.begin() + position, mOddElement);
    }
}

double PmergeMe::MeasureTimeForList()
{
	clock_t start = clock();
	MergeInsertionSortList();
	clock_t end = clock();
	
	double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	return (elapsedTime);
}

void PmergeMe::MergeInsertionSortList()
{
	std::cout << RED << "After: " << RESET;
	PrintInPutSequence();

	std::cout << BLUE << "MakePairs..." << RESET << std::endl;
	MakePairs();
		PrintPairList();

	std::cout << BLUE << "MergeSortList..." << RESET << std::endl;
	MergeSortList(mElementPairsList.begin(), mElementPairsList.end());
		PrintPairList();

	std::cout << BLUE << "SplitElementPairsList..." << RESET << std::endl;
    SplitElementPairsList();
		PrintAfterSplitList();

	InsertSortList();

	std::cout << RED << "RESULT: " << RESET;
		PrintSortedSequenceList();
}

void PmergeMe::SplitElementPairsList()
{
	mSortedList.clear();
	mPendingElementList.clear();
	for (std::list<std::pair<int, int> >::iterator it = mElementPairsList.begin(); it != mElementPairsList.end(); ++it)
	{
		mSortedList.push_back(it->first);
		mPendingElementList.push_back(it->second);
	}
}

void PmergeMe::MergeSortList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator right)
{
	std::list<std::pair<int, int> >::iterator nextLeft = left;
    nextLeft++;

    if (left == right || nextLeft == right)
    {
        return;
    }

	std::list<std::pair<int, int> >::iterator mid = left;
	std::advance(mid, std::distance(left, right) / 2);

	MergeSortList(left, mid);
	MergeSortList(mid, right);
	MergingList(left, mid, right);
}

void PmergeMe::MergingList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator mid, std::list<std::pair<int, int> >::iterator right)
{
	std::list<std::pair<int, int> > tempList;

	std::list<std::pair<int, int> >::iterator leftPair = left;
	std::list<std::pair<int, int> >::iterator rightPair = mid;

	while (leftPair != mid && rightPair != right)
	{
		if (leftPair->first <= rightPair->first)
		{
			tempList.push_back(*leftPair);
			leftPair++;
		}
		else
		{
			tempList.push_back(*rightPair);
			rightPair++;
		}
	}

	while (leftPair != mid)
	{
		tempList.push_back(*leftPair);
		leftPair++;
	}

	while (rightPair != right)
	{
		tempList.push_back(*rightPair);
		rightPair++;
	}
	std::copy(tempList.begin(), tempList.end(), left);
}

void PmergeMe::InsertSortList()
{
	std::cout << BLUE << "GenerateJacobsthalIndexes ..." << RESET << std::endl;
	GenerateJacobsthalIndexes(mPendingElementList.size());
		PrintJacobsthalIndex();

	InsertElementsUsingJacobsthalIndexesList();
    InsertOddElementList();
}

void PmergeMe::InsertElementsUsingJacobsthalIndexesList()
{
    for (size_t index = 0; index < mJacobsthalIndexVector.size(); ++index) 
    {
        int jacobsthalIndex = mJacobsthalIndexVector[index];

        std::list<int>::iterator valueIt = mPendingElementList.begin();
        std::advance(valueIt, jacobsthalIndex - 1);
        int value = *valueIt;

        int position = BinarySearchList(value);

        PrintInsertionDetails(jacobsthalIndex, value, position);
		
		std::cout << GREEN << "Before: " << RESET;
		PrintSortedSequenceList();

        std::list<int>::iterator it = mSortedList.begin();
        std::advance(it, position);
        mSortedList.insert(it, value);

		std::cout << GREEN << "After: " << RESET;
		PrintSortedSequenceList();
    }

    mPendingElementList.clear();
}


void PmergeMe::InsertOddElementList()
{
    if (mInputSequence.size() % 2 != 0)
	{
        int position = BinarySearchList(mOddElement);

        std::list<int>::iterator it = mSortedList.begin();
        std::advance(it, position);
        mSortedList.insert(it, mOddElement);

    }
}

int PmergeMe::BinarySearchList(int value)
{
    if (mSortedList.empty()) {
        return (0);
    }

    std::list<int>::iterator left = mSortedList.begin();
    std::list<int>::iterator right = mSortedList.end();
    right--; 
    std::list<int>::iterator mid;
    
    int remainingElements = std::distance(left, right) + 1;

    while (remainingElements > 0 && left != mSortedList.end() && std::distance(left, right) >= 0)
    {
        int moveDistance = remainingElements / 2;
        mid = left;
        std::advance(mid, moveDistance);

        if (*mid == value)
        {
            return std::distance(mSortedList.begin(), mid);
        }
        else if (*mid < value)
        {
            std::advance(left, moveDistance + 1);
            remainingElements -= (moveDistance + 1);
        }
        else
        {
            if (mid == mSortedList.begin()) {
				break;
			}
            right = mid;
            right--;
            remainingElements = moveDistance;
        }
    }
    return std::distance(mSortedList.begin(), left);
}

void PmergeMe::PrintInPutSequence()
{
    std::cout << "InputSequence : [";
    for (std::vector<int>::iterator it = mInputSequence.begin(); it != mInputSequence.end(); ++it)
    {
        if (it != mInputSequence.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;
}


void PmergeMe::PrintProcessingTime(std::string containerType, double time)
{
	std::cout << "Time to process a range of ";
	std::cout << mInputSequence.size();
	std::cout << " elements with std::" << containerType << " ";
	std::cout << RED;
	std::cout << time;
	std::cout << RESET;
	std::cout << " us" << std::endl;
}

void PmergeMe::PrintPairVector()
{
	std::cout << "====================" << std::endl;
	std::cout << "       Pairs        " << std::endl;
	std::cout << "====================" << std::endl;
	for (size_t index = 0; index < mElementPairsVector.size(); index++)
	{
		std::cout << "(" << mElementPairsVector[index].first;
		std::cout << ", " << mElementPairsVector[index].second << ")";
		std::cout << std::endl;
	}

	if (mInputSequence.size() % 2 != 0)
	{
		std::cout << "(" << mOddElement <<  ")" <<std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PmergeMe::PrintPairList()
{
    std::cout << "====================" << std::endl;
    std::cout << "       Pairs        " << std::endl;
    std::cout << "====================" << std::endl;

	std::list<std::pair<int, int> >::iterator it;
	for (it = mElementPairsList.begin(); it != mElementPairsList.end(); it++)
	{
        std::cout << "(" << it->first;
        std::cout << ", " << it->second << ")";
        std::cout << std::endl;
	}

    if (mInputSequence.size() % 2 != 0)
    {
        std::cout << "(" << mOddElement <<  ")" <<std::endl;
        std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PmergeMe::PrintAfterSplitVector()
{
	PrintSortedSequenceVector();
	PrintPendingElementsVector();
	PrintOddElement();
}

void PmergeMe::PrintAfterSplitList()
{
	PrintSortedSequenceList();
	PrintPendingElementsList();
	PrintOddElement();
}

void PmergeMe::PrintSortedSequenceVector()
{
    std::cout << "SortedSequence (Vector): [";
    for (std::vector<int>::iterator it = mSortedSVector.begin(); it != mSortedSVector.end(); ++it)
    {
        if (it != mSortedSVector.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;

}

void PmergeMe::PrintPendingElementsVector()
{
    std::cout << "PendingElements (Vector): [";
    for (std::vector<int>::iterator it = mPendingElementVector.begin(); it != mPendingElementVector.end(); ++it)
    {
        if (it != mPendingElementVector.begin())
        {
            std::cout << ", ";
        }
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;
}

void PmergeMe::PrintOddElement()
{
	if (mInputSequence.size() % 2 != 0)
	{
		std::cout << "OddElement: ";
		std::cout << mOddElement << std::endl;
		std::cout << std::endl;
	}
}


void PmergeMe::PrintJacobsthalIndex()
{
    std::cout << "jacobsthalIndex: [";
    for (size_t index = 0; index < mJacobsthalIndexVector.size(); ++index)
    {
        if (index != 0)
        {
            std::cout << ", ";
        }
        std::cout << mJacobsthalIndexVector[index];
    }
    std::cout << "]" << std::endl;
	std::cout << std::endl;
}


void PmergeMe::PrintInsertionDetails(int jacobsthalIndex, int value, int position)
{
	std::cout << BLUE << "Insert..." << RESET << std::endl;
    std::cout << CYAN << "Processing Jacobsthal Index: " << jacobsthalIndex << RESET << std::endl; 
    std::cout << MAGENTA << "Value to insert: " << value << RESET << std::endl; 
	std::cout << CYAN << "Position to insert in SortedSequence: " << position << RESET << std::endl;
}

void PmergeMe::PrintSortedSequenceList()
{
    std::cout << "SortedSequence (List): NULL <-> ";
    for (std::list<int>::iterator it = mSortedList.begin(); it != mSortedList.end(); ++it)
    {
        std::cout << "[" << *it << "] <-> ";
    }
    std::cout << "NULL" << std::endl;
    std::cout << std::endl;
}

void PmergeMe::PrintPendingElementsList()
{
    std::cout << "PendingElements (List): NULL <-> ";
    for (std::list<int>::iterator it = mPendingElementList.begin(); it != mPendingElementList.end(); ++it)
    {
        std::cout << "[" << *it << "] <-> ";
    }
    std::cout << "NULL" << std::endl;
    std::cout << std::endl;
}

