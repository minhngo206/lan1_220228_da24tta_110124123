#include <stdio.h>

void nhapchitieu(float a[], int n);
void hienthichitieu(float a[], int n);
float tongchitieu(float a[], int n);
float trungbinhchitieu(float a[], int n);
int timngaymax(float a[], int n);
int timngaymin(float a[], int n);
int demngayvuotmucX(float a[], int n, float X);
int demngaythapbangX(float a[], int n, float X);
void sapxep(float n, float m);
void sapxeptangdan(float a[], int n);


int main()
{
	int n;
	float A[31];
	float x;
	do
	{
		printf ("Nhap vao so ngay chi tieu (28<=n<=31): "); scanf ("%d",&n);
	}while (n<28||n>31);
	nhapchitieu(A,n);	printf ("\n");
	hienthichitieu(A,n);	printf ("\n");
	printf("tong chi trong thang :%.1f\n",tongchitieu(A,n));
	printf ("\ntrung binh chi tieu :%.1f",trungbinhchitieu(A,n));
	printf ("\n tim ngay max :%.1f",timngaymax(A,n));
	printf ("\n tim ngay min :%.1f",timngaymin(A,n));
	printf("\n nhap vao x:");
	scanf ("%f", &x);
	printf ("\n dem ngay vuot muc :%.1f",demngayvuotmucX(A,n,x));
	printf ("\n dem ngay thap :%.1f",demngaythapbangX(A,n,x));
	sapxeptangdan(A,n);
	return 0;
}

void nhapchitieu(float a[], int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("Ngay %d: ",i+1); scanf ("%f",&a[i]);
	}
}

void hienthichitieu(float a[], int n)
{
	printf ("Hien thi chi tieu tung ngay: \n");
	for (int i=0; i<n; i++)
	{
		printf ("Ngay %d: %.1f dong\n",i+1,a[i]);
	}
}

float tongchitieu(float a[], int n)
{
	float S=0;
	for (int i=0; i<n; i++)
		S+=a[i];
	return S;
}

float trungbinhchitieu(float a[], int n)
{
	float TB=0;
	for (int i=0; i<n; i++)
		TB+=a[i];
	return TB/n;
}

int timngaymax(float a[], int n)
{
	float max=a[0];
	int x=1;
	for (int i=0; i<n; i++)
	{
		if (max<a[i])
		{
			max=a[i];
			x=i+1;
		}
	}
	return x;
}

int timngaymin(float a[], int n)
{
	float min=a[0];
	int y=1;
	for (int j=0; j<n; j++)
	{
		if (min>a[j])
		{
			min=a[j];
			y=j+1;
		}
	}
	return y;
}


int demngayvuotmucX(float a[], int n, float X)
{
	int dem=0;
	for (int i=0; i<n; i++)
	{
		if (a[i]>X)
			dem++;
	}
	return dem;
}

int demngaythapbangX(float a[], int n, float X)
{
	int dem=0;
	for (int i=0; i<n; i++)
	{
		if (a[i]<=X)
			dem++;
	}
	return dem;
}

void sapxep(float *n, float *m)
{
	int temp=*n;
	*n=*m;
	*m=temp;
}

void sapxeptangdan(float a[], int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (a[i]>a[j])
				sapxep(&a[i],&a[j]);
		}
	}
	for (int i=0; i<n; i++)
	{
		printf ("Ngay %d: %.1f dong\n",i+1,a[i]);
	}
}
