#include <iostream>
using namespace std;
template<typename T>
struct Element
{
	T date;
	Element<T>* next;
	Element(T value) {
		date = value;
		next = nullptr;
	}





};
template<typename T>
class Queue {
private:
	Element<T>* head;
	Element<T>* tail;
public:

	Queue() {
		head = tail = nullptr;
	}
	void enqueue(T value) {
		Element<T>* newelement = new Element<T>(value);
		if (tail == nullptr) {
			head = tail = newelement;
			return;
		}
		tail->next = newelement;
		tail = newelement;
	}
	T dequeue() {
		Element<T>* tmp = head;
		head = head->next;
		if (head == nullptr) {
			tail = nullptr;
		}
		T val = tmp->date;
		delete tmp;
		tmp = nullptr;
		return val;
	}
	bool isEmpty()const {

		return !head && tail;
	}

	Element<T>* getHead()const {
		return head;
	}

	T peek() {
		return head->date;
	}
	~Queue() {
		while (this->isEmpty() == false)
		{
			this->dequeue();
			head = nullptr;
			tail = nullptr;

		} 
			
	}


	
};
template<typename T>
void reverseprint(Element<T>* element) {
	if (element == nullptr)
		return;
	reverseprint(element->next);
	cout << element->date << endl;
}
template<typename T>
void reverse(const Queue<T>& queu) {
	if (queu.isEmpty()) {
		return;
	}
	Element<T>* head = queu.getHead();

	reverseprint(head);


}



int main()
{
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);


	/*while (q.isEmpty() == false) {
		cout << q.dequeue() << "\n";
	}*/
	reverse(q);




















}


