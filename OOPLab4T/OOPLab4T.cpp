#include <iostream>
#include <string>
#include <map>
using namespace std;

class AssocArray {
private:
    map<string, string> data;
    int codeError;

public:
    AssocArray() {
        codeError = 0;
    }
    
    void set(string key, string value) {
        data[key] = value;
    }
    
    string get(string key) {
        if (data.count(key)) {
            return data[key];
        } else {
            codeError = 1; // Key not found    
        } 
    }
    
    string operator[](string key) {
        return get(key);
    }
    
    friend ostream& operator<<(ostream& os, const AssocArray& aa) {
        for (auto const& pair : aa.data) {
            os << pair.first << ": " << pair.second << endl;
        }
        return os;
    }
    
    friend istream& operator>>(istream& is, AssocArray& aa) {
        string key, value;
        cout << "Enter key and value (separated by space): ";
        is >> key >> value;
        aa.set(key, value);
        return is;
    }
    
    void printCodeError() {
        switch (codeError) {
            case 0:
                cout << "No error" << endl;
                break;
            case 1:
                cout << "Key not found" << endl;
                break;
            default:
                cout << "Unknown error" << endl;
                break;
        }
    }
};

class Vector3F {
private:
    double x, y, z;
    int state;
    int count;
public:
    Vector3F(double xVal, double yVal, double zVal) :state(0) {
        this->x = xVal;
        this->y = yVal;
        this->z = zVal;
    }
    Vector3F() :state(0) {
        x = 0.0;
        y = 0.0;
        z = 0.0;
        count++;
    }
    Vector3F(double Val) :state(0) {
        x = Val;
        y = Val;
        z = Val;
        count++;
    }
    Vector3F(double* Val) :state(0) {
        if (Val != nullptr) {
            x = Val[0];
            y = Val[1];
            z = Val[2];
            count++;
        }
        else {
            state = 1;
            cout << "Value = nullptr!";
            count++;
        }
    }
    ~Vector3F() {
        /*cout << endl;
        cout << "Vec destructed, success. State: " << state << endl;*/
        count--;
    }
    Vector3F& operator++() {
        x += 1;
        y += 1;
        z += 1;
        return *this;
    }
    Vector3F& operator++(int a) {
        Vector3F T = *this;
        x += 1;
        y += 1;
        z += 1;
        return T;
    }
    Vector3F& operator--() {
        x -= 1;
        y -= 1;
        z -= 1;
        return *this;
    }
    Vector3F& operator--(int a) {
        Vector3F T = *this;
        x -= 1;
        y -= 1;
        z -= 1;
        return T;
    }
    bool operator!() {
        if (x == 0 && y == 0 && z == 0) {
            return false;
        }
        else {
            return true;
        }
    }
    Vector3F operator-() {
        return Vector3F(-x, -y, -z);
    }
    Vector3F& operator=(const Vector3F other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
    Vector3F& operator+=(const Vector3F other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    Vector3F& operator-=(const Vector3F other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }
    Vector3F& operator*=(const Vector3F other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }
    Vector3F& operator/=(int Num) {
        if (Num == 0) {
            cout << "Ділення на нуль" << endl;
            state = -2;
        }
        x /= Num;
        y /= Num;
        z /= Num;
        return *this;
    }

    Vector3F operator+(Vector3F& C) {
        x = x + C.x;
        y = y + C.y;
        z = z + C.z;
        return *this;
    }
    Vector3F operator-(Vector3F& C) {
        x = x - C.x;
        y = y - C.y;
        z = z - C.z;
        return *this;
    }
    Vector3F operator*(Vector3F& C) {
        x = x * C.x;
        y = y * C.y;
        z = z * C.z;
        return *this;
    }
    Vector3F& operator/(int Num) {
        if (Num == 0) {
            cout << "Ділення на нуль" << endl;
            state = -3;
        }
        x = x / Num;
        y = y / Num;
        z = z / Num;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, Vector3F& C) {
        os << C.x << " \t";
        os << C.y << " \t";
        os << C.z << " \t";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Vector3F& A) {
        is >> A.x;
        is >> A.y;
        is >> A.z;
        return is;
    }
    bool operator>(const Vector3F& A) {
        return(x > A.x && y > A.y && z > A.z);
    }
    bool operator<(const Vector3F& A) {
        return(x < A.x&& y < A.y&& z < A.z);
    }
    bool operator<=(const Vector3F& A) {
        return(x <= A.x && y <= A.y && z <= A.z);
    }
    bool operator>=(const Vector3F& A) {
        return(x >= A.x && y >= A.y && z >= A.z);
    }
    bool operator==(const Vector3F other) {
        return(x == other.x && y == other.y && z == other.z);
    }
    bool operator!=(const Vector3F other) {
        return(x != other.x && y != other.y && z != other.z);
    }
};

void Task1() {
    double Arr[3] = { 1,2,3 };
    Vector3F A;
    cin >> A;
    cout << "A :";
    cout << A;
    Vector3F B(3, 4, 9);
    cout << endl;
    cout << "B :";
    cout << B;
    Vector3F C(Arr);
    cout << endl << "C :" ;
    cin >> C;
    cout << "C :";
    cout << C << endl << endl;

    /*cout << "A*B";
    A = A * B;
    cout << A << endl << endl;*/

    cout << "A++" << endl;
    A++;
    cout << A << endl << endl;

    cout << "A--" << endl;
    A--;
    cout << A << endl << endl;

    cout << "A+=B" << endl;
    A += B;
    cout << A << endl << endl;

    cout << "A*=B" << endl;
    A *= B;
    cout << A << endl << endl;

    cout << "A/2" << endl;
    A = A / 2;
    cout << A << endl << endl;

    cout << "A=-A" << endl;
    A =-A;
    cout << A << endl << endl;

    Vector3F AYE = ++C;
    cout << "++C" << endl;
    cout << AYE << endl;
    cout << "--C" << endl;
    AYE = --C;
    cout << AYE << endl;
    cout << "A > C :";
    bool L = A > C;
    cout << L << endl;
    bool I = A > C;
    cout << "A < C :";
    cout << I << endl;
    bool D = A <= C;
    cout << "A<=C :";
    cout << D << endl;
    bool O = A >= C;
    cout << "A>=C :";
    cout << O << endl;
    bool N = A == C;
    cout << "A==C :";
    cout << N << endl;
    bool H = A != C;
    cout << "A!=C :";
    cout << H;
}
void Task2() {
    AssocArray aa;
    aa.set("Taras Pashniak", "+380504441123");
    aa.set("Anna Chervinska", "+38066344862");
    aa.set("Vlad Demchenko", "+380992344821");

    cout << "aa[\"Taras Pashniak\"] = " << aa["Taras Pashniak"] << endl;
    cout << "aa[\"Anna Chervinska\"] = " << aa["Anna Chervinska"] << endl;
    aa.printCodeError();

    cout << endl << "Associative Array Contents:" << endl;
    cout << aa;

    cin >> aa;
    cout << endl << "Associative Array Contents After Input:" << endl;
    cout << aa;
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    int a;
    cout << "Choose 1 or 2 :" << endl;
    cin >> a;
    switch (a)
    {
    case 1:
        Task1();
        break;
    case 2:
        Task1();
        break;
    default:
        break;
    }
}

