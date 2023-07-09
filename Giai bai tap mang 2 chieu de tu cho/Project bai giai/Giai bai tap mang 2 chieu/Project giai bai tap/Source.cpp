#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 100

// Khai báo nguyên mẫu hàm.
void NhapMang(int [][MAX], int, int);
void XuatMang(int [][MAX], int, int);

// Câu 1.
void LietKeSoChan(int [][MAX], int, int);

// Câu 2.
bool KiemTraNguyenTo(int);
void LietKeNguyenTo(int [][MAX], int, int);

// Câu 3.
bool KiemTraHoanThien(int);
void LietKeSoHoanThien(int [][MAX], int, int);

// Câu 4.
int TimSoChanDauTien(int [][MAX], int, int);
int TimSoChanCuoiCung(int [][MAX], int, int);

// Câu 5.
int TinhTongMaTran(int [][MAX], int, int);

// Câu 6.
int TichCacSoLe(int [][MAX], int, int);
int DemSoLuongCacSoLe(int [][MAX], int, int);

// Câu 7.
int TinhTongDongX(int [][MAX], int, int);

// Câu 8.
int TinhTongCotY(int [][MAX], int, int);

// Câu 9.
void ThemMotDong(int [][MAX], int &, int, int [], int);

// Câu 10.
void XoaMotDong(int [][MAX], int &, int, int);

// Câu 13.
void HoanVi(int &, int &);
void HoanVi2Dong(int [][MAX], int, int, int);


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

/* ========================== CÂU 1 ========================== */
void LietKeSoChan(int a[][MAX], int dong, int cot)
{
	bool Check = false; // Khởi tạo là false tức là chưa tìm thấy số chẵn nào.
	
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				Check = true; // Đã tìm thấy chẵn.
				printf("%4d", a[i][j]); // In ra màn hình.
			}
		}
	}
	if(Check == false)
	{
		printf("Mang khong ton tai so chan !");
	}
}
/* =========================================================== */

/* ========================== CÂU 2 ========================== */

// Số nguyên tố: Là số >= 2 và chỉ chia hết cho 1 và chính nó.

// Trả về true nếu như x là nguyên tố, ngược lại trả về false.
bool KiemTraNguyenTo(int x)
{
	if(x < 2)
	{
		return false;
	}
	else if(x > 2)
	{
		if(x % 2 == 0)
		{
			return false;
		}
		for(int i = 3; i <= (int)sqrt((float)x); i += 2) // Chỉ xét các giá trị lẻ.
		{
			if(x % i == 0)
			{
				return false;
			}
		}
	}
	return true; // Thỏa.
}

void LietKeNguyenTo(int a[][MAX], int dong, int cot)
{
	bool Check = false; // Khởi tạo là false tức là chưa thấy số nguyên tố nào cả.

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(KiemTraNguyenTo(a[i][j]) == true) // a[i][j] là nguyên tố.
			{
				Check = true; // Tìm thấy nè.
				printf("%4d", a[i][j]); // In ra.
			}
		}
	}
	if(Check == false)
	{
		printf("Mang khong ton tai so nguyen to !");
	}
}
/* =========================================================== */

/* ========================== CÂU 3 ========================== */

// Số hoàn thiện là gì ? Là số mà tổng các ước số nhỏ hơn nó bằng chính nó.

// vd: 6 là số hoàn thiện vì các ước số nhỏ hơn 6 bao gồm: 1, 2, 3 và: 1 + 2 + 3 = 6.
// vd: 28 là số hoàn thiện vì các ước số nhỏ hơn 28 bao gồm: 1, 2, 4, 7, 14 và: 1 + 2 + 4 + 7 + 14 = 28.

// Trả về true nếu x là số hoàn thiện, ngược lại trả về false.
bool KiemTraHoanThien(int x)
{
	int Tong = 0;
	for(int i = 1; i <= x / 2; i++)
	{
		if(x % i == 0) // i là ước số của x.
		{
			Tong += i; // Cộng dồn i vào biến tổng.
		}
	}
	if(Tong == x)
	{
		return true; // Thỏa.
	}
	return false; // Không thỏa.
}

void LietKeSoHoanThien(int a[][MAX], int dong, int cot)
{
	bool Check = false; // Khởi tạo là false coi như chưa tìm thấy.

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(KiemTraHoanThien(a[i][j]) == true)
			{
				Check = true; // Tìm thấy nè.
				printf("%4d", a[i][j]);
			}
		}
	}
	if(Check == false)
	{
		printf("Mang khong ton tai so hoan thien !");
	}
}
/* =========================================================== */

/* ========================== CÂU 4 ========================== */


int TimSoChanDauTien(int a[][MAX], int dong, int cot)
{
	int Value = -1;
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] % 2 == 0) // Tìm ra số chẵn.
			{
				return a[i][j]; // Trả về.
			}
		}
	}
	return Value;
}

int TimSoChanCuoiCung(int a[][MAX], int dong, int cot)
{
	int Value = -1;
	for(int i = dong - 1; i >= 0; i--)
	{
		for(int j = cot - 1; j >= 0; j--)
		{
			if(a[i][j] % 2 == 0) // Là số chẵn.
			{
				return a[i][j]; // Trả về.
			}
		}
	}
	return Value;
}
/* =========================================================== */

/* ========================== CÂU 5 ========================== */

int TinhTongMaTran(int a[][MAX], int dong, int cot)
{
	int Tong = 0;
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			Tong += a[i][j]; 
		}
	}
	return Tong;
}
/* =========================================================== */

/* ========================== CÂU 6 ========================== */

// Trung bình tích của n số nguyên => căn bậc n của tích các số.
// => căn bậc n của x chính là x ^ (1/n)

int TinhTichCacSoLe(int a[][MAX], int dong, int cot)
{
	int Tich = 1; // Khởi tạo.

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] % 2 != 0) // Là số lẻ.
			{
				Tich *= a[i][j];
			}
		}
	}
	return Tich;
}

int DemSoLuongCacSoLe(int a[][MAX], int dong, int cot)
{
	int dem = 0;
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] % 2 != 0) // Là số lẻ.
			{
				dem++;
			}
		}
	}
	return dem;
}
/* =========================================================== */

/* ========================== CÂU 7 ========================== */

// Ý Tưởng: Viết 1 hàm trả về tổng của 1 dòng x nào đó. Sau đó gọi lại hàm lồng nó vào vòng lặp chạy từ dòng đầu tới cuối rồi mỗi lần thì truyền chỉ số dòng vào hàm.

int TinhTongDongX(int a[][MAX], int x, int cot)
{
	int Tong = 0;
	for(int j = 0; j < cot; j++) // Chạy hết các cột.
	{
		Tong += a[x][j]; // Cộng dồn vào biến tổng.
	}
	return Tong;
}
/* =========================================================== */


/* ========================== CÂU 8 ========================== */

int TinhTongCotY(int a[][MAX], int dong, int Y)
{
	int Tong = 0;

	for(int i = 0; i < dong; i++)
	{
		Tong += a[i][Y];
	}
	return Tong;
}
/* =========================================================== */

/* ========================== CÂU 9 ========================== */

void ThemMotDong(int a[][MAX], int &dong, int cot, int b[], int ViTriDongCanThem) // b chính là thông tin dòng cần thêm.
{
	for(int i = dong; i > ViTriDongCanThem; i--)
	{
		for(int j = 0; j < cot; j++)
		{
			a[i][j] = a[i - 1][j];
		}
	}
	dong++;
	for(int j = 0; j < cot; j++)
	{
		a[ViTriDongCanThem][j] = b[j];
	}
}
/* =========================================================== */

/* ========================== CÂU 10 ========================== */

void XoaMotDong(int a[][MAX], int &dong, int cot, int ViTriDongXoa)
{
	for(int i = ViTriDongXoa + 1; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			a[i - 1][j] = a[i][j];
		}
	}
	dong--;
}
/* =========================================================== */

/* ========================== CÂU 13 ========================== */

void HoanVi(int &x, int &y)
{
	int Temp = x;
	x = y;
	y = Temp;
}

// X & Y: Hai dòng cần hoán vị.
void HoanVi2Dong(int a[][MAX], int X, int Y, int cot)
{
	for(int j = 0; j < cot; j++)
	{
		HoanVi(a[X][j], a[Y][j]);
	}
}

/* =========================================================== */

int main()
{
	int a[MAX][MAX], dong, cot;

	// Nhập số dòng.
	do{
		printf("\nNhap vao so dong: ");
		scanf("%d", &dong);

		if(dong < 0 || dong > MAX)
		{
			printf("\nSo dong khong hop le. Xin kiem tra lai !");
		}
	}while(dong < 0 || dong > MAX);

	// Nhập số cột.
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

	// Câu 1.
	printf("\nCac so chan la: ");
	LietKeSoChan(a, dong, cot);

	// Câu 2.
	printf("\nCac so nguyen to la: ");
	LietKeNguyenTo(a, dong, cot);

	// Câu 3.
	printf("\nCac so hoan thien la: ");
	LietKeSoHoanThien(a, dong, cot);

	// Câu 4.
	int SoChanDauTien = TimSoChanDauTien(a, dong, cot);
	int SoChanCuoiCung = TimSoChanCuoiCung(a, dong, cot);

	// Kiểm tra.
	if(SoChanDauTien == -1)
	{
		printf("\nMang khong ton tai so chan !");
	}
	else
	{
		printf("\nSo chan dau tien la: %d", SoChanDauTien);
		printf("\nSo chan cuoi cung la: %d", SoChanCuoiCung);
	}

	// Câu 5.
	int Tong = TinhTongMaTran(a, dong, cot);
	float TrungBinhCong = (float)Tong / (dong * cot);
	printf("\nTrung binh cong = %f", TrungBinhCong);

	// Câu 6.
	int TichCacSoLe = TinhTichCacSoLe(a, dong, cot);
	int SoLuongCacSoLe = DemSoLuongCacSoLe(a, dong, cot);
	float TrungBinhTich = pow(TichCacSoLe, (float)1 / SoLuongCacSoLe);
	printf("\nTrung binh tich = %f", TrungBinhTich);

	// Câu 7.
	for(int i = 0; i < dong; i++) // Duyệt từ dòng đầu tới dòng cuối.
	{
		int TongDong = TinhTongDongX(a, i, cot);
		printf("\nTong dong %d la: %d", i, TongDong);
	}

	// Câu 8.
	for(int j = 0; j < cot; j++) // Duyệt từ cột đầu tới cột cuối.
	{
		int TongCot = TinhTongCotY(a, dong, j);
		printf("\nTong cot %d la: %d", j, TongCot);
	}

	// Câu 9.
	int b[MAX];
	printf("\nNhap du lieu cho dong can them gom %d phan tu: ", cot);
	for(int j = 0; j < cot; j++)
	{
		printf("\nNhap vao phan tu thu %d: ", j + 1);
		scanf("%d", &b[j]);
	}
	int ViTriDongThem;
	do{
		printf("\nNhap vao vi tri dong can them (%d --> %d): ", 0, dong);
		scanf("%d", &ViTriDongThem);

		if(ViTriDongThem < 0 || ViTriDongThem > dong)
		{
			printf("\nVi tri dong can them khong hop le. Xin kiem tra lai !");
		}
	}while(ViTriDongThem < 0 || ViTriDongThem > dong);

	ThemMotDong(a, dong, cot, b, ViTriDongThem);
	printf("\nMa tran sau khi them 1 dong vao vi tri %d la: \n", ViTriDongThem);
	XuatMang(a, dong, cot);

	// Câu 10.
	int ViTriDongCanXoa;

	do{
		printf("\nNhap vao vi tri dong can xoa (%d --> %d): ", 0, dong - 1);
		scanf("%d", &ViTriDongCanXoa);

		if(ViTriDongCanXoa < 0 || ViTriDongCanXoa > dong - 1)
		{
			printf("\nVi tri dong can xoa khong hop le. Xin kiem tra lai !");
		}
	}while(ViTriDongCanXoa < 0 || ViTriDongCanXoa > dong - 1);

	XoaMotDong(a, dong, cot, ViTriDongCanXoa);
	printf("\nMa tran sau khi xoa dong %d la: \n", ViTriDongCanXoa);
	XuatMang(a, dong, cot);

	// Câu 13.
	int d1, d2; // 2 chỉ số dòng cần hoán vị.

	do{
		printf("\nNhap vao chi so dong can hoan vi (%d --> %d): ", 0, dong - 1);
		scanf("%d", &d1);

		if(d1 < 0 || d1 > dong - 1)
		{
			printf("\nChi so dong khong hop le. Xin kiem tra lai !");
		}
	}while(d1 < 0 || d1 > dong - 1);

	do{
		printf("\nNhap vao chi so dong tiep theo can hoan vi (%d --> %d): ", 0, dong - 1);
		scanf("%d", &d2);

		if(d2 < 0 || d2 > dong - 1)
		{
			printf("\nChi so dong khong hop le. Xin kiem tra lai !");
		}
	}while(d2 < 0 || d2 > dong - 1);

	HoanVi2Dong(a, d1, d2, cot);
	printf("\nMa tran sau khi hoan vi 2 dong %d & %d la: \n", d1, d2);
	XuatMang(a, dong, cot);

	getch();
	return 0;
}