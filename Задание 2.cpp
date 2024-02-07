/*
Напишите программу, определяющую какая из n точек, заданных своими координатами, расположена ближе к началу координат.
Какой случай для алгоритма является наилучшим? Наихудшим? 
Сколько сравнений требуется этому алгоритму? Результаты тестирования вывести в текстовый файл.

Ошлаков Данил, ИВТ-22
*/

#include "Work2SAOD.h"
#include <vector>
#include <iostream>
#include "Work2SAOD.h"

using namespace std;

int main() {
    // Тестирование функций
    test();

    // Создание вектора с точками
    vector<vector<double>> points;

    // Заполнение массива координат
    points = mulNumbersInput();

    // Нахождение индекса ближайшей к началу координат точки
    int closestPointIndex = closestToOrigin(points);

    try 
    {
        // Вывод результата
        writeResultToFile(closestPointIndex);
    }
    catch (const invalid_argument & e)
    {
        cout << e.what() << endl;
    }
    return 0;
}