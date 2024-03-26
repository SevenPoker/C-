#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

// slist 안에 있는 요소를 가리키는 포인터 역할의 객체를 만들어보자.

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

    // find 에 보내려면 "++, ==, *, !=" 다 가능해야한다.

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

    // find 로 검색하려면 "시작과 마지막 다음"을 가리키는 반복자가 필요
    slist_iterator<int> begin() {return slist_iterator<int>(head); };
    slist_iterator<int> end() {return slist_iterator<int>(0); };
};

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

    slist_iterator<int> p1 = s.begin();
    slist_iterator<int> p2 = s.end();

    // p는 포인터가 아닌 "객체" 입니다.
    // 하지만 포인터 처럼 사용가능하도록 연산자 재정의가 되어있다.

    std::cout << *p1 << std::endl;
    ++p1;
    std::cout << *p1 << std::endl;

}
