#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>

template <class T>
class Vector
{
public:
    //typedef T const * const_iterator;
    //Vector (Vector<T> const &);
    //Vector<T> & operator = (Vector<T> const &);
    //const_iterator begin() const;
    //const_iterator end() const;
    //iterator erase();
    //const_iterator erase() const;
    typedef T value_type;
    typedef T* iterator;
    Vector();
    ~Vector();
    size_t size_f() const;
    size_t capacity_f () const;
    iterator begin();
    iterator end();
    T& operator [] (int i) const;
    const T& last ();
    void push_back(const T & p);
    void removee (int a);
    void clear();
    bool empty() const;
private:
    //std::unique_ptr <T> data;
    size_t size, capacity;
    T *data;
};

template <class T>
Vector<T>::Vector()
{
    data=new T[23];
    size=0;
    capacity=23;
}

template <class T>
Vector<T>::~Vector()
{
    delete[] data;
    size=0;
    capacity=0;
}

template <class T>
size_t Vector<T>::capacity_f() const
{
    return capacity;
}

template <class T>
size_t Vector<T>::size_f() const
{
    return size;
}

template <class T>
void Vector<T>::push_back(const T & p)
{
    if (capacity==size)
    {
        std::cout<<"done";
        int capacity_n=2*capacity_f();
        T* tmp = new T[capacity_n];
        std::copy(begin(), end(), tmp);
        delete[] data;
        data=tmp;
        delete[] tmp;
        capacity*=2;
    }
    *(data+size)=p;
    size++;
}

template <class T>
typename Vector<T>::iterator
Vector <T>::begin()
{
    return data;
}

template <class T>
typename Vector<T>::iterator
Vector <T>::end()
{
    return data+size;
}

template <class T>
void Vector<T>::clear()
{
    delete[] data;
    data = new T[23];
    size=0;
    capacity=23;
}

template <class T>
void Vector<T>::removee(int a)
{
    for (int i=a+1; i<size; i++)
    {
        data[i-1]=data[i];
    }
    size--;
}

template <class T>
bool Vector<T>::empty() const
{
    return (size==0);
}

template <class T>
T& Vector<T>::operator[](int pos) const
{
    return (*(data+pos));
}

template <class T>
const T& Vector<T>::last()
{
    return *(data+size-1);
}









#endif // VECTOR_H

/*template <class T>
typename Vector<T>::const_iterator
Vector <T>::begin() const
{
    return data;
}*/

/*
template <class T>
typename Vector<T>::const_iterator
Vector <T>::end() const
{
    return data+size;
}*/
