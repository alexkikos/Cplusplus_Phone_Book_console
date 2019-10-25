

void ClearWorkSpace( int where_place_x, int where_place_y, int, int color_t, int color_b);
void AddButton(int, int, int, int, int, int);



void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void setcolor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}




void PrintText(int s, int color_text = 1, int color_background = 6)
{
	setcolor(color_text, color_background);
	cout << s;
	setcolor(White, Black);
}

void PrintText(string s, int a, string g, int color_text = 1, int color_background = 6)
{
	setcolor(color_text, color_background);
	cout << s << a << g;
	setcolor(White, Black);
}


void PrintText3(string g, int color_text, int color_background, void (*name)(int x, int y) = gotoxy, int a = 1, int b = 1)
{
	name(a,b);
	setcolor(color_text, color_background);
	cout << g;
	setcolor(White, Black);
}





void PrintText(int s, string a, int color_text = 1, int color_background = 6)
{
	setcolor(color_text, color_background);
	cout << s << a;
	setcolor(White, Black);
}

void PrintText(string s, int color_text = 1, int color_background = 6)
{
	setcolor(color_text, color_background);
	cout << s;
	setcolor(White, Black);
}

void PrintText(string s, string s2, int color_text = 1, int color_background = 6)
{
	setcolor(color_text, color_background);
	cout << s << s2;
	setcolor(White, Black);
}


void PrintText2(string s, int a, int color_text = 1, int color_background = 0)
{
	setcolor(color_text, color_background);
	cout << s << a;
	setcolor(White, Black);
}

void PrintText2(string s, string s1, int a, int color_text = 1, int color_background = 0)
{
	setcolor(color_text, color_background);
	cout << s << s1 << a;
	cout << endl;
	setcolor(White, Black);
}














float FindDegreeNumber(float a, int n)//
{
	if (n == 0) return 1;
	if (n == 1) return a;
	if (n > 0) return a * FindDegreeNumber(a, n - 1);
	if (n < 0) return (1. / FindDegreeNumber(a, abs(n)));
	return 0;
}



int FindValueInrange(int a, int b)
{
	int res = 0;
	if (a > b) swap(a, b);//для движения по диапазону в обa направления, например 0 10 и 10 0
	for (int i = a + 1; i < b; i++)
	{
		res += i;
	}
	return res;
}




void FindPerfectValue(int a, int b)//ищем нужные числа и выводим их
{
	int s;
	if (a > b) swap(a, b);//для движения по диапазону в оба направления, например 0 10 и 10 0
	for (int i = a; i <= b; i++)//учитываем обратный диапазон
	{
		s = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				s += j;
			}
		}
		if (s == i and s != 0) cout << i << " ";
	}
	cout << "\n";
}





void FindCard(int a, char g, int d)
{
	switch (a)
	{
	case 1: cout << g << " " << d << " бубна\n";  break;
	case 2: cout << g << " " << d << " пика\n";  break;
	case 3: cout << g << " " << d << " черва\n";  break;
	case 4: cout << g << " " << d << " крест\n";  break;
	}
}




bool FindHappieNumber(int g)
{
	int sum = 0;
	int sum1 = 0;
	int k = 0;
	while (g != 0)
	{
		if (k < 3)
		{
			sum += g % 10;
			g /= 10;
			k++;
		}
		else
		{
			sum1 += g % 10;
			g /= 10;
			k++;
		}
	}
	return (sum == sum1) ? true : false;//sam vazvrashet i ne nyzno true or false
}




void Starline(int n = 10, char s = '*')
{
	for (int i = 0; i < n; i++) cout << s;
	cout << endl;
}



int FindCountNum(long long int  n, bool check_znak = true)//учитывать знаки отрицания как символ или нет
{
	int z = 0;
	if (n == 0) return 1;
	if (n < 0 and check_znak)
	{
		n = -n;
		z++;
	}
	z += (int)log10(n) + 1;
	return z;
}

int FindNumbersSum(long long int  n)//учитывать знаки отрицания как символ или нет
{
	if (n == 0) return 0;
	return n % 10 + FindNumbersSum(n / 10);
}




int FindCountNumArray(int a[], int n)
{
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		z += FindCountNum(a[i]);
	}
	return z;
}







void SortArray(int a[], int row_array, bool min_to_max = true)
{
	if (min_to_max)
	{
		for (int i = 0; i < row_array - 1; i++)
		{
			int min = i;
			for (int c = i + 1; c < row_array; c++)
			{
				if (a[c] <= a[min])
				{
					min = c;
				}
			}
			swap(a[i], a[min]);
		}
	}
	else
		for (int i = 0; i < row_array - 1; i++)
		{
			int min = i;
			for (int c = i + 1; c < row_array; c++)
			{
				if (a[c] >= a[min])
				{
					min = c;
				}
			}
			swap(a[i], a[min]);
		}
}


int FindKeyArray(int a[], int row_array, int key, bool method_binary, bool min_to_max = true)//по убыванию false
{
	SortArray(a, row_array, min_to_max);//сортируем массив
	//ShowArray(a, row_array);// для отладки выводил
	int mid = row_array / 2;
	int k = 0;
	while (k <= row_array / 2)
	{
		if (a[mid] > key)
		{
			mid /= 2;
		}
		else
			if (a[mid] < key)
			{
				mid += 1;
			}
			else
				return mid + 1;
		k++;
	}
	return 0;//если значения не нашли
}


int FindKeyArray(int a[], int row_array, int key)
{

	for (int i = 0; i < row_array; i++)
	{
		if (key == a[i])
		{
			return i + 1;
		}
	}
	return 0;
}


bool CheckNumberBinary(int c)//поиск небинарных чисел (выше 1)
{
	if (c < 0)//предотвращаем сторонние символы
	{
		return false;
	}
	if (c > 0)
	{
		int check = FindCountNum(c);
		while (check != 0)
		{
			if (c % 10 > 1) return false;
			c /= 10;
			check--;
		}
	}
	return true;
}



int BinaryToDecimal(int number)
{
	int res = 0;
	long long  int amount = FindCountNum(number, false);
	for (int i = 0; i < amount; i++)
	{
		res += number % 10 * FindDegreeNumber(2, i);
		number /= 10;
	}
	return res;
}

void PrintRazdelitel(int count = 100, char s = '=', int color = 3)
{
	setcolor(color, 0);
	cout << "\n";
	for (int i = 0; i < count; i++)
	{
		cout << s;
	}
	setcolor(LightGray, 0);
	cout << "\n";
}



void PrintNumberTask(int number, string s, int color = 14)
{
	setcolor(color, 0);
	cout << number << ". " << s;
	setcolor(LightGray, 0);
	cout << "\n";
}



void ShowErrorMessage(string s = "\nWrong input, try again\n")
{
	setcolor(Red, 0);
	cout << s;
	setcolor(LightGray, 0);
}



bool CheckVisYear(int year)
{
	if (year % 4 == 0 and year % 100 != 0 and year % 400 == 0)
	{
		return true;
	}
	else return false;
}


int FindDifferenceBetweenYears(int date1, int month1, int year1, int date2, int month2, int year2)
{
	int total_year = 0;
	int difference = 0;
	int sum = 0;
	int sum1 = 0;
	for (int i = year1; i <= year2; i++)
	{
		total_year += CheckVisYear(i) + 365;
	}
	for (int i = 1; i < month2; i++)
	{
		if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12)
		{
			sum1 += 31;
		}
		else
			if (i == 2)
			{
				sum1 += 28;
			}
			else
				sum1 += 30;
	}
	for (int i = month1; i <= 12; i++)
	{
		if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12)
		{
			sum += 31;
		}
		else
			if (i == 2)
			{
				sum += 28;
			}
			else
				sum += 30;
	}
	difference = sum - date1 + sum1 + date2;
	return total_year += difference - 730;
}



float FindArrayNumbersCount(int b[], int row_count, char search_znak, float search_number)
{
	float sum = 0;
	for (int i = 1; i <= row_count; i++)
	{
		switch (search_znak)
		{
		case '==': if (b[i] == search_number) sum++; break;
		case '>=': if (b[i] >= search_number) sum++; break;
		case '<=': if (b[i] <= search_number) sum++; break;
		case '<': if (b[i] < search_number) sum++; break;
		case '>': if (b[i] > search_number) sum++; break;
		}
	}
	return sum;
}



template <class T>
auto FindAverageInArray(T array[], int row_count)
{
	float sum = 0;
	for (int i = 0; i < row_count; i++)
	{
		sum += array[i];
	}
	return  sum / row_count;
}



template <class T1, class T2>//cоздает переменную с ее типом данных
T1 Sum(T1 a, T2 b)// -> decltype(a + b)
{
	return a + b;
}

int FindTotalDelitel(int a, int b)
{
	int min = a < b ? a : b;
	for (int i = min; i > 1; i--)
	{
		if (a % i == 0 and b % i == 0)
		{
			return i;
		}
	}
	return 0;
}



void ConvertCharToInt(char &a)
{
	int b;
	b = (int)a - (int) '0';
	a = b;
}


void addDrob(int a, int b, int c, int d)
{
	int res, t1 = 0;
	int res2, t2 = 0;
	res = (a * d) + (b * c);
	res2 = b * d;
	int y = FindTotalDelitel(res, res2);
	if (y > 0 and res < res2)
	{
		res /= y;
		res2 /= y;
		cout << res << "/" << res2;
	}
	else
		if (res > res2)
		{
			int b;
			int res_;
			res /= y;
			res2 /= y;
			res_ = res % res2;
			for (int i = 1; i < res2; i++)
			{
				b = i * res2 + res;
				if (b == res + res2)
				{
					b = i;
					break;
				}
			}
			cout << b << " " << res_ << " " << res2;
		}
}


int Factorial(int a)
{
	int c = 1;
	//if (a == 1) return 1;
	return a * Factorial(a - 1);
}


void Chisla(int n)
{
	if (1 < n)
	{
		Chisla(n - 1);
	}
	cout << n << " ";
}


void FindNumber(int a, int n)
{

	if (1 < a)
	{
		return FindNumber(a - 1, n);
	}
	cout << a;

}

int Fibo(int n)
{
	static int c = 1;
	cout << c++ << " ";
	if (n <= 2) return n - 1;
	if (n > 0)
	{
		return Fibo(n - 1) + Fibo(n - 2);
	}
}




int AddRandValue(int start, int off)
{
	srand(time(0));
	return rand() % (off - start + 1) + start;
}



int FindAverageDiv(int a, int b)
{
	if (a == 0) return b;

	return FindAverageDiv(b % a, a);
}




int Find_Cows(int a, int b)
{
	static int res = 0;
	static int position = 4;
	if (a % 10 == b % 10 and a != 0)
	{
		res++;
		PrintText2("Есть совпадение позиций чисел вашего и загаданнного: ", position, 2, Black);
		cout << endl;
	}
	position--;
	if (a == 0)
	{
		int temp = res;
		res = 0;
		position = 4;
		return temp;
	}
	return Find_Cows(a / 10, b / 10);
}





int Find_bik(int rand, int array[], int row)
{
	static int count = 0;
	if (rand == 0)
	{
		int temp = count;
		count = 0;
		return temp;
	}
	for (int i = 0; i < row; i++)
	{
		if (array[i] == rand % 10)
		{
			count++;
		}
	}
	return Find_bik(rand / 10, array, row);
}




int FIndMinAmountArray(int a[], int n, int steep_of_move)//поиск минимального индекса значения в определенном диапазоне
{
	int sum = 0;
	static int pos, min = 100;
	int i;
	for (i = n - 1; i >= n - steep_of_move; i--)
	{
		sum += a[i];
	}
	if (min >= sum)// если без = то выводим первый попавшийся, если с = последний
	{
		min = sum;
		pos = i;
	}
	if (n > steep_of_move)
	{
		FIndMinAmountArray(a, n - steep_of_move, steep_of_move);//ошибка в аудитории была шаг движения

	}
	else
	{
		min = 100;
		return pos + 2;//+1 компенсируем разницу с массивом 0, + еще 1 начало след индекса
	}
}



//int* SimpleNumber_Return(int* a, int& size)
//{
//
//	for (int i = 0; i < size; i++)
//	{
//		if (a[i] % 2 == 1)
//		{
//			DELETE_ELEMENTS_ARRAY_DYNAMIC(a, size, i);
//			i--;
//		}
//	}
//	return a;//
//}






template <class T1>
void Swap_My(T1& a, T1& b)
{
	T1 temp;
	temp = a;
	a = b;
	b = temp;
	//cout << a << " " << b;
}

void Hello()
{
	cout << "Hello" << endl;
}

void GoodMon()
{
	cout << "Good Morning" << endl;
}


void GodEvening()
{
	cout << "Good Evening" << endl;
}


void goodbye()
{
	cout << "Good bye" << endl;
}

template <class T1>
T1 Mult(T1 a, T1 b)
{
	return a * b;
}

template <class T1>
T1 Div(T1 a, T1 b)
{
	return a / b;
}

template <class T1>
T1 Minus(T1 a, T1 b)
{
	return a - b;
}

bool mintomax(int a, int b)
{
	return a > b ? true : false;
}

void bubblesort(int* a, int n, bool (*nethod)(int, int) = mintomax)
{
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (nethod(a[j], a[j + 1]))
			{
				swap(a[j], a[j + 1]);
				count++;
			}
		}
	}
	cout << count;
}



bool maxtomin(int a, int b)
{
	return a < b ? true : false;
}


bool firsteven(int a, int b)
{
	if (a % 2 == 0 and b % 2 == 1) return false;
	if (a % 2 == 1 and b % 2 == 0) return true;
	return mintomax(a, b);
}

bool firsteven_min(int a, int b)
{
	if (a % 2 == 0 and b % 2 == 1) return false;
	if (a % 2 == 1 and b % 2 == 0) return true;
	return maxtomin(a, b);
}










int quickSort(int* a, int n)
{	
	int static count = 0;
		int i = 0;
		int j = n;
		int p = a[n / 2];
		do
		{
			while (a[i] < p) i++;
			while (a[j] > p) j--;
			if (i <= j)
			{
				count++;
				swap(a[i], a[j]);
				i++;
				j--;
			}
		} while (i <= j);
		if (j > 0) quickSort(a, j);
		if (i < n) quickSort(a + i, n - i);
		return count;
}




void(*message(int h))()
{
	if (h < 12)
	{
		return GoodMon;
	}
	else return GodEvening;
}


int(*action())(int, int)//(тип) (*имя(параметры которые передаем) ) (параметры возвращаемой функции)
{
	int(*oper[])(int, int) = { Sum,Mult,Div };
	int choice;
	cout << "Выбрать операцию 1 '+' 2 '*' 3 '/' : ";
	cin >> choice;
	return oper[choice - 1];
}




void Preset()
{
	cout << "\t\t\t  _______      ___     .___   ____. ______ " << endl;
	cout << "\t\t\t /  _____|    /   \\   |   \\//  ||   ___|" << endl;
	cout << "\t\t\t|  |  __     /  ^  \\  |  \\  /  ||  |__   " << endl;
	cout << "\t\t\t|  | |_ |   /  /_\  \\ |  |\\/|  ||   __|  " << endl;
	cout << "\t\t\t|  |__| |  /  ____\\ \\|  |   |  ||   |__" << endl;
	cout << " \t\t\t\\______|/__/     \\__|__|   |__||______|" << endl;
	cout << "" << endl;
}

void Preset2()
{
	cout << "\t\t\t     _______..___________.     ___     .______      .___________." << endl;
	cout << "\t\t\t   /       ||           |    /   \\    |   _  \\     |           |" << endl;
	cout << "\t\t\t  |   (----``---|  |----`   /  ^  \\   |  |_)  |    `---|  |----`" << endl;
	cout << "\t\t\t    \\   \\        |  |       /  /_\\  \\  |      /         |  |     " << endl;
	cout << "\t\t\t.----)   |       |  |      /  _____  \\ |  |\\  \\----.    |  |     " << endl;
	cout << "\t\t\t|_______/        |__|     /__/     \\__\\| _| `._____|    |__|     " << endl;
	cout << "" << endl;
}


void Preset3()
{
	system("cls");
	cout << "\t\t\t ____    " << endl;
	cout << "\t\t\t|___ \\   " << endl;
	cout << "\t\t\t  __) |  " << endl;
	cout << "\t\t\t |__ <   " << endl;
	cout << "\t\t\t ___) |  " << endl;
	cout << "\t\t\t|____/   " << endl;
	cout << "" << endl;

}


void Preset4()
{
	system("cls");
	cout << "\t\t\t ___     " << endl;
	cout << "\t\t\t|__ \\    " << endl;
	cout << "\t\t\t   ) |   " << endl;
	cout << "\t\t\t  / /    " << endl;
	cout << "\t\t\t / /_    " << endl;
	cout << "\t\t\t|____|   " << endl;
	cout << "" << endl;

}



void Preset5()
{
	system("cls");
	cout << "\t\t\t __    " << endl;
	cout << "\t\t\t/_ |   " << endl;
	cout << "\t\t\t | |   " << endl;
	cout << "\t\t\t | |   " << endl;
	cout << "\t\t\t | |   " << endl;
	cout << "\t\t\t |_|   " << endl;
	cout << "" << endl;


}


void Preset6()
{
	system("cls");
	cout << "\t\t  _______   ______  " << endl;
	cout << "\t\t /  _____| /  __  \\ " << endl;
	cout << "\t\t|  |  __  |  |  |  |" << endl;
	cout << "\t\t|  | |_ | |  |  |  |" << endl;
	cout << "\t\t|  |__| | |  `--'  |" << endl;
	cout << " \t\t\\______|  \\______/ " << endl;
	cout << "" << endl;

}






void Gun(int* b)
{
	cout << endl;
	setcolor(rand() % 14 + 1, 0);
	cout << "+-- ^ ----------, --------, ---- - , -------- ^ -, " << endl;
	cout << "| |||||||||   `------- - '        |              0 " << endl;
	cout << "`+------------------------------- ^ -------------|" << endl;
	cout << "   `\_, -------- - , -------- - , -----------'" << endl;
	cout << "     / XXXXXX /'|       /'" << endl;
	cout << "    / XXXXXX / ` \     / '" << endl;
	cout << "   / XXXXXX / `-------'" << endl;
	cout << "  / XXXXXX /" << endl;
	cout << " / XXXXXX /" << endl;
	cout << "(________(" << endl;
	cout << "`----- - ' " << endl;

	b[0] -= 1;
	cout << endl;
}


void Riffle(int* b)
{
	setcolor(rand() % 14 + 1, 0);
	cout << endl;
	cout << "________________________________________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶" << endl;
	cout << "	_______________________________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__" << endl;
	cout << "________________________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_____________" << endl;
	cout << "	__________________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________________" << endl;
	cout << "	_________________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶______________________" << endl;
	cout << "	¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_________________________" << endl;
	cout << "	¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶_¶¶¶¶¶¶¶¶_________________________" << endl;
	cout << "	¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__¶¶¶¶¶___¶__¶¶¶¶¶¶________________________" << endl;
	cout << "	_¶¶¶¶¶¶¶¶¶¶¶¶____¶¶¶¶¶¶¶¶¶___¶¶¶¶¶¶_______________________" << endl;
	cout << "	__¶¶¶¶¶¶¶¶¶______¶¶¶¶¶_______¶¶¶¶¶¶¶______________________" << endl;
	cout << "	___¶¶¶¶¶¶________¶¶¶¶¶_________¶¶¶¶¶¶¶____________________" << endl;
	cout << "	____¶¶¶¶_________¶¶¶¶¶__________¶¶¶¶¶¶¶¶__________________" << endl;
	cout << endl;
	b[2] -= 10;
}


void Arrow(int* b)
{
	setcolor(rand() % 14 + 1, 0);
	cout << endl;
	cout << "			 4$$ - ." << endl;
	cout << "			 4 ." << endl;
	cout << "			 4 ^ ." << endl;
	cout << "			 4     $" << endl;
	cout << "			 4     'b" << endl;
	cout << "			 4       b." << endl;
	cout << "			 4        $" << endl;
	cout << "			 4        $r" << endl;
	cout << "			 4        $F" << endl;
	cout << "- $b========4========$b====>>=->>" << endl;
	cout << "			 4		  $$F" << endl;
	cout << "			 4        $$" << endl;
	cout << "			 4		.$F" << endl;
	cout << "			 4      dP" << endl;
	cout << "			 4     F" << endl;
	cout << "			 4    @" << endl;
	cout << "			 4  ." << endl;
	cout << "			 J." << endl;
	cout << endl;
	b[1] -= 1;


}


bool CheckAmunitions(int* a, int number, int minshot)
{
	if (a[number] >= minshot)
	{
		return true;
	}
	else
		return false;
}




bool FindMaxElem(int b, int max1)
{
	if (b > max1)
	{
		return true;
	}
	else return false;
}

bool FindMinElem(int b, int max1)
{
	if (max1 > b)
	{
		return true;
	}
	else return false;
}

int findMaxelemofArray(int*&a, int number, bool(*check)(int b, int max1) = FindMaxElem)//ПОКА НЕ ВЗЯЛ МАКС ПО АДРЕСУ НЕ СРАБАТЫВАЛА ПРОВЕРКА
{

	int max = a[0], imax = 0;
	for (int i = 0; i < number; i++)
	{
		if (check(a[i], max))
		{
			max = a[i];
			imax = i;
		}
	}
	return imax;
}



void(*shot(int* b))(int*)
{

	int max = findMaxelemofArray(b, 3);
	void(*action[])(int*) = { Gun,  Arrow, Riffle };
rep:
	if (max == 2 and b[max] < 9)
	{
		max = findMaxelemofArray(b, 2);
		goto rep;
	}
	if (b[max] > 0)
	{
		return action[max];
	}
	else
	{
		PrintText("\nПатроны закончились!!", 9, 0);
		exit(0);
	}

}


void finder1(int a)
{
	cout << endl;
	setcolor(Green, Black);
	cout << "                  {}\n";
	cout << "  ,   A           {}\n";
	cout << " / \\, | ,        .--.\n";
	cout << "|  =|= >        /.--.\\\n";
	cout << " \\ /` | `       |====|\n";
	cout << "  `   |         |`::`|\n";
	cout << "      |     .-;`\\..../`;_.-^-._\n";
	cout << "     /\\\\/  /  |...::..|`   :   `|\n";
	cout << "     |:'\\ |   /'''::''|   .:.    |\n";
	cout << "      \\ /\\;-,/\\   ::  |..Chest |\n";
	cout << "      |\\ <` >  >._::_.| ':Find:  |\n";
	cout << "      | `""`_/   ^^/>/>  |   ':'  |\n";
	cout << "      |       |       \\    :    /\n";
	cout << "      |       |        \\   :   /\n";
	cout << "      |       |___/\\___|`-.:.-`\n";
	cout << "      |        \\_ || _/    `\n";
	cout << "      |        <_ >< _>\n";
	cout << "      |        |  ||  |\n";
	cout << "      |        |  ||  |\n";
	cout << "      |       _\\.:||:./_\n";
	cout << "      | jgs  /____/\\____\\\n";
	cout << "\n";
	cout << ".:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:._.:*~*:" << endl;
	setcolor(White, Black);
	PrintText2("ВОУ ВЫ НАШЛИ СУНДУК С ПАТРОНАМИ!!! И ИХ КОЛИЧЕСТВО = ", a, 3, 0);
}




void MinValue(int* b, int count, int index)
{
	int imin = findMaxelemofArray(b, 3, FindMinElem);
	b[imin] += count;
}

void UserValue(int* b, int count, int index)//индекс 2 для защиты от ввода левых значений, к примеру у нас 3 пушки,пользователь ввел 5, поплнится по дефолту автомат
{
	if (index > 3 or index < 0) index = 2;//если ввели левый индекс по умолчанию пополним автомат
	b[index - 1] += count;
}



void addCart(int* a, int index, int amount, void(*addvalue)(int* b, int count, int index2) = MinValue)
{

	PrintText("\nТекущее количество боеприпасов : \n", 5, 0);
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "==" << a[i];
		cout << endl;
	}
	addvalue(a, amount, index);
	cout << "Пополнение успешно!";
	PrintText("\nколичество боеприпасов после пополнения:\n", 5, 0);
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << "==" << a[i];
		cout << endl;
	}
	cout << endl;
}


void FindChest(int* bullet, int& count, int rand_mov_value)
{
	if (rand_mov_value == count)
	{
		system("cls");
		char c;
		count = 0;
		int value = rand() % (30 - 1 + 1) + 1;//количество патронов рандомное
		finder1(value);//вывожу картинку с сообщением о нахождении сундука
		PrintText("\nВыберите номер оружия для пополнения '1' '2' '3', любой другой символ - пополнить оружие с минимальным количество патронов : ", 3, 0);
		c = _getch();
		ConvertCharToInt(c);
		if (c == 1 or c == 2 or c == 3)	addCart(bullet, c, value, UserValue);   else addCart(bullet, c, value);
	}
}


void ShowStatusBar(int* b)
{
	PrintText("\nКоличество боеприпасов(E-убрать/показать панель - при следующем ходе)\n", 10, 0);
	for (int c = 0; c < 3; c++)
	{
		if (c == 0 or c == 2)
		{
			for (int i = 0; i < 40; i++)
			{
				PrintText("#", 11, 0);
			}
		}
		if (c == 1)
		{
			cout << "Gun = " << b[0];
			cout << "    Arrow = " << b[1];
			cout << "    Riffle = " << b[2];

		}
		cout << endl;
	}
}


void rab_one()
{
	cout << "Works rab1" << endl;
}

void rab_two()
{
	cout << "Works rab2" << endl;
}

void transport()
{
	cout << "Works transport" << endl;
}


void(*prorab(int h)) ()
{
	void(*works[3])() = { rab_one, rab_two, transport };//тип (имя)(передаваемые значения)

	if (h < 50 and h > 0) return works[0];
	else
		if (h >= 50 and h < 110) return works[1];
		else
			return works[2];

	//if (h < 50 and h > 0) return rab_one; 
	//else
	//if (h >= 50 and h < 110) return rab_two;
	//else
	//	return transport;
}



template <class T1>
void AddPasengerOnStop(T1*& a, int& size, int amount)//создаю очередь по 1 человеку
{
	T1* temp = new T1[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = a[i];
	}
	temp[size] = 1;
	delete[]a;
	a = temp;
	size++;
	if (amount > 1) AddPasengerOnStop(a, size, amount - 1);//рекурсируем если количество пассажиров за единицу времени более чем 1 прибывает для формирования очереди по 1
}


template <class T1>
void AddAnalyticsParam(T1*& a, int& size, const int& size_of_passeg)//записываю каждые 10 мин, сколько людей осталось в очереди стоять после отправления машин
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = a[i];
	}
	temp[size] = size_of_passeg;
	delete[]a;
	a = temp;
	size++;
}


template <class G>
void RemovePassengerFromStop(G*& a, int& size, const int rand)
{
	cout << "\nПриехала машина с количеством свободных мест = " << rand;
	G* temp = new G[size + 1];
	int count = 0;
	if (rand > 0)// 0 - все места заняты, в таком случаее очередь накапливается
	{
		for (int i = rand; i < size; i++)//загружаем наших пассажиров, к примеру мест 5, и с 6го места обновляем список очереди так, что 6ой будет первым.
		{
			temp[count++] = a[i];
		}
		delete[]a;
		a = temp;
		size = count;
	}
}

template <class G>
G ShowReportAverage(G* a, const int& size)
{
	G sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += a[i];
	}
	return sum / size;
}



template <class G>
G GetTotalTimeMinMax(G average, const int  time_formove_onecar, const int  opti_param, const int  passenger_time_income, const int  amount_of_pass_peertime)
{
	G result;
	result = (average - opti_param) / (passenger_time_income * amount_of_pass_peertime);
	result = time_formove_onecar - result;
	return result;
}


template <class G>
G GetTotalTimeMaxMin(G average, const int time_formove_onecar, const int  opti_param, const int  passenger_time_income, const int  amount_of_pass_peertime)
{
	G result;
	result = opti_param - average;
	result /= (passenger_time_income * amount_of_pass_peertime);  //расчитываем минимальную очередь, для случая если очередей практически нет и нужно оптимизировать расходы
	result += time_formove_onecar; // 
	return result;
}




template <class G>
G MakeOptimization(G* optimization, const int& size_opti, const int time_formove_onecar, const int amount_of_pass_peertime, const int passenger_time_income, const int total_car, const int opti_param)
{
	G result;
	G average;
	average = ShowReportAverage(optimization, size_opti);
	if (average <= opti_param)
	{
		result = GetTotalTimeMaxMin(average, time_formove_onecar, opti_param, passenger_time_income, amount_of_pass_peertime);
	}
	else
	{
		result = GetTotalTimeMinMax(average, time_formove_onecar, opti_param, passenger_time_income, amount_of_pass_peertime);
	}
	return result;
}




template <class S>
S FindTotalPesengers(S* a, const int& size_passenger)
{
	S sum = 0;
	for (int i = 0; i < size_passenger; i++)
	{
		sum += a[i];
	}
	return sum;
}




void MainOperation(int& time_formove_onecar, const int totalcar, const int passenger_time_income, int* total_passengers, int& size_passenger, const int amount_of_pass_peertime, int*& optimization, int& size_opti)
{
	int count = 0;
	int check;
	int numbercar = 1;//отображение номера машины
	(passenger_time_income % 2 == 0) ? check = 0 : check = 1;
	while (count <= time_formove_onecar * totalcar) //беру замер сразу с 1 круга, 10 машин по 10 минут
	{
		if (count % passenger_time_income == check and count != 0)
		{
			AddPasengerOnStop(total_passengers, size_passenger, amount_of_pass_peertime);
		}
		if (count % time_formove_onecar == check and count != 0)
		{
			int rsr = rand() % 7;
			setcolor(10, 0);
			cout << "\nТекущее количество пассажиров: " << FindTotalPesengers(total_passengers, size_passenger);
			RemovePassengerFromStop(total_passengers, size_passenger, rsr);
			setcolor(11, 0);
			cout << "\nКоличество человек на остановке после отьезда машины № " << numbercar++ << " = " << FindTotalPesengers(total_passengers, size_passenger);
			AddAnalyticsParam(optimization, size_opti, size_passenger);//вношу значения для анализа после каждых 10 минут отправления машины		
		}
		count++;
	}

}



