



int sizestring(char* s)
{
	int count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return count;
}

int charCount(char* s, char t)
{
	int count = 0, i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == t)
		{
			count++;
		}
		i++;
	}
	return count;
}


void DelChar(char*& s, char del)
{
	int i = 0;
	int count = 0;
	char* temp = new char[strlen(s) + 1];
	while (s[i] != '\0')
	{
		if (s[i] != del) temp[count++] = s[i];
		i++;

	}
	temp[count] = '\0';
	delete[]s;
	s = temp;
}




char* DeleteNumberString(char* s, const int number)//можно было и через войд, по памяти массива сделать изменения, но решил так попробовать
{
	int i = 0, count = 0;
	int sizestr = strlen(s);
	char* temp = new char[sizestr + 1];

	while (i < sizestr)
	{
		if (i != number - 1) temp[count++] = s[i];
		i++;
	}
	temp[count] = '\0';
	delete[]s;
	return temp;
}




void DeletsSymvolChar(char*& a, const char symvol_del)
{
	char* tmp = new char[strlen(a) + 1];
	int i = 0, count = 0;
	while (i < strlen(a))
	{
		if (a[i] != symvol_del)
		{
			tmp[count++] = a[i];
		}
		i++;
	}
	tmp[count] = '\0';
	delete[]a;
	a = tmp;
}






void PutCharInSpecIndex(char*& a, const char symv, const int nubmer)
{
	int i = 0, count = 0;
	char* tmp = new char[strlen(a) + 1];
	while (i < strlen(a))
	{
		if (i == nubmer - 1)
		{
			char tempt;
			tempt = a[i];
			tmp[count++] = symv;//сохраняем символ старый
			tmp[count++] = tempt;
		}
		else
			tmp[count++] = a[i];
		i++;
	}
	tmp[count] = '\0';
	delete[]a;
	a = tmp;
}




void ReplaceUserCharToSpecChar(char*& a, const char symvol_to_search, const char symvol_to_change)
{
	int i = 0, count = 0;
	char* tmp = new char[strlen(a) + 1];
	while (i < strlen(a))
	{
		if (a[i] != symvol_to_search) tmp[count++] = a[i];
		else tmp[count++] = symvol_to_change;
		i++;
	}
	delete[]a;
	tmp[count] = '\0';
	a = tmp;
}



int FindCountNumbersString(const char* a, const char symvol_to_find)
{
	int count = 0, i = 0;
	while (i < strlen(a))
	{
		if (a[i] == symvol_to_find)
		{
			count++;
		}
		i++;
	}
	return count;
}


void FindTotalCountNumbersSymvolsElse(const char* a)
{
	int number = 0, symvol = 0, someelse = 0;
	int i = 0;
	while (i < strlen(a))
	{
		if (isalpha(a[i])) symvol++;
		else if (isdigit(a[i])) number++;
		else someelse++;
		i++;
	}

	cout << "total count numbers = " << number << endl;
	cout << "total count symvols = " << symvol << endl;
	cout << "total count else input = " << someelse << endl;
}



int FindCountWord(char* a)
{
	int count = 0;
	int i = 0;
	while (i < strlen(a))
	{
		if (isspace(a[i]) and !isspace(a[i - 1]))
		{
			count++;
		}
		i++;
		if (a[i] == '\0' and !isspace(a[i - 1]))
		{
			count++;
		}
	}
	return count;
}


char* AddSymvolToEnd(char* st)
{
	char* t = new char[strlen(st) + 2];
	int i = 0;
	strcat(strcpy(t, st), "!");
	return t;
}




int ShowMaxLengthWord(char* st)
{
	int max = 0;
	int len;
	char* t = st;
	while (strchr(t, ' '))
	{
		char* t1 = strchr(t, ' ');
		len = t1 - t;
		if (len > max)
		{
			max = len;

		}
		t = t1 + 1;
	}
	int l1 = strlen(st) - (t - st);
	if (l1 > max) max = l1;
	return max;
}

char* ShowMaxLengthWord1(char* st)
{
	int max = 0;
	int len;
	char* t = st, * tm = nullptr;	
	while (strchr(t, ' '))
	{
		char* t1 = strchr(t, ' ');
		len = t1 - t;
		if (len > max)
		{
			max = len;
			tm = t;


		}
		t = t1 + 1;
	}
	int l1 = strlen(st) - (t - st);
	if (l1 > max)
	{
		max = l1;
		tm = t;
	}
	char* w = new char[max + 1];
	strncpy(w, tm, max);
	w[max] = '\0';
	return w;
}

char* getFIO(char* f, char* name, char* surn)
{
	char* fio = new char[strlen(f) + strlen(name) + strlen(surn) + 3];
	strcpy(fio, f);
	strcat(fio, " ");
	strcat(fio, name);
	strcat(fio, " ");
	strcat(fio, surn);
	return fio;
}

char* GetNormString(char* a)
{
	char* tempt = new char[strlen(a)];
	int i = 0;
	int count = 0;
	while (a[i] != '\0')
	{

		if (a[i] != ' ')
		{
			tempt[count++] = a[i];
		}

		if (a[i] == ' ' and a[i - 1] != ' ')
		{
			tempt[count++] = a[i];

		}
		i++;

	}
	tempt[count] = '\0';
	return tempt;
}



char* ReversString(char* st, int where_place_x, int where_place_y)
{
	char* t = new char[strlen(st)];
	char* t1 = strchr(st, ' ');
	strncpy(t, t1 + 1, strlen(st) - (t1 - st));
	strcat(t, " ");
	strncat(t, st, t1 - st);
	return t;
}













//////////ФУНКЦИИ ДЛЯ ПОСЛЕДНЕГО ДЗ//////////////////
void ChangeWordOnNew(char*& start_ar, char*& b_whatfind, char*& c_onwhatreplace)
{
	char* Pstop_ptr = strstr(start_ar, b_whatfind);
	if (Pstop_ptr > 0)
	{
		char* temp = new char[strlen(start_ar) + strlen(c_onwhatreplace) + 2];//+2 тк добавляю 2 символа окончания строки		
		strncpy(temp, start_ar, strlen(start_ar) - strlen(Pstop_ptr));
		temp[strlen(start_ar) - strlen(Pstop_ptr)] = '\0';
		strcat(temp, c_onwhatreplace);
		int couunt = strlen(temp);
		for (int i = strlen(b_whatfind) + (strlen(start_ar) - strlen(Pstop_ptr)); i < strlen(start_ar); i++)
		{
			temp[couunt++] = start_ar[i];
		}
		temp[couunt] = '\0';
		delete[]start_ar;
		start_ar = temp;
		ChangeWordOnNew(start_ar, b_whatfind, c_onwhatreplace);
	}
}




void NumberToString(char*& mass, int where_place_x, int where_place_y, int color_t, int color_b)
{
	char* temp = new char[200];
	char* value = new char[200];
ress:
	
	ClearWorkSpace(where_place_x, where_place_y, 6, color_t, color_b);
	AddButton(15, 1, 6, 24, Red, 11);
	setcolor(color_t, color_b);
	int number;
	gotoxy(where_place_x, where_place_y);
	cout << "Введите  число двухзначное: ";
	gets_s(value, 200);
	number = atoi(value);
	if (number < 0 or number > 99)  goto ress;
	if (number >= 10 and number <= 20)
	{
		switch (number)
		{
		case 10: strcpy(temp, "Десять копеек"); break;
		case 11: strcpy(temp, "Одинадцать копеек"); break;
		case 12: strcpy(temp, "Двенадцать копеек"); break;
		case 13: strcpy(temp, "Тренадцать копеек"); break;
		case 14: strcpy(temp, "Четырнадцать копеек"); break;
		case 15: strcpy(temp, "Пятнадцать копеек"); break;
		case 16: strcpy(temp, "Шестнадцать копеек"); break;
		case 17: strcpy(temp, "Семнадцать копеек"); break;
		case 18: strcpy(temp, "Восемнадцать копеек"); break;
		case 19: strcpy(temp, "Девятнадцать копеек"); break;
		case 20: strcpy(temp, "Двадцать копеек"); break;
		default:
			break;
		}
	}
	else
	{
		switch (number / 10)
		{
		case 2: strcpy(temp, "Двадцать "); break;
		case 3: strcpy(temp, "Тридцать "); break;
		case 4: strcpy(temp, "Сорок "); break;
		case 5: strcpy(temp, "Пятьдесят "); break;
		case 6: strcpy(temp, "Шестьдесят "); break;
		case 7: strcpy(temp, "Семьдесят "); break;
		case 8: strcpy(temp, "Восемьдесят  "); break;
		case 9: strcpy(temp, "Девяносто "); break;
		default:
			break;
		}
		switch (number % 10)
		{
		case 0: (number < 9) ? strcat(strcpy(temp, "Ноль копеек"), "") : strcat(temp, "копеек"); break;
		case 1: (number < 9) ? strcat(strcpy(temp, "Одна копейка"), "") : strcat(temp, "одна копейка"); break;
		case 2: (number < 9) ? strcat(strcpy(temp, "Две копейки"), "") : strcat(temp, "две копейки"); break;
		case 3: (number < 9) ? strcat(strcpy(temp, "Три копейки"), "") : strcat(temp, "три копейки"); break;
		case 4: (number < 9) ? strcat(strcpy(temp, "Четыре копейки"), "") : strcat(temp, "четыре копейки"); break;
		case 5: (number < 9) ? strcat(strcpy(temp, "Пять копеек"), "") : strcat(temp, "пять копеек"); break;
		case 6: (number < 9) ? strcat(strcpy(temp, "Шесть копеек"), "") : strcat(temp, "шесть копеек"); break;
		case 7: (number < 9) ? strcat(strcpy(temp, "Семь копеек"), "") : strcat(temp, "семь копеек"); break;
		case 8: (number < 9) ? strcat(strcpy(temp, "Восемь копеек"), "") : strcat(temp, "восемь копеек"); break;
		case 9: (number < 10) ? strcat(strcpy(temp, "Девять копеек"), "") : strcat(temp, "девять копеек"); break;
		default:
			break;
		}
	}
	delete[] value;
	gotoxy(where_place_x, where_place_y += 1);
	cout << "Результат: " << temp;
	gotoxy(where_place_x, where_place_y += 1);
	cout << "Выберите меню для продолжения: ";
	delete[]mass;
}





/////////////////////////////////////////////////////////////////////////////
////////////////ФУНКЦИИ ДЛЯ КОНСОЛЬНОГО РЕДАКТОРА//////////////////////////


void ClearWorkSpace(int where_place_x, int where_place_y, int size_menu,  int color_t, int color_b)
{
	setcolor(color_t, color_b);
	int i = 0;
	gotoxy(where_place_x, where_place_y);
	while (i < size_menu)
	{
		cout << " ";
		for (int h = where_place_x; h < where_place_x + 75; h++)
		{

			cout << " ";
		}
		cout << " ";
		cout << endl;
		i++;
		gotoxy(where_place_x, where_place_y += 1);
	}


}


void ClearWorkSpace2(int where_place_x, int where_place_y, int size_menu, int length, int color_t, int color_b)
{
	setcolor(color_t, color_b);
	int i = 0;
	gotoxy(where_place_x, where_place_y);
	while (i < size_menu)
	{
		cout << " ";
		for (int h = where_place_x; h < where_place_x + length; h++)
		{

			cout << " ";
		}
		cout << " ";
		cout << endl;
		i++;
		gotoxy(where_place_x, where_place_y += 1);
	}

	gotoxy(3, 24);
	for (int h = 0; h < length*2+7; h++)
	{
		setcolor(White, Black);
		cout << " ";
	}
}


void ReversString2(char*& st, int where_place_x, int where_place_y, int color_t, int color_b)
{
	ClearWorkSpace(where_place_x, where_place_y, 6, color_t, color_b);
	AddButton(10, 1, 52, 24, Red, 11);
	setcolor(color_t, color_b);
	if (st == nullptr) st = new char[200];
	char* t = new char[200];
	gotoxy(where_place_x, where_place_y);
	cout << "Введите строку: ";
	gets_s(st, 200);

	char* t1 = strchr(st, ' ');
	if (t1 != NULL)
	{
		strncpy(t, t1 + 1, strlen(st) - (t1 - st));
		strcat(t, " ");
		strncat(t, st, t1 - st);
		gotoxy(where_place_x, where_place_y += 1);
		cout << "Результат: " << t;
		delete[] st;
		st = t;
		gotoxy(where_place_x, where_place_y += 1);
		cout << "Выберите меню для продолжения: ";
	}
	else
	{
		gotoxy(where_place_x, where_place_y += 1);
		cout << "Результат: " << st;
		gotoxy(where_place_x, where_place_y += 1);
		cout << "Выберите меню для продолжения: ";

	}

}




void GameArena(int x, int y)
{

	for (int i = 0; i < y; i++)
	{
		cout << "#";
		if (i == 0 or i == y - 1)
		{
			for (int j = 0; j < x; j++)
			{
				cout << "=";
			}
		}
		else
			if (i > 0 and i < y - 1)
			{
				for (int j = 0; j < x; j++)
				{
					cout << " ";
				}
			}
		cout << "#";
		cout << endl;
	}
}








////////////////вспомагательные

template <class T>
void DeleteRowArr2DPos(T**& a, int& row, int pos)//удаляем по индексу строки
{
	if (a == nullptr) return;
	if (pos + 1 > row) return;
	if (row == 1)
	{
		row = 0;
		delete[] a[row];
		delete[]a;
		a = nullptr;
		return;
	}
	else
	{
		T** temp = new T * [row - 1];
		int count = 0;
		for (int i = 0; i < pos; i++)
		{
			temp[count++] = a[i];
		}
		for (int i = pos + 1; i < row; i++)
		{
			temp[count++] = a[i];
		}
		delete[] a[pos];
		delete[] a;
		row = count;
		a = temp;
	}
}












void AddButton(int size_button_x, int size_button_y, int where_place_x, int where_place_y, int color_text, int color_back)
{

	for (int i = 0; i < size_button_y; i++)
	{
		gotoxy(where_place_x, where_place_y);
		setcolor(Yellow, Black);
		cout << "#";
		if (i == 0 or i == size_button_y - 1)
		{
			for (int j = 0; j < size_button_x; j++)
			{
				setcolor(Green, Black);
				cout << "=";
			}
		}
		else
			if (i > 0 and i < size_button_y - 1)
			{
				for (int j = 0; j < size_button_x; j++)
				{
					setcolor(color_text, color_back);
					cout << " ";
					setcolor(White, Black);
				}

			}
		setcolor(Yellow, Black);
		cout << "#";
		cout << endl;
		gotoxy(where_place_x, where_place_y++);
	}


}

void AddNameInButton(string s, string s2, int where_place_x, int where_place_y, int color_text, int color_back = 12)
{
	setcolor(color_text, color_back);
	gotoxy(where_place_x, where_place_y);
	cout << s;
	gotoxy(where_place_x, where_place_y += 1);
	cout << s2;
}

void AddNameInButton(int& s, string s2, int where_place_x, int where_place_y, int color_text, int color_back = 12)
{
	setcolor(color_text, color_back);
	gotoxy(where_place_x, where_place_y);

	cout << s;
	gotoxy(where_place_x, where_place_y += 1);
	cout << s2;
}


void ChangeTextInredact(char*& mass, char*& mass2, char*& mass3, int where_place_x, int where_place_y, int color_t, int color_b)
{
	setcolor(color_t, color_b);
	//ClearWorkSpace(where_place_x, where_place_y, 6,10, color_t, color_b);
	AddButton(10, 1, 31, 24, Red, 9);
	setcolor(color_t, color_b);
	gotoxy(where_place_x, where_place_y);
	cout << "Введи строку для обработки: ";
	gets_s(mass, 200);
	gotoxy(where_place_x, where_place_y += 1);
	cout << "Поиск слова для замены: ";
	gets_s(mass2, 200);
	gotoxy(where_place_x, where_place_y += 1);
	cout << "На что менять: ";
	gets_s(mass3, 200);
	ChangeWordOnNew(mass, mass2, mass3);
	gotoxy(where_place_x, where_place_y += 1);
	cout << "Результат: " << mass;
	gotoxy(where_place_x, where_place_y += 1);
	cout << "Выберите меню для продолжения: ";
}




void DeletsSymvolChar2(char*& a, int where_place_x, int where_place_y, int color_t, int color_b)
{
	ClearWorkSpace(where_place_x, where_place_y, 8, color_t, color_b);
	AddButton(10, 1, 73, 24, Red, 11);
	setcolor(color_t, color_b);
	gotoxy(where_place_x, where_place_y);
	cout << "Введи строку для обработки: ";
	gets_s(a, 200);
	gotoxy(where_place_x, where_place_y += 1);
	cout << "Введите символ для удаления: ";
	char symvol_del;
	symvol_del = _getch();
	char* tmp = new char[200]; // 
	int i = 0, count = 0;
	while (i < strlen(a))
	{
		if (a[i] != symvol_del)
		{
			tmp[count++] = a[i];
		}
		i++;
	}
	tmp[count] = '\0';
	gotoxy(where_place_x, where_place_y += 1);
	cout << "Результат: " << tmp;
	delete[] a;
	a = tmp;
	gotoxy(where_place_x, where_place_y += 1);
	cout << "Выберите меню для продолжения: ";
}

template <class T>
void FindTotalCountNumbersSymvolsElse(T**& a, int& symvolcount, int& numbcount, bool check = false, int column = 0)
{
	if (a != nullptr and check == false)
	{
		int row = _msize(a) / sizeof(int);
		int number = 0, symvol = 0, someelse = 0;
		for (int c = 0; c < row; c++)
		{
			int count = 0;
			while (a[c][count] != '\0')
			{
				if (isalpha(a[c][count])) symvol++; // не умеет считать русские символы
				else if (isdigit(a[c][count])) number++;
				else someelse++;
				count++;
			}
			numbcount = number;
			symvolcount = symvol;
		}
	}
	else
		if (a != nullptr and check)
		{
			int row = _msize(a) / sizeof(int);
			int number = 0, symvol = 0, someelse = 0;
			for (int i = 0; i < row; i++)
			{
				for (int c = 0; c < column; c++)
				{
					number++;
				}				
			}
			numbcount = number;
			symvolcount = symvol;
		}

}

template <class T>
void ShoInfoPanel(T**& mass,  int& symvolcount, int& numbcount, bool check = false, int column = 0)
{
	FindTotalCountNumbersSymvolsElse(mass,  symvolcount, numbcount, check, column);
	gotoxy(110, 2);
	cout << "Количест символов";
	AddButton(4, 3, 130, 1, White, 4);
	AddNameInButton(symvolcount, "", 132, 2, Black, 4);
	gotoxy(138, 2);
	setcolor(White, Black);
	cout << "Количест цифер";
	AddButton(4, 3, 156, 1, White, 7);
	AddNameInButton(numbcount, "", 158, 2, Black, 7);
}




bool BrecketCheck(char* st)
{
	char* t = nullptr;
	int size = 0, i = 0;
	while (st[i] != '\0')
	{
		if (st[i] == '(' or st[i] == '[' or st[i] == '{')
		{
			ADD_ELEMENTS_ARRAY_DYNAMIC(t, size, st[i], 0);
		}
		if (st[i] == ')' or st[i] == '}' or st[i] == ']')
		{
			if (size == 0) return false;
			else
			{
				if ((st[i] == ')' and t[0] == '(') or (st[i] == '}' and t[0] == '{') or (st[i] == ']' and t[0] == '['))
				{
					DELETE_ELEMENTS_ARRAY_DYNAMIC(t, size, 0);

				}
			}
		}
		i++;
	}
	if (size > 0)
	{
		delete[]t;
		return false;
	}
	else
		return  true;

}









bool MinMax(int a, int b)
{
	return (a > b) ? true : false;
}

bool MaxMin(int a, int b)
{
	return (a < b) ? true : false;
}




template <class G>
void ShowNamesArr2D(G** const& fio)
{
	cout << "Отсортированные фамилии:\n";
	int end = _msize(fio) / sizeof(int);
	for (int i = 0; i < end; i++)
	{
		cout << "Фамилия № " << i + 1 << " : " << fio[i] << endl;

	}
	for (int i = 0; i < end; i++)
	{
		delete[] fio[i];
	}
	delete[] fio; //закончили работу, все чистим 
}
//////////////////////////////////////////////

