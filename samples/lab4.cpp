#include "polynom.h"

using std::cin;
using std::cout;
using std::endl;

bool fill(Polynom& poly) // ������� false, ���� ������� �� ����� ���� ��������
{
	int num;
	cout << "\n������� ���������� ���������� � ����������: ";
	cin >> num;
	if (num < 1)
	{
		cout << "������: ��������������� ���������� �������" << endl;
		return false;
	}

	cout << "\n���������� ����������" << endl;
	double coefficient;
	int degree;

	for (int i = 0; i < num; i++)
	{
		cout << "\n������ �����������: ";
		cin >> coefficient;
		cout << endl << "������� �������: ";
		cin >> degree;
		try
		{
			poly.add_monom(coefficient, degree);
		}
		catch (const exception& except)
		{
			cout << "\n������: " << except.what() << endl;
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
	cout << "\n��������������: ";
	pol1.show();

	enum operations {
		ADD_POLYNOMIALS = 1,
		SUBTRACT_POLYNOMIALS,
		MULTIPLY_POLYNOMIALS,
		MULTIPLY_POLYNOMIAL_BY_NUMBER
	};

	int select;
	cout << "\n�������� ��������:\n" << endl;
	cout << "1 - ����������" << endl;
	cout << "2 - ���������" << endl;
	cout << "3 - ���������" << endl;
	cout << "4 - ��������� �� �����" << endl;
	cout << "\n����� ��������: ";
	cin >> select;

	switch (select)
	{
	case ADD_POLYNOMIALS:
	{
		Polynom pol2;
		if (!fill(pol2)) return 1;
		cout << "\n��������������: ";
		pol2.show();
		cout << "\n\n���������: ";
		(pol1 + pol2).show();
		break;
	}
	case SUBTRACT_POLYNOMIALS:
	{
		Polynom pol2;
		if (!fill(pol2)) return 1;
		cout << "\n��������������: ";
		pol2.show();
		cout << "\n\n���������: ";
		(pol1 - pol2).show();
		break;
	}
	case MULTIPLY_POLYNOMIALS:
	{
		Polynom pol2;
		if (!fill(pol2)) return 1;
		cout << "\n��������������: ";
		pol2.show();
		try
		{
			cout << "\n\n���������: ";
			(pol1 * pol2).show();
		}
		catch (const exception& except)
		{
			cout << "\n\n������: " << except.what() << endl;
			return 1;
		}
		break;
	}
	case MULTIPLY_POLYNOMIAL_BY_NUMBER:
	{
		double number;
		cout << "\n������� �����: ";
		cin >> number;
		cout << "\n\n���������: ";
		(pol1 * number).show();
		break;
	}
	default:
	{
		cout << "\n������: �������� ����� ��������" << endl;
		return 1;
	}
	}
	cout << endl;

	return 0;
}
