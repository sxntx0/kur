#pragma once

//Ћинейный поиск
bool lenear(unsigned long long A[], unsigned long long len, unsigned long long key);

//Ѕинарный поиск
bool binary(unsigned long long A[], unsigned long long low, unsigned long long high, unsigned long long key);

//ѕрыжковый поиск
bool jump(unsigned long long A[], unsigned long long len, unsigned long long key);

//»нтерпол€ционный поиск
bool interpolation(unsigned long long A[], unsigned long long len, unsigned long long key);

//Ёкспоненциальный поиск
bool exponential(unsigned long long A[], unsigned long long len, unsigned long long key);