#include <vector>
#include <algorithm>
#include "show.h"

struct array
{
	int buff[5];

	int size() const { return 5;}
};

int main()
{
	array arr = {1, 2, 3, 4, 5};
}
