//
// Created by sanch on 10/10/2019.
//

#ifndef PC2_HEAP_H
#define PC2_HEAP_H

#include <ostream>
#include <iostream>
#include <vector>
#include <fstream>
#include <>
using  namespace std;
template <typename T>
class heap {
    vector<T> vectorautilizar;
public:
    T get_max();
    T get_size();
    void heapSort(vector<T> vector1, T n);
    ostream& operator << (ostream& out);
    istream& operator >> (istream& in);
    void insert (T first, Args… items);
    void load_from(const string& file_name);
    void insert (T item);
};

template <typename T>
void heapify(vector<T> vector1, T n, T i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && vector1[l] > vector1[largest])
        largest = l;

    if (r < n && vector1[r] > vector1[largest])
        largest = r;

    if (largest != i) {
        swap(vector1[i], vector1[largest]);

        heapify(vector1, n, largest);
    }
}

template <typename T>
void heapSort(vector<T> vector1, T n)
{
    n = sizeof(vector1) / sizeof(vector1[0]);
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vector1, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(vector1[0], vector1[i]);
        heapify(vector1, i, 0);
    }
}


template<typename T>
void heap<T>::insert(T item)
{
    vectorautilizar.push_back(item);
}

template<typename T>
ostream &heap<T>::operator<<(ostream &out)
{
    auto iterator = vectorautilizar.begin();
    for(iterator; iterator != vectorautilizar.end(); iterator++)
        cout<< *iterator;
    return out;
}

template<typename T>
istream &heap<T>::operator>>(istream &in, T & datoatomar)
{
    in >> vectorautilizar.insert(datoatomar);
    return in;
}

template<typename T,typename ... Args>
void heap<T>::insert( T first, Args... second)
{
    vectorautilizar.push_back(first);
    vectorautilizar.push_back(second...);

}

template<typename T>
void heap<T>::load_from(const string &file_name)
{
    ifstream archivo;
    string linea;
    archivo.open(file_name, ios::in);
    if(archivo.fail())
    {
        cout<<"No se puede abrir";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, linea);
        vectorautilizar.push_back(linea);
    }
    archivo.close();
}

template<typename T>
T heap<T>::get_size()
{
    return vectorautilizar.size();

}

template<typename T>
T heap<T>::get_max()
{   T mayor = vectorautilizar[0];
    for (int i=1; i<vectorautilizar.size();i++)
    {
        if (mayor<vectorautilizar[i])
            vectorautilizar[i]=mayor;
    }
    return mayor;
}

#endif //PC2_HEAP_H
