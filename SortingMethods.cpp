#include "SortingMethods.h"
#include "SortingMethods-impl.cpp"
template<typename T>
void selectionSort(std::vector<T>& v)
{
	size_t maxElementIndex = 0;
	unsigned int const SIZE = v.size();
	for (size_t i = 0, offset = 0; i < SIZE - offset && offset != SIZE; ++i)
	{
		//finding the index of the largest element in an array
		if (v.at(i) > v.at(maxElementIndex))
			maxElementIndex = i;
		if (i == v.size() - offset - 1)
		{
			//swap an element to the beginning to the end of the unsorted part of the array
			std::swap(v.at(SIZE - offset - 1), v.at(maxElementIndex));
			maxElementIndex = i = 0;
			++offset;
		}
	}
}

template<typename T>
void insertSort(std::vector<T>& v)
{
	unsigned int const SIZE = v.size();
	for (size_t i = 1; i < SIZE; ++i)
	{
		for (size_t j = 0; j < i; ++j)
		{
			//find unsorted element, the smaller v.at(i)
			if (v.at(i) < v.at(j))
			{
				//and place it in front of it
				v.insert(v.begin() + j, v.at(i));
				v.erase((v.begin() + i + 1));
			}
		}
	}
}

template<typename T>
void bubbleSort(std::vector<T>& v)
{
	unsigned int const SIZE = v.size();
	bool isSorted = false;//flag to exit an already sorted array
	for (size_t i = 1; i < SIZE && !isSorted; ++i)
	{
		isSorted = true;
		for (size_t j = 0; j < SIZE - 1; ++j)
			if (v.at(j) > v.at(j + 1))//exchange of a neighboring smaller element with a larger one
			{
				std::swap(v.at(j), v.at(j + 1));
				isSorted = false;
			}
	}
}

template<typename T>
void shellSort(std::vector<T>& v)
{
	unsigned int const SIZE = v.size();
	int increment = SIZE / 2;//distance between sorted elements
	while (increment > 0)
	{
		for (size_t i = 0; i < increment; ++i)//number of comparison pairs =size/increment
			for (size_t j = 0; j < SIZE; j += increment)
			{//sorting within a group
				size_t k = j - increment;
				for (; k >= 0 && v.at(j) < v.at(k); k -= increment)
					v.at(k + increment) = v.at(k);
				v.at(k + increment) = v.at(j);
			}
		if (increment / 2 != 0)//reducing the distance between the sorted elements
			increment = increment / 2;
		else
			increment = increment == 1 ? 0 : 1;
	}
}

template<typename T>
void tournamentSort(std::vector<T>& v)
{
	unsigned int const SIZE = v.size();
	int cmp = 0;
	for (size_t a = 0; a < SIZE; ++a)
	{
		int index = a;
		//sorting the unsorted part of the array
		for (size_t i = a; i < SIZE; i += 2)
		{
			//search for the smallest element by the tournament principle
			int left = i;
			int right = i + 1;
			if (right < SIZE)
				cmp = v.at(left) < v.at(right) ? left : right;
			else
				cmp = left;
			index = v.at(index) < v.at(cmp) ? index : cmp;
		}
		//inserting the found element at the end of the sorted array
		std::swap(v.at(a), v.at(index));
	}
}

