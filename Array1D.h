
template <class T>
void Create_Dynamic_SizeOfArray(T*& a, int amount)
{
	if (a == nullptr)
	{
		a = new T[amount];
	}
}





template <class T>
void ADD_ELEMENTS_ARRAY_DYNAMIC(T*& a, int& size, T number, int index)
{

	T* p = new T[size + 1];
	for (int i = 0; i < index; i++)
	{
		p[i] = a[i];
	}
	p[index] = number;
	for (int i = index; i < size; i++)
	{
		p[i + 1] = a[i];
	}
	size++;
	delete[]a;
	a = p;

}


template <class T, class T2>
void ADD_ELEMENTS_ARRAY_DYNAMIC(T*& a, int& size, T2 number)
{

	T* p = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		p[i] = a[i];
	}
	p[size] = number;
	size++;
	delete[]a;
	a = p;
}



template <class T>
void DELETE_ELEMENTS_ARRAY_DYNAMIC(T*& a, int& size, int index)
{
	if (size == 1)
	{
		delete[]a;
		a = nullptr;
		size--;
		return;
	}
	T* p;
	p = new T[size - 1];
	for (int i = 0; i < index; i++)
	{
		p[i] = a[i];
	}
	for (int i = index + 1; i < size; i++)
	{
		p[i - 1] = a[i];
	}
	size--;
	delete[]a;
	a = p;
}


template <class T>
T* Add_ELem_int_third_mass(T* a, int size, T* b1, int size2, T* c, int& size3)//беру по адресу, чтобы можно было привязать количество елементов, для общей 1ой функции
{

	for (int i = 0; i < size; i++)
	{
		bool check = true;
		bool check2 = true;
		for (int b = 0; b < size2; b++)
		{
			if (a[i] == b1[b])
			{
				check = false;
				break;//если нашли совпадение, дальше сканировать нету смысла идем за другим значением
			}
		}
		if (check)
		{
			c = Add_Dynamic_SizeOfArray(c, size3);
			for (int g = 0; g <= size3; g++)
			{
				if (a[i] == c[g])
				{
					check2 = false;
					break;
				}
			}
			if (check2)
			{
				c = ADD_ELEMENTS_ARRAY_DYNAMIC(c, size3++, a[i]);
			}
		}
	}
	return (c);
}


//int* Delete_Repeat_Elements_Array(int* a, int& size_mass)
//{
//	for (int i = 0; i < size_mass; i++)
//	{
//		for (int c = 0; c < size_mass; c++)
//		{
//			if (a[c] == a[i] and i != c)
//			{
//				a = DELETE_ELEMENTS_ARRAY_DYNAMIC(a, size_mass, c);
//				c--;//при удалении елемента, массив уменьшается на 1 единицу, и чтобы не пропускать елемент, нужно С сразу уменьшить, если так не сделать то повторяются дубли
//			}
//		}
//	}
//	return a;
//}





template <class T1>
void ADD_ELEMENTS_ARRAY_DYNAMIC2(T1*& a, int& size, T1 number)
{
	T1* temp = new T1[size + 1];
	if (a == nullptr) T1* a = new T1[1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = a[i];
	}
	temp[size] = number;
	size++;
	delete[]a;
	a = temp;
}


template <class T1>
void  ReplaceArrayElements(T1* temp, int row, T1*& zero, int& zerosize, T1*& positive, int& positivesize, T1*& negative, int& negativesize)
{
	for (int i = 0; i < row; i++)
	{
		if (temp[i] > 0)
		{
			ADD_ELEMENTS_ARRAY_DYNAMIC2(positive, positivesize, temp[i]);
		}
		else
			if (temp[i] < 0)
			{
				ADD_ELEMENTS_ARRAY_DYNAMIC2(negative, negativesize, temp[i]);
			}
			else
				ADD_ELEMENTS_ARRAY_DYNAMIC2(zero, zerosize, temp[i]);
	}

}

template <class T>
void ShowArray(T*& a)
{
	int g = _msize(a) / sizeof(T);
	for (int i = 0; i < g; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}




void AddArray(int*& a, int count_row_array, int start = 0, int off = 100)
{
	//srand(time(0)); - в этом была причина долгих вычислений!!!!!!!!!!
	for (int i = 0; i < count_row_array; i++)
	{
		a[i] = rand() % (off - start + 1) + start;
	}
}

