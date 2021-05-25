#include <iostream>
#include <math.h>
#include <string>
using namespace std;
template <class T> // T - тип
class vector
{
	T* v; // внутрішній масив
	int size; // кількість елементів
public:
	vector(int newsize); // конструктор ініціалізації
	vector(vector&); // конструктор копіювання
	~vector(); // деструктор
	T extr(const char*); // пошук мінімального чи максимального елемента
	vector& sort(const char*); // сортування
	double norma(void); // обчислення норми

	friend vector<T> operator + <>(vector<T>& x, vector<T>& y); // додавання
	vector& operator *= (int); // множення
	vector& operator += (vector&); // збільшення на
	T& operator [] (int index); // індексування
	vector& operator = (const vector&); // присвоєння
	friend ostream& operator << <>(ostream&, vector&); // виведення
	friend istream& operator >> <>(istream&, vector&); // введення
};
template <class T>
vector<T>::vector(int newsize) // конструктор ініціалізації
{
	v = new T[size = newsize]; // новий розмір, виділення пам'яті для елементів
	for (int i = 0; i < size; i++) // присвоєння нульових значень елементам
		v[i] = T();
}
template <class T>
vector<T>::vector(vector<T>& x) // конструктор копіювання
{
	v = new T[size = x.size]; // новий розмір, виділення пам'яті для елементів
	for (int i = 0; i < size; i++) // присвоєння значень елементам
		v[i] = x.v[i];
}
template <class T>
vector<T>::~vector()
{
	delete[] v; // звільнення пам'яті
}
template <class T>
T vector<T>::extr(const char* MinOrMax) // MinOrMax - визначає, що шукаємо
{
	T ExtrElem = v[0];
	for (int i = 0; i < size; i++) {
		if (!strcmp(MinOrMax, "min")) {
			if (v[i] < ExtrElem) ExtrElem = v[i]; // мінімальний елемент 
		}
		else
			if (v[i] > ExtrElem) ExtrElem = v[i]; // максимальний елемент
	}
	return ExtrElem;
}
template <class T>
vector<T> & vector<T>::sort(const char* UpOrDown)
{ // UpOrDown - порядок сортування
	T x;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (!strcmp(UpOrDown, "up"))
			{ // за зростанням
				if (v[i] > v[j])
				{
					x = v[i];
					v[i] = v[j];
					v[j] = x;
				}
			}
			else // за спаданням
				if (v[i] < v[j])
				{
					x = v[i];
					v[i] = v[j];
					v[j] = x;
				}
	return *this;
}
template <class T>
double vector<T>::norma(void) // норма = сума квадратів елементів (для числових типів)
{
	double s = 0;
	for (int i = 0; i < size; i++)
		s += v[i] * v[i];
	return sqrt(s);
}
template <class T>
vector<T> operator + (vector<T>& x, vector<T>& y) // додавання
{
	if (x.size != y.size)
	{
		throw exception("The sizes should be the same!");
	}
	vector<T> z(x.size);
	for (int i = 0; i < x.size; i++)
		z.v[i] = x.v[i] + y.v[i];
	return z;
}
template <class T>
vector<T>& vector<T>::operator *= (int y) // множення
{
	for (int i = 0; i < size; i++)
		v[i] *= y;
	return *this;
}
template <class T>
vector<T>& vector<T>::operator += (vector<T>& y)
{
	for (int i = 0; i < size; i++)
		v[i] += y.v[i];
	return *this;
}
template <class T>
T& vector<T>::operator [] (int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Index out of the range");
	}
		return v[index];
}
template <class T>
vector<T>& vector<T>::operator = (const vector<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}
template <class T>
istream& operator >> (istream& is, vector<T>& x)
{
	cout << "Input " << x.size << " elements of vector" << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "element[" << i << "] = ? ";
		is >> x.v[i];
	}
	return is;
}
template <class T>
ostream& operator << (ostream& os, vector<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}
int main()
{
	try
	{
		vector<int> V(5), U(5), Z(5), T(5);
		cin >> V;
		cin >> U;
		T = V + U;
		cout << "summa of vectors:" << endl;
		cout << T;
		Z += V;
		Z += U;
		cout << "summa of vectors:" << endl;
		cout << Z;
		Z *= 5;
		cout << "power of vectors:" << endl;
		cout << Z;
		cout << "min element = " << Z.extr("min") << endl;
		Z.sort("up");
		cout << "sorted:" << endl;
		cout << Z;
		cout << "norma = " << Z.norma() << endl;
	}
		catch (exception e)
	{
		cerr << e.what() << endl;
	}
	system("pause");
	return 0;
}
