#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>


using namespace std;

int linearSearch(std::vector<int> a, int key)
{
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == key)
			return key;
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>((end - start));
	cout << "Linear search lasts " << duration.count() << " microseconds" << endl;
	return -1;
}

//int binarySearch(std::vector<int> a, int l, int r, int key)
//{
//	int split = a.size() / 2;
//
//	auto start = chrono::high_resolution_clock::now();
//	if (key == a[split])
//	{
//		return a[split];
//	}
//	auto end = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::microseconds>((end - start));
//	cout << "Part one lasts " << duration.count() << " microseconds" << endl;
//	start = chrono::high_resolution_clock::now();
//	if (key < a[split])
//	{
//		return binarySearch(a, l, split - 1, key);
//	}
//	end = chrono::high_resolution_clock::now();
//	duration = chrono::duration_cast<chrono::microseconds>((end - start));
//	cout << "Part two lasts " << duration.count() << " microseconds" << endl;
//	start = chrono::high_resolution_clock::now();
//	if (key > a[split])
//	{
//		return binarySearch(a, split + 1, r, key);
//	}
//	end = chrono::high_resolution_clock::now();
//	duration = chrono::duration_cast<chrono::microseconds>((end - start));
//	cout << "Part three lasts " << duration.count() << " microseconds" << endl;
//	return -1;
//}
int binarySearch(std::vector<int> a, int l, int r, int key)
{
	int split = (r + l) / 2;
	int left = l;
	int right = r;
	if (key == a[split])
		return a[split];
	else
	{
		
		while(a[split] != key)
		{
			auto start = chrono::high_resolution_clock::now();
			if (a[split] < key)
			{
				left = split;
				split = (right + split) / 2;
			}
			else if (a[split] > key)
			{
				right = split;
				split = (left + split) / 2;
			}
			auto end = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<chrono::microseconds>((end - start));
			cout << "Part one lasts " << duration.count() << " microseconds" << endl;
		}
		return split;
	}
	/*else if (key < a[split])
	{
		return binarySearch(a, l, split - 1, key);
	}
	else if (key > a[split])
	{
		return binarySearch(a, split + 1, r, key);
	}
	else return -1;*/

}

int main()
{
	int n = 0;
	vector<int> vec;
	cout << "Please enter a number: ";
	cin >> n;
	cout << endl;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		vec.push_back(rand() % 2001 - 1000);
	}


	sort(vec.begin(), vec.end());
	cout << endl;
	int a = 5000;

	linearSearch(vec, a);
	cout << binarySearch(vec, 0, vec.size() - 1, a);



}