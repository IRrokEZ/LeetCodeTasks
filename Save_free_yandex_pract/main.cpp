#include <iostream>

using namespace std;

int main()
{
    std::cout << "Happy coding!" << std::endl;

    // напишите тут команды роботу
    Up();
    Up();
    Right();
    Right();
    Up();
    Up();
    Down();
    Down();
    Left();
    Left();
    Down();
    Down();

    cout << "The quote from \"Hamlet\":" << endl;
    cout << "To be, or not to be, that is the question:" << endl;
    cout << "Whether 'tis nobler in the mind to suffer" << endl;
    cout << "The slings and arrows of outrageous fortune," << endl;
    cout << "Or to take arms against a sea of troubles" << endl;
    cout << "And by opposing end them." << endl;

    std::string save = x;
x = y;
y = save;

// Напишите ваше решение
wood_balance -= w1 * d1;
wood_balance -= w1 * h1 * 2;
wood_balance -= d1 * h1 * 2;
std::cout << "Remaining plywood: " << wood_balance << endl;
wood_balance -= w2 * d2;
wood_balance -= w2 * h2 * 2;
wood_balance -= d2 * h2 * 2;
std::cout << "Remaining plywood: " << wood_balance << endl;
wood_balance -= w3 * d3;
wood_balance -= w3 * h3 * 2;
wood_balance -= d3 * h3 * 2;
std::cout << "Remaining plywood: " << wood_balance << endl;

// Вычислите и выведите площадь треугольника со сторонами a, b, c
double p = a + b + c;
p /= 2;
double square = sqrt(p * (p - a) * (p - b) * (p - c));
std::cout << "S = " << square << endl;

cout << "Enter x and y:" << endl;
// Реализуйте ввод чисел, вычисление и вывод результата
double x, y;
std::cin >> x >> y;
std::cout << "x + y = " << x + y << endl;
std::cout << "x - y = " << x - y << endl;
std::cout << "x * y = " << x * y << endl;
std::cout << "x / y = " << x / y << endl;

// напишите тут команды роботу
Up(3);
Right(3);
Up(1);
Right(4);
Left(4);
Down(1);
Left(3);
Down(3);
//---------------------
Left(2);
Up(10);
Water();
Left(4);
Right(4);
Down(10);
Right(2);
//---------------------
Left(2);
Up(10);
Right(6);
Left(6);
Down(10);
Right(2);
//----------------
Left(2);
Up(10);
Right(6);
Up(3);
Down(3);
Left(6);
Down(10);
Right(2);
//----------------
Left(2);
Up(14);
Right(1);
Left(1);
Down(14);
Right(2);


// Считайте из cin два числа double.
// Найдите пару чисел, для которой они - сумма и произведение.
// Если числа найдены - выведите ответ в соотвествии с форматом.
// В конце не забудьте фразу Solving complete.
double s, p;
std::cin >> s >> p;
if ((s != 0) && (p != 0)) {
    double d = s * s - 4 * p;
    if (d > 0) {
        double sq = sqrt(d);
        double y = (s + sq) / 2;
        double x = s - y;
        if (y > x) {
            std::cout << x << " + " << y << " = " << s << std::endl;
            std::cout << x << " * " << y << " = " << p << std::endl;
        } else {
            std::cout << y << " + " << x << " = " << s << std::endl;
            std::cout << y << " * " << x << " = " << p << std::endl;
        }
    }
}
std::cout << "Solving complete" << endl;


double x, y;
std::string sym;
cin >> x >> sym >> y;
if ((sym != "+") && (sym != "-") && (sym != "*") && (sym != "/")) {
    std::cout << "Unknown operation: " << sym << std::endl;
} else {
    if ((sym == "/") && (y == 0)) {
        std::cout << "Division by zero" << std::endl;
    } else {
        if (sym == "+") {
            std::cout << "= " << x + y;
        } else if (sym == "-") {
            std::cout << "= " << x - y;
        } else if (sym == "*") {
            std::cout << "= " << x * y;
        } else if (sym == "/") {
            std::cout << "= " << x / y;
        }
    }
}


int x;
// считайте число и выведите его с суффиксом
std::cin >> x;
int m10 = x % 10, m100 = x % 100;
if ((m10 == 1) && (m100 != 11)) {
    std::cout << x << "st" << std::endl;
} else if ((m10 == 2) && (m100 != 12)) {
    std::cout << x << "nd" << std::endl;
} else if ((m10 == 3) && (m100 != 13)) {
    std::cout << x << "rd" << std::endl;
} else {
    std::cout << x << "th" << std::endl;
}


// Переставьте элементы вектора five_nums
std::reverse(five_nums.begin(), five_nums.end());

// Переместите элементы из переменной some_vector в
// переменную reversed_vector.
// Размер some_vector равен 4, но может быть и меньше.
if (!some_vector.empty()) {
    reversed_vector.reserve(some_vector.size());
    for (; some_vector.size() > 0;) {
        reversed_vector.push_back(some_vector[some_vector.size() - 1]);
        some_vector.pop_back();
    }
}

// Выведите таблицу умножения для чисел из some_vector
for (const auto& row : some_vector) {
    for (const auto& col : some_vector) {
        std::cout << row * col << " ";
    }
    std::cout << std::endl;
}

BypassComplexWall();
Up();
Up();
BypassComplexWall();
Up();
Right();
Up();
BypassComplexWall();


// Определяйте функции в файле functions.cpp
std::string name;
int birth_year;
int age;
std::cin >> name >> birth_year >> age;
PrintBirthday(name, birth_year, age);



int FindInVector (std::vector<std::string> vect, std::string sub) {
    if (vect.empty()) {
        return -1;
    }
    for (int i = 0; i < vect.size(); ++ i) {
        if (vect[i] == sub) {
            return i;
        }
    }
    return -1;
}


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Реализуйте функцию FindInVector
int FindInVector (std::vector<std::string> vect, std::string sub) {
    if (vect.empty()) {
        return -1;
    }
    for (int i = 0; i < vect.size(); ++ i) {
        if (vect[i] == sub) {
            return i;
        }
    }
    return -1;
}

// Не меняйте следующие функции
void PrintVector(vector<string> v) {
    bool is_first = true;
    for (string s : v) {
        if (!is_first) {
            cout << ", "s;
        }
        cout << s;
        is_first = false;
    }
}

void TestFind(vector<string> haystack, string needle) {
    int result = FindInVector(haystack, needle);

    if (result < 0 ) {
        cout << needle << " not found in "s;
        PrintVector(haystack);
        cout << endl;
    } else if (result < haystack.size() && haystack[result] == needle) {
        cout << needle << " found at "s << result << endl;
    } else {
        cout << "Incorrect result"s << endl;
    }
}

int main() {
    TestFind({"zero"s, "one"s, "two"s, "three"s, "four"s, "five"s}, "four"s);
    TestFind({"one"s, "two"s, "three"s}, "four"s);
    TestFind({"to"s, "be"s, "or"s, "not"s, "to"s, "be"s}, "be"s);
    return 0;
}




    return 0;
}
