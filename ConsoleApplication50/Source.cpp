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
				printf("\n������ �������� � ���� case1\n");
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

			FILE *fp = NULL;
			FILE *fp1 = NULL;
			FILE *fp2 = NULL;


			int mas[10];
			for (int i = 0; i < 5; i++)
			{
				mas[i] = 5 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			for (int i = 5; i < 10; i++)
			{
				mas[i] = -20 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			printf("\n");

			if ((fp = fopen("case4.txt", "w")) != NULL)
			{
				for (int i = 0; i < 10; i++)
					fprintf(fp, "%d\t", mas[i]);
			}
			fclose(fp);

			if (((fp = fopen("case4.txt", "r")) != NULL))
			{
				printf("���� ������\n");
				for (int i = 0; i < 10; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}
				if (((fp1 = fopen("case4_h.txt", "w")) != NULL) && ((fp2 = fopen("case4_hh.txt", "w")) != NULL))
				{
					printf("����� �������\n");
					for (int i = 0; i < 10; i++)
					{
						if (mas[i] < 0)
							fprintf(fp1, "%d\t", mas[i]);
						else
							fprintf(fp2, "%d\t", mas[i]);
					}
					fclose(fp1);
					fclose(fp2);
					if (((fp1 = fopen("case4_h.txt", "r")) != NULL) && ((fp2 = fopen("case4_hh.txt", "a+")) != NULL))
					{
						printf("����� �������\n");
						for (int i = 0; i < 5; i++)
						{
							fscanf(fp1, "%d", &mas[i]);
							/*printf("%d\t", mas[i]);*/
						}
						for (int i = 0; i < 5; i++)
						{
							fprintf(fp2, "%d\t", mas[i]);
						}
					}
					fclose(fp1);
					fclose(fp2);

				}
			}
			else
			{
				printf("���� �� ������\n");
				exit(1);
			}


		}break;

		case 5:
		{
			cout << "���������� ��� �������� ��������������� �����, ������ ������� �������� " << endl
				<< "� ��������� �����. ����������� ��� ��������" << endl
				<< "a.��������, ��� � ������������ ����� �������� 12 ����" << endl
				<< "b.������ ������������� ����� ����������\n\n";
			FILE *fp = NULL;
			FILE *fp1 = NULL;

			char *mas = "hello to everyone who reads this sentence hope you are doing well";
			
			if ((fp = fopen("case5.txt", "w")) != NULL)
			{
				fprintf(fp, "%s", mas);
				printf("���� ������� � �ase5\n");
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			fclose(fp);

			char newMas[12][20];
			if ((fp = fopen("case5.txt", "r")) != NULL)
			{
				for (int i = 0; i < 12; i++)
				{
					fscanf(fp, "%s", &newMas[i]);
				}
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			fclose(fp);

			if ((fp1 = fopen("newCase5.txt", "w")) != NULL)
			{
				for (int i = 0; i < 12; i++)
				{
					fprintf(fp1, "%s\n", newMas[i]);
				}
				printf("\n����� ���� ������� � newCase5\n");
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
			fclose(fp1);
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
						{
							printf("��� �� �� �����\n"); break;
						}
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
				printf("\n�����, ������������ �� ����� �, � ��������� � ����� case7\n");
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

					else if (mas[i] == 'c'&&mas[i - 1] == ' ')
					{
						int k = i;
						do {
							printf("%c", mas[k]); k++;
							mas[k] = getc(fp);
						} while (mas[k] != ' '&&k != lenght);
						printf("\n");
						i = k;
					}
				}
			}
			fclose(fp);
		}break;

		case 8:
		{
			cout << "������� �������������� ����, � ������� �������� 18 ����� �����." << endl
				<< "���������� ��� ������������� ����� ����� � ������ � ��� �� �������\n\n";
			FILE *fp = NULL;
			FILE *fp1 = NULL;

			int mas[18];
			printf("����� � ������ �����:\n");
			if ((fp = fopen("case8.txt", "w")) != NULL)
			{
				for (int i = 0; i < 18; i++)
				{
					mas[i] = -10 + rand() % 20;
					printf("%d\t", mas[i]);
					fprintf(fp, "%d\t", mas[i]);
				}
			}
			else
			{
				printf("error\n");
				exit(1);
			}
			fclose(fp);

			int c;

			if ((fp = fopen("case8.txt", "r")) != NULL)
			{
				if((fp1 = fopen("newCase8.txt", "w")) != NULL)
			{
				int j = 0;
				for (int i = 0; i < 18; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					if(mas[i]<=0)
						c = getc(fp);
					else if (mas[i] > 0)
					{
						fprintf(fp1, "%d\t", mas[i]);
						c = getc(fp);
					}
				}
				printf("\n����� ���� ������� � newCase8\n");
			}
				else
				{
					printf("error\n");
					exit(1);
				}
			}
			fclose(fp1);
		fclose(fp);
		}break;

		case 11:
		{

			cout << "������� �������������� ����, ���������� �������� �������� ��������� �����," << endl
				<< "������������ ������������������ ���������. �������� ����� ����, � ������� " << endl
				<< "����� ����� ��������� ����� ����������� ���������\n\n";
			FILE *fp = NULL;

			if ((fp = fopen("case11.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				char*str = "orpcessor";
				fprintf(fp, "%s", str);
				printf("����� ����, ������� ���������� � �����: %s\n", str);
			}
			fclose(fp);


			if ((fp = fopen("case11.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				int a;
				char newStr[20] = " ";
				char word[10] = "processor";
				printf("�� ������ ��� ��� �� �����?1/0");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
				{
					printf("�������� ���: ");
					scanf("%s", newStr);

					int  i = 0;
					while (i != 9)
					{
						if (word[i] == newStr[i])
							i++;
						else
						{
							printf("��� �� �� �����\n"); break;
						}
					}
					if (i == 9)
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

		case 13:
		{
			cout << "������� ���� � ��������� �������."<<endl
				<<"�������� � ������ ���� ����� ���������� ����� � �������� �������.\n\n";
			FILE *fp = NULL;
			FILE *fp1 = NULL;


			int mas[10];
			for (int i = 0; i < 30; i++)
			{
				mas[i] = 5 + rand() % 20;
				printf("%d\t", mas[i]);
			}
			printf("\n");

			if ((fp = fopen("case13.txt", "w")) != NULL)
			{
				for (int i = 0; i < 30; i++)
					fprintf(fp, "%d\t", mas[i]);
			}
			fclose(fp);

			if ((fp = fopen("case13.txt", "r")) != NULL)
			{
				for (int i = 0; i < 30; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}

				if ((fp1 = fopen("case13_new.txt", "w")) != NULL)
				{
					for (int i = 29; i >= 0; i--)
						fprintf(fp1, "%d\t", mas[i]);

					printf("\n����� �������� � �������� ������� � ����\n");
				}
				fclose(fp1);
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

