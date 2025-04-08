#include <stdio.h>
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>

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

void inclusionSortTrdTask(int* num, int size)
{
    auto begin = std::chrono::steady_clock::now();

    int cmp = 0, chg = 0, itr = 0;
    cout << "\n-------Сортировка с помощью прямого включения-------\n";
    // Для всех элементов кроме начального
    for (int i = 1; i < size; i++)
    {
        itr++;
        int value = num[i]; chg++; // запоминаем значение элемента
        int index = i; chg++;     // и его индекс
        cmp++;
        while ((index > 0) && (num[index - 1] < value) && num[index] % 2 == 0)
        {
            itr++;
            // смещаем другие элементы к концу массива пока они меньше index

            num[index] = num[index - 1]; chg++;
            index--;    // смещаем просмотр к началу массива
            cmp++;
        }
        num[index] = value; chg++;; // рассматриваемый элемент помещаем на освободившееся место
    }
    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Итераций = " << itr << "\t\tСравнений = " << cmp << "\t\tОбменов = " << chg << "\t\tВремя выполнения: " << elapsed_ms.count() << " миллисекунд" << endl;
}

void inclusionSort(int* num, int size)
{
    auto begin = std::chrono::steady_clock::now();

    int cmp = 0, chg = 0, itr = 0;
    cout << "\n-------Сортировка с помощью прямого включения-------\n";
    // Для всех элементов кроме начального
    for (int i = 1; i < size; i++)
    {
        itr++;
        int value = num[i]; chg++; // запоминаем значение элемента
        int index = i; chg++;     // и его индекс
        cmp++;
        while ((index > 0) && (num[index - 1] > value))
        {
            itr++;
            // смещаем другие элементы к концу массива пока они меньше index

            num[index] = num[index - 1]; chg++;
            index--;    // смещаем просмотр к началу массива
            cmp++;
        }
        num[index] = value; chg++;; // рассматриваемый элемент помещаем на освободившееся место
    }
    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Итераций = " << itr << "\t\tСравнений = " << cmp << "\t\tОбменов = " << chg << "\t\tВремя выполнения: " << elapsed_ms.count() << " миллисекунд" << endl;
}

void selectionSort(int* num, int size) {
    auto begin = std::chrono::steady_clock::now();
    int cmp = 0, chg = 0, itr = 0;
    cout << "\n-------Сортировка с помощью прямого выбора-------\n";
    int min, temp; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size - 1; i++)
    {
        itr++;
        min = i;  chg++;// запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
        {
            itr++;
            cmp++;
            if (num[j] < num[min]) // если элемент меньше минимального,
                min = j; chg++;      // запоминаем его индекс в min
        }
        cmp++;
        if (min == i) { continue; }  // чтобы не менять элемент сам с собой
        temp = num[i]; chg++;      // меняем местами i-ый и минимальный элементы
        num[i] = num[min]; chg++;
        num[min] = temp; chg++;
    }

    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Итераций = " << itr << "\t\tСравнений = " << cmp << "\t\tОбменов = " << chg << "\t\tВремя выполнения: " << elapsed_ms.count() << " миллисекунд" << endl;
}

void bubbleSort(int* num, int size) {
    auto begin = std::chrono::steady_clock::now();
    int cmp = 0, chg = 0, itr = 0;

    cout << "\n-------Сортировка пузырьком-------\n";

    // Для всех элементов
    for (int i = 0; i < size - 1; i++) {
        itr++;
        for (int j = (size - 1); j > i; j--) {
            itr++;// для всех элементов после i-ого
            cmp++;
            if (num[j - 1] > num[j]) {
                ;// если текущий элемент меньше предыдущего
                int temp = num[j - 1]; chg++; // меняем их местами
                num[j - 1] = num[j]; chg++;
                num[j] = temp; chg++;
            }
        }
    }


    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Итераций = " << itr << "\t\tСравнений = " << cmp << "\t\tОбменов = " << chg << "\t\tВремя выполнения: " << elapsed_ms.count() << " миллисекунд" << endl;
}

void quickSort(int* numbers, int left, int right, int& cmp, int& chg, int& itr) {
    itr++; // Считаем итерации (каждый раз, когда вызываем quickSort)

    int pivot = numbers[left]; // Разрешающий элемент
    int l_hold = left, r_hold = right; // Границы

    while (left < right) { // Пока границы не сомкнутся
        cmp++; // Сравнение
        while (numbers[right] > pivot && left < right) {
            right--;
            cmp++; // Ещё одно сравнение
        }

        if (left != right) { // Если границы не сомкнулись
            numbers[left] = numbers[right]; // Обмен
            chg++;
            left++;
        }

        cmp++; // Сравнение
        while (numbers[left] < pivot && left < right) {
            left++;
            cmp++; // Ещё одно сравнение
        }

        if (left != right) {
            numbers[right] = numbers[left]; // Обмен
            chg++;
            right--;
        }
    }

    numbers[left] = pivot; // Ставим разрешающий элемент на место
    chg++;
    int index = left;

    if (l_hold < index - 1)
        quickSort(numbers, l_hold, index - 1, cmp, chg, itr); // Рекурсивный вызов для левой части

    if (r_hold > index + 1)
        quickSort(numbers, index + 1, r_hold, cmp, chg, itr); // Рекурсивный вызов для правой части
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
            cout << "\n---------------------------------------------------\n";

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
            rnd = rand() % (size * 2 - start + 1);

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
            cout << "\n---------------------------------------------------\n";

            auto end = std::chrono::steady_clock::now();

            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

            cout << "    " << cmp << " сравнений" << "\t за: " << elapsed_ms.count() << " миллисекунд" << endl;
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

        int size, end, start;
        IOPUT(int, size, "\nВведите размер массива: ");
        int* arr = new int[size];

        int thirdCaseSwtch;
        IOPUT(int, thirdCaseSwtch, "\n1 - ввести массив ручками\n2 - сгенерировать массив случайно\n")
            cout << "\n";
        if (thirdCaseSwtch == 1) {
            InputIntElemsArr(arr, size);
        }
        else if (thirdCaseSwtch == 2)
        {
            start = -20;
            end = 20;

            for (int i = 0; i < size; i++)
            {
                arr[i] = rand() % (end - start + 1) + start;
            }
        }
        else {
            cout << "Не балуйтесь с клавиатурой!!!"; return 0;
        }


        inclusionSortTrdTask(arr, size);

        cout << "\n";
        for (int i = 0; i < size; i++) {

            printf("%d ", arr[i]);
        }
        cout << "\n\n";
        return 0;


    }
    default: { printf("\nВведён неверный номер!\n"); exit(0); }
    }
}