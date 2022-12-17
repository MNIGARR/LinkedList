#include<iostream>

using namespace std;

class Node {
public:
	string data;
	Node* next;
	Node(const string& data) : data(data), next(nullptr) {}
};

	class SinglyLinkedList {
		Node* head = nullptr;
	public:
		void AddBegining(const string& elemt) {
			Node* newNode = new Node(elemt);
			newNode->next = head;
			head = newNode;
		}
		void AddEnd(const string& elemt) {
			Node* newNode = new Node(elemt);
			if (head == nullptr) {
				head = newNode;
				return;
			}

			Node* temp = head;

			while (temp->next != nullptr) {
				temp = temp->next;
			}

			temp->next = newNode;
			temp = nullptr;
		}

		void DeleteBegining() {
			if (head != nullptr) {

				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}


		void DeleteLast() {
			if (head != nullptr) {

				Node* temp = head;

				while (temp->next->next != nullptr) {
					temp = temp->next;
				}

				delete temp->next;
				temp->next = nullptr;
			}
		}

		void Print() {

			Node* temp = head;

			while (temp != nullptr) {
				cout << temp->data << " ";
				temp = temp->next;
			}
		}

		void AddElBefore(const string& x, const string element) {
			Node* newNode = new Node(element);
			if (head != nullptr) {
				Node* temp = head;
				if (x == head->data)
				{
					AddBegining(element);
					return;
				}
				while (temp->next->data != x) {
					temp = temp->next;
				}
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		void AddElAfter(const string& x, const string val) {
			Node* newNode = new Node(val);
			if (head != nullptr) {
				Node* temp = head;
				while (temp->data != x) {
					temp = temp->next;
				}
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		void DeleteByValue(const string& val) {
			Node* temp = head;
			Node* prev = nullptr;
			if (head->data == val) {
				head = temp->next;
				delete temp;
				return;
			}
			while (temp->data != val) {
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			delete temp;
		}
	};

	void main() {
		SinglyLinkedList People;
		People.AddBegining("Aysu");
		People.AddBegining("Ayshan");
		People.AddBegining("Khayyam");
		People.AddBegining("Aynura");
		People.AddBegining("Nigar");
		People.DeleteByValue("Khayyam");
		cout << "\n";
		People.Print();
	}