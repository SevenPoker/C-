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

    using iterator = slist_iterator<T>;

    iterator begin() {return iterator(head); };
    iterator end() {return iterator(0); };
};

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;

	return first;
}

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);


    // 위에서 만든 slist 는 range-for 도 사용가능합니다..
    for (int e : s) // begin , end를 지원하는 모든 container는 사용가능하다.
    {
        std:: cout << e << ", ";
    }
    // 위 코드는 컴파일러에 의해서 아래 코드로 변경됩니다.
    auto first = s.begin();
    auto last = s.end();

    for( ; first != last; ++first)
    {
        int e = *first;
        //----------------------------------
        std::cout << e << ", ";
    }
}

// 1998 년 STL의 3대 요소

// Container :
// Iterator  :
// Algorithm : 
