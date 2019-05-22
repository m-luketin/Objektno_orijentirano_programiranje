#include "Zbroj.h"

template <typename T>
Zbroj<T>::Zbroj(T prviClan, T drugiClan)
{
	prvi = prviClan;
	drugi = drugiClan;
}


template <typename T>
T Zbroj<T>::Zbroji()
{
	return prvi + drugi;
}