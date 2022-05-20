#pragma once
template <class T>

void booble(T* arr, int n, bool (*comp)(const T&, const T&)) {
	T buf;
	int f = 1;
	while (f) {
		f = 0;
		for (int i = 0; i < n - 1; i++) {
			if (comp(arr[i],arr[i + 1])) {
				buf = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buf;
				f = 1;
			}
		}
	}
}

template <class T>
int  del(T* arr, T xin,int lg,int rg) {
	int fg = 0;
	while (rg >= lg) {
		int midle = (lg + rg) / 2;
		if (arr[midle] == xin) {
			return midle;
			/*fg = 0;
			cout << arr[midle];
			break;*/
		}
		else {
			if (arr[midle] > xin) {
				rg = midle - 1;
			}
			else {
				lg = midle + 1;
			}
		}
	}
	return -1;
}
template <class T>
void vstavki(T* arr, int n) {
	for (int i = 1; i < n;i++) {
		T b = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > b) {
			arr[j + 1] = arr[j];
			j = j - 1;
			if (j == 0)break;
		}
		arr[j + 1] = b;
	}
}
template <class T>
void shell(T* arr, int n,int t) {
	for (int s = t - 1; s > 0; s--) {
		for (int i = s; i < n; i++) {
			T b = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] >  b) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = b;
		}
	}
}
template <class T>
void vibor(T* arr, int n) {
	T b;
	int t = 0;
	for (int i = 0; i<n; i++) {
		arr[t] = arr[i];
		for (int j = i; j < n; i++) {
			if (arr[t] > arr[j]) {
				t = j;
			}
		}
		b = arr[i];
		arr[i] = arr[t];
		arr[t] = b;
	}
}

template <class T>
void Hoara(T* arr,int l, int r) {
	int i = l, j = r;
	T x = arr[l];
	T b;
	while (i <= j) {
		while (arr[i] < x && i < r) i = i + 1;
		while (arr[j] > x && j > l) j = j - 1;
		if (i <= j) {
			b = arr[i];
			arr[i] = arr[j];
			arr[j] = b;
			i = i + 1;
			j = j - 1;
		}
	}
	if (l < j) Hoara(arr, l, j); 
	if (i < r) Hoara(arr, i, r); 
}