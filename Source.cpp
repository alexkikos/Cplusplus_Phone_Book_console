#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<iostream>
#include<iomanip>
#include<cmath>
#include<Windows.h>
#include<algorithm>
#include<typeinfo>
#include<string>
#include<conio.h>
#include "Array1D.h"
#include"Function.h"
#include "Array2D.h"
#include "StringsChar.h"











bool MinMax(int a, int b)
{
	return (a > b) ? true : false;
}

bool MaxMin(int a, int b)
{
	return (a < b) ? true : false;
}





template <class T>
void SortNamesInArr2D(T**& a, bool(*method)(int a, int b) = MinMax)
{
	int row = _msize(a) / sizeof(int);
	for (int i = 0; i < row - 1; i++)
	{
		for (int c = i + 1; c < row; c++)
		{
			if (method(a[i][0], a[c][0]))
			{
				swap(a[i], a[c]);//пузырь
			}
			else
				if (a[i][0] == a[c][0] and method(a[i][1], a[c][1]))
				{
					swap(a[i], a[c]);//пузырь
				}
		}
	}
}






template <class T>
void Transportirovanie2D(T**& main_array, int& row, int& col)
{
	int col1 = row;
	int row1 = col;
	T** to_transP = nullptr;
	CreateArr2D(to_transP, row1, col1);
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
		{
			to_transP[i][j] = main_array[j][i];
		}
	}
	FreeMemoryArr2D(main_array);
	main_array = to_transP;
	row = row1;
	col = col1;
}



////////////////////ДОБАВЛЕНИЕ/УДАЛЕНИЕ/РЕДАКТИРОВАНИЕ ТЕЛ,КНИГИ



template <class T>
void AddRowArr2D(T**& main_array, int& row, T* row_what_need_add = nullptr)
{
	if (strlen(row_what_need_add) > 0)
	{
		T** p = new T * [row + 1];
		for (int i = 0; i < row; i++)
		{
			p[i] = main_array[i];
		}
		p[row] = row_what_need_add;// new T = [col];
		delete[]main_array;
		main_array = p;
		row++;
	}
}



template <class T>
void ShowArray2DStringName(T**& a, int whereplace_x, int whereplace_y, int coltext, int colback)//показывает контакты
{
	setcolor(coltext, colback);
	int count_all_numbers = 0;
	int row;
	if (a != nullptr)
	{
		row = _msize(a) / sizeof(int);
		if (row > 0)
		{
			for (int i = 0; i < row; i++)
			{
				if (strlen(a[i]) > 0)
				{
					gotoxy(whereplace_x, whereplace_y += 1);
					cout << count_all_numbers++ << ". " << a[i];
					cout << endl;
				}
			}
		}
	}
}

//поиск пользователя или номера телефона -- вывожу всю строку, тк нет смысла искать и находить пользователя и не видеть его тел и наоборот
void PhoneAndUser(char**& a, int where_place_x, int where_place_y, int color_t, int color_b)
{
	setcolor(color_t, color_b);
	char* name_what_need_find = new char[100];
	cout << "Введите имя для поиска: ";
	gets_s(name_what_need_find, 100);
	int row = _msize(a) / sizeof(int);
	int count = 0;
	char* find_overlap = nullptr;
	bool check = true;
	while (count != row)
	{
		if (strstr(a[count], name_what_need_find))
		{
			find_overlap = strstr(a[count], name_what_need_find);
			char* temp_new_string = new char[100];
			strncpy(temp_new_string, a[count], strlen(a[count]) - strlen(find_overlap));
			temp_new_string[strlen(a[count]) - strlen(find_overlap)] = '\0';
			strcat(temp_new_string, find_overlap);
			gotoxy(where_place_x, where_place_y += 1);
			if (find_overlap > 0) cout << "Найден контакт: " << temp_new_string;
			cout << endl;
			if (check) check = false;
			delete[] temp_new_string;
		}
		count++;
	}
	if (check)
	{
		gotoxy(where_place_x, where_place_y += 3);
		cout << "Контактов не найдено!";
	}
	delete[] name_what_need_find;
}



//редактирование контактной книги
bool ChangeNameInBook(char**& a, char* whatfind, char* whatchange, int where_place_x, int where_place_y, int color_t, int color_b)
{
	bool result = false;
	if (a != nullptr)
	{
		int row = _msize(a) / sizeof(int);
		int count = 0;
		char* temp = nullptr;
		while (count != row)
		{
			while (strstr(a[count], whatfind) > 0)
			{	
				char* newv = new char[200];
				char* temp = strstr(a[count], whatfind);						
				strncpy(newv, a[count], strlen(a[count]) - strlen(temp));
				newv[strlen(a[count]) - strlen(temp)] = '\0';
				strncat(newv, whatchange, strlen(whatchange));
				char* n1 = temp + strlen(whatfind);
				strncat(newv, n1, strlen(n1));
				if (result == false) result = true;		
				delete[] a[count];
				a[count] = newv;
			}	
			count++;
		}
	}
	return result;
}








int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
start:
	setcolor(White, Black);
	char user_enter;//ВИЗУАЛИЗАЦИЯ ТЕЛ,КНИГИ
	int numbcount = 0;
	int symvolcount = 0;
	int size_book = 100;
	int row = 0, col, row_trans, col_trans, where_y_printe, where_x_printe;
	char** adressbook = nullptr;
	int** trasport = nullptr;
	char pos;
	char* names = nullptr;
	char* whatfind = nullptr;
	char* whatchange = nullptr;
	bool get;
	CreateArr2D(adressbook, row, size_book);
	GameArena(170, 30);
	gotoxy(5, 2);
	cout << "Строка состояния";
	AddButton(16, 3, 23, 1, White, 14);
	AddNameInButton("Ожидаю ввод!", "", 26, 2, Red, 14);
	AddButton(16, 3, 77, 1, White, 11);
	AddNameInButton("Телефонная книга", "", 78, 2, Red, 11);
	AddButton(20, 4, 3, 25, White, Cyan);
	AddNameInButton("Ввести данные", "Жми - 1", 6, 26, Red, Cyan);
	AddButton(17, 4, 27, 25, White, 13);
	AddNameInButton("Поиск по телефону", "Жми - 2", 28, 26, 15, 13);
	AddButton(17, 4, 48, 25, White, 14);
	AddNameInButton("поиск имени", "Жми - 3", 52, 26, Black, 14);
	AddButton(17, 4, 69, 25, White, 12);
	AddNameInButton("Сортировка ФИО", "Жми - 4", 71, 26, 9, 12);
	AddButton(25, 4, 90, 25, White, 7);
	AddNameInButton("Транспонирование матриц", "Жми - 5", 91, 26, 9, 7);
	AddButton(7, 4, 119, 25, White, 6);
	AddNameInButton("Exit:", "ESC", 121, 26, 9, 6);
	AddButton(14, 4, 130, 25, White, 5);
	AddNameInButton("Удалить строку", "Жми - 6", 131, 26, 9, 5);
	AddButton(14, 4, 148, 25, White, 2);
	AddNameInButton("Редактировать", "Жми - 7", 149, 26, 9, 2);
	AddButton(80, 19, 3, 5, White, 3);
rep:
	ClearWorkSpace2(24, 2, 1, 14, 0, 14);
	AddNameInButton("Ожидаю ввод", "", 26, 2, Red, 14);
	user_enter = _getch();
	if (user_enter >=49 and user_enter <=56 or user_enter == '*' or user_enter == 27)
	{	
		ClearWorkSpace2(24, 2, 1,14, 0, 14);
		AddNameInButton("Выполняю", "", 26, 2, Red, 14);
		switch (user_enter)
		{
		case '1':
			if (adressbook == nullptr) CreateArr2D(adressbook, 0, size_book);	
			ClearWorkSpace2(88, 6, 17, 77, 0, 3);
			AddButton(80, 19, 86, 5, White, 9);
			AddButton(7, 1, 10, 24, White, 3);//полоса состояния
			setcolor(White, 9);
			gotoxy(88, 6);
			cout << "Введите данные: ";
			names = new char[size_book];//не чистим тк эти адреса лежат в массиве
			gets_s(names, size_book);
			AddRowArr2D(adressbook, row, names);
			ShowArray2DStringName(adressbook, 6, 5, White, 3);
			ShoInfoPanel(adressbook, numbcount, symvolcount);	
			break;
		case '2':
		case '3':
			ClearWorkSpace2(88, 6, 18, 78, 0, 3);
			AddButton(80, 19, 86, 5, White, 11);
			AddButton(7, 1, 54, 24, White, 3);//полоса состояния
			gotoxy(88, 6);
			PhoneAndUser(adressbook, 88, 6, Red, 11);
			ShoInfoPanel(adressbook, numbcount, symvolcount);
			break;
		case '4': 
			ClearWorkSpace2(88, 6, 18, 78, 0, 3);
			AddButton(80, 19, 86, 5, White, 8);
			AddButton(7, 1, 74, 24, White, 3);//полоса состояния
			SortNamesInArr2D(adressbook); 
			ShowArray2DStringName(adressbook, 6, 5, White, 3);
			setcolor(White, 8);
			gotoxy(88, 6);
			cout << "Выполнено!";
			break;
		case '5':
			where_y_printe = 6;	
			where_x_printe = 88;
			ClearWorkSpace2(88, 6, 18, 78, 0, 3);
			AddButton(80, 19, 86, 5, White, 4);
			AddButton(7, 1, 99, 24, White, 3);//полоса состояния
			setcolor(White, 4);
			gotoxy(88, where_y_printe);
			cout << "Введите размер матрицы: ";
			gotoxy(88, where_y_printe+=1);
			cin >> row_trans;
			gotoxy(88, where_y_printe += 1);
			cin >> col_trans;
			if (row_trans > 7 or col_trans > 7)
			{
				gotoxy(88, where_y_printe+=1);
				cout << "Большой диапазон! (7*7 its ok)";
				break;
			}	
			CreateArr2D(trasport, row_trans, col_trans);
			AddArray2D(trasport, row_trans, col_trans);
			ShowArray2D(trasport, row_trans, col_trans, 88, 8);		
			Transportirovanie2D(trasport, row_trans, col_trans);
			ShowArray2D(trasport, row_trans, col_trans, 115 + ((_msize(trasport) / sizeof(int)) * 2), 6 + _msize(trasport) / sizeof(int));
			ShoInfoPanel(trasport, numbcount, symvolcount, true, col_trans);
			break;
		case '6':
			ClearWorkSpace2(88, 6, 18, 78, 0, 3);
			AddButton(80, 19, 86, 5, White, 2);
			AddButton(7, 1, 135, 24, White, 3);//полоса состояния
			setcolor(White, 2);
			where_y_printe = 6;
			gotoxy(88, where_y_printe);
			if (row > 0)
			{					
				cout << "Введите строку для удаления: ";
				pos = _getch();
				ConvertCharToInt(pos);
				if (pos + 1 <= row and pos >= 0)
				{
					DeleteRowArr2DPos(adressbook, row, pos);
				}
				else 		
					cout << " Не верный запрос!";
				ClearWorkSpace(6, 6, 16, White, 3);
				ShowArray2DStringName(adressbook, 6, 5, White, 3);
				ShoInfoPanel(adressbook, numbcount, symvolcount);
			}
			else cout << "Значений в книгe нет!";
			break;
		case '7':
			where_y_printe = 6;
			ClearWorkSpace2(88, 6, 18, 78, 0, 3);
			AddButton(7, 1, 152, 24, White, 3);//полоса состояния
			AddButton(80, 19, 86, 5, White, 7);
			setcolor(Red, 7);
			gotoxy(88, where_y_printe);
			whatfind = new char[size_book];
			whatchange = new char[size_book];
			cout << "Что заменить?: ";
			gets_s(whatfind, size_book);
			gotoxy(88, where_y_printe += 1);
			cout << "На что заменить: ";
			gets_s(whatchange, size_book);
			if (strstr(whatchange, whatfind))
			{
				gotoxy(88, where_y_printe += 1);
				cout << "Замена не возможна";
				break;
			}
			gotoxy(88, where_y_printe += 1);
			get = ChangeNameInBook(adressbook, whatfind, whatchange, 88, 6, White, 3);
			setcolor(Red, 7);
			gotoxy(88, where_y_printe += 1);
			if (get)
			{
				cout << "Готово";
			}
			else cout << "Совпадений нет!";
			ShowArray2DStringName(adressbook, 6, 5, White, 3);
			ShoInfoPanel(adressbook, numbcount, symvolcount);
			delete[] whatfind;
			delete[] whatchange;
			break;
		case '*': setcolor(White, Black);	ClearWorkSpace2(0, 0,40,300, White,Black);  goto start;  break;
		default: gotoxy(0, 35); exit(0);	break;
		}
	}
	goto rep;
	system("pause");
	return 0;
}















