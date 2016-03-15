#pragma once
#include <fstream>
#include <iostream>

using namespace std;

ofstream fout;
ifstream fin;

class Matrix
{
	int stroki;
	int stolbs;
	double **e;

public:
	Matrix() : stroki(0), stolbs(0), e(nullptr) {};
	Matrix(int n, int m) : stroki(n), stolbs(m)
	{
		e = new double*[n];
		for (int i = 0; i < n; i++)
			e[i] = new double[m];
	};
	Matrix(const Matrix &M) : stroki(M.stroki), stolbs(M.stolbs)
	{ //Конструктор копирования
		e = new double*[stroki];
		for (int i = 0; i < stroki; i++)
		{
			e[i] = new double[stolbs];
		}
		for (int i = 0; i < stroki; i++)
		{
			for (int j = 0; j < stolbs; j++)
			{
				e[i][j] = M.e[i][j];
			}
		}

	};
	~Matrix(){
		{
			if (e != nullptr)
			{
				for (int i = 0; i < stroki; i++)
				{
					delete[] e[i];
				}
				delete[] e;
			}
		}
	};
	void Set(char *path)
	{ //Запись в файл
		fout.open(path);
		for (int i = 0; i < stroki; i++)
		{
			for (int j = 0; j < stolbs; j++)
			{
				cin >> e[i][j];
				fout << " " << e[i][j];
			}
			fout << "\n";
		}
		fout.close();
	};
	int STR() {  return stroki; };
	int STOLB(){ return stolbs; };
	int print()
	{ //Вывод на экран
		for (int i = 0; i < stroki; i++)
		{
			for (int j = 0; j < stolbs; j++)
			{
				cout << e[i][j] << " ";
			}
			cout << "\n";
		}
		return 0;
	};

	Matrix operator + ( const Matrix &M2)
	{ //Оператор сложения 2ух матриц
		Matrix M3(M2.stroki, M2.stolbs);
		for (int i = 0; i < M2.stroki; i++)
		for (int j = 0; j < M2.stolbs; j++)
			M3.e[i][j] = e[i][j] + M2.e[i][j];
		cout << "Матрица 1 + Матрица 2=\n"; M3.print();
		return M3;
	};

	Matrix operator * ( const Matrix &M2)
	{ //Оператор умножения 2ух матриц
		Matrix M3(stroki, M2.stolbs);
		int k = 0;
		for (int i = 0; i < stroki; i++)
		{
			for (int j = 0; j < M2.stolbs; j++)
			{
				M3.e[i][j] = 0;
				for (int k = 0; k <= M2.stolbs; k++)
				{
					M3.e[i][j] += (e[i][k] * M2.e[k][j]);
				}
			}
		}
		cout << "Матрица 1 * Матрица 2  =\n"; M3.print();
		return M3;
	}

	double * operator [] (int k)
	{
		double* stroka = new double[stolbs];
		for (int j = 0; j < stolbs; j++)
		{
			stroka[j] = e[k - 1][j];
		}
		return stroka;


	};
};
