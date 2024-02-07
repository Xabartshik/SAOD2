/*
Напишите программу, определяющую какая из n точек, заданных своими координатами, расположена ближе к началу координат.
Какой случай для алгоритма является наилучшим? Наихудшим?
Сколько сравнений требуется этому алгоритму? Результаты тестирования вывести в текстовый файл.

Ошлаков Данил, ИВТ-22
*/

#include "Work2SAOD.h"


using namespace std;

double distanceToOrigin(double x, double y) {
    return sqrt(x * x + y * y);
}
// Функция для определения ближайшей к началу координат точки из массива точек

/*
 Этому алгоритму требуется n - 1 сравнение, так как он сравнивает расстояния от начала координат до каждой точки.
 Возможна модификация с проверкой, является ли точка началом координат, однако это увеличит число сравнений в два раза: 
 С модификацией:
 Лучший случай: первая точка -- начало координат
 Худший случай: нет точки начала координат
 Средний случай: точка начала координат не начало и не конец
 Без модификации:
 Лучший случай: любой случай
 Худший случай: любой случай
 Средний случай: любой случай
*/
int closestToOrigin(const vector<vector<double>>& points) {
    int closestPointIndex = 0;
    double minDistance = distanceToOrigin(points[0][0], points[0][1]);

    for (int i = 1; i < points.size(); i++) {
        double distance = distanceToOrigin(points[i][0], points[i][1]);
        if (distance < minDistance) {
            minDistance = distance;
            closestPointIndex = i;
        }
        //if (distance == 0) {
        //    return i;
        //}
    }

    return closestPointIndex;
}

// Подпрограмма test для проверки правильности работы функций
void test() {
    vector<vector<double>>  testPoints1 = { {1, 2}, {3, 4}, {5, 6}, {7, 8} };
    assert(closestToOrigin(testPoints1) == 0);
    assert(distanceToOrigin(4, 0) == 4);

    vector<vector<double>>  testPoints2 = { {-1, 2}, {7, 4}, {5, 6}, {8, 8} };
    assert(closestToOrigin(testPoints2) == 0);
    assert(distanceToOrigin(0, 0) == 0);

    vector<vector<double>> testPoints3 = { {2, 2}, {3, 3}, {5, 5}, {7, 7} };
    assert(closestToOrigin(testPoints3) == 0);
    assert(distanceToOrigin(3, 4) == 5);
}

// Подпрограмма для записи результата в файл
void writeResultToFile(int closestIndex) {
    std::ofstream outputFile("result.txt", std::ios::app);
    if (outputFile.is_open()) {
        outputFile << "Индекс ближайшей к началу координат точки: " << closestIndex << std::endl;
        outputFile.close();
    }
    else {
        throw
            invalid_argument("Невозможно открыть файл для записи результатов.");
    }
}
// Подпрограмма для перевода строки в координаты (взято с выч.мата)
vector<double> parseNumbers(const string& input) 
{
    vector<double> result;
    istringstream iss(input);
    string token;

    while (getline(iss, token, ' ')) {
        // Заменяем запятые на точки, чтобы правильно обработать дробную часть
        for (char& ch : token) {
            if (ch == ',') {
                ch = '.'; // замена запятой на точку
            }
        }
        result.push_back(stod(token)); // преобразуем строку в double и добавляем в массив
    }

    return result;
}
// Подпрограмма для ввода массива координат (взято с выч.мата)
vector<vector<double>> mulNumbersInput()
{
    unsigned pointNum;//Число точек
    string input;//Строка для ввода
    vector<vector<double>> result;//Все точки 
    cout << "Введите число точек" << endl;
    cin >> pointNum;
    cout << "Введите координаты (X и Y): " << endl;
    cin.ignore();
    for (unsigned i = 0; i < pointNum; i++)
    {
        getline(cin, input);
        result.push_back(parseNumbers(input));
    }

    return result;
}