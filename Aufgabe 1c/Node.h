#ifndef _NODE_H
#define _NODE_H
template < typename _T >

class Node
{
public:
	typename _T key;
	Node < typename _T > * next, *prev;
public:

	Node()
	{
		next = 0;
		prev = 0;
	}
	Node(typename _T key, Node < typename _T > * next, Node < typename _T > * prev)
	{
		this->key = key;
		this->next = next;
		this->prev = prev;
	}
	~Node()
	{
	}
};
#endif