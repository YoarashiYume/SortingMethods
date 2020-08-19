#include "SortingMethods.h"
#include "SortingMethods-impl.cpp"
template<typename T>
void selectionSort(std::vector<T>& v)
{
	T maxElementIndex = 0;
	unsigned int const SIZE = v.size();
	for (size_t i = 0, offset = 0; i < SIZE - offset && offset != SIZE; ++i)
	{
		if (v.at(i) > v.at(maxElementIndex))
			maxElementIndex = i;
		if (i == v.size() - offset - 1)
		{
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
			if (v.at(i) < v.at(j))
			{
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
	bool isSorted = false;
	for (size_t i = 1; i < SIZE && !isSorted; ++i)
	{
		isSorted = true;
		for (size_t j = 0; j < SIZE - 1; ++j)
			if (v.at(j) > v.at(j + 1))
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
	int swp = 0;
	int comp = 0;
	int increment = SIZE / 2;
	while (increment > 0)
	{
		for (size_t i = 0; i < increment; ++i)
			for (size_t j = 0; j < SIZE; j += increment,++swp)
			{
				size_t k = j - increment;
				for (; k >= 0 && v.at(j) < v.at(k); k -= increment,++swp,++comp)
					v.at(k + increment) = v.at(k);
				v.at(k + increment) = v.at(j);
			}
		++comp;
		if (increment / 2 != 0)
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
		for (size_t i = a; i < SIZE; i += 2)
		{
			int left = i;
			int right = i + 1;
			if (right < SIZE)
				cmp = v.at(left) < v.at(right) ? left : right;
			else
				cmp = left;
			index = v.at(index) < v.at(cmp) ? index : cmp;
		}
		std::swap(v.at(a), v.at(index));
	}
}

