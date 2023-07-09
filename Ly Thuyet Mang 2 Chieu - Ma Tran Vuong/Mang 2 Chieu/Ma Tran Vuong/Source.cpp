#include <stdio.h>
#include <conio.h>
#define MAX 100

// n tượng trưng cho dòng & cột
void NhapMaTran(int a[][MAX], int n)
{
	// Cách 1
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("\nNhap vao a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}*/

	for(int i = 0; i < n * n; i++)
	{
		printf("\nNhap vao a[%d][%d] = ", i / n, i % n);
		scanf("%d", &a[i / n][i % n]);
	}
}

// n tượng trưng cho dòng & cột
void XuatMaTran(int a[][MAX], int n)
{
	//for(int i = 0; i < n; i++) // dòng
	//{
	//	for(int j = 0; j < n; j++) // cột
	//	{
	//		printf("%4d", a[i][j]);
	//	}
	//	printf("\n"); // phải xuống dòng
	//	
	//}

	for(int i = 0; i < n * n; i++)
	{
		printf("%4d", a[i / n][i % n]);
		if((i + 1) % n == 0) // n chính là số cột
		{
			printf("\n");
		}
	}
}

int TinhTongDong(int a[][MAX], int chisodong, int n)
{
	int Tong = 0;

	// Cho chạy từ đầu tới cuối các cột
	for(int i = 0; i < n; i++)
	{
		Tong += a[chisodong][i];
	}
	return Tong;
}

int TinhTichCot(int a[][MAX], int chisocot, int n)
{
	int Tich = 1;

	// Cho chạy từ đầu tới cuối các dòng
	for(int i = 0; i < n; i++)
	{
		Tich *= a[i][chisocot];
	}
	return Tich;
}

void TinhTongTungDong(int a[][MAX], int n)
{
	// Cách 1: Cho vòng lặp duyệt qua các dòng rồi gọi lại hàm cũ
	/*for(int i = 0; i < n; i++)
	{
		int Tong = TinhTongDong(a, i, n);
		printf("\nTong dong %d la: %d", i, Tong);
	}*/

	// Cách 2: Làm trực tiếp
	for(int i = 0; i < n; i++) // dòng
	{
		int Tong = 0;
		for(int j = 0; j < n; j++) // cột
		{
			Tong += a[i][j];
		}
		printf("\nTong dong %d = %d", i, Tong);
	}
}

void TinhTichTungCot(int a[][MAX], int n)
{
	// cho vòng lặp duyệt qua tất cả các cột rồi truyền chỉ số cột vào
	//for(int i = 0; i < n; i++) // n ở đây là số cột
	//{
	//	int Tich = TinhTichCot(a, i, n);
	//	printf("\nTich cua cot %d = %d", i, Tich);
	//}

	// Cách 2: Làm trực tiếp
	for(int i = 0; i < n; i++) // duyệt qua cột
	{
		int Tich = 1;
		for(int j = 0; j < n; j++) // duyệt qua dòng
		{
			Tich *= a[j][i];
		}
		printf("\nTich cua cot %d = %d", i, Tich);
	}
}

void LietKeTinhTongCheoChinh(int a[][MAX], int n)
{
	int Tong = 0;
	printf("\nCac phan tu nam tren duong cheo chinh la: ");
	for(int i = 0; i < n; i++)
	{
		printf("%4d", a[i][i]);
		Tong += a[i][i];
	}
	printf("\nTong cac phan tu tren cheo chinh = %d", Tong);
}

void LietKeTimMinMaxCheoPhu(int a[][MAX], int n)
{
	int Min, Max;
	Min = Max = a[0][n - 1];
	printf("\nDuong cheo phu la: %4d", a[0][n - 1]);

	for(int i = 1; i < n; i++)
	{
		printf("%4d", a[i][n - 1 - i]);
		Max = a[i][n - 1 - i] > Max ? a[i][n - 1 - i] : Max;
		Min = a[i][n - 1 - i] < Min ? a[i][n - 1 - i] : Min;
	}
	printf("\nMin = %d & Max = %d", Min, Max);
}

void LietKeDemSoChanTamGiacTrenCheoChinh(int a[][MAX], int n)
{
	printf("\nCac phan tu tren cheo chinh la: ");
	int dem = 0;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			printf("%4d", a[i][j]);
			if(a[i][j] % 2 == 0)
			{
				dem++;
			}
		}
	}
	if(dem == 0)
	{
		printf("\nKhong co so chan");
	}
	else
	{
		printf("\nCo %d so chan", dem);
	}
}

void LietKeVaTimXTrongTamGiacDuoiCheoChinh(int a[][MAX], int n, int x)
{
	int Check = 0;
	printf("\nCac phan tu duoi cheo chinh la: ");
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			printf("%4d", a[i][j]);
			if(x == a[i][j])
			{
				Check = 1;
			}
		}
	}
	if(Check == 0)
	{
		printf("\nKhong tim thay x");
	}
	else
	{
		printf("\nCo tim thay x");
	}
}

int main()
{
	int a[MAX][MAX], n;

	do{
		printf("\nNhap vao n = ");
		scanf("%d", &n);

		if(n < 1 || n > MAX)
		{
			printf("\nGia tri khong hop le. Xin kiem tra lai !");
		}
	}while(n < 1 || n > MAX);

	NhapMaTran(a, n);
	XuatMaTran(a, n);

	/*int i = 1;
	int Tong = TinhTongDong(a, i, n);
	int Tich = TinhTichCot(a, i, n);

	printf("\nTong dong %d la: %d", i, Tong);
	printf("\nTich cot %d la: %d", i, Tich);*/

	TinhTongTungDong(a, n);
	TinhTichTungCot(a, n);

	LietKeTinhTongCheoChinh(a, n);
	LietKeTimMinMaxCheoPhu(a, n);
	LietKeDemSoChanTamGiacTrenCheoChinh(a, n);

	int x = 7;
	LietKeVaTimXTrongTamGiacDuoiCheoChinh(a, n, x);

	getch();
	return 0;
}