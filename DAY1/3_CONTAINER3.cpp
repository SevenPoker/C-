#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

template<typename T>
class slist_iterator
{
    Node<T>* current;
public:
    slist_iterator( Node<T>* p = nullptr) : current(p) {}

    slist_iterator& operator++()
    {
        current = current->next;
        return *this;
    }

    T& operator*() {return current->data;}

    bool operator==(const slist_iterator& other) {return current == other.current;}

    bool operator!=(const slist_iterator& other) {return current != other.current;}
};


template<typename T>
class slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}
    // 모든 컨테이너 설계자는 자신의 "반복자 이름"을
    // 약속된 이름 (iterator) 로 외부에 노출하기로 약속

    using iterator = slist_iterator<T>;


    iterator<int> begin() {return iterator<int>(head); };
    iterator<int> end() {return iterator<int>(0); };
};

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

    slist<int>::iterator p1 = s.begin();
    slist<int>::iterator p2 = s.end();

    std::cout << *p1 << std::endl;
    ++p1;
    std::cout << *p1 << std::endl;

}
