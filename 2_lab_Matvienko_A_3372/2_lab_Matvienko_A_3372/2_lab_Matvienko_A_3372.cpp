#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    const int size = 100;
    srand(time(0));
    int arrNotSorted[size];
    int arrSorted[size];
    int swap = 0;


    cout << "исходный массив: \n";
    for (int i = 0; i < size; i++)
    {
        arrNotSorted[i] = -99 + rand() % (99 - (-99) + 1);
        arrSorted[i] = arrNotSorted[i];
        cout << arrNotSorted[i] << " ";
    }
    cout << endl;

    while (true)
    {
        cout << "1)    Создать целочисленный массив размерности N = 100.\nЭлементы массива должны принимать случайное значение в диапазоне от -99 до 99.\n\n";
        cout << "2)    Отсортировать заданный в пункте 1 массив[…] сортировкой(от меньшего к большему).\nОпределить время, затраченное на сортировку, используя библиотеку chrono.\n\n";
        cout << "3)    Найти максимальный и минимальный элемент массива.\nПодсчитать время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono.\n\n";
        cout << "4)    Вывести среднее значение(если необходимо, число нужно округлить) максимального и минимального значения\n в отсортированном и неотсортированном.\nВывести индексы всех элементов, которые равны этому значению, и их количество.Подсчитать время поиска.\n\n";
        cout << "5)    Вывести количество элементов в отсортированном массиве, которые меньше числа a,\n которое инициализируется пользователем.\n\n";
        cout << "6)    Вывести количество элементов в отсортированном массиве, которые больше числа b,\n которое инициализируется пользователем.\n\n";
        cout << "7)    Вывести информацию о том, есть ли введенное пользователем число в отсортированном массиве.\nРеализовать алгоритм бинарного поиска.Сравните скорость его работы с обычным перебором. (*)\n\n";
        cout << "8)    Поменять местами элементы массива, индексы которых вводит пользователь.\nВывести скорость обмена, используя библиотеку chrono.\n\n";

        
        int maxNotSorted = 0;
        int minNotSorted = 10000000;
        int maxSorted = 0;
        int minSorted = 10000000;



        int number;
        cin >> number;

        switch (number)
        {
        case 1:
        {
            cout << "Массив уже создан." << endl;
            break;
        }
        case 2:
        {
            time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
            nanoseconds result;
            cout << "Выберите сортировку: " << endl;
            cout << "1) Bubble sort (пузырьковая сортировка)" << endl;
            cout << "2) Shaker sort (шейкер-сортировка)" << endl;
            cout << "3) Insert sort(сортировка вставками)" << endl;
            cout << "4) Comb sort (сортировка расчёской)" << endl; 
            cout << "5) Shell sort (сортировка Шелла) - ИДЗ 4" << endl;
            int vvod;
            cin >> vvod;
            if (vvod == 1)
            {
                cout << "\nотсортированный массив: \n";
                start = steady_clock::now();
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size - 1; j++)
                    {
                        if (arrSorted[j] > arrSorted[j + 1])
                        {
                            swap = arrSorted[j];
                            arrSorted[j] = arrSorted[j + 1];
                            arrSorted[j + 1] = swap;
                        }
                    }
                }
                end = steady_clock::now();
                for (int i = 0; i < size; i++)
                {
                    cout << arrSorted[i] << " ";
                }
                result = duration_cast<nanoseconds>(end - start);
                cout << endl << "массив отсортировался Bubble sort за " << result.count() << " наносекунд\n" << endl;
                break;
            }
            if (vvod == 2)
            {
                cout << "\nотсортированный массив: \n";
                start = steady_clock::now();
                for (int i = 0; i < size / 2; i++)
                {
                    for (int j = i; j < size - i - 1; j++)
                    {
                        if (arrSorted[j] > arrSorted[j + 1])
                        {
                            swap = arrSorted[j];
                            arrSorted[j] = arrSorted[j + 1];
                            arrSorted[j + 1] = swap;
                        }
                    }
                    for (int j = size - i - 2; j > i; j--)
                    {
                        if (arrSorted[j - 1] > arrSorted[j])
                        {
                            swap = arrSorted[j];
                            arrSorted[j] = arrSorted[j - 1];
                            arrSorted[j - 1] = swap;
                        }
                    }
                }
                end = steady_clock::now();
                for (int i = 0; i < size; i++)
                {
                    cout << arrSorted[i] << " ";
                }
                result = duration_cast<nanoseconds>(end - start);
                cout << endl << "массив отсортировался Shaker sort за " << result.count() << " наносекунд\n" << endl;
                break;
            }
            if (vvod == 3)
            {
                cout << "\nотсортированный массив: \n";
                start = steady_clock::now();
                for (int i = 1; i < size; i++)
                {
                    int key = arrSorted[i];
                    int j = i - 1;
                    while ((j >= 0) and (arrSorted[j] > key))
                    {
                        arrSorted[j + 1] = arrSorted[j];
                        j = j - 1;
                    }
                    arrSorted[j + 1] = key;
                }
                end = steady_clock::now();
                for (int i = 0; i < size; i++)
                {
                    cout << arrSorted[i] << " ";
                }
                result = duration_cast<nanoseconds>(end - start);
                cout << endl << "массив отсортировался Insert sort за " << result.count() << " наносекунд\n" << endl;
                break;
            }
            if (vvod == 4)
            {
                cout << "\nотсортированный массив: \n";
                start = steady_clock::now();
                int swap;
                float k = 1.247, S = size - 1;
                int count = 0;
                while (S >= 1)
                {
                    for (int i = 0; i + S < size; i++)
                    {
                        if (arrSorted[i] > arrSorted[int(i + S)])
                        {
                            swap = arrSorted[int(i + S)];
                            arrSorted[int(i + S)] = arrSorted[i];
                            arrSorted[i] = swap;
                        }
                    }
                    S /= k;
                }

                while (true)
                {
                    for (int i = 0; i < size - 1; i++)
                    {
                        if (arrSorted[i] > arrSorted[i + 1])
                        {
                            swap = arrSorted[i + 1];
                            arrSorted[i + 1] = arrSorted[i];
                            arrSorted[i] = swap;
                        }
                        else count++;
                    }
                    if (count == size - 1)
                        break;
                    else
                        count = 0;
                }
                end = steady_clock::now();
                for (int i = 0; i < size; i++)
                {
                    cout << arrSorted[i] << " ";
                }
                result = duration_cast<nanoseconds>(end - start);
                cout << endl << "массив отсортировался Comb sort за " << result.count() << " наносекунд\n" << endl;
                break;
            }
            if (vvod == 5)
            {
                cout << "\nотсортированный массив: \n";
                start = steady_clock::now();
                int i, j;
                int memory = 0;
                for (int step = size / 2; step > 0; step /= 2)
                    for (i = step; i < size; i++)
                    {
                        memory = arrSorted[i];
                        for (j = i; j >= step; j -= step)
                        {
                            if (memory < arrSorted[j - step])
                                arrSorted[j] = arrSorted[j - step];
                            else
                                break;
                        }
                        arrSorted[j] = memory;
                    }
                end = steady_clock::now();
                for (i = 0; i < size; i++)
                {
                    cout << arrSorted[i] << " ";
                }
                result = duration_cast<nanoseconds>(end - start);
                cout << endl << "массив отсортировался Shell sort за " << result.count() << " наносекунд\n" << endl;
            }
            break;
        }
        case 3: 
        {
            time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> startMinNotSorted, endMinNotSorted, startMaxNotSorted, endMaxNotSorted, startMinSorted, endMinSorted, startMaxSorted, endMaxSorted;
            nanoseconds resultMinNotSorted, resultMaxNotSorted, resultMinSorted, resultMaxSorted;
            startMinNotSorted = steady_clock::now();
            for (int i = 0; i < size; i++)
            {
                if (arrNotSorted[i] < minNotSorted)
                {
                    minNotSorted = arrNotSorted[i];
                }
            }
            endMinNotSorted = steady_clock::now();
            startMaxNotSorted = steady_clock::now();
            for (int i = 0; i < size; i++)
            {
                if (arrNotSorted[i] > maxNotSorted)
                {
                    maxNotSorted = arrNotSorted[i];
                }
            }
            endMaxNotSorted = steady_clock::now();
            resultMinNotSorted = duration_cast<nanoseconds>(endMinNotSorted - startMinNotSorted);
            resultMaxNotSorted = duration_cast<nanoseconds>(endMaxNotSorted - startMaxNotSorted);
            cout << "В неотсортированном:" << endl;
            cout << minNotSorted << " - минимальное, на вычисление потребовалось " << resultMinNotSorted.count() << " наносекунд" << endl;
            cout << maxNotSorted << " - максимальное, на вычисление потребовалось " << resultMaxNotSorted.count() << " наносекунд\n" << endl;

            startMinSorted = steady_clock::now();
            for (int i = 0; i < size; i++)
            {
                if (arrSorted[i] < minSorted)
                {
                    minSorted = arrSorted[i];
                }
            }
            endMinSorted = steady_clock::now();
            startMaxSorted = steady_clock::now();
            for (int i = 0; i < size; i++)
            {
                if (arrSorted[i] > maxSorted)
                {
                    maxSorted = arrSorted[i];
                }
            }
            endMaxSorted = steady_clock::now();
            resultMinSorted = duration_cast<nanoseconds>(endMinSorted - startMinSorted);
            resultMaxSorted = duration_cast<nanoseconds>(endMaxSorted - startMaxSorted);
            cout << "В отсортированном:" << endl;
            cout << minSorted << " - минимальное, на вычисление потребовалось " << resultMinSorted.count() << " наносекунд" << endl;
            cout << maxSorted << " - максимальное, на вычисление потребовалось " << resultMaxSorted.count() << " наносекунд\n" << endl;
            break;
        }
        case 4:
        {
            int countNotSorted = 0;
            int countSorted = 0;
            int srValueNotSorted1;
            int srValueSorted1;
            int indexNotSorted;
            int indexSorted;
            time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> startSrNotSorted, endSrNotSorted, startSrSorted, endSrSorted;
            nanoseconds resultSrNotSorted, resultSrSorted;
            startSrNotSorted = steady_clock::now();
            for (int i = 0; i < size; i++)
            {
                if (arrNotSorted[i] < minNotSorted)
                {
                    minNotSorted = arrNotSorted[i];
                }
            }
            for (int i = 0; i < size; i++)
            {
                if (arrNotSorted[i] > maxNotSorted)
                {
                    maxNotSorted = arrNotSorted[i];
                }
            }
            int srValueNotSorted;
            srValueNotSorted = ((minNotSorted + maxNotSorted) * 10) / 2;
            if (srValueNotSorted < 0)
            {
                if ((srValueNotSorted * (-1)) % 10 >= 5)
                {
                    cout << srValueNotSorted / 10  - 1 << " - среднее значение макисмального и минимального в неотсортированном" << endl;
                    srValueNotSorted1 = srValueNotSorted / 10 - 1;
                }
                if (srValueNotSorted * (-1) % 10 < 5)
                {
                    cout << srValueNotSorted / 10 << " - среднее значение макисмального и минимального в неотсортированном" << endl;
                    srValueNotSorted1 = srValueNotSorted / 10;
                }
            }
            if (srValueNotSorted >= 0)
            {
                if (srValueNotSorted % 10 >= 5)
                {
                    cout << srValueNotSorted / 10 + 1 << " - среднее значение макисмального и минимального в неотсортированном" << endl;
                    srValueNotSorted1 = srValueNotSorted / 10 + 1;
                }
                if (srValueNotSorted % 10 < 5)
                {
                    cout << srValueNotSorted / 10 << " - среднее значение макисмального и минимального в неотсортированном" << endl;
                    srValueNotSorted1 = srValueNotSorted / 10;
                }
            }
            endSrNotSorted = steady_clock::now();
            resultSrNotSorted = duration_cast<nanoseconds>(endSrNotSorted - startSrNotSorted);
            cout << "На вычисление потребовалось " << resultSrNotSorted.count() << " наносекунд" << endl;
            startSrSorted = steady_clock::now();
            for (int i = 0; i < size; i++)
            {
                if (arrSorted[i] < minSorted)
                {
                    minSorted = arrSorted[i];
                }
            }
            for (int i = 0; i < size; i++)
            {
                if (arrSorted[i] > maxSorted)
                {
                    maxSorted = arrSorted[i];
                }
            }
            int srValueSorted;
            srValueSorted = ((minSorted + maxSorted) * 10) / 2;
            if (srValueSorted < 0)
            {
                if ((srValueSorted * (-1)) % 10 >= 5)
                {
                    cout << srValueSorted / 10 - 1 << " - среднее значение макисмального и минимального в отсортированном" << endl;
                    srValueSorted1 = srValueSorted / 10 - 1;
                }
                if (srValueSorted * (-1) % 10 < 5)
                {
                    cout << srValueSorted / 10 << " - среднее значение макисмального и минимального в отсортированном" << endl;
                    srValueSorted1 = srValueSorted / 10;
                }
            }
            if (srValueSorted >= 0)
            {
                if (srValueSorted % 10 >= 5)
                {
                    cout << srValueSorted / 10 + 1 << " - среднее значение макисмального и минимального в отсортированном" << endl;
                    srValueSorted1 = srValueSorted / 10 + 1;
                }
                if (srValueSorted % 10 < 5)
                {
                    cout << srValueSorted / 10 << " - среднее значение макисмального и минимального в отсортированном" << endl;
                    srValueSorted1 = srValueSorted / 10;
                }
            }
            endSrSorted = steady_clock::now();
            resultSrSorted = duration_cast<nanoseconds>(endSrSorted - startSrSorted);
            cout << "На вычисление потребовалось " << resultSrSorted.count() << " наносекунд" << endl;
            for (int i = 0; i < size; i++)
            {
                if (arrNotSorted[i] == srValueNotSorted1)
                {
                    cout << arrNotSorted[i] << " - элемент с индексом " << i << " в неосортированном" << endl;
                    countNotSorted += 1;
                }
            }
            cout << "Всего таких элементов в неотсортированном массиве " << countNotSorted << endl;
            for (int i = 0; i < size; i++)
            {
                if (arrSorted[i] == srValueSorted1)
                {
                    cout << arrSorted[i] << " - элемент с индексом " << i << " в осортированном" << endl;
                    countSorted += 1;
                }
            }
            cout << "Всего таких элементов в отсортированном массиве " << countSorted << endl;
            break;
        }
        case 5:
        {
            cout << "Введите число" << endl;
            int a;
            int result = 0;
            int i = 0;
            cin >> a;
            while (arrSorted[i] < a)
            {
                result += 1;
                i += 1;
            }
            cout << "В массиве " << result << " меньших числа " << a << endl;
            break;
        }
        case 6:
        {
            cout << "Введите число" << endl;
            int b;
            int result = 0;
            int i = 99;
            cin >> b;
            while (arrSorted[i] > b)
            {
                result += 1;
                i -= 1;
            }
            cout << "В массиве " << result << " больших числа " << b << endl;
            break;
        }
        case 8:
        {
            int swap1 = 0;
            int swap2 = 0;
            cout << "Введите первый индекс элемента массива: " << endl;
            int numb1;
            cin >> numb1;
            cout << "Введите второй индекс элемента массива: " << endl;
            int numb2;
            cin >> numb2;
            

            time_point<steady_clock, duration<__int64, ratio<1, 100000000000000>>> startSwitchElements, endSwitchElements;
            nanoseconds resultSwitchElements;
            startSwitchElements = steady_clock::now();
            swap1 = arrSorted[numb1];
            arrSorted[numb1] = arrSorted[numb2];
            swap2 = swap1;
            arrSorted[numb2] = swap2;
            endSwitchElements = steady_clock::now();

            for (int i = 0; i < size; i++)
            {
                cout << arrSorted[i] << " ";
            }

            resultSwitchElements = duration_cast<nanoseconds>(endSwitchElements - startSwitchElements);
            cout << "\nЭлементы поменялись местами за " << resultSwitchElements.count() << " наносекунд" << endl;
            break;
        }
        default:
            cout << "Доступно только 8 заданий";
        }
        _getch();
    }
    return 0;
}