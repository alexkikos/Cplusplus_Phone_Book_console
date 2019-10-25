

template <class T>
void CreateArr2D(T**& a, int row, int col)
{
	a = new T * [row];
	for (int i = 0; i < row; i++)
	{
		a[i] = new T[col];
	}
}



template <class T>
void AddRowArr2D(T**& a, int& row, int col, T* b = nullptr)
{
	if (b)
	{
		int col_b = _msize(b) / sizeof(T);//находим размер массива б чтобы не выходит за рамки колонок кол
		if (col_b != col)
		{
			cout << "Cant add string";
			return;
		}
		else
		{
			T** p = new T * [row + 1];
			for (int i = 0; i < row; i++)
			{
				p[i] = a[i];
			}
			p[row] = b;// new T = [col];
			delete[]a;
			a = p;
			row++;
		}
	}
	else
	{
		T** p = new T * [row + 1];
		for (int i = 0; i < row; i++)
		{
			p[i] = a[i];
		}
		p[row] = new T[col];
		delete[] a;
		a = p;
		row++;
	}
}









template <class T>
void AddRowArr2DPos(T**& a, int& row, const int col, int pos, T*& b)
{
	if (pos > row)
	{
		cout << "error position";
		return;
	}
	T** p = new T * [row + 1];
	int count = 0;

	for (int i = 0; i < pos; i++)
	{
		p[count++] = a[i];
	}
	p[count++] = b;
	for (int i = pos; i < row; i++)
	{
		p[count++] = a[i];
	}
	delete[]a;
	a = p;
	row++;
}

template <class T>
void DeleteRowArr2D(T**& a, int& row)//удаляем с конца строки
{
	if (row == 1)
	{
		delete[] a;
		a = nullptr;
		row = 0;
		return;
	}
	else
	{
		T** p = new T * [row - 1];
		for (int i = 0; i < row - 1; i++)
		{
			p[i] = a[i];
		}
		delete[] a[row - 1];
		delete[] a;
		row--;
		a = p;
	}
}



template <class T>
void AddColumn2D(T**& a, const int row, int& column, T* b)// добавляю строку ранее иницилизированню
{
	T** temp = new T * [row];//создам 2мерный массив с нужны количеством строк
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		temp[i] = new T[column + 1];
		for (int j = 0; j < column; j++)
		{
			temp[i][j] = a[i][j];
		}
		temp[i][column] = b[count++];
	}
	column++;
	delete[] a;
	a = temp;
}


template <class T>
void AddColumn2DPos(T**& a, const int row, int& column, const int pos_where_put_column, T* b)//
{
	if (pos_where_put_column > column)
	{
		cout << "error position";
		return;
	}
	T** temp = new T * [row];//создам 2мерный массив с нужны количеством строк
	int count2 = 0;
	for (int i = 0; i < row; i++)
	{
		temp[i] = new T[column + 1];
		int count = 0;
		for (int j = 0; j < pos_where_put_column; j++)
		{
			temp[i][count++] = a[i][j];
		}
		temp[i][count++] = b[count2++];
		for (int j = pos_where_put_column; j < column; j++)
		{
			temp[i][count++] = a[i][j];
		}
	}
	delete[] a;
	column++;
	a = temp;
}


template <class G>
void DeleteColumn2d(G**& a, const int row, int& column)
{
	if (column == 1)
	{
		for (int i = 0; i < row; i++)
		{
			delete[] a[i]; //удаляю информацию в строках
		}
		column = 0;
		a = nullptr;
		return;
	}
	G** tmp = new G * [row];
	for (int i = 0; i < row; i++)
	{
		tmp[i] = new G[column - 1];
		for (int c = 0; c < column - 1; c++)
		{
			tmp[i][c] = a[i][c];
		}
		delete[] a[i];
	}
	delete[]a;
	a = tmp;
	column--;
}



template <class H>
void DeleteColumn2dPos(H**& a, const int row, int& column, int pos_for_delete)
{
	if (column == 1)
	{
		for (int i = 0; i < row; i++)
		{
			delete[] a[i]; //удаляю информацию в строках
		}
		column = 0;
		a = nullptr;
		return;
	}
	H** temp = new H * [row];
	for (int i = 0; i < row; i++)
	{
		temp[i] = new H[column - 1];
		int count = 0;
		for (int c = 0; c < pos_for_delete; c++)
		{
			temp[i][count++] = a[i][c];
		}
		for (int c = pos_for_delete + 1; c < column; c++)
		{
			temp[i][count++] = a[i][c];
		}
		delete[] a[i];//удаляем не нужную строку
	}
	delete[] a;
	a = temp;
	column--;

}



template <class T>
void AddArray2D(T**& a, int count_row_array, int col, int start = 0, int off = 100)
{

	for (int i = 0; i < count_row_array; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a[i][j] = rand() % (off - start + 1) + start;
		}
	}
}






template <class T>
void FillArr2d(T**& a, int count_row_array, int col, int start = 0, int off = 100)
{
	srand(time(0));
	for (int i = 0; i < count_row_array; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a[i][j] = rand() % (off - start + 1) + start;
		}
	}
}

template <class T>
void FreeMemoryArr2D(T**& a)
{
	int row = _msize(a) / sizeof(T);
	for (int i = 0; i < row; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}




int findMaxelemofArray2D(int** a, const int row, const int col)//ПОКА НЕ ВЗЯЛ МАКС ПО АДРЕСУ НЕ СРАБАТЫВАЛА ПРОВЕРКА
{
	int max = 0;
	int index;
	for (int i = 0; i < row; i++)
	{
		for (int c = 0; c < col; c++)
		{
			if (a[i][c] > max)
			{
				max = a[i][c];
				index = i;
			}
		}
	}
	return index;
}

int findMinelemofArray2D(int** a, const int row, const int col)//ПОКА НЕ ВЗЯЛ МАКС ПО АДРЕСУ НЕ СРАБАТЫВАЛА ПРОВЕРКА
{
	int min = a[0][0];
	int index;
	for (int i = 0; i < row; i++)
	{
		for (int c = 0; c < col; c++)
		{
			if (min > a[i][c])
			{
				min = a[i][c];
				index = i;
			}
		}
	}
	return index;
}




template <class T>
void ShowArray2D(T**& a, int& row, int& col, int where_x_printe = 0, int where_y_printe=0)
{
	for (int i = 0; i < row; i++)
	{
		if (where_x_printe > 0) gotoxy(where_x_printe, where_y_printe += 1); ///шоу аррей не подошел, тут переделанный способ
		for (int j = 0; j < col; j++)
		{
			cout << setw(4) << a[i][j] << " ";
		}
		cout << endl;	
	}

}







int isNoll(int* a, int n)
{
	int index = -1, count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			index = i;
			count++;
		}
	}
	return (count == 1) ? index : -1;
}



template <class T>
void Arr2dZeroPerColomn(T**& a, const int row, const int col)
{
	int index;
	bool check;
	for (int i = 0; i < row; i++)
	{
		do
		{
			check = false;
			AddArray(a[i], col, 0, 3);
			index = isNoll(a[i], col);
			if (index > -1)
			{

				for (int j = 0; j < i; j++)
				{
					if (a[j][index] == 0)
					{
						check = true;
					}
				}
			}
		} while (index == -1 || check);
	}
}






/////////////ЗАДАЧА 2/////////////////
template <class T>
T FindSizeOfArray2D(T** a)
{
	return _msize(a) / sizeof(T);
}



template <class H>
bool FindCoom(H number, H** b, const int column, H* odnomer = nullptr)
{
	if (odnomer == nullptr)
	{
		int row_a = FindSizeOfArray2D(b);
		for (int i = 0; i < row_a; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (number == b[i][j])
				{
					return true;
				}
			}
		}
	}
	else
	{
		int row_a = _msize(odnomer) / sizeof(H);
		for (int i = 0; i < row_a; i++)
		{
			if (number == odnomer[i])
			{
				return true;
			}
		}
	}
	return false;
}


template <class H>
H* AllValue(H** a, const int cola, H** b, const int colb, H** c, const int colc)//Общие значения для А Б С без повторений
{
	int row_a = FindSizeOfArray2D(a);
	int count = 0;
	H* odnomer = new H;
	for (int i = 0; i < row_a; i++)
	{
		for (int j = 0; j < cola; j++)
		{
			if (FindCoom(a[i][j], b, colb) and FindCoom(a[i][j], c, colc) and !FindCoom(a[i][j], c, colc, odnomer))
			{
				ADD_ELEMENTS_ARRAY_DYNAMIC(odnomer, count, a[i][j]);
			}
		}
	}

	if (count > 0)
	{
		return odnomer;
	}
	else delete[] odnomer;
}

template <class H>
H* OnlyTwo(H** a, const int cola, H** c, const int colc, H** b, const int colb)//Общие значения для А С
{
	int row_a = FindSizeOfArray2D(a);
	int count = 0;
	H* odnomer = new H;
	for (int i = 0; i < row_a; i++)
	{
		for (int j = 0; j < cola; j++)
		{
			if (FindCoom(a[i][j], c, colc) and !FindCoom(a[i][j], c, colc, odnomer))
			{
				ADD_ELEMENTS_ARRAY_DYNAMIC(odnomer, count, a[i][j]);
			}
		}
	}

	if (count > 0)
	{
		return odnomer;
	}
	else delete[] odnomer;
}

template <class H>
H* OnlyNegativeValue(H** a, const int cola, H** b, const int colb, H** c, const int colc)//Все отрицательные значения А В С, без повторений
{
	int row_a = FindSizeOfArray2D(a);
	int count = 0;
	H* odnomer = new H;
	for (int i = 0; i < row_a; i++)
	{
		for (int j = 0; j < cola; j++)
		{
			if (a[i][j] >= 0)
			{
				continue;
			}
			else
				if (FindCoom(a[i][j], b, colb) and FindCoom(a[i][j], c, colc) and !FindCoom(a[i][j], c, colc, odnomer))
				{

					ADD_ELEMENTS_ARRAY_DYNAMIC(odnomer, count, a[i][j]);
				}
		}
	}

	if (count > 0)
	{
		return odnomer;
	}
	else delete[] odnomer;

}


template <class C>
bool Uniq2D(C number, C** a, const int cola)
{
	int count = 0;
	int row_a = FindSizeOfArray2D(a);
	for (int i = 0; i < row_a; i++)
	{
		for (int j = 0; j < cola; j++)
		{
			if (a[i][j] == number)
			{
				count++;
			}
			if (count > 1) return true;
		}
	}
	return  false;
}

template <class H>
H* OnlyUniques(H** a, const int cola, H** b, const int colb, H** c, const int colc)//Которые есть в одном массиве и нету в других, и не повторяется в этом массиве
{
	int row_a = FindSizeOfArray2D(a);
	int row_b = FindSizeOfArray2D(b);
	int row_c = FindSizeOfArray2D(c);
	int count = 0;
	H* odnomer = new H;
	for (int i = 0; i < row_a; i++)
	{
		for (int j = 0; j < cola; j++)
		{
			if (!FindCoom(a[i][j], b, colb) and !FindCoom(a[i][j], c, colc) and !Uniq2D(a[i][j], a, cola))
			{
				ADD_ELEMENTS_ARRAY_DYNAMIC(odnomer, count, a[i][j]);
			}
		}
	}
	for (int i = 0; i < row_b; i++)
	{
		for (int j = 0; j < colb; j++)
		{
			if (!FindCoom(b[i][j], a, cola) and !FindCoom(b[i][j], c, colc) and !Uniq2D(b[i][j], b, colb))
			{
				ADD_ELEMENTS_ARRAY_DYNAMIC(odnomer, count, b[i][j]);
			}
		}
	}

	for (int i = 0; i < row_c; i++)
	{
		for (int j = 0; j < colc; j++)
		{
			if (!FindCoom(c[i][j], a, cola) and !FindCoom(c[i][j], b, colb) and !Uniq2D(c[i][j], c, colc))
			{
				ADD_ELEMENTS_ARRAY_DYNAMIC(odnomer, count, c[i][j]);
			}
		}
	}
	if (count > 0)
	{
		return odnomer;
	}
	else delete[] odnomer;
}




template <class H>
H* FindCommonValues(H** a, const int cola, H** b, const int colb, H** c, const int colc, H* (*findvalue) (H**, const int, H**, const int, H**, const int) = AllValue)
{
	H* w = findvalue(a, cola, b, colb, c, colc);
	return w;
}




template <class T>
void CreateArr3D(T***& a, T amount_of_3d, int row, int col)
{
	T*** a = new T * *[amount_of_3d];
	for (int i = 0; i < amount_of_3d; i++)
	{
		a[i] = new T * [row];
		for (int j = 0; j < row; j++)
		{
			a[i][j] = new T[col];
		}
	}
}

template <class T>
void FreeMemoryArr3D(T***& a, T amount_of_3d, int row, int col)
{
	for (int i = 0; i < amount_of_3d; i++)
	{
		for (int j = 0; j < row; j++)
		{
			delete[] a[i][j];
		}
		delete[] a[i];
	}
	delete[] a;
}

template <class T>
void addnumber2D(T**& a, int& size)
{
	int cnt = 1;
	for (int k = 0; k < size / 2; k++)
	{
		for (int i = k; i < size - k; i++)
		{
			a[k][i] = cnt++;
		}
		for (int i = k + 1; i < size - 1 - k; i++)
		{
			a[i][size - k - 1] = cnt++;
		}
		for (int i = size - 1 - k; i >= k; i--)
		{
			a[size - 1 - k][i] = cnt++;
		}
		for (int i = size - 2 - k; i >= k + 1; i--)
		{
			a[i][k] = cnt++;
		}

	}
	if (size % 2 == 1)
		a[size / 2][size / 2] = cnt;
}


