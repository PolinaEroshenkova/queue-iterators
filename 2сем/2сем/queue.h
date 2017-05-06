#include<iostream>
#include<exception>
#pragma once

template<class T>
class myiterator;

template <class T>
class queue
{
	friend class myiterator<T>;
	T data;
	queue *next;
	queue *head;
	queue *tail;
public:
	queue();
	void push(T);
	void pop();
	void clear();
	void display();
	int size();
	T GetData();
	void SetData(T);
	myiterator<T> begin();
	myiterator<T> end();
	friend ostream& operator<<(ostream& f,queue<T>* store)
	{
		f << store->GetData();
		return f;
	}
};

template<class T>
class myiterator
{
	queue<T> *current;
public:
	myiterator();
	myiterator<T> operator++();
	bool operator!=(myiterator<T>);
	queue<T>* GetCurrent();
	void SetCurrent(queue<T>*);
	myiterator<T> operator*();
	friend ostream& operator<<(ostream& f, myiterator<T> iter)
	{
		f << iter.GetCurrent();
		return f;
	}
};

template<class T>
queue<T>::queue()
{
	next = NULL;
	head = NULL;
	tail = NULL;
}

template<class T>
void queue<T>::push(T obj)
{
	queue <T> *tmp = new queue < T >;
	tmp->data = obj;
	if (head == NULL)
	{
		head = tmp;
		tail = tmp;
		tmp->next = NULL;
	}
	else{
		tail->next = tmp;
		tail = tmp;
	}
}

template<class T>
void queue<T>::pop()
{
	queue <T> *tmp = head;
	if (head != NULL)
	{
		head = head->next;
		if (head == NULL)
			tail = NULL;
		delete tmp;
	}
}

template<class T>
void queue<T>::clear()
{
	queue <T> *tmp = head;
	while (head != NULL)
	{
		head = head->next;
		delete tmp;
		tmp = head;
	}
}

template<class T>
void queue<T>::display()
{
	queue <T> *tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}

template<class T>
T queue<T>::GetData()
{
	return data;
}

template<class T>
void queue<T>::SetData(T data)
{
	this->data = data;
}

template<class T>
myiterator<T> queue<T>::begin()
{
	myiterator<T> iter;
	iter.SetCurrent(head);
	return iter;
}

template<class T>
myiterator<T> queue<T>::end()
{
	myiterator<T> iter;
	try{
		iter.SetCurrent(tail->next);
	}
	catch (OutOfQueue e)
	{
		iter.SetCurrent(head);
	}
	return iter;
}

template<class T>
int queue<T>::size()
{
	queue <T> *tmp = head;
	int i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}




template<class T>
myiterator<T>::myiterator()
{
	current = NULL;
}

template < class T >
myiterator<T> myiterator<T>::operator++()
{
	current = current->next;
	return *this;
}

template<class T>
bool myiterator<T>::operator!=(myiterator<T> tmp)
{
	return current != tmp.GetCurrent();
}

template<class T>
queue<T>* myiterator<T>::GetCurrent()
{
	return current;
}

template<class T>
void myiterator<T>::SetCurrent(queue<T>* temp)
{
	current = temp;
}

template<class T>
myiterator<T> myiterator<T>::operator*()
{
	return *this;
}

template<class T>
queue<T>* myiterator<T>::operator[](int N)
{
	current = head;
	for (i = 0; i < N; i++)
	{
		current = current->next;
	}
	return current;
}


