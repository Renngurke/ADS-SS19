#include "List.h"

List::List()
{
	// Konstruktor f�r eine leere Liste
	head_tail = new Node;
	list_size = 0;
	temp = false;
	head_tail->next = head_tail;
	head_tail->prev = head_tail;
}

List::List(const List & _List)
{
	// Konstruktor mit �bergabe einer Liste, die dann kopiert wird.
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	list_form = _List.list_form;
	head_tail = new Node;
	list_size = 0;
	temp = _List.temp;
	head_tail->next = head_tail;
	head_tail->prev = head_tail;
	Node * tmp_node;
	tmp_node = _List.head_tail->next;
	while (tmp_node != _List.head_tail)
	{
		head_tail->prev = new Node(tmp_node->key, head_tail->prev->next, head_tail->prev);
		head_tail->prev->prev->next = head_tail->prev;
		list_size++;
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;		// ist die �bergebene Liste eine tempor�re Liste? -> aus Operator +
}

List::List(const List * _List)
{
	// Konstruktor mit �bergabe einer Liste, die dann kopiert wird.
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	list_form = _List->list_form;
	head_tail = new Node;
	list_size = 0;
	temp = _List->temp;
	head_tail->next = head_tail;
	head_tail->prev = head_tail;
	Node * tmp_node;
	tmp_node = _List->head_tail->next;
	while (tmp_node != _List->head_tail)
	{
		head_tail->prev = new Node(tmp_node->key, head_tail->prev->next, head_tail->prev);
		head_tail->prev->prev->next = head_tail->prev;
		list_size++;
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;		// ist die �bergebene Liste eine tempor�re Liste? -> aus Operator +
}

List::~List()
{
	if (head_tail->next == head_tail) {		//Wenn der Pointer auf sich selbst zeigt
		delete head_tail;					// ist die Liste leer und kann gel�scht werden
	}
	else {																	//
		Node * tmp_ptr = head_tail;											//erstelle zwei tempor�re Pointer, tmp_ptr mit der gleich head_tail ist
		Node * delete_ptr = nullptr;										// und delete_ptr, welcher zum l�schen dient
		while (tmp_ptr->next != head_tail->prev) {							
			delete_ptr = tmp_ptr;											//
			tmp_ptr = tmp_ptr->next;
			delete delete_ptr;
		}
		
	}

}

void List::insertFront(int key)
{
	// Node(key, head ,tail) zeigt auf das Erste Element
	Node *n(new Node(key, head_tail->next, head_tail));

	// das erste element soll auf N (das neue erste element zeigen) zeigen
	head_tail->next->prev = n;

	// head_tail zeigt auf den Anfang
	head_tail->next = n;

	list_size++;
	/*
		Einen neuen Knoten mit dem Schl�sselwert key am Anfang der Liste einf�gen
	*/
}

void List::insertFront(List & _List)
{
	//Wenn �bergabene Liste leer ist nich einf�gen
	if (_List.head_tail->next != _List.head_tail)
	{
		// Gr��e der einzuf�genden Liste auf Liste addieren
		list_size += _List.list_size;
		if (head_tail->next == head_tail)
		{
			// Wenn liste leer
				//head_tail->next auf erstes Element der einzuf�genden Liste umbiegen
			head_tail->next = _List.head_tail->next;
			//head_tail->prev auf das letzte Element der einzuf�genden Liste umbiegen
			head_tail->prev = _List.head_tail->prev;
			//Das letzte Element der einzuf�genen Liste zeigt noch auf den head_tail der Liste _List und wird umgebogen auf den head_tail der Eingabeliste
			_List.head_tail->prev->next = head_tail;
			//Das erste Element der eizuf�gendne Liste zeigt noch auf den alten head_tail, und muss noch umgebogen werden
			_List.head_tail->next->prev = head_tail;

		}
		else
		{
			_List.head_tail->prev->next = head_tail->next;
			//head_tail->next auf erstes Element der einzuf�genden Liste umbiegen
			head_tail->next = _List.head_tail->next;
			//Das letzte Element der einzuf�genen Liste zeigt noch auf den head_tail der Liste _List und wird umgebogen auf den head_tail der Eingabeliste
			//_List.head_tail->prev->next = head_tail->next;
			//Das erste Element der eizuf�gendne Liste zeigt noch auf den alten head_tail, und muss noch umgebogen werden
			_List.head_tail->next->prev = head_tail;
			//das letzte element der einzuf�genden liste muss auf das Alte erste Element der aktuellen Liste zeigen
			head_tail->next->next->prev = _List.head_tail->prev;

			//Node(key,next,prev)

		}
		//l�schen des head_tail der �bergabe Liste
		delete _List.head_tail;
	}
}


void List::insertFront(List * _List)
{

	//Wenn �bergabene Liste leer ist nich einf�gen
	if (_List->head_tail->next != _List->head_tail)
	{
		// Gr��e der einzuf�genden Liste auf Liste addieren
		list_size += _List->list_size;
		if (head_tail->next == head_tail)
		{
			// Wenn liste leer
			//head_tail->next auf erstes Element der einzuf�genden Liste umbiegen
			head_tail->next = _List->head_tail->next;
			//head_tail->prev auf das letzte Element der einzuf�genden Liste umbiegen
			head_tail->prev = _List->head_tail->prev;
			//Das letzte Element der einzuf�genen Liste zeigt noch auf den head_tail der Liste _List und wird umgebogen auf den head_tail der Eingabeliste
			_List->head_tail->prev->next = head_tail;
			//Das erste Element der eizuf�gendne Liste zeigt noch auf den alten head_tail, und muss noch umgebogen werden
			_List->head_tail->next->prev = head_tail;

		}
		else
		{
			_List->head_tail->prev->next = head_tail->next;
			//head_tail->next auf erstes Element der einzuf�genden Liste umbiegen
			head_tail->next = _List->head_tail->next;
			//Das letzte Element der einzuf�genen Liste zeigt noch auf den head_tail der Liste _List und wird umgebogen auf den head_tail der Eingabeliste

			//_List->head_tail->prev->next = head_tail->next;

			//Das erste Element der eizuf�gendne Liste zeigt noch auf den alten head_tail, und muss noch umgebogen werden
			_List->head_tail->next->prev = head_tail;
			//das letzte element der einzuf�genden liste muss auf das Alte erste Element der aktuellen Liste zeigen
			head_tail->next->next->prev = _List->head_tail->prev;

			//Node(key,next,prev)

		}
		//l�schen des head_tail der �bergabe Liste
		delete _List->head_tail;
	}
}

void List::insertBack(int key)
{
	//wie Front, nur anderes herum
	Node *n(new Node(key, head_tail, head_tail->prev));

	//das alte letzte zeigt jetzt auf das neue Letze element
	head_tail->prev->next = n;
	//das letzte zeigt auf den Head_tail
	head_tail->prev = n;

	list_size++;

	// Einf�gen eines neuen Knotens am Ende der Liste
/*
	Einen neuen Knoten mit dem Schl�sselwert key am Ende der Liste einf�gen
*/
}

void List::insertBack(List & _List)
{//Wenn �bergabene Liste leer ist nich einf�gen
	if (_List.head_tail->next != _List.head_tail)
	{
		// Gr��e der einzuf�genden Liste auf Liste addieren
		list_size += _List.list_size;
		if (head_tail->next == head_tail)
		{
			// Wenn liste leer
				//head_tail->prev auf letzte Element der einzuf�genden Liste umbiegen
			head_tail->prev = _List.head_tail->next;
			//head_tail->next auf das erste Element der einzuf�genden Liste umbiegen
			head_tail->next = _List.head_tail->next;
			//Das letzte Element der einzuf�genen Liste zeigt noch auf den head_tail der Liste _List und wird umgebogen auf den head_tail der Eingabeliste
			_List.head_tail->prev->next = head_tail;
			//Das erste Element der eizuf�gendne Liste zeigt noch auf den alten head_tail, und muss noch umgebogen werden
			_List.head_tail->next->prev = head_tail;

		}
		else
		{
			_List.head_tail->next->prev = head_tail->prev;

			head_tail->prev->next = _List.head_tail->next;
			//das letzte element der einzuf�genden liste muss auf das Alte erste Element der aktuellen Liste zeigen
			head_tail->prev = _List.head_tail->prev;

			//Das letzte Element der einzuf�genen Liste zeigt noch auf den head_tail der Liste _List und wird umgebogen auf den head_tail der Eingabeliste
			_List.head_tail->prev->next = head_tail;

			

			//Node(key,next,prev)
		}
		//l�schen des head_tail der �bergabe Liste
		delete _List.head_tail;
	}
}

void List::insertBack(List * _List)
{
	if (_List->head_tail->next != _List->head_tail)
	{
		// Gr��e der einzuf�genden Liste auf Liste addieren
		list_size += _List->list_size;
		if (head_tail->next == head_tail)
		{
			// Wenn liste leer
				//head_tail->prev auf letzte Element der einzuf�genden Liste umbiegen
			head_tail->prev = _List->head_tail->next;
			//head_tail->next auf das erste Element der einzuf�genden Liste umbiegen
			head_tail->next = _List->head_tail->next;
			//Das letzte Element der einzuf�genen Liste zeigt noch auf den head_tail der Liste _List und wird umgebogen auf den head_tail der Eingabeliste
			_List->head_tail->prev->next = head_tail;
			//Das erste Element der eizuf�gendne Liste zeigt noch auf den alten head_tail, und muss noch umgebogen werden
			_List->head_tail->next->prev = head_tail;

		}
		else
		{
			_List->head_tail->next->prev = head_tail->prev; //muss hier stehen bevor er veraendert wird

			head_tail->prev->next = _List->head_tail->next;
			//das letzte element der einzuf�genden liste muss auf das Alte erste Element der aktuellen Liste zeigen
			head_tail->prev = _List->head_tail->prev;
			//Das letzte Element der einzuf�genen Liste zeigt noch auf den head_tail der Liste _List und wird umgebogen auf den head_tail der Eingabeliste
			_List->head_tail->prev->next = head_tail;

			//Node(key,next,prev)
		}
		//l�schen des head_tail der �bergabe Liste
		delete _List->head_tail;
	}

}

bool List::getFront(int & key)
{
	// entnehmen des Knotens am Anfang der Liste
	// der Wert wird als Parameter zur�ckgegeben
	// der Knoten wird entnommen
	bool returnvalue=false;

	if (head_tail->next)
	{
		Node *n(head_tail->next); // zeigt auf das erste element
		if (n != head_tail) // solange die liste nicht leer ist
		{
			head_tail->next = n->next; // headtail zeigt auf das zweite element
			n->next->prev = head_tail; //das dritte zeigt auf das zweite (jetzt das zweite aufs erste)
			key = n->key; // Wert vom zu l�schenden Element auf Key setzen
			delete n; // erstes elemtn l�schen
			list_size--;
			returnvalue = true;
		}

	}

	return returnvalue;
	/*
		Der Wert des vorderen Schl�sselknotens wird r�ckgegeben und der Knoten gel�scht.
		Die Methode del(key) darf nicht zum l�schen benutzt werden.
	*/
}

bool List::getBack(int & key)

{
	//Node * last = head_tail->prev;

	// entnehmen des Knotens am Ende der Liste
	// der Wert wird als Parameter zur�ckgegeben
	// der Knoten wird entnommen

	bool returnvalue=false;

	if (head_tail)
	{
		Node *n(head_tail->prev);
		if (n != head_tail)

		{

			head_tail->prev = n->prev;

			n->prev->next = head_tail;

			key = n->key;

			delete n;

			list_size--;

			returnvalue = true;

		}

	}

	return returnvalue;

	/*
	Der Wert des letzten Schl�sselknotens wird r�ckgegeben und der Knoten gel�scht.
	Die Methode del(key) darf nicht zum l�schen benutzt werden.
*/
}

bool List::del(int key)
{
	Node * current = head_tail->next;
	while (current->key != key && current != head_tail) { //solange nicht hinten und nicht wert gefunden, einen weiter gehen
		current = current->next;
	}
	if (current != head_tail) {

		current->prev->next = current->next; //den pointer vom vorherigen element auf das n�chste setzen
		current->next->prev = current->prev; //den pointer vom n�chsten element auf das aktuelle auf das vorherige element setzen

		delete current;		//aktuelles element l�chen und liste um 1 verkleinern
		list_size--;
		return true;
	}
	return false;//nichts gefunden
				 /*
				 L�schen des Knotens mit dem Schl�ssel key
				 */

}

bool List::search(int key)
{
	Node * current = head_tail->next;			//pointer current wird mit zeigt auf das erste Element


	while (current->key != key && current != head_tail) {	// solange wir nicht den wert gefunden haben und nicht am ende sind auf den naechsten pointer setzen.
		current = current->next;
	}

	return current != head_tail;		//true zur�ckgeben, wenn current ungleich headtail ist 
	/*
	suchen ob ein Knoten mit dem Schl�ssel key existiert.
	*/
}



bool List::swap(int key1, int key2)
{
	// Vertauschen von zwei Knoten
	// Dabei werden die Zeiger der Knoten und deren Nachbarn ver�ndert.
	Node * swapkey1 = nullptr;		//zwei tempor�te Pointer zum tauschen werden initialisiert
	Node * swapkey2 = nullptr;
	Node * temp = head_tail->next;
	while (temp != head_tail) {		//geht alle nodes durch, bis der vorherige Platz gefunden wurde
		if (temp->key == key1) {	//Wenn temp->key auf den ersten Platz zeigt, in swap1 kopieren
			swapkey1 = temp;
			break;
		}
		temp = temp->next;			//liste durchlaufen
	}
	temp = head_tail->next;
	while (temp != head_tail) {
		if (temp->key == key2) {
			swapkey2 = temp;
			break;
		}
		temp = temp->next;
	}
	if (swapkey1 != nullptr && swapkey2 != nullptr) {  //wenn beide gefunden wurden, kann das tauschen beginnen
		if (swapkey1->next == swapkey2) {
			swapkey1->prev->next = swapkey2;
			swapkey1->next = swapkey2->next;
			temp = swapkey1->prev;
			swapkey1->prev = swapkey2;
			swapkey2->next->prev = swapkey1;
			swapkey2->next = swapkey1;
			swapkey2->prev = temp;
		}
		else if (swapkey2->next == swapkey1) {
			swapkey2->prev->next = swapkey1;
			swapkey2->next = swapkey1->next;
			temp = swapkey2->prev;
			swapkey1->prev = swapkey1;
			swapkey1->next->prev = swapkey2;
			swapkey1->next = swapkey2;
			swapkey1->prev = temp;
		}
		else {

			temp = swapkey1->prev;
			swapkey1->prev = swapkey2->prev;
			swapkey2->prev = temp;

			temp = swapkey1->next;
			swapkey1->next = swapkey2->next;
			swapkey2->next = temp;

			swapkey1->next->prev = swapkey1; //eingliedern
			swapkey1->prev->next = swapkey1;

			swapkey2->next->prev = swapkey2;
			swapkey2->prev->next = swapkey2;
		}
		return true;
	}
	return false;


}

int List::size(void)
{
	// R�ckgabe der Knoten in der Liste mit O(1)
	/*
	Anzahl der Knoten in der Liste zur�ckgeben.
	*/
	return list_size;
}

bool List::test(void)
{
	// Testmethode: die Methode durchl�uft die Liste vom Anfang bis zum Ende und zur�ck
	// Es werden dabei die Anzahl der Knoten gez�hlt.
	// Stimmt die Anzahl der Knoten �berein liefert die Methode true
	Node * tmp = head_tail->next;
	int i_next = 0, i_prev = 0;
	while (tmp != head_tail) {
		tmp = tmp->next;
		if (i_next > list_size) return false;
		i_next++;
	}
	if (i_next != list_size) return false;
	tmp = head_tail->prev;
	while (tmp != head_tail) {
		tmp = tmp->prev;
		if (i_prev > list_size) return false;
		i_prev++;
	}
	return i_prev == i_next;
}


List & List::operator = (const List & _List)
{
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;		//  !! keine Aktion notwendig
	list_form = _List.list_form;
	Node * tmp_node;
	if (list_size)
	{
		Node * tmp_del;
		tmp_node = head_tail->next;
		while (tmp_node != head_tail)		// Alle eventuell vorhandenen Knoten in this l�schen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		list_size = 0;
		head_tail->next = head_tail;
		head_tail->prev = head_tail;
	}
	tmp_node = _List.head_tail->next;		// Die Listen-Knotenwerte werden kopiert
	while (tmp_node != _List.head_tail)
	{
		insertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;			// ist die �bergebene Liste eine tempor�re Liste? -> aus Operator +
	return *this;
}

List & List::operator = (const List * _List)
{
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;		//  !! keine Aktion notwendig
	list_form = _List->list_form;
	Node * tmp_node;
	if (list_size)
	{
		Node * tmp_del;
		tmp_node = head_tail->next;
		while (tmp_node != head_tail)		// Alle eventuell vorhandenen Knoten in this l�schen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		list_size = 0;
		head_tail->next = head_tail;
		head_tail->prev = head_tail;
	}
	tmp_node = _List->head_tail->next;
	while (tmp_node != _List->head_tail)	// Die Listen-Knotenwerte werden kopiert
	{
		insertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;			// ist die �bergebene Liste eine tempor�re Liste? -> aus Operator +
	return *this;
}

List & List::operator + (const List & List_Append)
{
	// Die Methode +
	// Es werden zwei Listen aneinander gehangen.
	// Dabei werden beide Ursprungslisten nicht ver�ndert. Es entsteht eine neue Ergebnisliste.
	Node * tmp_node;
	List * tmp;
	if (temp) {										// this ist eine tempor�re Liste und kann ver�ndert werden
		tmp = this;
	}
	else {
		tmp = new List(this);						// this ist keine tempor�re Liste -> Kopie erzeugen
		tmp->temp = true;							// Merker setzten, dass es sich um eine tempor�re Liste handelt
	}
	if (List_Append.list_size) {					// anh�ngen der �bergebenen Liste an tmp
		tmp_node = List_Append.head_tail->next;
		while (tmp_node != List_Append.head_tail) {
			tmp->insertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append.temp) delete & List_Append;		// wurde eine tempor�re Liste �bergeben, dann wird diese gel�scht						
	return *tmp;
}

List & List::operator + (const List * List_Append)
{
	// Die Methode +
	// Es werden zwei Listen aneinander gehangen.
	// Dabei werden beide Ursprungslisten nicht ver�ndert. Es entsteht eine neue Ergebnisliste.
	Node * tmp_node;
	List * tmp;
	if (temp) {										// this ist eine tempor�re Liste und kann ver�ndert werden
		tmp = this;
	}
	else {
		tmp = new List(this);						// this ist keine tempor�re Liste -> Kopie erzeugen
		tmp->temp = true;							// Merker setzten, dass es sich um eine tempor�re Liste handelt
	}
	if (List_Append->list_size) {					// anh�ngen der �bergebenen Liste an tmp
		tmp_node = List_Append->head_tail->next;
		while (tmp_node != List_Append->head_tail) {
			tmp->insertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->temp) delete List_Append;		// wurde eine tempor�re Liste �bergeben, dann wird diese gel�scht					
	return *tmp;
}

void List::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	// Setzen des Formates f�r die Ausgabesteuerung der Liste bei cout
	// das Format wird f�r den �berladenen Operator << verwendet
	list_form.start = start;
	list_form.zwischen = zwischen;
	list_form.ende = ende;
}

std::ostream & operator<<(std::ostream  & stream, List const & Liste)
{
	// Ausgabe der Liste mit cout
	stream << Liste.list_form.start;
	for (Node * tmp = Liste.head_tail->next; tmp != Liste.head_tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.head_tail ? Liste.list_form.ende : Liste.list_form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine tempor�re Liste �bergeben, dann wird diese gel�scht
	return stream;
}

std::ostream & operator << (std::ostream & stream, List const * Liste)
{
	// Ausgabe der Liste mit cout
	stream << Liste->list_form.start;
	for (Node * tmp = Liste->head_tail->next; tmp != Liste->head_tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->head_tail ? Liste->list_form.ende : Liste->list_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine tempor�re Liste �bergeben, dann wird diese gel�scht
	return stream;
}
