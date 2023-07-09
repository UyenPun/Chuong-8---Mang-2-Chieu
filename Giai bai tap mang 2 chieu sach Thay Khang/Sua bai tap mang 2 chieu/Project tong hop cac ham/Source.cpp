/* 
			CHƯƠNG 6: Ma Trận

		  * KỸ THUẬT TÍNH TOÁN *

Bài 320:

float TinhTongCacSoDuong(float a[][MAX], int dong, int cot)
{
	float Tong = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				Tong += a[i][j];
			}
		}
	}
	return Tong;
}

Bài 321:

int TinhTichCacSoLe(int a[][MAX], int dong, int cot)
{
	int Tich = 1;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] % 2 != 0)
			{
				Tich *= a[i][j];
			}
		}
	}
	return Tich;
}

Bài 322:

float TinhTongDongK(float a[][MAX], int k, int cot)
{
	float Tong = 0;

	for(int j = 0; j < cot; j++)
	{
		Tong += a[k][j];
	}

	return Tong;
}

Bài 323:

float TinhTichCacSoDuongTrenCotK(float a[][MAX], int dong, int k)
{
	float Tich = 1;

	for(int i = 0; i < dong; i++)
	{
		if(a[i][k] >= 0)
		{
			Tich *= a[i][k];
		}
	}
	return Tich;
}

Bài 324, 325 tương tự => tự làm

Bài 326:

float TinhTrungBinhCongCacSoDuong(float a[][MAX], int dong, int cot)
{
	int dem = 0; // Đếm số lượng các số dương.
	float Tong = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				dem++; // Tăng biến đếm lên.
				Tong += a[i][j];
			}
		}
	}
	return Tong / dem;
}

Bài 327: 

float TinhTongBien(float a[][MAX], int dong, int cot)
{
	float Tong = 0;

	// Tính tổng của dòng đầu và dòng cuối.
	for(int j = 0; j < cot; j++)
	{
		Tong += (a[0][j] + a[dong - 1][j]);
	}

	// Tính tổng của cột đầu và cột cuối (bỏ đi 2 ô đầu và cuối).
	for(int i = 1; i < dong - 1; i++)
	{
		Tong += (a[i][0] + a[i][cot - 1]);
	}
	return Tong;
}

Bài 328:
#include <math.h>

// Tính căn bậc n của số x.
float TinhCanBac_n(float x, int n)
{
	return pow(x, (float)1 / n);
}

float TinhTrungBinhNhanCacSoDuong(float a[][MAX], int dong, int cot)
{
	float Tich = 1;
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				Tich *= a[i][j];
				dem++;
			}
		}
	}
	return TinhCanBac_n(Tich, dem);
}

Bài 329: 
#include <math.h>

void BienDoi(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] < 0)
			{
				a[i][j] *= -1; // Hoặc dùng: a[i][j] = fabs(a[i][j]). Lưu ý: fabs trả về trị tuyệt đối của 1 số thực, còn abs trả về trị tuyệt đối của số nguyên.
			}
		}
	}
}

Bài 331, 332: Tự làm

Bài 333:

Số hoàn thiện là số mà cộng các ước số nhỏ hơn nó lại bằng chính nó.

bool KiemTraSoHoanThien(int x)
{
	int Tong = 0;

	for(int i = 1; i <= x / 2; i++)
	{
		if(x % i == 0)
		{
			Tong += i;
		}
	}

	if(Tong == x)
	{
		return true; // Là số hoàn thiện.
	}
	return false; // Không phải là số hoàn thiện.
}

int TinhTongCacSoHoanThien(int a[][MAX], int dong, int cot)
{
	int Tong = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(KiemTraSoHoanThien(a[i][j]) == true)
			{
				Tong += a[i][j];
			}
		}
	}
	return Tong;
}

					* KỸ THUẬT ĐẾM *

Bài 334: Đếm số lượng các số dương có trong ma trận các số thực

int DemSoLuongCacSoDuong(float a[][MAX], int dong, int cot)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				dem++; // Tăng biến đếm lên.
			}
		}
	}
	return dem;
}

Bài 335: Đếm số nguyên tố trong ma trận các số nguyên

// Số nguyên tố là số >= 2 và chỉ chia hết cho 1 và chính nó.

bool KiemTraSoNguyenTo(int x)
{
	if(x < 2)
	{
		return false; // Không là nguyên tố.
	}
	else if(x > 2)
	{
		if(x % 2 == 0)
		{
			return false; // Không là nguyên tố.
		}
		for(int i = 3; i <= sqrt((float)x); i += 2)
		{
			if(x % i == 0)
			{
				return false; // Không là nguyên tố.
			}
		}
	}
	return true; // Là nguyên tố.
}

int DemSoLuongCacSoNguyenTo(int a[][MAX], int dong, int cot)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(KiemTraSoNguyenTo(a[i][j]) == true)
			{
				dem++;
			}
		}
	}
	return dem;
}

Bài 336: Đếm tần suất xuất hiện của một giá trị x trong ma trận các số thực

int DemTanSuatXuatHienCuaX(float a[][MAX], int dong, int cot, float x)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] == x)
			{
				dem++;
			}
		}
	}
	return dem;
}

Bài 337: Đếm số chữ số có trong ma trận các số nguyên dương.

vd: ma trận 2 x 3
12 35 5
87 0 69

=> số chữ số: 10

int DemSoLuongChuSoCuaX(int x)
{
	int dem = 0;

	while(x != 0)
	{
		x /= 10;
		dem++;
	}
	return dem;
}

int DemSoLuongChuSoCuaMaTran(int a[][MAX], int dong, int cot)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			dem += DemSoLuongChuSoCuaX(a[i][j]);
		}
	}
	return dem;
}

Bài 338: Đếm số lượng số dương trên 1 hàng
Bài 339: Đếm số lượng số hoàn thiện trên 1 hàng
Bài 340: Đếm số lượng số âm trên 1 cột.
Bài 341: Đếm số lượng số dương trên biên ma trận

=> Hoàn toàn tương tự các bài trước đó.

Bài 342 (*): Đếm số lượng phần tử cực đại trong ma trận các số thực. Một phần 
tử được gọi là cực đại khi nó lớn hơn các phần tử xung quanh.

Bài 343 (*): Đếm số lượng phần tử cực trị trong ma trận các số thực. Một phần 
tử được gọi là cực trị khi nó lớn hơn hoặc nhỏ hơn các phần tử xung quanh.

Làm mẫu bài 343: 

#include <limits.h>

int DemSoLuongCucTri(float a[][MAX], int dong, int cot)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			int Max = INT_MIN;
			int Min = INT_MAX;
			// ví dụ ta đang xét là a[i][j].
			=> trên a[i][j]: a[i - 1][j]
			=> dưới a[i][j]: a[i + 1][j]
			=> trái a[i][j]: a[i][j - 1]
			=> phải a[i][j]: a[i][j + 1]

			// Xét trên.
			if(i - 1 < 0)
			{
				=> lỗi ko xét.
			}
			else
			{
				Max = a[i - 1][j] > Max ? a[i - 1][j] : Max;
				Min = a[i - 1][j] < Min ? a[i - 1][j] : Min;
			}

			// Xét dưới.
			if(i + 1 == dong)
			{
				=> lỗi ko xét.
			}
			else
			{
				Max = a[i + 1][j] > Max ? a[i + 1][j] : Max;
				Min = a[i + 1][j] < Min ? a[i + 1][j] : Min;
			}

			// Xét trái.
			if(j - 1 < 0)
			{
				=> lỗi không xét.
			}
			else
			{
				Max = a[i][j - 1] > Max ? a[i][j - 1] : Max;
				Min = a[i][j - 1] < Min ? a[i][j - 1] : Min;
			}

			// Xét phải.
			if(j + 1 == cot)
			{
				=> lỗi không xét.
			}
			else
			{
				Max = a[i][j + 1] > Max ? a[i][j + 1] : Max;
				Min = a[i][j + 1] < Min ? a[i][j + 1] : Min;
			}

			if(a[i][j] > Max || a[i][j] < Min) // a[i][j] chính là cực trị.
			{
				dem++;
			}
		}
	}
	return dem;
}

Bài 344 (*): Đếm số lượng giá trị có trong ma trận các số thực.
Lưu ý: Nếu có k phần tử (k >= 1) trong ma trận bằng nhau thì ta chỉ tính 1

=> Đề bài này ý nói là đếm số lượng các phần tử phân biệt có trong ma trận.

vd: ma trận 2 x 3
1 2 1
1 0 0

=> có 3 phần tử phân biệt là: 1, 2, 0

=> Xem trong Project Bai 344

Bài 345: Tính tổng các phần tử cực trị
=> giống bài 343

Bài 346 (*): Đếm số lượng giá trị hoàng hậu trên ma trận. Một phần tử được gọi là hoàng hậu
khi nó lớn nhất trên dòng, trên cột và hai đường chéo đi qua nó.

=> GỢI Ý:
vd: Ma trận đang xét là 4 x 5
a[i][j] đang xét là: a[1][2]
+ Xét dòng đang chứa nó: Cố định dòng đang đứng và cột chạy từ 0 cho tới cột - 1
+ Xét cột đang chứa nó: Cố định cột đang đứng và dòng chạy từ 0 cho tới dòng - 1
+ Xét chéo đi từ trên trái xuống dưới phải: a[0][1], a[1][2], a[2][3], a[3][4]
=> hình thành 2 đường đi lên và đi xuống. đi lên thì cột và dòng cùng giảm 1, đi xuống thì cột và
dòng cùng tăng 1.
+ Xét chéo đi từ trên phải xuống dưới trái: a[0][3], a[1][2], a[2][1], a[3][0]
=> hình thành 2 đường đi lên và đi xuống. Đi lên thì dòng giảm 1, cột tăng 1. Đi xuống thì dòng
tăng 1, cột giảm 1.

Bài 347 (*): Đếm số lượng giá trị yên ngựa trên ma trận. Một phần tử được gọi là yên ngựa khi nó
lớn nhất trên dòng và nhỏ nhất trên cột.

=> GỢI Ý:
Xét dòng và cột đang chứa nó.
Đây chỉ là bài con của bài 346

						* KỸ THUẬT ĐẶT CỜ HIỆU *

Bài 348: Kiểm tra ma trận có tồn tại số dương hay không ?

// Trả về true nếu có tồn tại dương, ngược lại trả về false.
bool KiemTraTonTaiDuong(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				return true;
			}
		}
	}
	return false;
}

Bài 349: Kiểm tra ma trận có tồn tại số hoàn thiện hay không ?
=> giống bài 348

Bài 350: Kiểm tra ma trận có tồn tại số lẻ hay không ?
=> giống bài 348

Bài 351: Kiểm tra ma trận có toàn dương hay không ?
=> chỉ cần gặp thằng âm đầu tiên là kết luận không thỏa, còn nếu đi tới cuối cùng thì sẽ thỏa

bool KiemTraToanDuong(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] < 0)
			{
				return false;
			}
		}
	}
	return true;
}

Bài 352: Kiểm tra 1 hàng có tăng dần hay không ?

// Kiểm tra hàng k tăng dần. Nếu đúng trả về true, nếu sai trả về false.
bool KiemTraHangTangDan(float a[][MAX], int k, int cot)
{
	for(int j = 0; j < cot - 1; j++)
	{
		if(a[k][j] > a[k][j + 1])
		{
			return false;
		}
	}
	return true; // Tăng dần.
}

Bài 353: Kiểm tra 1 cột giảm dần
=> giống bài 352

Bài 354: Kiểm tra các giá trị trong ma trận có giảm dần theo dòng và cột hay không ?
=> kết hợp lại 2 bài trên sẽ ra được.

Bài 355: Liệt kê các dòng toàn âm trong ma trận các số thực.

// Kiểm tra dòng k có toàn âm hay không ? Nếu có trả về true, ngược lại trả về false.

bool KiemTraToanAm(float a[][MAX], int k, int cot)
{
	for(int j = 0; j < cot; j++)
	{
		if(a[k][j] >= 0)
		{
			return false;
		}
	}
	return true;
}

void LietKe(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++) // Chạy hết dòng.
	{
		if(KiemTraToanAm(a, i, cot) == true)
		{
			printf("\nDong %d thoa man toan am !", i);
		}
	}
}

Bài 360: Liệt kê các cột trong ma trận có chứa số chính phương

- Số chính phương là số mà kết quả khai căn bậc 2 là 1 số nguyên
vd: 0, 1, 4, 9, 16, 25 ...

#include <math.h>

bool KiemTraChinhPhuong(int x)
{
	return sqrt((float)x) == (int)sqrt((float)x);
}

						* KỸ THUẬT ĐẶT LÍNH CANH *

Bài 366: Tìm số chẵn đầu tiên xuất hiện trong ma trận số nguyên.

int TimSoChanDauTien(int a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				return a[i][j]; // Số chẵn tìm thấy.
			}
		}
	}
	return -1; // Không tồn tại số chẵn.
}

Bài 367: Tìm giá trị lớn nhất trong ma trận.

// Cách này chấp nhận duyệt lại a[0][0] thêm 1 lần.
float TimMax_Cach1(float a[][MAX], int dong, int cot)
{
	float Max = a[0][0];
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] > Max)
			{
				Max = a[i][j];
			}
		}
	}
	return Max;
}

// Cách này không cần duyệt lại a[0][0] mà chỉ duyệt các phần tử tiếp theo.
float TimMax_Cach2(float a[][MAX], int dong, int cot)
{
	float Max = a[0][0];

	for(int i = 1; i < dong * cot; i++)
	{
		if(a[i / cot][i % cot] > Max)
		{
			Max = a[i / cot][i % cot];
		}
	}
	return Max;
}


Bài 368: Tìm giá trị lớn thứ nhì trong ma trận. Giả sử ma trận có nhiều hơn hai giá trị.

=> CẢI TIẾN ĐỀ BÀI: Nhập vào số k (số lượng phần tử phân biệt >= k >= 1) tìm ra phần tử
lớn thứ k trong ma trận

vd: Nhập k = 1 => tìm ra phần tử lớn nhất
vd: Nhập k = 2 => tìm ra phần tử lớn nhì
vd: Nhập k = 3 => tìm ra phần tử lớn thứ 3

...


*/