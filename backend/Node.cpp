#include "Node.hpp"

template <typename T> Node<T>::Node(T newData) { data = newData; }

template <typename T> Node<T>::~Node() {}

template <typename T> T Node<T>::getData() { return data; }
