/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:35:03 by dkham             #+#    #+#             */
/*   Updated: 2023/12/27 19:35:04 by dkham            ###   ########.fr       */
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

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m" 

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void IsValidInput(int argc, char** argv);
		bool IsPositiveInteger(const std::string& inputString);
		void SortUsingContainer();

		void MakePairs();
		void GenerateJacobsthalIndexes(int pendingElementSize);
		int Jacobsthal(int n);

		double MeasureTimeForVector();
		void MergeInsertionSortVector();
		void MergeSortVector(int left, int right);
		void MergingVector(int left, int mid, int right);
		void SplitElementPairsVector();
		void InsertSortVector();
		void InsertElementsUsingJacobsthalIndexesVector(); 
		void InsertOddElementVector();
		int BinarySearchVector(int value);

		double MeasureTimeForList();
		void MergeInsertionSortList();
		void MergeSortList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator right);
		void MergingList(std::list<std::pair<int, int> >::iterator left, std::list<std::pair<int, int> >::iterator mid, std::list<std::pair<int, int> >::iterator right);
		void SplitElementPairsList();
		void InsertSortList();
		void InsertElementsUsingJacobsthalIndexesList();
		void InsertOddElementList();
		int BinarySearchList(int value);


		void PrintInPutSequence();
		void PrintOddElement();
		void PrintJacobsthalIndex();
		void PrintInsertionDetails(int jacobsthalIndex, int value, int position);
		void PrintProcessingTime(std::string containerType, double time);

		void PrintPairVector();
		void PrintAfterSplitVector();
		void PrintSortedSequenceVector();
		void PrintPendingElementsVector();

		void PrintPairList();
		void PrintAfterSplitList();
		void PrintSortedSequenceList();
		void PrintPendingElementsList();


	private:
		std::vector<int> mInputSequence;
		std::vector<int> mJacobsthalIndexVector;
        int mOddElement;

        std::vector<std::pair<int, int> > mElementPairsVector;
		std::vector<int> mSortedSVector;
        std::vector<int> mPendingElementVector;

		std::list<std::pair<int, int> > mElementPairsList;
		std::list<int> mSortedList;
		std::list<int> mPendingElementList;
};

#endif
