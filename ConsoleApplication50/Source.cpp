#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#define printName(name) printf("hello, %s\n", name)
#define len 250

using namespace std;

unsigned short int q;

void main()

{
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	int bckr, t;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));


	srand(time(NULL));

	unsigned short int nz;

	do
	{
		cout << "������� ����� �������: ";
		cin >> nz;

		cin.get();

		switch (nz)
		{
		case 1:
		{
			cout << "���� ������������������ ����� �����, �������������� �����." << endl
				<< "�������� ��� ����� ������������������ � �������������� ����\n\n";
			FILE *fp = NULL;

			if ((fp = fopen("case1.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				int mas[10];
				for (int i = 0; i < 10; i++)
				{
					mas[i] = 1 + rand() % 11;
					if (i == 9)
						mas[i] = 0;
					printf("%d\t", mas[i]);
					fprintf(fp, "%d\t", mas[i]);
				}
			}

			fclose(fp);
		}break;

		case 2:
		{
			cout << "��� ���� f, ���������� �������� �������� ������ �������. �������� � ����" << endl
				<< "g ��� ������ ����� ����� f, � � ���� h � ��� ��������. " << endl
				<< "������� ���������� ����� �����������\n\n";

			FILE *f = NULL;
			FILE *g = NULL;
			FILE *h = NULL;
			printf("�����, ���������� � ���� f:\n");
			if ((f = fopen("f.txt", "w")) == NULL || (g = fopen("g.txt", "w")) == NULL ||
				(h = fopen("h.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				int mas[15];
				for (int i = 0; i < 15; i++)
				{
					mas[i] = 1 + rand() % 10;
					printf("%d ", mas[i]);
					if ((mas[i]) % 2 == 0)
						fprintf(g, "%d ", mas[i]);
					else if ((mas[i]) % 2 != 0)
						fprintf(h, "%d ", mas[i]);

					fprintf(f, "%d ", mas[i]);
				}
				printf("\n������ ������ ���������\n");
			}

			/*	fclose(f);

				char mas[len];

				if ((f = fopen("f.txt", "r")) == NULL || (g = fopen("g.txt", "w")) == NULL
					|| (h = fopen("h.txt", "w")) == NULL)
				{
					printf("error\n");
					exit(1);
				}
				else
				{
					int count;

					count = fread(mas, 1, 500, f);

					cout << endl << count << endl;
					for (int i = 0; i < count; i++)
					{
						fread(mas, 1, 500, f);

						if (mas[i] % 2 == 0)
							fwrite(mas, 1, 1, g);
						else if (mas[i] % 2 != 0)
							fwrite(mas, 1, 1, h);
					}
				}*/
			fclose(f);
			fclose(h);
			fclose(g);
		}break;

		case 3:
		{
			cout << "��� ���������� ���� f. �������� � ���� g ���������� ����� f � \n�������� �������\n\n";

			FILE *fp = NULL;
			FILE *gp = NULL;

			if ((fp = fopen("f.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				char mas[len] = "������� ���� �������� ������, ��� � �����, � ����, � ������.";
				printf("� ���� f ����� �������� ��������� �����������: \n%s\n\n", mas);
				fprintf(fp, "%s", mas);
			}

			fclose(fp);

			char mas[len];

			if ((fp = fopen("f.txt", "r")) == NULL || (gp = fopen("g.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				char mas[len];
				int count;
				count = fread(mas, 1, len, fp);

				for (int i = count - 1; i >= 0; i--)
				{
					fprintf(gp, "%c", mas[i]);
				}
				printf("���� g ������� �������\n");
			}
			fclose(fp);
			fclose(gp);
		}break;

		case 4:
		{
			cout << "��� ���� f, ���������� �������� �������� ������ �������. ������� �� " << endl
				<< "��������� ����� �� ����� ����. ���� f �������� ������� �� �������������" << endl
				<< "�����, ������� � �������������. ��������� ��������������� ���� h, ����������" << endl
				<< "���������� ����� f � ���� g ���, ����� � ����� g :" << endl
				<< "a.�� ���� ���� �������� ����� � ����� ������" << endl
				<< "b.������� ��� �������������, ����� ������������� �����" << endl
				<< "c.����� ��� � ��������� ������� : ��� ��������������, ��� �������������," << endl
				<< "��� �������������, ��� ������������� � �.�. (��������������, ��� ����� " << endl
				<< "��������� � ����� f ������� �� 4)\n\n";

		}break;

		case 5:
		{
			cout << "���������� ��� �������� ��������������� �����, ������ ������� �������� " << endl
				<< "� ��������� �����. ����������� ��� ��������" << endl
				<< "a.��������, ��� � ������������ ����� �������� 12 ����" << endl
				<< "b.������ ������������� ����� ����������\n\n";
			cout << "���-�� �� ������ �������: ���� ���� ������ ������� �� ����� ��, ��� �������� � �����?�.�\n";
		}break;

		case 6:
		{
			cout << "������� ����, ���������� �������� �������� ��������� �����." << endl
				<< "�������� �����, ������������ ����� �������\n\n";
			FILE *fp = NULL;

			if ((fp = fopen("case6.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				char*str = "e l l o h";
				fprintf(fp, "%s", str);
				printf("����� ����, ������� ���������� � �����: %s\n", str);
			}
			fclose(fp);


			if ((fp = fopen("case6.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				int a;
				char newStr[20] = " ";
				char word[10] = "hello";
				printf("�� ������ ��� ��� �� �����?1/0");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
				{
					printf("�������� ���: ");
					scanf("%s", newStr);

					int  i = 0;
					while (i != 4)
					{
						if (word[i] == newStr[i])
							i++;
						else
							printf("��� �� �� �����\n"); break;
					}
					if (i == 4)
					{
						printf("�� �������!\n������ �������� ��� � ����?1/0");
						a = 0;
						scanf("%d", &a);
						switch (a)
						{
						case 1:
						{
							fprintf(fp, "%s", newStr);
							printf("���� ������� �������\n");
						}break;
						case 0:
						{
							printf("���� �� ����� ����������������");
						}break;
						}
					}
				}break;

				case 0:
				{
					printf("��������� � ���������� �������\n");
				}break;
				}
			}
			fclose(fp);

		}break;

		case 7:
		{
			cout << "������� �������������� ����, ���������� �������� �������� ��������� �����." << endl
				<< "���������� ��� �����, ������������ �� ����� �.\n\n";
			FILE *fp = NULL;
			int lenght;
			if ((fp = fopen("case7.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				char *str = "computer desk cisco cat ccc rain etc cuculele";
				fprintf(fp, "%s", str);
				printf("����� ���� � ������ �����:\n%s\n", str);
				lenght = strlen(str);
			}
			fclose(fp);


			if ((fp = fopen("case7.txt", "r")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				/*int c = 0;
				do
				{
					c = getc(fp);
					if (c == 'c')
						do
						{
							printf("%c", c);
							c = getc(fp);
						} while (c != ' ' || c != lenght);
						printf(" ");

				} while (c != lenght);
*/
				char mas[len];
				for (int i = 0; i < lenght; i++)
				{
					mas[i] = getc(fp);

					if (i == 0 && mas[i] == 'c')
					{
						int j = i;
						do {
							printf("%c", mas[j]); j++;
							mas[j] = getc(fp);
						} while (mas[j] != ' ');
						printf("\n");
						i = j;
					}

					else if(mas[i]=='c'&&mas[i-1]==' ')
					{
						int k = i;
						do {
							printf("%c", mas[k]); k++;
							mas[k] = getc(fp);
						} while (mas[k] != ' '&&k!=lenght);
						printf("\n");
						i = k;
					}
				}
			}
			fclose(fp);
		}break;
		}
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
		cout << "������ ���������� 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
			cout << "������" << endl;
		}
	} while (nz > 0);


}

