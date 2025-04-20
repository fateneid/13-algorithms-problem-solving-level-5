#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{

protected:

	int _Size = 0;

public:

	class Node
	{
	public:
		T value;
		Node* prev;
		Node* next;
	};

	Node* head = NULL;

	void InsertAtBeginning(T value) {

		Node* new_node = new Node();

		new_node->value = value;
		new_node->prev = NULL;
		new_node->next = head;

		if (head != NULL) {
			head->prev = new_node;
		}

		head = new_node;
		_Size++;

	}

	Node* Find(T value) {

		Node* current = head;

		while (current != NULL && current->value != value) {
			current = current->next;
		}

		return current;

	}

	void PrintList() {

		Node* current = head;

		while (current != NULL) {
			cout << current->value << " ";
			current = current->next;
		}
		cout << "\n";

	}

	void InsertAfter(Node* current, T value) {

		Node* new_node = new Node();

		new_node->value = value;
		new_node->prev = current;
		new_node->next = current->next;

		if (current->next != NULL) {
			current->next->prev = new_node;
		}

		current->next = new_node;
		_Size++;

	}

	void InsertAtEnd(int value) {

		Node* new_node = new Node();

		new_node->value = value;
		new_node->next = NULL;

		if (head == NULL) {
			new_node->prev = NULL;
			head = new_node;
			_Size++;
			return;
		}

		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = new_node;
		new_node->prev = current;
		_Size++;

	}

	void DeleteNode(Node*& node_to_delete) {

		if (head == NULL || node_to_delete == NULL) return;

		if (head == node_to_delete)
			head = node_to_delete->next;

		if (node_to_delete->next != NULL)
			node_to_delete->next->prev = node_to_delete->prev;

		if (node_to_delete->prev != NULL)
			node_to_delete->prev->next = node_to_delete->next;

		delete node_to_delete;
		_Size--;

	}

	void DeleteFirstNode() {

		if (head == NULL) return;

		Node* temp = head;
		head = head->next;

		if (head != NULL) {
			head->prev = NULL;
		}

		delete temp;
		_Size--;

	}

	void DeleteLastNode() {

		if (head == NULL) return;

		if (head->next == NULL) {
			delete head;
			head = NULL;
			_Size = 0;
			return;
		}

		Node* current = head;

		while (current->next != NULL) {
			current = current->next;
		}

		current->prev->next = NULL;
		delete current;
		_Size--;

	}

	int Size() {

		return _Size;

	}

	bool IsEmpty() {

		return _Size == 0;

	}

	void Clear() {

		while (_Size > 0) {

			DeleteFirstNode();

		}

	}

	void Reverse() {

		Node* current = head;
		Node* temp = nullptr;

		while (current != nullptr) {

			temp = current->prev;
			current->prev = current->next;
			current->next = temp;

			current = current->prev;

		}
	
		if (temp != nullptr) {
			head = temp->prev;
		}

	}

	Node* GetNode(int index) {

		if (index < 0 || index >= _Size) return NULL;

		Node* current = head;
		while (index-- && current != NULL) {
			current = current->next;
		}

		return current;

	}

	T GetItem(int index) {

		Node* ItemNode = GetNode(index);
		
		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->value;

	}

	bool UpdateItem(int index, T new_value) {

		if (Node* ItemNode = GetNode(index)) {
			ItemNode->value = new_value;
			return true;
		}

		return false;

	}

	bool InsertAfter(int index, T value) {

		if (Node* ItemNode = GetNode(index)) {
			InsertAfter(ItemNode, value);
			return true;
		}
		return false;

	}

};
