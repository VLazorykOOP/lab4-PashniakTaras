 // OOPLab4T.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №4. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


#include <iostream>

// Ваші файли загловки 
//
#include "Lab4Exmaple.h"

// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//
#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include <math.h>
#if !defined(CODING_VS_CODE)
#include <clocale>
#include <malloc.h>
#include <conio.h>
#endif
// Ваші файли загловки 
//
using namespace std;
typedef unsigned int uint;


/*
Створити тип даних - клас вектор, який має поля x, y та z типу float і змінну стану. У
класі визначити
o конструктор без параметрів(інінціалізує поля в нуль);
o конструктор з одним параметром типу float (інінціалізує поля x, y та z
значенням параметру);
o конструктор з одним параметром вказівник на тип (інінціалізує поля x, y та z
значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити
код помилки);
o деструктор із виведенням інформації про стан вектора;
o визначити функцію, яка присвоює полю x, y або z деяке значення (параметр за
замовчуванням);
Об’єктно – орієнтоване програмування мовою С++ Лазорик В.В.
16
o функцію яка одержує деякий елемент з полів x, y та z;
o конструктор копій та операцію присвоєння; // !!!
o визначити функції друку, додавання, віднімання, векторний добуток які
здійснюють ці арифметичні операції з даними цього класу;
o функцію ділення на ціле типу short(при діленні на 0 змінити стан, а ділення не
виконувати);
o визначити функції порівняння: більше, менше або рівно, які повертають true
або false.
У змінну стани встановлювати код помилки, діленні на 0, при передачі NULL (nulptr) в
конструкторі із вказівником. Передбачити можливість підрахунку числа об'єктів даного типу.
Написати програму тестування всіх можливостей цього класу.
*/
const int OK = 0;
const int BAD_INIT = 1;
const int BAD_DIV = 2;

enum State {
	NoErrors,
	NoMemory, //не вистачає пам'яті
	NotInRange, //виходить за межі множини
	InvalidNumber // ініціалізація числом
};
static string SetStateStrings[] = { "NoErrors", "NoMemory", "NotInRange", "InvalidNumber" };


class Vector3F
{
	float  x, y, z;
	int state;
	unsigned long size;
	static int count;
public:

	long* v;
	Vector3F() {
		v = (long*)calloc(1, sizeof(long));
		v[0] = 0;
		size = 1;
	}

	Vector3F(unsigned long SizeVec) {
		v = (long*)calloc(SizeVec, sizeof(long));
		for (int i = 0; i < SizeVec; i++) {
			v[i] = 0;
		}
		size = SizeVec;
	}

	Vector3F(unsigned long SizeVec, long value) {
		v = (long*)calloc(SizeVec, sizeof(long));
		for (int i = 0; i < SizeVec; i++) {
			v[i] = value;
		}
		size = SizeVec;
	}

	Vector3F(const Vector3F& ref_Point)
	{
		this->state = ref_Point.state;
		this->size = ref_Point.size;

		this->v = (long*)calloc(size, sizeof(long));
		for (int i = 0; i < size; i++) {
			this->v[i] = ref_Point.v[i];
		}
	}

	~Vector3F() {
		free(v);
	}
	/*
	Vector3F() : x(0), y(0), z(0) {
		state = OK; count++;
	}   // o конструктор без параметрів(інінціалізує поля в нуль);

	Vector3F(float iv) : x(iv), y(iv), z(iv) {
		state = OK; count++;
	}	// o конструктор з одним параметром типу float(інінціалізує поля x, y та z значенням параметру);

	Vector3F(float ix, float iy, float iz);
	Vector3F(float ix, float iy) : x(ix), y(iy), z(0) {
		state = OK; count++;
	};
	Vector3F(float* v) {
		if (v == nullptr) {
			state = BAD_INIT; x = 0; y = 0; z = 0;
		}
		else {
			x = v[0]; y = v[1]; z = v[2];
			state = OK;
		}
		count++;
	}
	~Vector3F() {
		count--;
		cout << " state Vec: " << state;
		cout << " Vec delete \n";
	}
	void Input();   //  !!! Без первантаження операцій    
	void Output();  //  !!! Без первантаження операцій
	bool CompLessAll(Vector3F& s);
	static int getCount() {
		if (count <= 0) cout << " Немає об'єктів Vector3F ";
		return count;
	}
	int getState() { return state; }
	*/
	//k

	Vector3F& operator++(const int param) {
		for (int i = 0; i < size; i++) {
			this->v[i]++;
		}
		return *this;
	}

	Vector3F& operator--(const int param) {
		for (int i = 0; i < size; i++) {
			this->v[i]--;
		}
		return *this;
	}

	bool operator!() {
		return size != 0;
	}


	Vector3F& operator~() {
		for (int i = 0; i < size; i++) {
			this->v[i] = ~v[i];
		}
		return *this;
	}

	Vector3F& operator-() {
		for (int i = 0; i < size; i++) {
			this->v[i] = this->v[i] * (-1);
		}
		return *this;
	}

	Vector3F& operator=(Vector3F& a) {
		this->size = a.size;
		free(v);
		v = (long*)calloc(a.size, sizeof(long));
		for (int i = 0; i < a.size; i++) {
			this->v[i] = a.v[i];
		}
		return *this;
	}

	Vector3F& operator+=(Vector3F& a) {
		long* v_temp;
		unsigned long new_size = max(this->size, a.size);
		v_temp = (long*)calloc(new_size, sizeof(long));
		for (int i = 0; i < new_size; i++) {
			if (i < this->size && i < a.size) {
				v_temp[i] = this->v[i] + a.v[i];
			}
			else if (i < this->size) {
				v_temp[i] = this->v[i];
			}
			else {
				v_temp[i] = a.v[i];
			}
		}
		free(this->v);
		this->v = v_temp;
		this->size = new_size;
		return *this;
	}




	Vector3F& operator-=(Vector3F& a) {
		long* v_temp;
		unsigned long new_size = max(this->size, a.size);
		v_temp = (long*)calloc(new_size, sizeof(long));
		for (int i = 0; i < new_size; i++) {
			if (i < this->size && i < a.size) {
				v_temp[i] = this->v[i] - a.v[i];
			}
			else if (i < this->size) {
				v_temp[i] = this->v[i];
			}
			else {
				v_temp[i] = 0;
			}
		}
		free(this->v);
		this->v = v_temp;
		this->size = new_size;
		return *this;
	}

	Vector3F& operator*=(long value) {
		for (int i = 0; i < size; i++) {
			this->v[i] = this->v[i] * value;
		}
		return *this;
	}

	Vector3F& operator/=(long value) {
		for (int i = 0; i < size; i++) {
			this->v[i] = this->v[i] / value;
		}
		return *this;
	}

	Vector3F& operator%=(long value) {
		for (int i = 0; i < size; i++) {
			this->v[i] = this->v[i] % value;
		}
		return *this;
	}

	Vector3F& operator|=(Vector3F& a) {
		long* v_temp;
		unsigned long new_size = max(this->size, a.size);
		v_temp = (long*)calloc(new_size, sizeof(long));
		for (int i = 0; i < new_size; i++) {
			if (i < this->size && i < a.size) {
				v_temp[i] = this->v[i] | a.v[i];
			}
			else if (i < this->size) {
				v_temp[i] = this->v[i];
			}
			else {
				v_temp[i] = a.v[i];
			}
		}
		free(this->v);
		this->v = v_temp;
		this->size = new_size;
		return *this;
	}

	Vector3F& operator^=(Vector3F& a) {
		long* v_temp;
		unsigned long new_size = max(this->size, a.size);
		v_temp = (long*)calloc(new_size, sizeof(long));
		for (int i = 0; i < new_size; i++) {
			if (i < this->size && i < a.size) {
				v_temp[i] = this->v[i] ^ a.v[i];
			}
			else if (i < this->size) {
				v_temp[i] = this->v[i];
			}
			else {
				v_temp[i] = a.v[i];
			}
		}
		free(this->v);
		this->v = v_temp;
		this->size = new_size;
		return *this;

	}

	Vector3F& operator&=(Vector3F& a) {
		long* v_temp;
		unsigned long new_size = max(this->size, a.size);
		v_temp = (long*)calloc(new_size, sizeof(long));
		for (int i = 0; i < new_size; i++) {
			if (i < this->size && i < a.size) {
				v_temp[i] = this->v[i] & a.v[i];
			}
			else if (i < this->size) {
				v_temp[i] = this->v[i];
			}
			else {
				v_temp[i] = a.v[i];
			}
		}
		free(this->v);
		this->v = v_temp;
		this->size = new_size;
		return *this;

	}

	Vector3F& operator+(Vector3F& a) {
		long* v_temp;
		unsigned long new_size = max(this->size, a.size);
		v_temp = (long*)calloc(new_size, sizeof(long));
		for (int i = 0; i < new_size; i++) {
			if (i < this->size && i < a.size) {
				v_temp[i] = this->v[i] + a.v[i];
			}
			else if (i < this->size) {
				v_temp[i] = this->v[i];
			}
			else {
				v_temp[i] = a.v[i];
			}
		}


		free(this->v);
		this->v = v_temp;
		this->size = new_size;
		return *this;
	}

	Vector3F& operator-(Vector3F& a) {
		long* v_temp;
		unsigned long new_size = max(this->size, a.size);
		v_temp = (long*)calloc(new_size, sizeof(long));
		for (int i = 0; i < new_size; i++) {
			if (i < this->size && i < a.size) {
				v_temp[i] = this->v[i] - a.v[i];
			}
			else if (i < this->size) {
				v_temp[i] = this->v[i];
			}
			else {
				v_temp[i] = 0;
			}
		}
		free(this->v);
		this->v = v_temp;
		this->size = new_size;
		return *this;
	}

	Vector3F& operator*(long value) {
		for (int i = 0; i < size; i++) {
			this->v[i] = this->v[i] * value;
		}
		return *this;
	}

	Vector3F& operator/(long value) {
		for (int i = 0; i < size; i++) {
			this->v[i] = this->v[i] / value;
		}
		return *this;
	}

	Vector3F& operator%(long value) {
		for (int i = 0; i < size; i++) {
			this->v[i] = this->v[i] % value;
		}
		return *this;
	}


	Vector3F& operator|(Vector3F& a) {
		long* v_temp;
		unsigned long new_size = max(this->size, a.size);
		v_temp = (long*)calloc(new_size, sizeof(long));
		for (int i = 0; i < new_size; i++) {
			if (i < this->size && i < a.size) {
				v_temp[i] = this->v[i] | a.v[i];
			}
			else if (i < this->size) {
				v_temp[i] = this->v[i];
			}
			else {
				v_temp[i] = a.v[i];
			}
		}
		free(this->v);
		this->v = v_temp;
		this->size = new_size;
		return *this;
	}

	Vector3F& operator^(Vector3F& a) {
		long* v_temp;
		unsigned long new_size = max(this->size, a.size);
		v_temp = (long*)calloc(new_size, sizeof(long));
		for (int i = 0; i < new_size; i++) {
			if (i < this->size && i < a.size) {
				v_temp[i] = this->v[i] ^ a.v[i];
			}
			else if (i < this->size) {
				v_temp[i] = this->v[i];
			}
			else {
				v_temp[i] = a.v[i];
			}
		}
		free(this->v);
		this->v = v_temp;
		this->size = new_size;
		return *this;

	}

	Vector3F& operator&(Vector3F& a) {
		long* v_temp;
		unsigned long new_size = max(this->size, a.size);
		v_temp = (long*)calloc(new_size, sizeof(long));
		for (int i = 0; i < new_size; i++) {
			if (i < this->size && i < a.size) {
				v_temp[i] = this->v[i] & a.v[i];
			}
			else if (i < this->size) {
				v_temp[i] = this->v[i];
			}
			else {
				v_temp[i] = a.v[i];
			}
		}
		free(this->v);
		this->v = v_temp;
		this->size = new_size;
		return *this;

	}

	Vector3F& operator>>(long value) {
		for (int i = 0; i < size; i++) {
			this->v[i] = this->v[i] >> value;
		}
		return *this;
	}

	Vector3F& operator<<(long value) {
		for (int i = 0; i < size; i++) {
			this->v[i] = this->v[i] << value;
		}
		return *this;
	}

	bool operator==(Vector3F& a) {

		if (this->size != a.size) {
			return false;
		}

		for (int i = 0; i < size; i++) {
			if (this->v[i] != a.v[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator!=(Vector3F& a) {
		if (this->size != a.size) {
			return true;
		}
		for (int i = 0; i < size; i++) {
			if (this->v[i] != a.v[i]) {
				return true;
			}
		}
		return false;
	}

	long& operator[](const int index) {
		if (size < index) {
			state = NotInRange;
			return v[size - 1];
		}
		else {
			return v[index];
		}
	}

	long GetObjectWeight() {
		unsigned long j = 0;
		for (int i = 0; i < size; i++) {
			j = j + (v[i] * v[i]);
		}
		return j;
	}

	bool operator>(Vector3F& a) {
		return a.GetObjectWeight() > this->GetObjectWeight();
	}

	bool operator>=(Vector3F& a) {
		return a.GetObjectWeight() >= this->GetObjectWeight();
	}

	bool operator<(Vector3F& a) {
		return a.GetObjectWeight() < this->GetObjectWeight();
	}

	bool operator<=(Vector3F& a) {
		return a.GetObjectWeight() <= this->GetObjectWeight();
	}

	void printInfo()
	{

		cout << "Size =" << size << " ";
		cout << "State=" << SetStateStrings[state] << " ";
		for (int i = 0; i < size; i++) {
			cout << "[" << v[i] << "] ";
		}

		cout << endl;
	}

}; //кінець класу

void Unari() {
	Vector3F obj1(5, 4);
	obj1.v[1] = 6;
	obj1.printInfo();
	cout << "Test ++" << endl;
	obj1++;
	obj1.printInfo();
	cout << "Test --" << endl;
	obj1--;
	obj1.printInfo();
	cout << "Test !" << endl;
	cout << "Result " << !obj1 << endl;
	cout << "Test ! if size = 0" << endl;
	Vector3F obj2(0);
	cout << "Result " << !obj2 << endl;

	Vector3F obj3(5, 4);
	obj3.v[1] = 6;
	obj3.printInfo();
	cout << "Test ~" << endl;
	~obj3;
	obj3.printInfo();
	cout << "Test -" << endl;
	Vector3F obj6(5, 4);
	obj6.v[1] = 6;
	Vector3F obj5;
	obj6.printInfo();
	obj5 = -obj6;
	obj6.printInfo();

}

void Prisvoena() {

	cout << "Test =" << endl;
	Vector3F obj7(5, 4);
	obj7.v[1] = 6;
	Vector3F obj8(6, 3);
	obj8.v[1] = 5;
	cout << "Before" << endl;
	obj7.printInfo();
	obj8.printInfo();
	cout << "After" << endl;
	obj8 = obj7;
	obj7.printInfo();
	obj8.printInfo();

	cout << "Test +=" << endl;
	Vector3F obj3(6, 7);
	obj3.v[1] = 5;
	Vector3F obj4(6, 3);
	obj4.v[1] = 5;
	cout << "Before" << endl;
	obj3.printInfo();
	cout << "After" << endl;
	obj3 += obj4;
	obj3.printInfo();

	cout << "Test -=" << endl;
	Vector3F obj5(6, 2);
	obj5.v[1] = 8;
	Vector3F obj6(6, 4);
	obj6.v[1] = 1;
	cout << "Before" << endl;
	obj5.printInfo();
	cout << "After" << endl;
	obj5 -= obj6;
	obj5.printInfo();

	cout << "Test *=" << endl;
	Vector3F obj1(4, 7);
	obj1.v[1] = 4;
	cout << "Before" << endl;
	obj1.printInfo();
	cout << "After" << endl;
	obj1 *= 8;
	obj1.printInfo();

	cout << "Test /=" << endl;
	Vector3F obj2(7, 2);
	obj2.v[1] = 4;
	cout << "Before" << endl;
	obj2.printInfo();
	cout << "After" << endl;
	obj2 /= 2;
	obj2.printInfo();

	cout << "Test %=" << endl;
	Vector3F obj9(4, 7);
	obj9.v[1] = 4;
	cout << "Before" << endl;
	obj9.printInfo();
	cout << "After" << endl;
	obj9 %= 4;
	obj9.printInfo();

	cout << "Test |=" << endl;
	Vector3F obj10(3, 5);
	obj10.v[1] = 9;
	Vector3F obj11(7, 2);
	obj11.v[1] = 9;
	cout << "Before" << endl;
	obj10.printInfo();
	cout << "After" << endl;
	obj10 |= obj11;
	obj10.printInfo();

	cout << "Test ^=" << endl;
	Vector3F obj12(6, 2);
	obj12.v[1] = 8;
	Vector3F obj13(6, 4);
	obj13.v[1] = 1;
	cout << "Before" << endl;
	obj12.printInfo();
	cout << "After" << endl;
	obj12 ^= obj13;
	obj12.printInfo();

	cout << "Test &=" << endl;
	Vector3F obj14(6, 2);
	obj14.v[1] = 8;
	cout << "Before" << endl;
	obj14.printInfo();
	cout << "After" << endl;
	obj14 &= obj14;
	obj14.printInfo();
}

void Arithmetic() {
	cout << "Test +" << endl;
	Vector3F obj5(6, 7);
	obj5.v[1] = 5;
	Vector3F obj4(6, 3);
	obj4.v[1] = 5;
	cout << "Before" << endl;
	obj4.printInfo();
	obj5.printInfo();
	Vector3F obj3;
	cout << "After" << endl;
	obj3 = obj4 + obj5;
	obj3.printInfo();

	cout << "Test -" << endl;
	Vector3F obj1(5, 7);
	obj1.v[1] = 4;
	Vector3F obj2(4, 3);
	obj2.v[1] = 5;
	cout << "Before" << endl;
	obj1.printInfo();
	obj2.printInfo();
	Vector3F obj6;
	cout << "After" << endl;
	obj6 = obj1 - obj2;
	obj6.printInfo();

	cout << "Test *" << endl;
	Vector3F obj7(4, 7);
	obj7.v[1] = 4;
	cout << "Before" << endl;
	obj7.printInfo();
	cout << "After" << endl;
	Vector3F obj8;
	obj8 = obj7 * 5;
	obj8.printInfo();

	cout << "Test /" << endl;
	Vector3F obj10(3, 9);
	obj10.v[1] = 3;
	cout << "Before" << endl;
	obj10.printInfo();
	cout << "After" << endl;
	Vector3F obj11;
	obj11 = obj10 / 3;
	obj11.printInfo();

	cout << "Test %" << endl;
	Vector3F obj9(6, 8);
	obj9.v[1] = 4;
	cout << "Before" << endl;
	obj9.printInfo();
	cout << "After" << endl;
	Vector3F obj12;
	obj12 = obj9 % 3;
	obj12.printInfo();
}

void Pobitovi() {
	cout << "Test |" << endl;
	Vector3F obj1(5, 7);
	obj1.v[1] = 4;
	Vector3F obj2(3, 4);
	obj2.v[1] = 8;
	cout << "Before" << endl;
	obj1.printInfo();
	obj2.printInfo();
	Vector3F obj3;
	cout << "After" << endl;
	obj3 = obj1 | obj2;
	obj3.printInfo();

	cout << "Test ^" << endl;
	Vector3F obj4(5, 4);
	obj4.v[1] = 3;
	Vector3F obj5(4, 3);
	obj5.v[1] = 5;
	cout << "Before" << endl;
	obj4.printInfo();
	obj5.printInfo();
	Vector3F obj6;
	cout << "After" << endl;
	obj6 = obj4 ^ obj5;
	obj6.printInfo();

	cout << "Test &" << endl;
	Vector3F obj7(7, 8);
	obj7.v[1] = 6;
	Vector3F obj8(6, 9);
	obj8.v[1] = 3;
	cout << "Before" << endl;
	obj7.printInfo();
	obj8.printInfo();
	Vector3F obj9;
	cout << "After" << endl;
	obj9 = obj7 & obj8;
	obj9.printInfo();
}

void Operation() {
	cout << "Test >>" << endl;
	Vector3F obj7(4, 7);
	obj7.v[1] = 4;
	cout << "Before" << endl;
	obj7.printInfo();
	cout << "After" << endl;
	Vector3F obj8;
	obj8 = obj7 >> 5;
	obj8.printInfo();

	cout << "Test <<" << endl;
	Vector3F obj9(6, 8);
	obj9.v[1] = 4;
	cout << "Before" << endl;
	obj9.printInfo();
	cout << "After" << endl;
	Vector3F obj12;
	obj12 = obj9 << 3;
	obj12.printInfo();

	cout << "Test ==" << endl;
	Vector3F obj1(5, 4);
	obj1.v[1] = 6;
	Vector3F obj2(6, 3);
	obj2.v[1] = 5;
	cout << "Result " << (obj1 == obj2) << endl;

	cout << "Test !=" << endl;
	Vector3F obj3(3, 4);
	obj3.v[1] = 8;
	Vector3F obj4(6, 3);
	obj4.v[1] = 7;
	cout << "Result " << (obj3 != obj4) << endl;

	cout << "Test []" << endl;
	Vector3F obj13(6, 3);
	obj13[1] = 5;
	obj13.printInfo();


}

void Comparition() {
	cout << "Test >" << endl;
	Vector3F obj3(3, 4);
	obj3.v[1] = 8;
	Vector3F obj4(6, 3);
	obj4.v[1] = 7;
	cout << "Result " << (obj3 > obj4) << endl;

	cout << "Test >=" << endl;
	Vector3F obj1(5, 4);
	obj1.v[1] = 6;
	Vector3F obj2(6, 3);
	obj2.v[1] = 5;
	cout << "Result " << (obj1 >= obj2) << endl;

	cout << "Test <" << endl;
	Vector3F obj5(4, 6);
	obj5.v[1] = 2;
	Vector3F obj6(5, 8);
	obj6.v[1] = 1;
	cout << "Result " << (obj5 < obj6) << endl;

	cout << "Test <=" << endl;
	Vector3F obj7(3, 4);
	obj7.v[1] = 8;
	Vector3F obj8(3, 4);
	obj8.v[1] = 8;
	cout << "Result " << (obj7 <= obj8) << endl;

}

void Errors() {
	cout << "Test []" << endl;
	Vector3F obj13(6, 3);
	obj13[100] = 5;
	obj13.printInfo();
}









/*

int Vector3F::count = 0;
Vector3F::Vector3F(float ix, float iy, float iz) {
	x = ix; y = iy; z = iz;
	state = OK;
	count++;
};
Vector3F::Vector3F(const Vector3F& s) {
	//if (this == &s) return; //  // the expression is used in the old standard
	x = s.x; y = s.y; z = s.z; state = OK;
	count++;
};
// Vector3F::Vector3F(float* v) {}
void Vector3F::Input() {
	cout << " Input  x y z";
	cin >> x >> y >> z;
}
void Vector3F::Output() {
	cout << " x =" << x << " y = " << y << " z = " << z << " state  " << state << endl;
}

Vector3F Vector3F::Add(Vector3F& s) {
	Vector3F tmp;
	tmp.x = x + s.x;
	tmp.y = y + s.y;
	tmp.z = z + s.z;
	return tmp;
}

Vector3F Vector3F::Sub(Vector3F& s) {
	Vector3F tmp;
	tmp.x = x - s.x;
	tmp.y = y - s.y;
	tmp.z = z - s.z;
	return tmp;
}
Vector3F Vector3F::Div(float d) {
	Vector3F tmp;
	if (fabs(d) < 1.e-25) {
		tmp.state = BAD_DIV;
		cout << " Error div \n";
		return *this;
	}
	tmp.x = x / d;
	tmp.y = y / d;
	tmp.z = z / d;
	return tmp;
}
Vector3F Vector3F::Mul(float d) {
	Vector3F tmp(*this);
	tmp.x = x * d;
	tmp.y = y * d;
	tmp.z = z * d;
	return tmp;
}

bool Vector3F::CompLessAll(Vector3F& s) {

	if (x < s.x && y < s.y && z < s.z) return true;
	return false;
}

//Teстування
void mainExample3()
{
	setlocale(LC_CTYPE, "ukr");
	cout << "Тестування створенного класу \n";
	cout << "Тестування конструкторiв \n";
	cout << "Testing create class  \n";
	cout << "Testing crot's  \n";
	Vector3F ObjCDef;
	ObjCDef.Output();
	Vector3F ObjP1(10.0);
	ObjP1.Output();
	float  a = 1.0, b = 2.0;
	Vector3F  ObjP2(a, b);
	ObjP2.Output();
	Vector3F ObjCopy(ObjP2);
	float* v = nullptr, v2[] = { 1.2f, 3.3f };
	Vector3F  ObjP3(v2);
	if (ObjP3.getState() != OK) cout << " ObjP3  x= 0  y= 0  \n";
	Vector3F  ObjP4(v2);
	if (ObjP4.getState() != OK) cout << " ObjP4 x= 0  y= 0  \n";
	cout << " Кiлькiсть створених об'єктiв Vector3F " << Vector3F::getCount() << endl;
	cout << "Тестування введення \n";
	ObjCDef.Input();
	cout << "Тестування функцiй \n";
	ObjCDef = ObjCDef.Add(ObjP2);
	ObjCDef.Output();
	cout << " \n Кiлькiсть створених об'єктiв Vector3F до Sub " << Vector3F::getCount() << endl;
	ObjCDef = ObjCDef.Sub(ObjP2);
	cout << " \n Кiлькiсть створених об'єктiв Vector3F пiсля Sub " << Vector3F::getCount() << endl;

	cout << "Testing input \n";
	ObjCDef.Input();
	cout << "Testing gunction \n";
	ObjCDef = ObjCDef.Add(ObjP2);
	ObjCDef.Output();
	cout << " \n Counts create objects Vector3F before  Sub " << Vector3F::getCount() << endl;
	ObjCDef = ObjCDef.Sub(ObjP2);
	cout << " \n  Counts create objects Vector3F after Sub  " << Vector3F::getCount() << endl;


	ObjCDef.Output();
	ObjCDef = ObjCDef.Mul(5);
	ObjCDef.Output();
	ObjCDef = ObjCDef.Div(1.3);
	if (ObjCDef.getState() == BAD_DIV) cout << "BAD_DIV \n";
	ObjCDef.Output();

	ObjCDef = ObjCDef.Div(0.0);
	if (ObjCDef.getState() == BAD_DIV) cout << "BAD_DIV \n";
	ObjCDef.Output();
	cout << "ObjCopy state " << ObjCopy.getState() << endl;
	if (ObjCopy.CompLessAll(ObjCDef))  cout << "ObjCopy less ObjDef  " << endl;


	cout << "Завершення  тестування  \n";

	cout << "Completion of testing  \n";
	cin.get();
	return;
} */


int main()
{
	//  Код виконання завдань
	//  Головне меню завдань
	system("cls");
	std::cout << " Lab #4  task chain  !\n";
	char ch;
	do {
		cout << "\nSelect operation: \n";
		cout << "    1.  Unarni operation \n";
		cout << "    2.  Operation Prisvoena \n";
		cout << "    3.  Arithmetic binary\n";
		cout << "    4.  Pobitovi operation\n";
		cout << "    5.  Operation ==,!=,[]\n";
		cout << "    6.  Operation comparition (>, >=, <,<= ) \n";
		cout << "    7.  Test Errors \n";
		cout << "    8.  Exit \n";

		ch = _getch();
		switch (ch) {
		case '1':  Unari(); break;
		case '2': Prisvoena(); break;
		case '3': Arithmetic(); break;
		case '4': Pobitovi(); break;
		case '5': Operation(); break;
		case '6': Comparition(); break;
		case '7': Errors(); break;
		}
	} while (ch != '8');
	return 0;
	//  Функції та класи можуть знаходитись в інших файлах проекту
}



