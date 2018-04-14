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
		cout << "Введите номер задания: ";
		cin >> nz;

		cin.get();

		switch (nz)
		{
		case 1:
		{
			cout << "Дана последовательность целых чисел, оканчивающаяся нулем." << endl
				<< "Записать все числа последовательности в типизированный файл\n\n";
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
				printf("\nданные записаны в файл case1\n");
			}

			fclose(fp);
		}break;

		case 2:
		{
			cout << "Дан файл f, компоненты которого являются целыми числами. Записать в файл" << endl
				<< "g все четные числа файла f, а в файл h — все нечетные. " << endl
				<< "Порядок следования чисел сохраняется\n\n";

			FILE *f = NULL;
			FILE *g = NULL;
			FILE *h = NULL;
			printf("числа, записанные в файл f:\n");
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
				printf("\nзапись файлов завершена\n");
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
			cout << "Дан символьный файл f. Записать в файл g ком¬поненты файла f в \nобратном порядке\n\n";

			FILE *fp = NULL;
			FILE *gp = NULL;

			if ((fp = fopen("f.txt", "w")) == NULL)
			{
				printf("error\n");
				exit(1);
			}
			else
			{
				char mas[len] = "сегодня была странная погода, был и дождь, и снег, и солнце.";
				printf("в файл f будет записано следующее предложение: \n%s\n\n", mas);
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
				printf("файл g успешно записан\n");
			}
			fclose(fp);
			fclose(gp);
		}break;

		case 4:
		{
			cout << "Дан файл f, компоненты которого являются целыми числами. Никакая из " << endl
				<< "компонент файла не равна нулю. Файл f содержит столько же отрицательных" << endl
				<< "чисел, сколько и положительных. Используя вспомогательный файл h, переписать" << endl
				<< "компоненты файла f в файл g так, чтобы в файле g :" << endl
				<< "a.не было двух соседних чисел с одним знаком" << endl
				<< "b.сначала шли положительные, потом отрицательные числа" << endl
				<< "c.числа шли в следующем порядке : два положитель¬ных, два отрицательных," << endl
				<< "два положительных, два отрица¬тельных и т.д. (предполагается, что число " << endl
				<< "компонент в файле f делится на 4)\n\n";

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
				printf("Файл открыт\n");
				for (int i = 0; i < 10; i++)
				{
					fscanf(fp, "%d", &mas[i]);
					/*printf("%d\t", mas[i]);*/
				}
				if (((fp1 = fopen("case4_h.txt", "w")) != NULL) && ((fp2 = fopen("case4_hh.txt", "w")) != NULL))
				{
					printf("Файлы открыты\n");
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
						printf("Файлы открыты\n");
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
				printf("Файл не открыт\n");
				exit(1);
			}


		}break;

		case 5:
		{
			cout << "Напечатать все элементы типизированного файла, каждый элемент которого " << endl
				<< "— отдельное слово. Рассмотреть два варианта" << endl
				<< "a.известно, что в существующем файле записаны 12 слов" << endl
				<< "b.размер существующего файла неизвестен\n\n";
			FILE *fp = NULL;
			FILE *fp1 = NULL;

			char *mas = "hello to everyone who reads this sentence hope you are doing well";
			
			if ((fp = fopen("case5.txt", "w")) != NULL)
			{
				fprintf(fp, "%s", mas);
				printf("файл записан в сase5\n");
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
				printf("\nновый файл записан в newCase5\n");
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
			cout << "Имеется файл, элементами которого являются отдельные буквы." << endl
				<< "Получить слово, образованное этими буквами\n\n";
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
				printf("набор букв, который присутвует в файле: %s\n", str);
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
				printf("вы знаете что это за слово?1/0");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
				{
					printf("напишите его: ");
					scanf("%s", newStr);

					int  i = 0;
					while (i != 4)
					{
						if (word[i] == newStr[i])
							i++;
						else
						{
							printf("это не то слово\n"); break;
						}
					}
					if (i == 4)
					{
						printf("Вы угадали!\nхотите записать это в файл?1/0");
						a = 0;
						scanf("%d", &a);
						switch (a)
						{
						case 1:
						{
							fprintf(fp, "%s", newStr);
							printf("файл успешно записан\n");
						}break;
						case 0:
						{
							printf("файл не будет перезаписываться");
						}break;
						}
					}
				}break;

				case 0:
				{
					printf("переходим к следующему заданию\n");
				}break;
				}
			}
			fclose(fp);

		}break;

		case 7:
		{
			cout << "Имеется типизированный файл, элементами которого являются отдельные слова." << endl
				<< "Напечатать все слова, начинающиеся на букву с.\n\n";
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
				printf("набор слов в данном файле:\n%s\n", str);
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
				printf("\nслова, начинающиеся на букву с, и считанные с файла case7\n");
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
			cout << "Имеется типизированный файл, в котором записаны 18 целых чисел." << endl
				<< "Переписать все положительные числа файла в массив в том же порядке\n\n";
			FILE *fp = NULL;
			FILE *fp1 = NULL;

			int mas[18];
			printf("числа в первом файле:\n");
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
				printf("\nновый файл записан в newCase8\n");
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

			cout << "Имеется типизированный файл, элементами которого являются отдельные буквы," << endl
				<< "составляющие последовательность орпцессор. Получить новый файл, в котором " << endl
				<< "буквы слова процессор будут расположены правильно\n\n";
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
				printf("набор букв, который присутвует в файле: %s\n", str);
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
				printf("вы знаете что это за слово?1/0");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
				{
					printf("напишите его: ");
					scanf("%s", newStr);

					int  i = 0;
					while (i != 9)
					{
						if (word[i] == newStr[i])
							i++;
						else
						{
							printf("это не то слово\n"); break;
						}
					}
					if (i == 9)
					{
						printf("Вы угадали!\nхотите записать это в файл?1/0");
						a = 0;
						scanf("%d", &a);
						switch (a)
						{
						case 1:
						{
							fprintf(fp, "%s", newStr);
							printf("файл успешно записан\n");
						}break;
						case 0:
						{
							printf("файл не будет перезаписываться");
						}break;
						}
					}
				}break;

				case 0:
				{
					printf("переходим к следующему заданию\n");
				}break;
				}
			}
			fclose(fp);
		}break;

		case 13:
		{
			cout << "Имеется файл с тридцатью числами."<<endl
				<<"Записать в другой файл числа имеющегося файла в обратном порядке.\n\n";
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

					printf("\nчисла записаны в обратном порядке в файл\n");
				}
				fclose(fp1);
			}
			fclose(fp);
		}break;
	}
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	cout << "Хотите продолжить 1/0?";
	cin >> q;


	switch (q)
	{
	case 1:
		system("cls");
		break;
	default:
		cout << "ошибка" << endl;
	}
} while (nz > 0);


}

