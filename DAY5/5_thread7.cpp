#include <atomic>

int a = 0;
int b = 0;

// foo, goo 는 다른 스레드가 실행합니다.
void foo()
{
	a = b + 1;

	std::atomic_thread_fence( std::memory_order_seq_cst );

	b = 1;		// 최적화가 되면 reordering이 되기 때문에 순서가 뒤집어진다.
	// 그래서 위의 b = 1; 위에 펜스를 친다.
}

// godbolt 에 코드를 넣어보면 (fence 안쳤을때)
// 최적화 전이면
/*
        mov     eax, DWORD PTR b[rip]
        add     eax, 1
        mov     DWORD PTR a[rip], eax
        mov     DWORD PTR b[rip], 1
*/
// 최적화 후면
/*
        mov     eax, DWORD PTR b[rip]
        mov     DWORD PTR b[rip], 1
        add     eax, 1
        mov     DWORD PTR a[rip], eax
*/
// 때문에 b==1 이면 a =1 임을 보장할수가 없다.

void goo()
{
	if (b == 1)
	{
		// a는 반드시 1일까요 ?
		// 아닐 수도 있다.
	}
}

int main()
{
}
