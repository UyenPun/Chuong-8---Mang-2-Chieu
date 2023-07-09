#include <stdio.h>
#include <conio.h>
#define MAX 100

void NhapMang(int a[][MAX], int sodong, int socot)
{
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			printf("\nNhap vao a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void XuatMang(int a[][MAX], int sodong, int socot)
{
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n"); // Nhớ có \n để mà hết 1 dòng thì xuống nhìn cho nó ra vẻ ma trận
	}
}


int main()
{
	// Khai báo trực tiếp mảng
	/*int a[5] = {1, 2, 3, 4, 5};
	int b[2][3] = {{1, 2, 3}, {4, 5, 6}};

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			printf("%4d", b[i][j]);
		}
		printf("\n");
	}*/

	int a[MAX][MAX]; // Khai báo đầy đủ
	int sodong, socot;

	do{
		printf("\nNhap vao so dong: ");
		scanf("%d", &sodong);

		if(sodong < 1 || sodong > MAX)
		{
			printf("\nSo dong khong hop le. Xin kiem tra lai !");
		}
	}while(sodong < 1 || sodong > MAX);


	do{
		printf("\nNhap vao so cot: ");
		scanf("%d", &socot);

		if(socot < 1 || socot > MAX)
		{
			printf("\nSo cot khong hop le. Xin kiem tra lai !");
		}
	}while(socot < 1 || socot > MAX);

	NhapMang(a, sodong, socot);
	XuatMang(a, sodong, socot);

	getch();
	return 0;
}