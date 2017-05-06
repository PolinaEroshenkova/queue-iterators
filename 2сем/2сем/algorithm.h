#include"queue.h"
using namespace std;

template<class T>
class algorithm
{
public:
	void sort(myiterator<T>,myiterator<T>);
	void sort(myiterator<T>, myiterator<T>, myiterator<T>);
	int distance(myiterator<T>, myiterator<T>);
	myiterator<T> FindMiddle(myiterator<T>, int);
};

template<class T>
void algorithm::sort(myiterator<T> begin, myiterator<T> end, myiterator<T> middle)
{
	auto temp;
	myiterator<T> left=begin;
	myiterator<T> right=middle;
	myiterator<T> mid = middle;
	myiterator<T> last = end;
	while (left != mid && right != last)
	{
		if (left <= right)
		{
			left++;
			temp.push(move(left));
		}
		else {
			right++;
			temp.push(move(right));
		}
	}
	
}

template<class T>
void algorithm::sort(myiterator<T> begin, myiterator<T> end)
{
	int size = distance(begin, end);
	if (size < 2) return;
	myiterator<T> middle = FindMiddle(begin, size / 2);
	sort(begin, middle);
	sort(middle, end);

}

template<class T>
int algorithm::distance(myiterator<T> begin, myiterator<T> end)
{
	int i = 0;
	while (begin != end)
	{
		i++;
		begin++;
	}
	return i;
}

template<class T>
myiterator<T> algorithm::FindMiddle(myiterator<T> temp, int N)
{
	for (int i = 0; i < N; i++)
		temp++;
	return temp;
}