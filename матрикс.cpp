// �������.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
#include <fstream>
#include <clocale>
#include <conio.h>
#include "Matrix.h"


using namespace std;


	int _tmain(int argc, _TCHAR* argv[])
	{
		setlocale(LC_CTYPE, "Russian");
		int x; // �����
		cout << "   1. �������� � ���� �������;\n   2. ��������� ����;\n   3. ��������� �������� ���� ������;\n   4. ��������� ��������� ���� ������;\n   5. ��������� k-�� ������ �������;\n   6. �������� ���-�� ����� � ��������\n\n";
		cin >> x;
		cout << endl;
		switch (x) {
		case 1: {
					int n; //���-�� �����
					int m; //���-�� ��������
					char  p[32];
					cout << "������� ���� � �����:";
					cin >> p;
					cout << "������� ���-�� �����:";
					cin >> n;
					cout << "������� ���-�� ��������:";
					cin >> m;
					Matrix object1(n, m);
					object1.Path(p);
					break; }

		case 2:	{
					char  p[32];
					cout << "������� ���� � �����:";
					cin >> p;
					fin.open(p);
					if (!fin.is_open()) // ���� ���� �� ������
						cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
					else
					{
						char buff[50];
						while (!fin.eof())
						{
							fin.getline(buff, 50); // ������� ������ �� �����
							cout << buff << endl;
						}
						fin.close(); // ��������� ���� 
					}
					break; }
		

		case 3: {
					char  p[32];
					int n1; //���-�� �����
					int n2;
					int m1; //���-�� ��������
					int m2;
					cout << " ������� ����������� ������ �������: ";
					cin >> n1 >> m1;
					cout << " ������� ����������� ������ �������: ";
					cin >> n2 >> m2;
					if (n1 == n2 && m1 == m2)
					{
						Matrix M1(n1, m1);
						Matrix M2(n2, m2);
						cout << "������� ���� � ����� 1-�� �������:";
						cin >> p;
						M1.Path(p);
						cout << "������� ���� � ����� 2-�� �������:";
						cin >> p;
						M2.Path(p);
						M1 + M2;
					}
					else cout << "������! ������� ����� ������ �������." << "\n";
					break; }

		case 4: {
					char  p[32];
					int n1; //���-�� �����
					int n2;
					int m1; //���-�� ��������
					int m2;
					cout << " ������� ����������� ������ �������: ";
					cin >> n1 >> m1;
					cout << " ������� ����������� ������ �������: ";
					cin >> n2 >> m2;
					if (m1 == n2)
					{
						Matrix M1(n1, m1);
						Matrix M2(n2, m2);
						cout << "������� ���� � ����� 1-�� �������:";
						cin >> p;
						M1.Path(p);
						cout << "������� ���� � ����� 2-�� �������:";
						cin >> p;
						M2.Path(p);
						M1 * M2;
					}
					else cout << "������! ������� ���������� ����������� ������.";
					break; }

		case 5: {
					int n, m; //���-�� �����, ��������
					int k; //����� ������ ������
					char p[32];
					cout << " ������� ����������� �������: ";
					cin >> n >> m;
					Matrix M (n, m);
					cout << "������� ���� � ����� �������:";
					cin >> p;
					M.Path(p);
					M.print();
					cout << "����� ������ ������:";
					cin >> k;
					M[k];
					break; }
		case 6: {
					int n;
					int m;
					cout << " ������� ����������� �������:\n ";
					cin >> n >> m;
					Matrix M(n, m);
					M.STR(); cout << "x";
					M.STOLB();
					break; }
		};
		getch();
	return 0;
}
