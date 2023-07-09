#include <stdio.h>
#include <conio.h>
#include <limits.h>
#define MAX 100

void NhapMang(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("\nNhap vao a[%d][%d] = ", i, j);
			scanf("%f", &a[i][j]);
		}
	}
}

void XuatMang(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("%6.2f", a[i][j]);
		}
		printf("\n");
	}
}

int DemSoLuongCucTri(float a[][MAX], int dong, int cot)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			int Max = INT_MIN;
			int Min = INT_MAX;
			/* ví dụ ta đang xét là a[i][j].
			=> trên a[i][j]: a[i - 1][j]
			=> dưới a[i][j]: a[i + 1][j]
			=> trái a[i][j]: a[i][j - 1]
			=> phải a[i][j]: a[i][j + 1] */

			// Xét trên.
			if(i - 1 < 0)
			{
				// => lỗi ko xét.
			}
			else
			{
				Max = a[i - 1][j] > Max ? a[i - 1][j] : Max;
				Min = a[i - 1][j] < Min ? a[i - 1][j] : Min;
			}

			// Xét dưới.
			if(i + 1 == dong)
			{
				// => lỗi ko xét.
			}
			else
			{
				Max = a[i + 1][j] > Max ? a[i + 1][j] : Max;
				Min = a[i + 1][j] < Min ? a[i + 1][j] : Min;
			}

			// Xét trái.
			if(j - 1 < 0)
			{
				// => lỗi không xét.
			}
			else
			{
				Max = a[i][j - 1] > Max ? a[i][j - 1] : Max;
				Min = a[i][j - 1] < Min ? a[i][j - 1] : Min;
			}

			// Xét phải.
			if(j + 1 == cot)
			{
				// => lỗi không xét.
			}
			else
			{
				Max = a[i][j + 1] > Max ? a[i][j + 1] : Max;
				Min = a[i][j + 1] < Min ? a[i][j + 1] : Min;
			}

			if(a[i][j] > Max || a[i][j] < Min) // a[i][j] chính là cực trị.
			{
				printf("\n%.2f\n", a[i][j]);
				dem++;
			}
		}
	}
	return dem;
}


int main()
{
	float a[MAX][MAX];
	int dong, cot;

	// Nhập vào số dòng.
	do{
		printf("\nNhap vao so dong: ");
		scanf("%d", &dong);

		if(dong < 0 || dong > MAX)
		{
			printf("\nSo dong khong hop le. Xin kiem tra lai !");
		}
	}while(dong < 0 || dong > MAX);

	// Nhập vào số cột.
	do{
		printf("\nNhap vao so cot: ");
		scanf("%d", &cot);

		if(cot < 0 || cot > MAX)
		{
			printf("\nSo cot khong hop le. Xin kiem tra lai !");
		}
	}while(cot < 0 || cot > MAX);

	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);

	printf("\nMa tran co cac phan tu cuc tri la: \n");
	int SoLuong = DemSoLuongCucTri(a, dong, cot);
	printf("\nSo luong cuc tri la: %d", SoLuong);

	getch();
	return 0;
}