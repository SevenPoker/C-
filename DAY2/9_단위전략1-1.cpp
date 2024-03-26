template<typename T> class List
{	
public:
	void push_front(const T& a)
	{
		// ......
	}
};

List<int> st; // st는 전역변수. 모든 스레드가 공유.
			  //멀티스레드환경에서 안전하지 않다.

int main()
{
	// 스레드로 쓰면 아래처럼 계속 lock, unlock 하지말고 객체 안에서 lock, unlock을 쓰자.
	
	// lock()
	st.push_front(10);
	// unlock()
}
