# include <iostream>
# include <cmath>
# include <stdlib.h>
# include <ctime>
# include <vector>
# include <string>

# define MINUS -1
# define PLUS 1
# define MAX_ITER 10
# define Sqr(X) X*X

using namespace std;

class Longint
{
private:
	vector<int> digits;
	int sign;
public:
	Longint(char* str);
	Longint();
	Longint(const  Longint& x);
	~Longint();
	friend ostream& operator<< (ostream& stream, const Longint&);
	friend istream& operator >> (istream& stream, Longint&);
	Longint& operator= (const Longint&);
	Longint& operator= (char* s);
	Longint operator* (const Longint&);
	Longint operator* (const int&);
	Longint operator+ (const Longint&);
	Longint operator+ (const int&);
	Longint operator- (const Longint&);
	Longint operator- (const int&);
	Longint operator/ (const Longint&);
	Longint operator/ (const int&);
	Longint operator% (const Longint&);
	Longint operator% (const int&);
	bool operator <(const Longint&);
	bool operator <=(const Longint&);
	bool operator > (const Longint&);
	bool operator >=(const Longint&);
	bool operator ==(const Longint&);
	bool lessAbsVal(const Longint&);
	int getSize() // возвращает количество цифр
	{
		return digits.size();
	}
	Longint symbJacobi(Longint);
	Longint gcd(Longint); // наибольший общий делитель
	Longint exp_mod(const Longint&, const Longint&);
	Longint convertDecBi(); // преобразует с 10 в двоичную
	Longint convertBiDec(); // с 2-чной в 10-чную
	Longint exp(const Longint&);
	void normalize();
	void pbZero(int); // ставит 0 в конце числа
	void delBackZero(); // удаляет 0 в конце числа
	void printInverse(const int&);
	Longint Karatsuba(const Longint&);
	Longint KaratsubaRecur(const Longint&, int);
	Longint ToomCook(const Longint&);
	Longint ShonhageStrassen(const Longint&);
	Longint CookInverse();
	Longint CookDiv(const Longint&, const int&);
	bool Lehmann();
	bool RabinMiller();
	bool SolovayStrassen();
};
//--------------------------------------------------------------------------------------------

int choice();
void interface();
void Commands();
void FFT(vector <double>&, bool inverse);

//---------------------------------------------------------------------------------------------

void Commands()
{
	cout << "Оберiть один з методiв, наведених нижче" << endl;
	cout << "Для виходу з програми введiть 0" << endl;
	cout << "1. Карацуби" << '\n';
	cout << "2. Тоом-Кук" << '\n';
	cout << "3. Шенхаге" << '\n';
	cout << "4. Штрассена" << '\n';
	cout << "5. Аглоритм Кука для знаходження оберненого числа " << '\n';
	cout << "6. Дiлення Кука" << '\n';
	cout << "7. Простота Лемана" << '\n';
	cout << "8. Простота Рабiна Мiллера" << '\n';
	cout << "9. Простота Соловея Штрассена" << '\n';
	cout << "10. Простота Агравала" << '\n';
	cout << endl;
}

void interface()
{
	int f = choice();
	double start = 0, end = 0, time = 0;
	while (f != 0)
	{
		switch (f)
		{
		case 1:
		{
			cout << "Множення Карацуби" << endl;
			cout << "Введiть х : ";
			Longint* x = new Longint;
			cin >> *x;
			cout << "Введiть y : ";
			Longint* y = new Longint;
			cin >> *y;
			Longint t;
			start = clock();
			t = (*x).Karatsuba((*y));
			end = clock();
			cout << t;
			time = (end - start) / CLOCKS_PER_SEC;
			cout << "Running time: " << time << endl;
			delete x;
			delete y;
			break;
		}
		case 2:
		{
			cout << "Множення Тоома-Кука " << endl;
			cout << "Введiть х : ";
			Longint* x = new Longint;
			cin >> *x;
			cout << "Введiть y : ";
			Longint* y = new Longint;
			cin >> *y;
			Longint t;
			start = clock();
			t = (*x).ToomCook((*y));
			end = clock();
			cout << t;
			time = (end - start) / CLOCKS_PER_SEC;
			cout << "Running time: " << time << endl;
			delete x;
			delete y;
			break;
		}
		case 3:
		{
			cout << "Не працює" << endl;
			break;
		}
		case 4:
		{
			cout << "Множення Штрассена" << endl;
			cout << "Введiть х : ";
			Longint* x = new Longint;
			cin >> *x;
			cout << "Введiть y : ";
			Longint* y = new Longint;
			cin >> *y;
			Longint t;
			start = clock();
			t = (*x).ShonhageStrassen(*y);
			end = clock();
			cout << t;
			time = (end - start) / CLOCKS_PER_SEC;
			cout << "Running time: " << time << endl;
			delete x;
			delete y;
			break;
		}
		case 5:
		{
			cout << "Алгоритм Кука для оберненої величини" << endl;
			cout << "Введiть х : ";
			Longint* x = new Longint;
			cin >> *x;
			Longint t;
			start = clock();
			t = (*x).CookInverse();
			end = clock();
			t.printInverse((*x).getSize());
			time = (end - start) / CLOCKS_PER_SEC;
			cout << "Running time: " << time << endl;
			delete x;
			break;
		}
		case 6:
		{
			cout << "Множення Кука" << endl;
			cout << "Введiть х : ";
			Longint* x = new Longint;
			cin >> *x;
			cout << "Введiть y : ";
			Longint* y = new Longint;
			cin >> *y;
			Longint t, p;
			start = clock();
			t = (*y).CookInverse();
			p = (*x).CookDiv(t, (*y).getSize());
			end = clock();
			cout << p;
			time = (end - start) / CLOCKS_PER_SEC;
			cout << "Running time: " << time << endl;
			delete x;
			delete y;
			break;
		}
		case 7:
		{
			cout << "Простота Лемана" << endl;
			cout << "Введiть х : ";
			Longint* x = new Longint;
			cin >> *x;
			int d;
			start = clock();
			d = (*x).Lehmann();
			end = clock();
			cout << d << endl;
			time = (end - start) / CLOCKS_PER_SEC;
			cout << "Running time " << time << endl;
			delete x;
			break;
		}
		case 8:
		{
			cout << "Простота Рабiна-Мiллера" << endl;
			cout << "Введiть х : ";
			Longint* x = new Longint;
			cin >> *x;
			int d;
			start = clock();
			d = (*x).RabinMiller();
			end = clock();
			cout << d << endl;
			time = (end - start) / CLOCKS_PER_SEC;
			cout << "Running time: " << time << endl;
			delete x;
			break;
		}
		case 9:
		{
			cout << "Простота Соловея-Штрассена" << endl;
			cout << "Введiть х : ";
			Longint* x = new Longint;
			cin >> *x;
			int d;
			start = clock();
			d = (*x).SolovayStrassen();
			end = clock();
			cout << d << endl;
			time = (end - start) / CLOCKS_PER_SEC;
			cout << "Running time: " << time << endl;
			delete x;
			break;
		}
		case 10:
		{
			cout << "Не працює" << endl;
		}
		}
		f = choice();
	}
}

int choice()
{
	int command;
	cout << "Виберiть метод : ";
	cin >> command;
	while ((command > 11) || (command < 0))
	{
		cout << "Введiть число вiд 0-10" << endl;
		cin >> command;
	}
	return command;
}

Longint::Longint(char* str)
{
	sign = PLUS;
	if (str[0] == '-')
		sign = MINUS;
	if (str[0] == '-' || str[0] == '+')
		str++;
	int len = strlen(str);
	for (int i = len - 1; i >= 0; i--)
		digits.push_back(str[i] - '0');
}

Longint::Longint()
{
	sign = PLUS;
}

Longint::Longint(const  Longint& x)
{
	digits = x.digits;
	sign = x.sign;
}

Longint::~Longint()
{
}

ostream& operator<< (ostream& stream, const Longint& x) {
	int i = 0;
	if (x.sign == MINUS)
		stream << '-';
	for (i = x.digits.size() - 1; i > 0; i--) {
		if (x.digits[i] != 0) break;
	}
	for (; i >= 0; i--) {
		stream << x.digits[i];
	}
	stream << endl;
	return stream;
}

istream& operator >> (istream& stream, Longint& x) {
	string str;
	stream >> str;
	if (x.digits.size() != 0) x.digits.clear();
	if (str[0] == '-') {
		x.sign = MINUS;
	}
	while (str[0] == '+' || str[0] == '-') str = str.substr(1);
	int len = str.length();
	for (int i = len - 1; i >= 0; i--) {
		x.digits.push_back(str[i] - '0');
	}
	return stream;
}

Longint& Longint:: operator= (char* s) {
	string str = s;
	if (digits.size() != 0) digits.clear();
	sign = PLUS;
	if (str[0] == '-') {
		sign = MINUS;
	}
	while (str[0] == '+' || str[0] == '-') str = str.substr(1);
	int len = str.length();
	for (int i = len - 1; i >= 0; i--) {
		digits.push_back(str[i] - '0');
	}
	return (*this);
}

Longint& Longint::operator = (const Longint& p) {
	if (this == &p) return (*this);
	digits = p.digits;
	sign = p.sign;
	return (*this);
}

Longint Longint::operator + (const Longint& p) {
	Longint res, t1 = (*this), t2 = p;
	res.sign = 1;
	if (t1.sign == -1 && t2.sign == -1) res.sign = -res.sign;
	if (t1.sign == 1 && t2.sign == -1) {
		if (t1.lessAbsVal(t2)) {
			res.sign = -res.sign;
			for (long f = 0; f < t1.digits.size(); f++)
				t1.digits[f] = -t1.digits[f];
		}
		else {
			for (long f = 0; f < t2.digits.size(); f++)
				t2.digits[f] = -t2.digits[f];
		}
	}
	if (t1.sign == -1 && t2.sign == 1) {
		if (t2.lessAbsVal(t1)) {
			res.sign = -res.sign;
			for (long f = 0; f < t2.digits.size(); f++)
				t2.digits[f] = -t2.digits[f];
		}
		else {
			for (long f1 = 0; f1 < t1.digits.size(); f1++)
				t1.digits[f1] = -t1.digits[f1];
		}
	}
	int m = (t1.digits.size() > t2.digits.size()) ? t1.digits.size() : t2.digits.size();
	int d = 4 * m;
	for (long k = 0; k < d; k++) res.digits.push_back(0);
	for (long i = 0; i < t1.digits.size(); i++) {
		res.digits[i] += t1.digits[i];
	}
	for (long h = 0; h < t2.digits.size(); h++) {
		res.digits[h] += t2.digits[h];
	}
	res.normalize();
	return res;
}

Longint Longint::operator+ (const int& y) {
	Longint res = (*this);
	res.digits[0] += y;
	res.normalize();
	return res;
}

Longint Longint::operator * (const Longint& p) {
	Longint res;
	res.sign = PLUS;
	if ((sign == -1 || p.sign == -1) && (!(sign == -1 && p.sign == -1))) res.sign = -1;
	int m = (digits.size() > p.digits.size()) ? digits.size() : p.digits.size();
	int d = 4 * m;
	for (long k = 0; k < d; k++) res.digits.push_back(0);
	for (long i = 0; i < digits.size(); i++) {
		for (long j = 0; j < p.digits.size(); j++)
			res.digits[i + j] += digits[i] * p.digits[j];
	}
	res.normalize();
	return res;
}

Longint Longint::operator *(const int& d) {
	Longint res;
	res.sign = 1;
	if ((sign == -1 || d < 0) && (!(sign == -1 && d < 0))) res.sign = -1;
	int len = digits.size() + 10;
	for (long k = 0; k < len; k++) res.digits.push_back(0);
	for (long i = 0; i < digits.size(); i++)
		res.digits[i] = digits[i] * d;
	res.normalize();
	return res;
}

Longint Longint::operator /(const Longint& y) {
	Longint res, ost, p = y;
	if ((sign == -1 || p.sign == -1) && (!(sign == -1 && p.sign == -1))) res.sign = -1;
	int max = (digits.size() > p.digits.size()) ? digits.size() : p.digits.size();
	for (long k = 0; k < 2 * max; k++) res.digits.push_back(0);
	int n = digits.size();
	int m = p.digits.size();
	int wer = 0;
	for (int i = n - 1; i >= 0; i--) {
		ost.digits.push_back(0);
		for (int j = ost.digits.size() - 2; j >= 0; j--)
			ost.digits[j + 1] = ost.digits[j];
		ost.digits[0] = digits[i];
		wer = 0;
		while (p <= ost) {
			ost = ost - p;
			ost.delBackZero();
			wer++;
		}
		res.digits[i] = wer;
	}
	normalize();
	return res;
}

Longint Longint::operator /(const int& y) {
	int t = y, r;
	Longint p;
	p.sign = 1;
	if (t < 0) { p.sign = -1; t = -t; }
	while (t) {
		r = t % 10;
		t = t / 10;
		p.digits.push_back(r);
	}
	p.digits.push_back(t);
	return (*this) / p;
}

Longint Longint::operator% (const Longint& p) {
	Longint t = p;
	Longint rez1, res;
	rez1 = (*this) / t;
	res = (*this) - t * rez1;
	return res;
}

Longint Longint::operator% (const int& y) {
	int t = y, r;
	Longint p;
	p.sign = 1;
	if (t < 0) { p.sign = -1; t = -t; }
	while (t) {
		r = t % 10;
		t = t / 10;
		p.digits.push_back(r);
	}
	p.digits.push_back(t);
	return (*this) % p;
}

bool Longint::operator >=(const Longint& p) {
	if (!((*this) < p)) return 1;
	else return 0;

}

bool Longint::operator <=(const Longint& t) {
	Longint p = t;
	p.delBackZero();
	(*this).delBackZero();
	if (sign == -1 && p.sign == 1) return true;
	if (sign == 1 && p.sign == -1) return false;
	if (digits.size() < p.digits.size() && sign == 1 && p.sign == 1) return true;
	if (digits.size() > p.digits.size() && sign == -1 && p.sign == -1) return true;
	if (digits.size() > p.digits.size() && sign == 1 && p.sign == 1) return false;
	if (digits.size() < p.digits.size() && sign == -1 && p.sign == -1) return false;
	int i = digits.size() - 1;
	int j = p.digits.size() - 1;
	while (digits[i] == p.digits[j] && i > 0 && j > 0) {
		i--;
		j--;
	}
	if (i >= 0 && digits[i] > p.digits[j] && sign == 1 && p.sign == 1)   return false;    // >
	if (i >= 0 && digits[i] < p.digits[j] && sign == 1 && p.sign == 1)   return true;  // <
	if (i >= 0 && digits[i] > p.digits[j] && sign == -1 && p.sign == -1)   return true;    // >
	if (i >= 0 && digits[i] < p.digits[j] && sign == -1 && p.sign == -1)   return false;  // <
	return true;
}

bool Longint::operator ==(const Longint& t) {
	Longint p = t;
	p.delBackZero();
	(*this).delBackZero();
	int i = digits.size() - 1;
	int j = p.digits.size() - 1;
	while (digits[i] == p.digits[j] && i > 0 && j > 0) {
		i--;
		j--;
	}
	if (i == 0 && j == 0 && digits[i] == p.digits[j] && sign == p.sign) return true;
	return false;
}

bool Longint::operator <(const Longint& t) {
	Longint p = t;
	p.delBackZero();
	(*this).delBackZero();
	if (sign == -1 && p.sign == 1) return true;
	if (sign == 1 && p.sign == -1) return false;
	if (digits.size() < p.digits.size() && sign == 1 && p.sign == 1) return true;
	if (digits.size() > p.digits.size() && sign == -1 && p.sign == -1) return true;
	if (digits.size() > p.digits.size() && sign == 1 && p.sign == 1) return false;
	if (digits.size() < p.digits.size() && sign == -1 && p.sign == -1) return false;
	int i = digits.size() - 1;
	int j = p.digits.size() - 1;
	while (digits[i] == p.digits[j] && i > 0 && j > 0) {
		i--;
		j--;
	}
	if (i >= 0 && digits[i] > p.digits[j] && sign == 1 && p.sign == 1)   return false;    // >
	if (i >= 0 && digits[i] < p.digits[j] && sign == 1 && p.sign == 1)   return true;  // <
	if (i >= 0 && digits[i] > p.digits[j] && sign == -1 && p.sign == -1)   return true;    // >
	if (i >= 0 && digits[i] < p.digits[j] && sign == -1 && p.sign == -1)   return false;  // <
	return false;
}

bool Longint:: operator > (const Longint& x) {
	return (!((*this) <= x));
}

bool Longint::lessAbsVal(const Longint& t) {
	Longint p = t;
	p.delBackZero();
	(*this).delBackZero();
	if (digits.size() < p.digits.size()) return true;
	if (digits.size() > p.digits.size()) return false;
	int i = digits.size() - 1, j = p.digits.size() - 1;
	while (digits[i] == p.digits[j] && i > 0 && j > 0) {
		i--;
		j--;
	}
	if (i >= 0 && digits[i] > p.digits[j])   return false;    // >
	if (i >= 0 && digits[i] < p.digits[j])   return true;  // <
	return false;
}

Longint Longint::operator - (const Longint& p) {
	Longint res, t = p;
	t.sign = -p.sign;
	res = (*this) + t;
	res.normalize();
	return res;
}

Longint Longint::operator - (const int& y) {
	int t = y, r;
	Longint p;
	p.sign = 1;
	if (t < 0) { p.sign = -1; t = -t; }
	while (t) {
		r = t % 10;
		t = t / 10;
		p.digits.push_back(r);
	}
	p.digits.push_back(t);
	return (*this) - p;
}

void Longint::pbZero(int d) // 0 в кінці
{
	while (digits.size() < d)
		digits.push_back(0);
}

void Longint::delBackZero() // видалити 0 в кінці
{
	while (digits.size() > 1 && digits[digits.size() - 1] == 0)
		digits.pop_back();
}

void Longint::printInverse(const int& ne)
{
	int i;
	if (sign == MINUS)
		cout << '-';
	cout << 0 << ".";
	(*this).delBackZero();
	for (int j = 2; j < ne; j++)
		cout << 0;
	for (i = digits.size() - 1; i > 0; i--)	if (digits[i] != 0) break;
	for (; i >= 0; i--) cout << digits[i];
	cout << endl;
}

Longint Longint::exp_mod(const Longint& y, const Longint& n) {
	Longint s, t = (*this), u = y, f, m = n;
	t.delBackZero();
	u.delBackZero();
	m.delBackZero();
	s.digits.push_back(1);
	Longint h;
	h.digits.push_back(0);
	while (!(u == h)) {
		f = u % 2;
		f.delBackZero();
		if (f.digits[0] == 1) {
			s = s * t;
			s.delBackZero();
			s = s % m;
			s.delBackZero();
		}
		u = u / 2;
		u.delBackZero();
		t = (t * t) % m;
		t.delBackZero();
	}
	s.delBackZero();
	s.normalize();
	s.sign = (*this).sign;
	return s;
}

Longint Longint::exp(const Longint& y) {
	Longint s, t = (*this), u = y, f;
	t.delBackZero();
	u.delBackZero();
	s.digits.push_back(1);
	Longint h;
	h.digits.push_back(0);
	while (!(u == h)) {
		f = u % 2;
		f.delBackZero();
		if (f.digits[0] == 1) {
			s = s * t;
			s.delBackZero();
			s = s;
			s.delBackZero();
		}
		u = u / 2;
		u.delBackZero();
		t = (t * t);
		t.delBackZero();
	}
	s.delBackZero();
	s.normalize();
	s.sign = (*this).sign;
	return s;
}

Longint Longint::convertDecBi()
{
	Longint res, t;
	int d = 4 * digits.size();
	t = (*this);
	t.delBackZero();
	for (long k = 0; k < d; k++) res.digits.push_back(0);
	Longint r;
	int i = 0;
	while (1) {
		if ((t.digits[0] == 0 && t.digits.size() == 1) || (t.digits[0] == 1 && t.digits.size() == 1)) { res.digits[i] = t.digits[0]; i++; break; }
		r = t % 2;
		r.delBackZero();
		t = t / 2;
		t.delBackZero();
		res.digits[i] = r.digits[0];
		i++;
	}
	return res;
}

Longint Longint::convertBiDec() {
	Longint res, t;
	int d = 4 * digits.size();
	t = (*this);
	t.delBackZero();
	for (long k = 0; k < d; k++) res.digits.push_back(0);
	for (int i = 0; i < t.digits.size(); i++) {
		res.digits[0] += t.digits[i] * (int)pow((double)2, (double)i);
	}
	res.normalize();
	res.delBackZero();
	return res;
}

Longint Longint::gcd(Longint p) {
	Longint a, b, res, h;
	h.digits.push_back(0);
	a = (*this);
	b = p;
	a.delBackZero();
	b.delBackZero();
	if (a.sign == -1) a.sign = 1;
	if (b.sign == -1) b.sign = 1;
	if (a + b == h) {
		cout << "GCD error." << endl;
		return h;
	}
	res = b;
	while (h < a) {
		res = a;
		a = b % a;
		a.delBackZero();
		b = res;
	}
	res.delBackZero();
	return res;
}



Longint Longint::symbJacobi(Longint n) {
	Longint res, b, h, v, n1, tr, pj, se, a1, m;
	(*this).delBackZero();
	n.delBackZero();
	h.digits.push_back(0);
	res.digits.push_back(0);
	v.digits.push_back(1);
	b = (*this);
	Longint e;
	e.digits.push_back(0);
	tr.digits.push_back(3);
	pj.digits.push_back(5);
	se.digits.push_back(7);
	if ((*this) == h) return h;
	if ((*this) == v) return v;
	while ((b % 2) == h) {
		b = b / 2;
		b.delBackZero();
		e = e + v;
		e.delBackZero();
	}
	a1 = b;
	m = n % 8;	m.delBackZero();
	if ((e % 2) == h) res = v;
	else if (m == v || m == se) { res = v; res.sign = PLUS; }
	else if (m == tr || m == pj) { res = v; res.sign = MINUS; }
	if (((n % 4) == tr) && ((a1 % 4) == tr)) res.sign = -res.sign;
	if (!(a1 == v)) { n1 = n % a1; n1.delBackZero(); }
	else n1 = v;
	return res * n1.symbJacobi(a1);
}

void Longint::normalize() {
	int c = 0, i;
	for (i = 0; i < digits.size(); i++) {
		digits[i] += c;
		if (digits[i] < 0) {
			c = -(-(digits[i] + 1) / 10 + 1);
		}
		else {
			c = digits[i] / 10;
		}
		digits[i] -= c * 10;
	}
	if (c != 0) {
		cout << "Normalization error." << endl;
	}
}
//------------------------------------------------------------------------------------
Longint Longint::Karatsuba(const Longint& p) {
	Longint res, t = p;
	int m = (digits.size() > t.digits.size()) ? digits.size() : t.digits.size();
	int d;
	for (d = 1; d < m; d *= 2);
	int len = 5 * d;
	for (long k = 0; k < len; k++)
	{
		res.digits.push_back(0);
	}
	t.pbZero(d);
	(*this).pbZero(d);
	res = KaratsubaRecur(t, d);
	res.sign = 1;
	if ((sign == -1 || t.sign == -1) && (!(sign == -1 && t.sign == -1))) res.sign = -1;
	res.normalize();
	return res;
}

Longint Longint::KaratsubaRecur(const Longint& p, int d)
{
	Longint res, t = p;
	if (d <= 4) return (*this) * p;
	for (long k = 0; k < 5 * d; k++) res.digits.push_back(0);
	Longint t11, t12, t21, t22, x1, x3, x1s, x2s, x2;
	int d1 = d / 2;
	for (long k1 = 0; k1 < d1; k1++) t11.digits.push_back(digits[k1]);
	for (long k2 = d1; k2 < d; k2++) t12.digits.push_back(digits[k2]);
	for (long k3 = 0; k3 < d1; k3++) t21.digits.push_back(t.digits[k3]);
	for (long k4 = d1; k4 < d; k4++) t22.digits.push_back(t.digits[k4]);
	int i;
	for (long z2 = 0; z2 < d1; z2++)
	{
		x1s.digits.push_back(0);
		x2s.digits.push_back(0);
	}
	for (long z1 = 0; z1 < d1; z1++)
	{
		x1s.digits[z1] = t11.digits[z1] + t12.digits[z1];
		x2s.digits[z1] = t21.digits[z1] + t22.digits[z1];
	}
	x1 = t11.KaratsubaRecur(t21, d1);
	x2 = t12.KaratsubaRecur(t22, d1);
	x3 = (x1s).KaratsubaRecur(x2s, d1);
	for (long z = 0; z < 2 * d; z++) x3.digits[z] = x3.digits[z] - x1.digits[z] - x2.digits[z];
	for (i = 0; i < 2 * d; i++)	res.digits[i] += x1.digits[i];
	for (i = 0; i < 2 * d; i++)	res.digits[i + d] += x2.digits[i];
	for (i = 0; i < 2 * d; i++)	res.digits[i + d / 2] += x3.digits[i];
	return res;
}
//------------------------------------------------------------------------------------------------------
Longint Longint::ToomCook(const Longint& p) {
	Longint res, t = p;
	t.delBackZero();
	(*this).delBackZero();
	int m = (digits.size() > t.digits.size()) ? digits.size() : t.digits.size();
	int len = 4 * m;
	int mnew;
	for (long k = 0; k < len; k++) res.digits.push_back(0);
	if (m % 3 == 0) {
		mnew = m / 3;
		(*this).pbZero(m);
		t.pbZero(m);

	}
	else if (m % 3 == 1) {
		mnew = (m + 2) / 3;
		(*this).pbZero(m + 2);
		t.pbZero(m + 2);

	}
	else {
		mnew = (m + 1) / 3;
		(*this).pbZero(m + 1);
		t.pbZero(m + 1);

	}
	if (mnew <= 4) return (*this) * t;

	Longint m2, m1, m0, n2, n1, n0;

	for (long k1 = 0; k1 < mnew; k1++) m0.digits.push_back(digits[k1]);
	for (long k2 = mnew; k2 < mnew * 2; k2++) m1.digits.push_back(digits[k2]);
	for (long k3 = mnew * 2; k3 < mnew * 3; k3++) m2.digits.push_back(digits[k3]);

	for (long k4 = 0; k4 < mnew; k4++) n0.digits.push_back(t.digits[k4]);
	for (long k5 = mnew; k5 < mnew * 2; k5++) n1.digits.push_back(t.digits[k5]);
	for (long k6 = mnew * 2; k6 < mnew * 3; k6++) n2.digits.push_back(t.digits[k6]);

	Longint p0, p1, p_1, p_2, p_, q0, q1, q_1, q_2, q_, r0, r1, r_1, r_2, r_;
	p0 = m0 + m2;
	p0.delBackZero();
	p_1 = p0 - m1;
	p_1.delBackZero();
	p1 = p0 + m1;
	p1.delBackZero();
	p_2 = (p_1 + m2) * 2 - m0;
	p_2.delBackZero();
	p0 = m0;
	p0.delBackZero();
	p_ = m2;
	p_.delBackZero();

	q0 = n0 + n2;
	q0.delBackZero();
	q_1 = q0 - n1;
	q_1.delBackZero();
	q1 = q0 + n1;
	q1.delBackZero();
	q_2 = (q_1 + n2) * 2 - n0;
	q_2.delBackZero();
	q0 = n0;
	q0.delBackZero();
	q_ = n2;
	q_.delBackZero();

	r0 = p0.ToomCook(q0);
	r0.delBackZero();
	r1 = p1.ToomCook(q1);
	r1.delBackZero();
	r_1 = p_1.ToomCook(q_1);
	r_1.delBackZero();
	r_2 = p_2.ToomCook(q_2);
	r_2.delBackZero();
	r_ = p_.ToomCook(q_);
	r_.delBackZero();

	Longint rv0, rv1, rv2, rv3, rv4;
	rv0 = r0;
	rv0.delBackZero();
	rv4 = r_;
	rv4.delBackZero();
	rv3 = (r_2 - r1) / 3;
	rv4.delBackZero();
	rv1 = (r1 - r_1) / 2;
	rv1.delBackZero();
	rv2 = r_1 - r0;
	rv2.delBackZero();
	rv3 = (rv2 - rv3) / 2 + r_ * 2;
	rv3.delBackZero();
	rv2 = rv2 + rv1 - r_;
	rv2.delBackZero();
	rv1 = rv1 - rv3;
	rv1.delBackZero();

	for (long i0 = 0; i0 < rv0.digits.size(); i0++) res.digits[i0] += rv0.digits[i0];
	for (long i1 = 0; i1 < rv1.digits.size(); i1++) res.digits[i1 + mnew] += rv1.digits[i1];
	for (long i2 = 0; i2 < rv2.digits.size(); i2++) res.digits[i2 + 2 * mnew] += rv2.digits[i2];
	for (long i3 = 0; i3 < rv3.digits.size(); i3++) res.digits[i3 + 3 * mnew] += rv3.digits[i3];
	for (long i4 = 0; i4 < rv4.digits.size(); i4++) res.digits[i4 + 4 * mnew] += rv4.digits[i4];

	if ((sign == -1 || t.sign == -1) && (!(sign == -1 && t.sign == -1))) res.sign = -1;
	res.normalize();
	return res;
}

void FFT(vector <double>& a, bool inverse) {
	const double pi = 3.14159265358979323846;
	double twr, twi, twpr, twpi, twtemp, ttheta,
		c1, c2, h1r, h1i, h2r, h2i, wrs, wis,
		wtemp, wr, wpr, wpi, wi, theta, tempr, tempi;
	int i, i1, i2, i3, i4, nn, ii, jj, n, mmax, m, j, istep, isign;

	if (a.size() == 1)return;

	if (!inverse) {
		ttheta = 2 * pi / a.size();
		c1 = 0.5;
		c2 = -0.5;
	}
	else {
		ttheta = 2 * pi / a.size();
		c1 = 0.5;
		c2 = 0.5;
		ttheta = -ttheta;
		twpr = -2.0 * Sqr(sin(0.5 * ttheta));
		twpi = sin(ttheta);
		twr = 1.0 + twpr;
		twi = twpi;
		for (i = 2; i <= a.size() / 4 + 1; i++) {
			i1 = i + i - 2;
			i2 = i1 + 1;
			i3 = a.size() + 1 - i2;
			i4 = i3 + 1;
			wrs = twr;
			wis = twi;
			h1r = c1 * (a[i1] + a[i3]);
			h1i = c1 * (a[i2] - a[i4]);
			h2r = -c2 * (a[i2] + a[i4]);
			h2i = c2 * (a[i1] - a[i3]);
			a[i1] = h1r + wrs * h2r - wis * h2i;
			a[i2] = h1i + wrs * h2i + wis * h2r;
			a[i3] = h1r - wrs * h2r + wis * h2i;
			a[i4] = -h1i + wrs * h2i + wis * h2r;
			twtemp = twr;
			twr = twr * twpr - twi * twpi + twr;
			twi = twi * twpr + twtemp * twpi + twi;
		}
		h1r = a[0];
		a[0] = c1 * (h1r + a[1]);
		a[1] = c1 * (h1r - a[1]);
	}
	isign = inverse ? -1 : +1;

	n = a.size();
	nn = a.size() / 2;
	j = 1;
	for (ii = 1; ii <= nn; ii++) {
		i = 2 * ii - 1;
		if (j > i) {
			tempr = a[j - 1];
			tempi = a[j];
			a[j - 1] = a[i - 1];
			a[j] = a[i];
			a[i - 1] = tempr;
			a[i] = tempi;
		}
		m = n / 2;
		while (m >= 2 && j > m) {
			j = j - m;
			m = m / 2;
		}
		j = j + m;
	}
	mmax = 2;
	while (n > mmax) {
		istep = 2 * mmax;
		theta = 2 * pi / (isign * mmax);
		wpr = -2.0 * Sqr(sin(0.5 * theta));
		wpi = sin(theta);
		wr = 1.0;
		wi = 0.0;
		for (ii = 1; ii <= mmax / 2; ii++) {
			m = 2 * ii - 1;
			for (jj = 0; jj <= (n - m) / istep; jj++) {
				i = m + jj * istep;
				j = i + mmax;
				tempr = wr * a[j - 1] - wi * a[j];
				tempi = wr * a[j] + wi * a[j - 1];
				a[j - 1] = a[i - 1] - tempr;
				a[j] = a[i] - tempi;
				a[i - 1] = a[i - 1] + tempr;
				a[i] = a[i] + tempi;
			}
			wtemp = wr;
			wr = wr * wpr - wi * wpi + wr;
			wi = wi * wpr + wtemp * wpi + wi;
		}
		mmax = istep;
	}
	if (inverse) {
		for (i = 1; i <= 2 * nn; i++) {
			a[i - 1] = a[i - 1] / nn;
		}
	}
	else {
		twpr = -2.0 * Sqr(sin(0.5 * ttheta));
		twpi = sin(ttheta);
		twr = 1.0 + twpr;
		twi = twpi;
		for (i = 2; i <= a.size() / 4 + 1; i++) {
			i1 = i + i - 2;
			i2 = i1 + 1;
			i3 = a.size() + 1 - i2;
			i4 = i3 + 1;
			wrs = twr;
			wis = twi;
			h1r = c1 * (a[i1] + a[i3]);
			h1i = c1 * (a[i2] - a[i4]);
			h2r = -c2 * (a[i2] + a[i4]);
			h2i = c2 * (a[i1] - a[i3]);
			a[i1] = h1r + wrs * h2r - wis * h2i;
			a[i2] = h1i + wrs * h2i + wis * h2r;
			a[i3] = h1r - wrs * h2r + wis * h2i;
			a[i4] = -h1i + wrs * h2i + wis * h2r;
			twtemp = twr;
			twr = twr * twpr - twi * twpi + twr;
			twi = twi * twpr + twtemp * twpi + twi;
		}
		h1r = a[0];
		a[0] = h1r + a[1];
		a[1] = h1r - a[1];
	}
}
//------------------------------------------------------------------------------------

Longint Longint::ShonhageStrassen(const Longint& p) {                            //////////////////////////////////////4
	Longint res, t = p;
	t.delBackZero();
	(*this).delBackZero();
	int m = (digits.size() > t.digits.size()) ? digits.size() : t.digits.size();
	int len = 4 * m;
	for (long k = 0; k < len; k++) res.digits.push_back(0);
	int dov = digits.size() + t.digits.size();
	int z = 2;
	while (z < dov) z *= 2;
	dov = z;
	vector <double> X, Y;
	for (int i = 0; i < digits.size(); i++)
		X.push_back(digits[i]);
	for (int j = X.size(); j < dov; j++)
		X.push_back(0);
	for (int i1 = 0; i1 < t.digits.size(); i1++)
		Y.push_back(t.digits[i1]);
	for (int j1 = Y.size(); j1 < dov; j1++)
		Y.push_back(0);

	FFT(X, 0);
	FFT(Y, 0);
	X[0] *= Y[0];
	X[1] *= Y[1];
	double a0, a1;
	for (int i = 2; i < dov; i += 2) {
		a0 = X[i];
		a1 = X[i + 1];
		X[i] = a0 * Y[i] - a1 * Y[i + 1];
		X[i + 1] = a1 * Y[i] + a0 * Y[i + 1];
	}

	FFT(X, 1);
	int d = digits.size() + t.digits.size();
	int per = 0;
	for (int i = 0; i < d; i++) {
		per += (int)(X[i] + 0.5);
		res.digits[i] = per % 10;
		per = per / 10;
	}

	res.sign = 1;
	if ((sign == -1 || t.sign == -1) && (!(sign == -1 && t.sign == -1))) res.sign = -1;
	res.normalize();
	return res;
}
//------------------------------------------------------------------------------------
bool Longint::Lehmann() {
	Longint p = (*this);
	p.delBackZero();
	Longint a, res;
	int k = 0;
	int x = 0;
	Longint h;
	h.digits.push_back(0);
	a.digits.push_back(0);
	Longint j = (p - 1) / 2;
	j.delBackZero();
	Longint v;
	v.digits.push_back(1);
	for (int t = 0; t < MAX_ITER; t++) {
		while (x == 0) x = rand() % 2 * p.digits.size();
		for (int i = 0; i < x; i++)
			a.digits.push_back(rand() % 10);
		h.sign = a.sign;
		a = a % p;
		int temp = 0;
		while (a == h) {
			while (x == 0) x = rand() % 2 * p.digits.size();
			for (int i = 0; i < x; i++)
				a.digits.push_back(rand() % 10);
			h.sign = a.sign;
			a = a % p;
			temp++;
			if (temp == 10) a.digits[0] = 1;
		}
		a.delBackZero();
		res = a.exp_mod(j, p);
		res.delBackZero();
		if (res == v) {
			k++;
		}
		else
			if (res == p - 1) {
				k--;
			}
			else return false;
		a.digits.clear();
		x = 0;
	}
	if (k == MAX_ITER) return false;
	return true;
}
//------------------------------------------------------------------------------------
bool Longint::RabinMiller() {
	Longint p = (*this);
	p.delBackZero();
	Longint a, res;
	int k = 0;
	int x = 0;
	Longint h;
	h.digits.push_back(0);
	a.digits.push_back(0);
	Longint j = p - 1;
	j.delBackZero();
	Longint v;
	v.digits.push_back(1);
	Longint b;
	bool flag;
	Longint d;
	d.digits.push_back(2);
	while ((j % 2) == h) j = j / 2;

	for (int t = 0; t < MAX_ITER; t++) {
		flag = 1;
		while (x == 0) x = rand() % 2 * p.digits.size();
		for (int i = 0; i < x; i++)
			a.digits.push_back(rand() % 10);
		h.sign = a.sign;
		a = a % p;
		int temp = 0;
		while (a == h) {
			while (x == 0) x = rand() % 2 * p.digits.size();
			for (int i = 0; i < x; i++)
				a.digits.push_back(rand() % 10);
			h.sign = a.sign;
			a = a % p;
			temp++;
			if (temp == 10) a.digits[0] = 1;
		}
		a.delBackZero();

		res = a.exp_mod(p - 1, p);
		res.delBackZero();
		if (!(res == v)) return false;
		a = a.exp_mod(j, p);
		if (!(a == v)) {
			while ((!(a == v)) && (!(a == (p - 1)))) a = a.exp_mod(d, p);
			if (a == v) return false;
		}
	}
	return flag;
}
//------------------------------------------------------------------------------------
bool Longint::SolovayStrassen() {
	Longint p = (*this);
	p.delBackZero();
	Longint a, res, j, jac;
	int x = 0;
	Longint h, v1;
	h.digits.push_back(0);
	a.digits.push_back(0);
	Longint v;
	v.digits.push_back(1);
	v1 = v;
	v1.sign = -1;
	int t;
	for (int t = 0; t < MAX_ITER; t++) {
		while (x == 0) x = rand() % 2 * p.digits.size();
		for (int i = 0; i < x; i++)
			a.digits.push_back(rand() % 10);
		h.sign = a.sign;
		a = a % p;
		int temp = 0;
		while (a == h) {
			while (x == 0) x = rand() % 2 * p.digits.size();
			for (int i = 0; i < x; i++)
				a.digits.push_back(rand() % 10);
			h.sign = a.sign;
			a = a % p;
			temp++;
			if (temp == 10) a.digits[0] = 1;
		}
		a.delBackZero();
		if (!(a.gcd(p) == v)) return false;
		j = a.exp_mod((p - 1) / 2, p);
		j.delBackZero();
		jac = a.symbJacobi(p);
		jac.delBackZero();
		if (jac.digits[0] == 0 && jac.digits.size() == 1) jac.sign = 1;
		if ((!((jac == v) && (j == v))) && (!((jac == h) && (j == h))) && (!((jac == v1) && (j == p - 1)))) return false;
	}
	return true;
}
//------------------------------------------------------------------------------------5
Longint Longint::CookInverse() {
	if (digits.size() < 3) {
		pbZero(2);
		int temp = 10 * digits[1] + digits[0];
		double t = 1 / (double)temp;
		Longint res;
		if (digits.size() == 1) {
			double t1 = t * 10;
			res.digits.push_back((floor(t1)));
		}
		if (digits.size() == 2) {
			double t1 = t * 10;
			res.digits.push_back(0);
			res.digits.push_back((floor(t1)));
			res.digits.push_back(res.digits[1]);
			res.digits[2] = floor((t1 - floor(t1)) * 10);
		}
		return res;
	}
	Longint z1, z2, z, a;
	int ne = digits.size();
	int n2 = 2 * ne;
	for (int i = 0; i < 3; i++)
		a.digits.push_back(digits[digits.size() - 3 + i]);
	for (int i = 0; i < n2; i++)
		z1.digits.push_back(0);
	Longint z10;

	for (int i = 0; i < 5; i++)z10.digits.push_back(0);
	z10.digits.push_back(1);
	z2 = z10 / a;
	z2.delBackZero();
	for (int i = ne + 1; (i >= 0) && (i >= (ne + 2 - z2.digits.size())); i--)
		z1.digits[i - 1] = z2.digits[z2.digits.size() - 1 - (ne + 1 - i)];
	int k = 0, r;
	do {
		Longint v;
		int kz = ((int)pow((double)10, (double)(k + 1)) + 3);
		for (int i = 0; i < ne; i++) v.digits.push_back(0);
		for (int i = 0; (i < kz) && (i < digits.size()); i++)
			v.digits[ne - 1 - i] = digits[digits.size() - 1 - i];
		Longint s, w = z1 * z1;
		for (int i = 0; i < n2; i++)
			s.digits.push_back(w.digits[ne + i]);
		w = s * v;
		Longint q;
		for (int i = 0; i < n2; i++)
			q.digits.push_back(w.digits[ne + i]);
		z1 = z1 + z1 - q;
		k++;
	} while ((int)pow((double)10, (double)k) < digits.size());
	return z1;
}

Longint Longint::CookDiv(const Longint& p, const int& ne) {
	Longint r, res;
	r = (*this) * p;
	//r.delBackZero();
	int d = 2 * ne;
	for (int i = d; i < r.digits.size(); i++)
		res.digits.push_back(r.digits[i]);
	return res;
}

int main()
{
	setlocale(LC_CTYPE, "ukr");
	Commands();
	interface();
	system("pause");
	return 0;
}
