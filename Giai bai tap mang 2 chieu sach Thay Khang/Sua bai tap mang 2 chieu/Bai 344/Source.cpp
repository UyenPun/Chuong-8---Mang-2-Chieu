#include <stdio.h>
#include <conio.h>
#include <limits.h>
#define MAX 100

void NhapMang(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong * cot; i++)
	{
		printf("\nNhap vao a[%d][%d] = ", i / cot, i % cot);
		scanf("%f", &a[i / cot][i % cot]);
	}
}

void XuatMang(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong * cot; i++)
	{
		printf("%6.2f", a[i / cot][i % cot]);
		if((i + 1) % cot == 0)
		{
			printf("\n");
		}
	}
}

int DemSoLuongPhanBiet(float a[][MAX], int dong, int cot)
{
	int dem = 0;
	for(int i = 0; i < dong * cot; i++)
	{
		bool Check = true; // Mặc định là chưa bị trùng.
		for(int j = i - 1; j >= 0; j--)
		{
			if(a[i / cot][i % cot] == a[j / cot][j % cot])
			{
				Check = false; // Bị trùng.
				break;
			}
		}

		if(Check == true)
		{
			printf("%.2f\n", a[i / cot][i % cot]);
			dem++;
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

	printf("\nMa tran co cac phan tu phan biet la: \n");
	int SoLuong = DemSoLuongPhanBiet(a, dong, cot);
	printf("\nCo %d phan tu phan biet !", SoLuong);

	getch();
	return 0;
}