/*
Напишите программу, определяющую какая из n точек, заданных своими координатами, расположена ближе к началу координат.
Какой случай для алгоритма является наилучшим? Наихудшим?
Сколько сравнений требуется этому алгоритму? Результаты тестирования вывести в текстовый файл.

Ошлаков Данил, ИВТ-22
*/

#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// Функция для вычисления расстояния от точки до начала координат
double distanceToOrigin(double x, double y);

// Функция для определения ближайшей к началу координат точки из массива точек
int closestToOrigin(const vector<vector<double>>& points);

// Подпрограмма test для проверки правильности работы функций
void test();

// Подпрограмма для записи результата в файл
void writeResultToFile(int closestIndex);

// Подпрограмма для перевода строки в координаты (взято с выч.мата)
vector<double> parseNumbers(const string & input);

// Подпрограмма для ввода массива координат (взято с выч.мата)
vector<vector<double>> mulNumbersInput();