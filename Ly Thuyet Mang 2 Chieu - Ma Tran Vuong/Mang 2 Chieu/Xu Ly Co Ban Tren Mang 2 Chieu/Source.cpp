#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 100

/* 
- Tính tổng các phần tử trong mảng
- đếm số lượng các số chẵn trong mảng
- liệt kê các số chính phương có trong mảng
- Tìm kiếm 1 phần tử trong mảng
- Tìm Min/Max
*/

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

int TinhTongMang(int a[][MAX], int sodong, int socot)
{
	int Tong = 0;
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			Tong += a[i][j];
		}
	}
	return Tong;
}

int DemSoLuongSoChan(int a[][MAX], int sodong, int socot)
{
	int dem = 0;
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				dem++;
			}
		}
	}
	return dem;
}

int KiemTraChinhPhuong(int x)
{
	// Cách thiếu nhi
	//if(sqrt((double)x) == (int)sqrt((double)x))
	//{
	//	return 1; // là số CP
	//}
	//return 0; // Không phải là số CP

	//// Cách dậy thì
	//return sqrt((double)x) == (int)sqrt((double)x) ? 1 : 0;

	// Cách vào đời
	return sqrt((double)x) == (int)sqrt((double)x);
}

void LietKeChinhPhuong(int a[][MAX], int sodong, int socot)
{
	printf("\nCac so chinh phuong la: ");
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			if(KiemTraChinhPhuong(a[i][j]) == 1)
			{
				printf("%4d", a[i][j]);
			}
		}
	}
}

int TimKiem(int a[][MAX], int sodong, int socot, int x)
{
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			if(a[i][j] == x)
			{
				return i; // tìm thấy
			}
		}
	}
	return -1; // không thấy
}

// phanloai = 2 => tìm Max, phanloai = 1 => tìm Min
int TimMaxMin(int a[][MAX], int sodong, int socot, int phanloai)
{
	int Temp = a[0][0];

	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			// Tìm Max
			if(phanloai == 2)
			{
				if(a[i][j] > Temp)
				{
					Temp = a[i][j];
				}
			}
			else
			{
				if(a[i][j] < Temp)
				{
					Temp = a[i][j];
				}
			}
		}
	}
	return Temp;
}

void ChuyenMang(int a[][MAX], int sodong, int socot, int b[])
{
	int idx = 0;
	for(int i = 0; i < sodong; i++)
	{
		for(int j = 0; j < socot; j++)
		{
			b[idx++] = a[i][j];
		}
	}
}

void LietKePhanBiet(int b[], int n)
{
	printf("\nCac phan tu phan biet la: ");
	for(int i = 0; i < n; i++)
	{
		int Check = true;
		for(int j = i - 1; j >= 0; j--)
		{
			if(b[i] == b[j]) // bị trùng
			{
				Check = false; // cập nhật lại cờ hiệu
				break; // thoát ra
			}
		}
		// nếu không trùng => in ra
		if(Check == true)
		{
			printf("%4d", b[i]);
		}
	}
}

void LietKePhanBiet_Cach2(int a[][MAX], int sodong, int socot)
{
	printf("\nLiet ke cac phan tu phan biet: ");
	for(int i = 0; i < sodong * socot; i++)
	{
		int Check = 1;
		for(int j = i - 1; j >= 0; j--)
		{
			if(a[i / socot][i % socot] == a[j / socot][j % socot])
			{
				Check = 0; // bị trùng
				break;
			}
		}
		if(Check == 1)
		{
			printf("%4d", a[i / socot][i % socot]);
		}
	}
}

void HoanVi(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

void SapXep(int a[][MAX], int sodong, int socot, char phanloai)
{
	for(int i = 0; i < sodong * socot - 1; i++)
	{
		for(int j = i + 1; j < sodong * socot; j++)
		{
			if(phanloai == 't')
			{
				if(a[i / socot][i % socot] > a[j / socot][j % socot])
				{
					HoanVi(a[i / socot][i % socot], a[j / socot][j % socot]);
				}
			}
			else if(phanloai == 'g')
			{
				if(a[i / socot][i % socot] < a[j / socot][j % socot])
				{
					HoanVi(a[i / socot][i % socot], a[j / socot][j % socot]);
				}
			}
		}
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

	int Tong = TinhTongMang(a, sodong, socot);
	printf("\nTong = %d", Tong);

	int dem = DemSoLuongSoChan(a, sodong, socot);
	printf("\nSo luong cac so chan la: %d", dem);

	LietKeChinhPhuong(a, sodong, socot);

	int x = 5;

	int kiemtra = TimKiem(a, sodong, socot, x);

	if(kiemtra == -1)
	{
		printf("\nKhong tim thay");
	}
	else
	{
		printf("\nTim thay");
	}

	int Max = TimMaxMin(a, sodong, socot, 2);
	int Min = TimMaxMin(a, sodong, socot, 1);

	printf("\nMax = %d", Max);
	printf("\nMin = %d", Min);

	// Đây là cách làm của những người không biết dùng 1 vòng lặp để duyệt mảng 2 chiều
	/*int b[MAX];
	ChuyenMang(a, sodong, socot, b);
	LietKePhanBiet(b, sodong * socot);*/

	LietKePhanBiet_Cach2(a, sodong, socot);

	printf("\nSap tang dan\n");
	SapXep(a, sodong, socot, 't');
	XuatMang(a, sodong, socot);

	printf("\nSap giam dan\n");
	SapXep(a, sodong, socot, 'g');
	XuatMang(a, sodong, socot);

	char s[5][30] = {"Son dep trai", "Tuan xinh gai", 
		"Tu be de", "Thien gay", "Linh Less"};


	getch();
	return 0;
}