// матрикс.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
#include <fstream>
#include <clocale>
#include <conio.h>
#include "Matrix.h"
#include <string>

using namespace std;


	int _tmain(int argc, _TCHAR* argv[])
	{
		setlocale(LC_CTYPE, "Russian");
		string Mtype;
		int x; // выбор
		cout << "   1. Записать в файл матрицу;\n   2. Прочитать файл;\n   3. Выполнить сложение двух матриц;\n   4. Выполнить умножение двух матриц;\n   5. Прочитать k-ую строку матрицы;\n   6. Получить кол-во строк и столбцов\n\n";
		cin >> x;
		cout << endl;
		switch (x) {
		case 1: {
					int n; //кол-во строк
					int m; //кол-во столбцов
					char  p[32];
					cout << "Введите путь к файлу:";
					cin >> p;
					cout << "Введите кол-во строк:";
					cin >> n;
					cout << "Введите кол-во столбцов:";
					cin >> m;
					cin >> Mtype;
					Matrix <Mtype> object1(n, m);
					object1.Set(p);
					break; }

		case 2:	{
					char  p[32];
					cout << "Введите путь к файлу:";
					cin >> p;
					fin.open(p);
					if (!fin.is_open()) // если файл не открыт
						cout << "Файл не может быть открыт!\n"; // сообщить об этом
					else
					{
						char buff[50];
						while (!fin.eof())
						{
							fin.getline(buff, 50); // считали строку из файла
							cout << buff << endl;
						}
						fin.close(); // закрываем файл 
					}
					break; }
		

		case 3: {
					char  p[32];
					int n1; //кол-во строк
					int n2;
					int m1; //кол-во столбцов
					int m2;
					cout << " Введите размерность первой матрицы: ";
					cin >> n1 >> m1;
					cout << " Введите размерность второй матрицы: ";
					cin >> n2 >> m2;
					cin>>Mtype;
					if (n1 == n2 && m1 == m2)
					{
						Matrix <Mtype> M1(n1, m1);
						Matrix <Mtype> M2(n2, m2);
						cout << "Введите путь к файлу 1-ой матрицы:";
						cin >> p;
						M1.Set(p);
						cout << "Введите путь к файлу 2-ой матрицы:";
						cin >> p;
						M2.Set(p);
						M1 + M2;
					}
					else cout << "Ошибка! Матрицы имеют разные размеры." << "\n";
					break; }

		case 4: {
					char  p[32];
					int n1; //кол-во строк
					int n2;
					int m1; //кол-во столбцов
					int m2;
					cout << " Введите размерность первой матрицы: ";
					cin >> n1 >> m1;
					cout << " Введите размерность второй матрицы: ";
					cin >> n2 >> m2;
					cin>>Mtype;
					if (m1 == n2)
					{
						Matrix <Mtype> M1(n1, m1);
						Matrix <Mtype> M2(n2, m2);
						cout << "Введите путь к файлу 1-ой матрицы:";
						cin >> p;
						M1.Set(p);
						cout << "Введите путь к файлу 2-ой матрицы:";
						cin >> p;
						M2.Set(p);
						M1 * M2;
					}
					else cout << "Ошибка! Введите корректные размерности матриц.";
					break; }

		case 5: {
					int n, m; //кол-во строк, столбцов
					int k; //номер нужной строки
					char p[32];
					double *stroka;
					cout << " Введите размерность матрицы: ";
					cin >> n >> m;
					cin>>Mtype;
					Matrix <Mtype> M (n, m);
					cout << "Введите путь к файлу матрицы:";
					cin >> p;
					M.Set(p);
					M.print();
					//stroka = new double[m];
					cout << "Номер нужной строки:";
					cin >> k;
					stroka = M[k];
					for (int i = 0; i < m; i++)
					{
						cout << stroka[i] <<" ";
					}
					break; }
		case 6: {
					int n;
					int m;
					cout << " Введите размерность матрицы:\n ";
					cin >> n >> m;
					cin>>Mtype;
					Matrix <Mtype> M(n, m);
					n = M.STR();
					m = M.STOLB();
					cout << n << "x" << m;
					break; }
		};
		getch();
	return 0;
}
