#include <stdio.h>
#include <conio.h>
#define MAX 100

void NhapMang(int a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("\nNhap vao a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void XuatMang(int a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

int TinhTongSoDuong(int a[][MAX], int dong, int cot)
{
	int Tong = 0;
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] > 0)
			{
				Tong += a[i][j];
			}
		}
	}
	return Tong;
}

int TinhTongBien(int a[][MAX], int dong, int cot)
{
	int Tong = 0;

	// duyet qua dòng đầu & dòng cuối
	for(int j = 0; j < cot; j++)
	{
		Tong += a[0][j] + a[dong - 1][j];
		//a[0][j];
		//a[dong - 1][j];
	}

	// duyệt qua cột đầu & cột cuối bỏ đi 2 ô đầu ở mỗi cột.
	for(int i = 1; i < dong - 1; i++)
	{
		Tong += a[i][0] + a[i][cot - 1];
		// a[i][0]
		// a[i][cot - 1];
	}

	return Tong;
}

void LietKeSoDuongTrongTungDong(int a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		int dem = 0;
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				dem++;
			}
		}
		if(dem != 0)
		{
			printf("\nDong %d co so luong so duong la: %d", i, dem);
		}
		else
		{
			printf("\nDong %d khong co so duong nao ca", i);
		}
	}
}

// hàm truyền vào 1 chỉ số dòng và tìm ra Max trên chỉ số dòng đó
int TimMaxDong(int a[][MAX], int chisodong, int cot, int &vitricot)
{

	int Max = a[chisodong][0];
	vitricot = 0;

	for(int i = 1; i < cot; i++)
	{
		if(a[chisodong][i] > Max)
		{
			Max = a[chisodong][i];
			vitricot = i;
		}
	}
	return Max;
}

// hàm truyền vào 1 chỉ số cột và tìm ra Min trên cột đó.
int TimMinCot(int a[][MAX], int dong, int chisocot)
{
	int Min = a[0][chisocot];

	for(int i = 1; i < dong; i++)
	{
		if(a[i][chisocot] < Min)
		{
			Min = a[i][chisocot];
		}
	}
	return Min;
}


// Hàm truyền vào chỉ số dòng i & j và kiểm tra nó có là yên ngựa hay không ?
// Nếu thỏa thì trả về 1, còn không thì trả về 0
int KiemTraYenNgua(int a[][MAX], int dong, int cot, int chisodong, int chisocot)
{
	// Kiểm tra xem a[chisodong][chisocot] có là lớn nhất trên dòng đó hay không ?
	for(int j = 0; j < cot; j++)
	{
		if(a[chisodong][j] > a[chisodong][chisocot])
		{
			return 0; // sai
		}
	}

	// Kiểm tra xem a[chisodong][chisocot] có là nhỏ nhất trên cột đó hay không ?
	for(int i = 0; i < dong; i++)
	{
		if(a[i][chisocot] < a[chisodong][chisocot])
		{
			return 0; // sai
		}
	}
	return 1; // dung
}

void LietKeYenNgua(int a[][MAX], int dong, int cot)
{
	printf("\nCac phan tu yen ngua la: ");
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(KiemTraYenNgua(a, dong, cot, i, j) == 1)
			{
				printf("%4d", a[i][j]);
			}
		}
	}
}

// Nếu tăng dần thì trả về 1, ngược lại trả về 0
int KiemTraDongTangDan(int a[][MAX], int chisodong, int cot)
{
	for(int j = 1; j < cot; j++)
	{
		if(a[chisodong][j] < a[chisodong][j - 1])
		{
			return 0; // không tăng dần
		}
	}
	return 1; // thỏa tăng dần.
}

void KiemTraTungDong(int a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		if(KiemTraDongTangDan(a, i, cot) == 1)
		{
			printf("\nDong %d tang dan", i);
		}
		else
		{
			printf("\nDong %d khong tang dan", i);
		}
	}
}

void HoanViPhanTu(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

void HoanViDong(int a[][MAX], int cot, int dong1, int dong2)
{
	for(int j = 0; j < cot; j++)
	{
		HoanViPhanTu(a[dong1][j], a[dong2][j]);
	}
}

void XoaDong(int a[][MAX], int &dong, int cot, int vitridongxoa)
{
	for(int i = vitridongxoa; i < dong - 1; i++)
	{
		HoanViDong(a, cot, i, i + 1);
	}
	dong--;
}

void ThemDong(int a[][MAX], int &dong, int cot, int b[], int vitridongthem)
{
	dong++; // tăng 1 dòng lên

	// đầu tiên thêm mảng b vào cuối cùng của ma trận
	for(int j = 0; j < cot; j++)
	{
		a[dong - 1][j] = b[j];
	}

	for(int i = dong - 1; i > vitridongthem; i--)
	{
		HoanViDong(a, cot, i, i - 1);
	}
}

void LietKeCheoTrai(int a[][MAX], int dong, int cot, int chisodong, int chisocot)
{
	int StartDong = chisodong, StartCot = chisocot;

	// tìm ra điểm bắt đầu của dòng và cột
	while(true)
	{
		StartDong--;
		StartCot--;

		if(StartDong < 0 || StartCot < 0)
		{
			StartDong += 1;
			StartCot += 1;
			break;
		}
	}
	//printf("\nStart dong = %d", StartDong);
	//printf("\nStart cot = %d", StartCot);

	// từ điểm bắt đầu đó lần lượt đi liệt kê ra các phần tử cho đến hết
	while(true)
	{
		printf("\ndong = %d & cot = %d", StartDong, StartCot);
		StartDong++;
		StartCot++;

		if(StartDong >= dong || StartCot >= cot)
		{
			break;
		}
	}
}

int main()
{
	int a[MAX][MAX], dong, cot;

	do{
		printf("\nNhap vao so dong: ");
		scanf("%d", &dong);

		if(dong < 1 || dong > 100)
		{
			printf("\nSo dong khong hop le. Xin kiem tra lai !");
		}
	}while(dong < 1 || dong > 100);

	do{
		printf("\nNhap vao so cot: ");
		scanf("%d", &cot);

		if(cot < 1 || cot > 100)
		{
			printf("\nSo cot khong hop le. Xin kiem tra lai !");
		}
	}while(cot < 1 || cot > 100);

	//NhapMang(a, dong, cot);
	//XuatMang(a, dong, cot);

	/*int TongDuong = TinhTongSoDuong(a, dong, cot);
	printf("\nTong cac so duong = %d", TongDuong);

	int TongBien = TinhTongBien(a, dong, cot);
	printf("\nTong bien = %d", TongBien);

	LietKeSoDuongTrongTungDong(a, dong, cot);
	LietKeYenNgua(a, dong, cot);

	KiemTraTungDong(a, dong, cot);*/

	//XoaDong(a, dong, cot, 0);
	//int b[MAX];

	// NHẬP VÀO SỐ PHẦN TỬ TRONG 1 DÒNG
	/*for(int i = 0; i < cot; i++)
	{
		printf("\nNhap vao phan tu cua cot %d la: ", i);
		scanf("%d", &b[i]);
	}

	ThemDong(a, dong, cot, b, 0);

	printf("\nMa tran sau khi bien doi la\n");
	XuatMang(a, dong, cot);*/

	LietKeCheoTrai(a, dong, cot, 3, 1);

	getch();
	return 0;
}