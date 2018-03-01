
#include <iostream>
using namespace std;

	void Mas(int** mas1, int** mas2, int &n)
{
	cin >> n;
	*mas1 = new int[n];
	*mas2 = new int[n];
	for (int i = 0; i < n; i++) {
		(*mas1)[i] = rand() % 10;

	}
	for (int j = 0; j < n; j++) {
		(*mas2)[j] = rand() % 10;
	}
}

	void PrintMas(int* mas1, int* mas2, int n) {
		for (int i = 0; i < n; i++) {
			cout << mas1[i] << '\t';
		}
		cout << endl;
	
	 	 for (int j = 0; j < n; j++) {
			cout << mas2[j] << '\t';
		}
		cout << endl;
	}

	void Same(int** mas1, int** mas2, int &n)
	{
		int* newMassiv = new int[n + n];
		copy(*mas1, *mas1 + n, newMassiv);
		copy(*mas2, *mas2 + n, newMassiv + n);

		for (int i = 0; i < n + n; i++) {
			cout << newMassiv[i] << '\t';
		}
		cout << endl;

		int Sam = 0;
		for (int i = 0; i < n + n; i++) {
			for (int j = 0; j < n + n; j++){
			  if (newMassiv[j] == newMassiv[i]&& i>j) {
					Sam++;
				}
			}
		}
		int *newMas = new int[Sam];
		int Move = 0;
		for (int i = 0; i < n + n; i++) {
			for (int j = 0; j < n + n; j++)
				if (newMassiv[j] == newMassiv[i] && i > j) {
					newMas[Move] = newMassiv[i];
					Move++;
				}
		}

		for (int i = 0; i < Sam; i++) {
			cout << newMas[i] << '\t';
		}
		cout << endl;
		delete[](newMas);
		delete[](newMassiv);
	}

	void Uniq(int** mas1, int** mas2, int &n)
	{
		int* newMassiv = new int[n + n];
		copy(*mas1, *mas1 + n, newMassiv);
		copy(*mas2, *mas2 + n, newMassiv + n);

		for (int i = 0; i < n + n; i++) {
			cout << newMassiv[i] << '\t';
		}
		cout << endl;

		int tmp;
		for (int i = 0, j = 0; i<n+n; i++)
		{
			tmp = newMassiv[i];
			j = i - 1;
			while ((j >= 0) && (newMassiv[j] > tmp))
			{
				newMassiv[j + 1] = newMassiv[j];
				j = j - 1;
			}
			newMassiv[j + 1] = tmp;
		}

		int Unik = 0;
		for (int i = 0; i < n + n; i++) {
			if (newMassiv[i] != newMassiv[i+1]) {
					Unik++;
				}
			}
		int *newMas = new int[Unik];
		int Move = 0;
		for (int i = 0; i < n + n; i++) {
				if (newMassiv[i] != newMassiv[i+1]) {
					newMas[Move] = newMassiv[i];
					Move++;
				}
		}

		for (int i = 0; i < Unik; i++) {
			cout << newMas[i] << '\t';
		}
		cout << endl;
		delete[](newMas);
		delete[](newMassiv);
	}

	int main () {
		int n = 0;
		int *mas1 = NULL;
		int *mas2 = NULL;
		Mas(&mas1, &mas2, n);
		PrintMas(mas1, mas2, n);
		Same(&mas1, &mas2, n);
		Uniq(&mas1, &mas2, n);
		delete[] mas1;
		delete[] mas2;
		system("pause");
		return 0;
	}
