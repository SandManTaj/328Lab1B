#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>


using namespace std;

int linearSearch(std::vector<int> a, int key)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == key)
			return key;
	}
	return -1;
}

int binarySearch(std::vector<int> a, int l, int r, int key)
{
	int split = (r + l) / 2;
	int left = l;
	int right = r;
	if (l > r)
	{
		return 0;
	}
	if (key == a[split])
		return split;
	else if (key < a[split])
	{
		return binarySearch(a, l, split - 1, key);
	}
	else if (key > a[split])
	{
		return binarySearch(a, split + 1, r, key);
	}
	
}

int binarySearchStep(std::vector<int> a, int l, int r, int key)
{
	int split = (r + l) / 2;
	int left = l;
	int right = r;
	if (l > r)
	{
		return 0;
	}
	if (key == a[split])
		return 0;
	else if (key < a[split])
	{
		return 0;
	}
	else if (key > a[split])
	{
		return 0;
	}

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
	int a = 5000;

	auto start = chrono::high_resolution_clock::now();
	linearSearch(vec, a);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>((end - start));
	cout << "Linear search lasts " << duration.count() << " microseconds" << endl;
	
	start = chrono::high_resolution_clock::now();
	binarySearch(vec, 0, vec.size() - 1, a);
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>((end - start));
	cout << "Binary search lasts " << duration.count() << " microseconds" << endl;

	start = chrono::high_resolution_clock::now();
	binarySearchStep(vec, 0, vec.size() - 1, a);
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>((end - start));
	cout << "One binary search step lasts " << duration.count() << " microseconds" << endl;
	long bigCase = (duration.count()*log2(100000000));
	cout << "10 to the 7th would take " << bigCase << " microseconds" << endl;


	return 0;

}