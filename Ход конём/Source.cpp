#include <iostream>
using namespace std;
void possible(int**& desk, int col, int row, int curI, int curJ, int& num)
{
	if (((curI - 1 >= 0) and (curJ - 2 >= 0)) and (desk[curI - 1][curJ - 2] == 0))
		num++;
	if (((curI - 2 >= 0) and (curJ - 1 >= 0)) and (desk[curI - 2][curJ - 1] == 0))
		num++;
	if (((curI - 2 >= 0) and (curJ + 1 < row)) and (desk[curI - 2][curJ + 1] == 0))
		num++;
	if (((curI - 1 >= 0) and (curJ + 2 < row)) and (desk[curI - 1][curJ + 2] == 0))
		num++;
	if (((curI + 1 < col) and (curJ + 2 < row)) and (desk[curI + 1][curJ + 2] == 0))
		num++;
	if (((curI + 2 < col) and (curJ + 1 < row)) and (desk[curI + 2][curJ + 1] == 0))
		num++;
	if (((curI + 2 < col) and (curJ - 1 >= 0)) and (desk[curI + 2][curJ - 1] == 0))
		num++;
	if (((curI + 1 < col) and (curJ - 2 >= 0)) and (desk[curI + 1][curJ - 2] == 0))
		num++;

}
void move(int**& desk, int col, int row, int curI, int curJ, int num, int product, int i)
{
	if (product == 2)
		return;
	int min = 8;
	int minI = 0, minJ = 0;
	if (((curI - 1 >= 0) and (curJ - 2 >= 0)) and (desk[curI - 1][curJ - 2] == 0))
		possible(desk, col, row, curI - 1, curJ - 2, num);
	if (num != 0) 
	{
		min = num;
		minI = curI - 1;
		minJ = curJ - 2;
	}
	num = 0;
	if (((curI - 2 >= 0) and (curJ - 1 >= 0)) and (desk[curI - 2][curJ - 1] == 0))
		possible(desk, col, row, curI - 2, curJ - 1, num);
	if ((min >= num) and (num != 0)) {
		min = num;
		minI = curI - 2;
		minJ = curJ - 1;
	}
	num = 0;
	if (((curI - 2 >= 0) and (curJ + 1 < row)) and (desk[curI - 2][curJ + 1] == 0))
		possible(desk, col, row, curI - 2, curJ + 1, num);
	if ((min >= num) and (num != 0)) {
		min = num;
		minI = curI - 2;
		minJ = curJ + 1;
	}
	num = 0;
	if (((curI - 1 >= 0) and (curJ + 2 < row)) and (desk[curI - 1][curJ + 2] == 0))
		possible(desk, col, row, curI - 1, curJ + 2, num);
	if ((min >= num) and (num != 0)) {
		min = num;
		minI = curI - 1;
		minJ = curJ + 2;
	}
	num = 0;
	if (((curI + 1 < col) and (curJ + 2 < row)) and (desk[curI + 1][curJ + 2] == 0))
		possible(desk, col, row, curI + 1, curJ + 2, num);
	if ((min >= num) and (num != 0)) {
		min = num;
		minI = curI + 1;
		minJ = curJ + 2;
	}
	num = 0;
	if (((curI + 2 < col) and (curJ + 1 < row)) and (desk[curI + 2][curJ + 1] == 0))
		possible(desk, col, row, curI + 2, curJ + 1, num);
	if ((min >= num) and (num != 0)) {
		min = num;
		minI = curI + 2;
		minJ = curJ + 1;
	}
	num = 0;
	if (((curI + 2 < col) and (curJ - 1 >= 0)) and (desk[curI + 2][curJ - 1] == 0))
		possible(desk, col, row, curI + 2, curJ - 1, num);
	if ((min >= num) and (num != 0)) {
		min = num;
		minI = curI + 2;
		minJ = curJ - 1;
	}
	num = 0;
	if (((curI + 1 < col) and (curJ - 2 >= 0)) and (desk[curI + 1][curJ - 2] == 0))
		possible(desk, col, row, curI + 1, curJ - 2, num);
	if ((min >= num) and (num != 0)) {
		min = num;
		minI = curI + 1;
		minJ = curJ - 2;
	}
	num = 0;
	min = 8;
	curI = minI;
	curJ = minJ;
	i++;
	desk[curI][curJ] = i;
	move(desk, col, row, curI, curJ, num, product - 1, i);
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			if (desk[i][j] == 0) {
				desk[i][j] = col * row;
				break;
			}
}
int main()
{
	setlocale(0, "");
	int posX, posY, row, col, num = 0, min = 8, curI, curJ, tmpI, tmpJ, minI, minJ, product, i = 1;
	do {
		cout << "Введите ширину шахматной доски ";
		cin >> col;
		if (col < 3)
			cout << "Некоректный ввод, попробуйте снова (слишком мало места для хода конем) " << "\n";
		else
			break;
	} while (true);
	do {
		cout << "Введите длину шахматной доски ";
		cin >> row;
		if (row < 3)
			cout << "Некоректный ввод, попробуйте снова (слишком мало места для хода конем) " << "\n";
		else
			break;
	} while (true);
	do {
		cout << "Введите позицию коня по вертикали ";
		cin >> posY;
		if (posY > col)
			cout << "Некоректный ввод, попробуйте снова (позиция коня выходит за грань доски) " << "\n";
		else
			break;
	} while (true);
	do {
		cout << "Введите позицию коня по горизонтали ";
		cin >> posX;
		if (posX > row)
			cout << "Некоректный ввод, попробуйте снова (позиция коня выходит за грань доски) " << "\n";
		else
			break;
	} while (true);
	product = col * row;
	int** desk = new int* [col];
	for (int i = 0; i < col; i++)
		desk[i] = new int[row];
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			desk[i][j] = 0;
	desk[posY - 1][posX - 1] = 1;
	curI = posY - 1;
	curJ = posX - 1;
	cout << "\n";
	move(desk, col, row, curI, curJ, num, product, i);



	FILE* f;
	const char* path = "F:\\Hod_konem.txt";
	if ((fopen_s(&f, path, "w")) != NULL)
	{
		cout << "Не удалось создать файл";
	}
	else
	{
		fprintf(f, "%s ", "Ход конём");
		fprintf(f, "\n");
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				fprintf(f, "%1d ", desk[i][j]);
			}
			fprintf(f, "\n");
		}

		fclose(f);
		if (fclose(f) == EOF)
		{
			cout << "Файл готов и закрыт";
		}
		else
		{
			cout << "Файл не закрыт";
		}
	}
	return 0;
}