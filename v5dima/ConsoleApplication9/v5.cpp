
#include "array.h"
#include "Aeroflot.h"
void result(MyArr<Aeroflot> mas, string x);

int main()
{
	string x;
	MyArr<Aeroflot> mas;
	ifstream in("f1.txt");
	ofstream out("f2.txt");
	in >> mas;
	mas.sort(Aeroflot::compAll);
	out << mas;
	cin >> x;
	result(mas, x);
}

void result(MyArr<Aeroflot> mas, string x) {
	int fg = 1;
	for (int i = 0; i < mas.len(); i++) {
		if (x == mas[i].getT()) {
			cout << mas[i].getP() << "		" << mas[i].getN() << "\n";
			fg = 0;
		}
	}
	if (fg) {
		cout << "Not Aeroflot this type";
	}
}