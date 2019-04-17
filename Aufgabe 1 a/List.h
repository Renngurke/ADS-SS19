#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <string>
#include <iostream>

class List
{
	/*
	Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse List
	kann ein Stapel oder Warteschlange realisiert werden.
	*/
private:
	struct form { std::string start = "<< "; std::string zwischen = ", "; std::string ende = " >>\n"; } list_form;
	Node * head_tail;						// Zeiger auf Kopf- und End-Element -> next der 1. Knoten; -> prev der letzte Knoten
	int list_size;							// Länge der Kette
	bool temp;								// normalerweise false; ist true, wenn es sich um eine temoräre Liste handelt
											// die innerhalb der überladenen Operatoren angelegt wird
public:
	List();
	List(const List & _List);				// Kopie Konstruktor
	List(const List * _List);				// Kopie Konstruktor
	~List();
	void insertFront(int key);				// Einfügen eines Knotens am Anfang
	void insertFront(List & _List);			// Einfügen einer vorhandenen Liste am Anfang
	void insertFront(List * _List);			// Einfügen einer vorhandenen Liste am Anfang
	void insertBack(int key);				// Einfügen eines Knotesn am Ende
	void insertBack(List & _List);			// Einfügen einer vorhandenen Liste am Ende
	void insertBack(List * _List);			// Einfügen einer vorhandenen Liste am Ende
	bool getFront(int & key);				// Entnehmen eines Knoten am Anfang
	bool getBack(int & key);				// Entnehmen eines Knoten am Ende
	bool del(int key);						// löschen eines Knotens [key]
	bool search(int key);					// Suchen eines Knoten
	bool swap(int key1, int key2);			// Knoten in der Liste vertauschen
	int size(void);							// Größe der Lise (Anzahl der Knoten)
	bool test(void);						// Überprüfen der Zeigerstruktur der Liste
	void format(const std::string & start, const std::string & zwischen, const std::string & ende);	
											// Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
											// start: stirng vor der Ausgabe der Liste
											// zwischen: string zwischen Listenknoten
											// ende: string am Ende der Liste
	List & operator = (const List & _List);						// Zuweisungsoperator definieren
	List & operator = (const List * _List);						// Zuweisungsoperator definieren
	List & operator + (const List & List_Append);				// Listen zusammenführen zu einer Liste
	List & operator + (const List * List_Append);				// Listen zusammenführen zu einer Liste
	friend std::ostream & operator << (std::ostream & stream, List const & Liste);		// Ausgabeoperator überladen
	friend std::ostream & operator << (std::ostream & stream, List const * Liste);		// Ausgabeoperator überladen
	friend Node* get_anker(List& l);
	friend int get_AnzahlNodes(List& l);
};

#endif

