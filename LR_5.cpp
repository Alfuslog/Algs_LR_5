#include <stdio.h>
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <string>

using namespace std;

#define IOPUT(type, var, prompt)\
    cout << prompt;\
    if (!(cin >> var) ){\
        cout << "\nВведено некорректное значение!\n";\
        exit(-1);\
    }

void InputIntElemsArr(int* arr, int size) {
    printf("\nЗаполните массив через Enter:\n\n");
    for (int i = 0; i < size; i++) {
        cout << i + 1; IOPUT(int, arr[i], ")");
    }
}
void InputFloatElemsArr(int* arr, int size) {
    printf("\nЗаполните массив через Enter:\n\n");
    for (int i = 0; i < size; i++) {
        cout << i + 1; IOPUT(double, arr[i], ")");
    }
}
void NewPointer(int* arr, int size, int** ptrArr) {
    for (int i = 0; i < size; i++) {
        ptrArr[i] = new int(arr[i]);
    }
}
void WritePtr(int** ptrArr, int iPtr, int chislo) {
    *(ptrArr[iPtr - 1]) = chislo;
}
void ReadPtr(int** ptrArr, int iPtr) {
    cout << *(ptrArr[iPtr - 1]);
}
void freePtr(int* arr, int** ptrArr) {
    delete[] arr;
    delete[] ptrArr;
}

// функция с алгоритмом двоичного поиска 
void Search_Binary(int arr[], int left, int right, int key)
{
    string otvet;
    int cntSravn = 0, midd = 0;
    while (1)
    {
        midd = (left + right) / 2;
        cntSravn++;
        if (key < arr[midd])       // если искомое меньше значения в ячейке
            right = midd - 1;      // смещаем правую границу поиска
        
        else if (key > arr[midd]) {  // если искомое больше значения в ячейке
            cntSravn++;
            left = midd + 1;	   // смещаем левую границу поиска
        }
        else {                      // иначе (значения равны)
            cout << "\nЗначение " << arr[midd] << " находится в ячейке с индексом: " << midd << endl;
            string otvet = to_string(midd) + "";// функция возвращает индекс ячейки
        }
        cntSravn++;
        if (left > right) {          // если границы сомкнулись 
            cout << "В массиве нет такого значения";

        }
        cout << "\n\tСравнений: " << cntSravn << endl;
    }
}

int linSearch(int arr[], int requiredKey, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == requiredKey)
            return i;
    }
    return -1;
}


int main() {
    cin.clear();
    setlocale(LC_ALL, "RUS");
    int choise;

    IOPUT(int, choise, "\nВведите номер задания: ");
    switch (choise) {
    case(1): {

        int requiredKey;
        IOPUT(int, requiredKey,"Введите искомое значение:..")

        int rnd, nElement;
        int start = 0;


        int fixArr[6] = { 20, 500, 1000, 3000, 5000, 10000 };

        for (int i = 0; i < 6; i++) {
            printf("\n\n\t\tДля %d элементов:\n", fixArr[i]);

            int size = fixArr[i];
            int* arr1 = new int[size];


            for (int i = 0; i < size; i++)
            {
                rnd = rand() % (size - start + 1) + start;
                arr1[i] = rnd;
            }


            auto begin = std::chrono::steady_clock::now();

            int cmp = 0;
            nElement = linSearch(arr1, requiredKey, size);

            if (nElement != -1){
                //если в массиве найдено искомое число - выводим индекс элемента на экран
                cout << "\nЗначение " << requiredKey << " находится в ячейке с индексом: " << nElement << endl;
            }
            else{
                //если в массиве не найдено искомое число
                cout << "В массиве нет такого значения" << endl;
            }

            auto end = std::chrono::steady_clock::now();

            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

            cout << "    " << cmp << " сравнений" << "\t за: " << elapsed_ms.count() << " миллисекунд" << endl;
        }

        break;
    }
    case(2): {

        int size, start = 0, rnd, nElement, requiredKey;


        IOPUT(int, size, "\nВведите размер массива: ");

        IOPUT(int, requiredKey, "Введите искомое значение:..")

        int* arr1 = new int[size];//1   итоговый
        int* arr2 = new int[size];//2 уже отсортированный
        int* arr3 = new int[size];//3 отсортированный в обратном порядке
        int* arr4 = new int[size];//4 частично отсортированный 25
        int* arr5 = new int[size];//5 50
        int* arr6 = new int[size];//6 75

        for (int i = size - 1; i >= 0; i--)
        {
            rnd = rand() % (size/4 - start + 1);

            if (i > (3 * size) / 4) {  //6 75
                arr6[i] = rnd;
            }
            else {
                arr6[i] = i + 1;
            }
            if (i > (size) / 2) { //5 50
                arr5[i] = rnd;
            }
            else {
                arr5[i] = i + 1;
            }
            if (i > (size) / 4) { //4 частично отсортированный 25
                arr4[i] = rnd;
            }
            else {
                arr4[i] = i + 1;
            }

            arr1[i] = rnd;          //1   итоговый

            arr2[size - i - 1] = i;      //2 уже отсортированный

            arr3[i] = i;            //3 отсортированный в обратном порядке
        }

        int* arrays[] = { arr1, arr2, arr3, arr4, arr5, arr6 };
        for (int i = 0; i < 6; i++) {
            cout << "\n\nДля " << i + 1 << " массива:\n";

            int key = 0;
            int index = 0;


            cout << "\n------------------Линейный посик---------------------\n";
            auto begin = std::chrono::steady_clock::now();
            nElement = 0;
            int cmp = 0;
            nElement = linSearch(arr1, requiredKey, size);

            if (nElement != -1) {
                //если в массиве найдено искомое число - выводим индекс элемента на экран
                cout << "\nЗначение " << requiredKey << " находится в ячейке с индексом: " << nElement << endl;
            }
            else {
                //если в массиве не найдено искомое число
                cout << "В массиве нет такого значения" << endl;
            }

            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            
            cout << "    " << cmp << " сравнений" << "\t за: " << elapsed_ms.count() << " миллисекунд" << endl;
        

            cout << "\n------------------Бинарный посик---------------------\n";
        
            auto FndBegin = std::chrono::steady_clock::now();
            nElement = 0;
            cmp = 0;
            nElement = linSearch(arr1, requiredKey, size);

            if (nElement != -1) {
                //если в массиве найдено искомое число - выводим индекс элемента на экран
                cout << "\nЗначение " << requiredKey << " находится в ячейке с индексом: " << nElement << endl;
            }
            else {
                //если в массиве не найдено искомое число
                cout << "В массиве нет такого значения" << endl;
            }

            auto fndEnd = std::chrono::steady_clock::now();
            auto FndElapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(fndEnd - FndBegin);

            cout << "    " << cmp << " сравнений" << "\t за: " << elapsed_ms.count() << " миллисекунд" << endl;




            Search_Binary(arr1, 0, size, requiredKey);

            if (index >= 0)
                cout << "Указанное число находится в ячейке с индексом: " << index << "\n\n";
            else
                cout << "В массиве нет такого числа!\n\n";

        }


        cout << "\n";
        for (int i = 0; i < size; i++) {

            printf("%d ", arr1[i]);
        }
        cout << "\n\n";

        // Освобождаем память
        for (int* arr : { arr1, arr2, arr3, arr4, arr5, arr6 }) {
            delete[] arr;
        }
        break;
    }
    case(3):
    {
        srand(time(0));
        int sizes[] = { 1000, 2000, 3000, 5000, 10000 };
        int target = -1; // значение, которое точно не будет найдено для худшего случая

        for (int s = 0; s < 5; ++s) {
            int size = sizes[s];
            int* arr = new int[size + 1]; 
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 10000;
            }

            // ЛИНЕЙНЫЙ ПОИСК БЕЗ БАРЬЕРА
            int comparisons = 0;
            auto start = chrono::steady_clock::now();
            int index = -1;
            for (int i = 0; i < size; i++) {
                comparisons++;
                if (arr[i] == target) {
                    index = i;
                    break;
                }
            }
            auto end = chrono::steady_clock::now();
            auto time_no_barrier = chrono::duration_cast<chrono::microseconds>(end - start);

            cout << "\nРазмер массива: " << size;
            cout << "\n[Без барьера] Сравнений: " << comparisons << ", Время: " << time_no_barrier.count() << " мкс";


            // ЛИНЕЙНЫЙ ПОИСК С БАРЬЕРОМ
            comparisons = 0;
            arr[size] = target; // барьер
            start = chrono::steady_clock::now();
            int i = 0;
            while (arr[i] != target) {
                comparisons++;
                i++;
            }
            end = chrono::steady_clock::now();
            auto time_with_barrier = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "\n[С барьером] Сравнений: " << comparisons << ", Время: " << time_with_barrier.count() << " мс\n";

            delete[] arr;
        }
        break;
    }

    default: { printf("\nВведён неверный номер!\n"); exit(0); }
    }
}