/*************************************************
* ADS Praktikum 1.1
* Unit-Testdatei
* �nderungen f�rs Praktikum untersagt!
*************************************************/
#include "catch.hpp"
#include "List.h"
#include "Node.h"
#include <string>

using namespace std;

// Friend-Methode fuer Testroutine
Node* get_anker(List& l) {
	return l.head_tail;
}

int get_AnzahlNodes(List& l) {
	return l.list_size;
}

TEST_CASE("List Testing", "[List]") {

	List test_list;
	List second;

	SECTION("Hinzufuegen und Suche von Nodes - simple") {
		test_list.insertFront(5);
		test_list.insertFront(7);

		test_list.insertBack(9);
		test_list.insertBack(4);

		REQUIRE(test_list.size() == 4);

		REQUIRE(test_list.search(7) == true);
		REQUIRE(test_list.search(8) == false);
		REQUIRE(test_list.search(3) == false);
		REQUIRE(test_list.search(9) == true);

		int key;
		test_list.getBack(key);
		REQUIRE(key == 4);
		test_list.getFront(key);
		REQUIRE(key == 7);
	}

	SECTION("Hinzufuegen von Nodes aus zweiter Liste am Ende") {
		test_list.insertFront(5);
		test_list.insertFront(7);

		test_list.insertBack(9);
		test_list.insertBack(4);

		second.insertFront(5);
		second.insertFront(5);
		
		second.insertBack(5);
		second.insertBack(5);

		test_list.insertBack(second);

		REQUIRE(test_list.size() == 8);		
		
		Node* tmp = get_anker(test_list);
		tmp = tmp->next;
		int key = tmp->key;
		REQUIRE(key == 7);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 5);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 9);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 4);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 5);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 5);
		
		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 5);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 5);

		for (int i = 0; i < 8; i++)
			tmp = tmp->prev;

		//head_tail wieder erreicht
		key = tmp->key;
		REQUIRE(key == 0);
	}

	SECTION("Hinzufuegen von Nodes aus zweiter Liste am Anfang") {
		test_list.insertFront(5);
		test_list.insertFront(7);
		test_list.insertBack(9);

		second.insertFront(5);
		second.insertFront(5);
		second.insertBack(5);

		test_list.insertFront(second);

		REQUIRE(test_list.size() == 6);

		Node* tmp = get_anker(test_list);
		tmp = tmp->next;
		int key = tmp->key;
		REQUIRE(key == 5);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 5);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 5);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 7);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 5);

		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 9);

		for (int i = 0; i < 7; i++)
			tmp = tmp->prev;

		//head_tail wieder erreicht
		key = tmp->key;
		REQUIRE(key == 0);
	}

	SECTION("Hinzufuegen und Loeschen von Nodes - simpel") {
		test_list.insertFront(5);
		test_list.insertFront(7);
		test_list.insertFront(9);
		test_list.insertFront(4);

		test_list.insertBack(3);
		test_list.insertBack(2);
		test_list.insertBack(4);
		test_list.insertBack(1);

		REQUIRE(test_list.size() == 8);

		REQUIRE(test_list.del(8) == false);
		REQUIRE(test_list.del(4) == true);
		REQUIRE(test_list.del(1) == true);
		REQUIRE(test_list.del(5) == true);

		REQUIRE(test_list.size() == 5);

		int key;
		test_list.getBack(key);
		REQUIRE(key == 4);
		test_list.getFront(key);
		REQUIRE(key == 9);
	}

	SECTION("Vertauschen von zwei Elementen und testen der Zeiger") {
		test_list.insertFront(5);
		test_list.insertFront(7);
		test_list.insertFront(9);
		test_list.insertFront(4);

		test_list.insertBack(3);
		test_list.insertBack(2);
		test_list.insertBack(4);
		test_list.insertBack(1);

		REQUIRE(test_list.size() == 8);
		//////////////////////////////////////////////////////////////
		//Fall 1: Zwei Knoten aus der Mitte, nicht nebeneinander	//
		//////////////////////////////////////////////////////////////
		REQUIRE(test_list.swap(7, 2) == true);
		Node* tmp = get_anker(test_list);
		//pr�fe ob 2 an neuem Platz
		for (int i = 0; i < 3; i++)
			tmp = tmp->next;
		int key = tmp->key;
		REQUIRE(key == 2);
		//Pr�fe ob 7 an neuem Platz
		for (int i = 0; i < 3; i++)
			tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 7);
		tmp = tmp->next;
		//Pr�fe ob Anker wieder erreichbar
		for (int i = 0; i < 7; i++)
			tmp = tmp->prev;
		key = tmp->key;
		REQUIRE(key == 0);

		//////////////////////////////////////////////////////////////////////////
		//Fall 2: Erster Knoten mit einem aus der Mitte, nicht nebeneinander	//
		//////////////////////////////////////////////////////////////////////////
		REQUIRE(test_list.swap(4, 5) == true);
		tmp = tmp->next;
		//Pr�fe ob neuer erster richtig
		key = tmp->key;
		REQUIRE(key == 5);
		//Pr�fe ob 4 an neuem Platz
		for (int i = 0; i < 3; i++)
			tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 4);
		tmp = tmp->next;
		//Pr�fe ob Anker wieder erreichbar
		for (int i = 0; i < 5; i++)
			tmp = tmp->prev;
		key = tmp->key;
		REQUIRE(key == 0);

		//////////////////////////////////////////////////////////////////////////
		//Fall 3: Letzter Knoten mit einem aus der Mitte, nicht nebeneinander	//
		//////////////////////////////////////////////////////////////////////////
		REQUIRE(test_list.swap(1, 3) == true);
		for(int i = 0; i < 5; i++)
			tmp = tmp->next;
		//Pr�fe ob 1 an neuem Platz
		key = tmp->key;
		REQUIRE(key == 1);
		//Pr�fe ob neuer letzter richtig
		for (int i = 0; i < 3; i++)
			tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 3);
		tmp = tmp->next;
		//Pr�fe ob Anker wieder erreichbar
		for (int i = 0; i < 9; i++)
			tmp = tmp->prev;
		key = tmp->key;
		REQUIRE(key == 0);

		//////////////////////////////////////////////////////
		//Fall 4: Zwei Knoten aus der Mitte, nebeneinander	//
		//////////////////////////////////////////////////////
		REQUIRE(test_list.swap(2, 4) == true);
		for (int i = 0; i < 3; i++)
			tmp = tmp->next;
		//Pr�fe ob 4 an neuem Platz
		key = tmp->key;
		REQUIRE(key == 4);
		//Pr�fe ob 1 an neuem Platz
		tmp = tmp->next;
		key = tmp->key;
		REQUIRE(key == 2);
		tmp = tmp->next;
		//Pr�fe ob Anker wieder erreichbar
		for (int i = 0; i < 5; i++)
			tmp = tmp->prev;
		key = tmp->key;
		REQUIRE(key == 0);
	}
}