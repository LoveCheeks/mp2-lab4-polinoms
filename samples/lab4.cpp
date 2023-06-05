#include "polynom.h"

using std::cin;
using std::cout;
using std::endl;

bool fill(Polynom& poly) // вернуть false, если полином не может быть заполнен
{
	int num;
	cout << "\nВведите количество одночленов в многочлене: ";
	cin >> num;
	if (num < 1)
	{
		cout << "ОШИБКА: Неположительное количество мономов" << endl;
		return false;
	}

	cout << "\nЗаполнение многочлена" << endl;
	double coefficient;
	int degree;

	for (int i = 0; i < num; i++)
	{
		cout << "\nВедите коэффициент: ";
		cin >> coefficient;
		cout << endl << "Введите степень: ";
		cin >> degree;
		try
		{
			poly.add_monom(coefficient, degree);
		}
		catch (const exception& except)
		{
			cout << "\nОШИБКА: " << except.what() << endl;
			return false;
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Polynom pol1;
	if (!fill(pol1)) return 1;
	cout << "\nПолиномиальный: ";
	pol1.show();

	enum operations {
		ADD_POLYNOMIALS = 1,
		SUBTRACT_POLYNOMIALS,
		MULTIPLY_POLYNOMIALS,
		MULTIPLY_POLYNOMIAL_BY_NUMBER
	};

	int select;
	cout << "\nВыберите операцию:\n" << endl;
	cout << "1 - добавление" << endl;
	cout << "2 - вычитание" << endl;
	cout << "3 - умножение" << endl;
	cout << "4 - умножение на число" << endl;
	cout << "\nНомер операции: ";
	cin >> select;

	switch (select)
	{
	case ADD_POLYNOMIALS:
	{
		Polynom pol2;
		if (!fill(pol2)) return 1;
		cout << "\nПолиномиальный: ";
		pol2.show();
		cout << "\n\nРезультат: ";
		(pol1 + pol2).show();
		break;
	}
	case SUBTRACT_POLYNOMIALS:
	{
		Polynom pol2;
		if (!fill(pol2)) return 1;
		cout << "\nПолиномиальный: ";
		pol2.show();
		cout << "\n\nРезультат: ";
		(pol1 - pol2).show();
		break;
	}
	case MULTIPLY_POLYNOMIALS:
	{
		Polynom pol2;
		if (!fill(pol2)) return 1;
		cout << "\nПолиномиальный: ";
		pol2.show();
		try
		{
			cout << "\n\nРезультат: ";
			(pol1 * pol2).show();
		}
		catch (const exception& except)
		{
			cout << "\n\nОШИБКА: " << except.what() << endl;
			return 1;
		}
		break;
	}
	case MULTIPLY_POLYNOMIAL_BY_NUMBER:
	{
		double number;
		cout << "\nВведите номер: ";
		cin >> number;
		cout << "\n\nРезультат: ";
		(pol1 * number).show();
		break;
	}
	default:
	{
		cout << "\nОШИБКА: Неверный номер операции" << endl;
		return 1;
	}
	}
	cout << endl;

	return 0;
}
