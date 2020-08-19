#ifndef _SORTINGMETHODS_H_
#define _SORTINGMETHODS_H_
#include <vector>
#include <algorithm>
template< typename T>
void selectionSort(std::vector<T>& v);
template< typename T>
void insertSort(std::vector<T>& v);
template< typename T>
void bubbleSort(std::vector<T>& v);
template< typename T>
void shellSort(std::vector<T>& v);
template< typename T>
void tournamentSort(std::vector<T>& v);
#endif