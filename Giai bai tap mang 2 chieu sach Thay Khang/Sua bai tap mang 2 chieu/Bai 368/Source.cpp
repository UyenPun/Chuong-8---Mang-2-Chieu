#include <stdio.h>
#include <conio.h>
#define MAX 100

void NhapMaTran(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong * cot; i++)
	{
		printf("\nNhap vao a[%d][%d] = ", i / cot, i % cot);
		scanf("%f", &a[i / cot][i % cot]);
	}
}

void XuatMaTran(float a[][MAX], int dong, int cot)
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
			dem++;
		}
	}
	return dem;
}

void HoanVi(float &a, float &b)
{
	float Temp = a;
	a = b;
	b = Temp;
}

void SapXepGiamDan(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong * cot - 1; i++)
	{
		for(int j = i + 1; j < dong * cot; j++)
		{
			if(a[i / cot][i % cot] < a[j / cot][j % cot])
			{
				HoanVi(a[i / cot][i % cot], a[j / cot][j % cot]);
			}
		}
	}
}

float TimMaxThuK(float a[][MAX], int dong, int cot, int k)
{
	SapXepGiamDan(a, dong, cot);
	int dem = 0;
	for(int i = 0; i < dong * cot; i++)
	{
		bool Check = true; // Kiểm tra trùng.

		// Kiểm tra xem phần tử hiện tại có bị trùng với trước đó ?
		for(int j = i - 1; j >= 0; j--)
		{
			if(a[i / cot][i % cot] == a[j / cot][j % cot])
			{
				Check = false;
				break;
			}
		}
		if(Check == true)
		{
			dem++;
			if(dem == k)
			{
				return a[i / cot][i % cot]; // Phần tử lớn thứ k.
			}
		}
	}
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

	NhapMaTran(a, dong, cot);
	XuatMaTran(a, dong, cot);

	int SoLuongPhanBiet = DemSoLuongPhanBiet(a, dong, cot);

	int k;
	SonDepTrai:
	// Nhập vào k.
	do{
		printf("\nNhap vao k (%d --> %d): ", 1, SoLuongPhanBiet);
		scanf("%d", &k);

		if(k < 1 || k > SoLuongPhanBiet)
		{
			printf("\nGia tri k khong hop le. Xin kiem tra lai !");
		}
	}while(k < 1 || k > SoLuongPhanBiet);
	
	float Max = TimMaxThuK(a, dong, cot, k);
	printf("\nMax thu %d la: %f", k, Max);
	goto SonDepTrai;
	getch();
	return 0;
}