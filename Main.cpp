#include "Header.h"
#include <random>
#include <time.h>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void uniform_data(unsigned long long A[], unsigned long long len)
{
	for (unsigned long long i = 0; i < len; i++)
	{
		A[i] = i;
	}
}

void non_uniform_data(unsigned long long A[], unsigned long long len)
{
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(0, 4);

	A[0] = 0;

	for (unsigned long long i = 1; i < len; i++)
	{
		A[i] = A[i - 1] + distribution(generator);
	}
}

double mst_l(unsigned long long L[], unsigned long long len) {
	auto start = high_resolution_clock::now();
	
	if (lenear(L, len, L[int(len*2/3)]));

	auto end = high_resolution_clock::now();
	duration<double, milli> elapsed = end - start;
	return elapsed.count();
}

double mst_b(unsigned long long L[], unsigned long long len) {
	auto start = high_resolution_clock::now();

	if (binary(L, 0, len - 1, L[int(len * 2 / 3)]));

	auto end = high_resolution_clock::now();
	duration<double, milli> elapsed = end - start;
	return elapsed.count();
}

double mst_j(unsigned long long L[], unsigned long long len) {
	auto start = high_resolution_clock::now();

	if (jump(L, len, L[int(len * 2 / 3)]));

	auto end = high_resolution_clock::now();
	duration<double, milli> elapsed = end - start;
	return elapsed.count();
}

double mst_i(unsigned long long L[], unsigned long long len) {
	auto start = high_resolution_clock::now();

	if (interpolation(L, len, L[int(len * 2 / 3)]));

	auto end = high_resolution_clock::now();
	duration<double, milli> elapsed = end - start;
	return elapsed.count();
}

double mst_e(unsigned long long L[], unsigned long long len) {
	auto start = high_resolution_clock::now();

	if (exponential(L, len, L[int(len * 2 / 3)]));

	auto end = high_resolution_clock::now();
	duration<double, milli> elapsed = end - start;
	return elapsed.count();
}

int main()
{
	setlocale(LC_ALL, "ru"); unsigned long long len = 3000000000; 
	unsigned long long* L; //= new unsigned long long[len];

	//uniform_data(L, len);
	//non_uniform_data(L, len);
	ofstream F_l("out_data_l.txt");
	ofstream F_b("out_data_b.txt");
	ofstream F_j("out_data_j.txt");
	ofstream F_i("out_data_i.txt");
	ofstream F_e("out_data_e.txt");


	for (unsigned long long i = len / 15; i <= len; i += len / 15)
	{
		L = new unsigned long long[i];
		non_uniform_data(L, i);

		F_l << i << " " << mst_l(L, i) << endl;
		F_b << i << " " << mst_b(L, i) << endl;
		F_j << i << " " << mst_j(L, i) << endl;
		F_i << i << " " << mst_i(L, i) << endl;
		F_e << i << " " << mst_e(L, i) << endl;

		delete[] L;
	}

	F_l.close();
	F_b.close();
	F_j.close();
	F_i.close();
	F_e.close();
	return 0;
}