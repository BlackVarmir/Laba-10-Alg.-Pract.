#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Функція для генерації випадкових чисел у заданому діапазоні
int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Завдання 1: Знайти мінімальний елемент та добуток всіх додатних елементів
void task1(vector<int>& arr) {
    int minElement = arr[0];
    int product = 1;
    bool hasPositive = false;

    for (int num : arr) {
        if (num < minElement) {
            minElement = num;
        }
        if (num > 0) {
            product *= num;
            hasPositive = true;
        }
    }

    cout << "Мінімальний елемент: " << minElement << endl;
    if (hasPositive) {
        cout << "Добуток всіх додатних елементів: " << product << endl;
    }
    else {
        cout << "Немає додатних елементів." << endl;
    }
}

// Завдання 2: Скалярний добуток двох масивів
void task2(vector<int>& arr1, vector<int>& arr2) {
    int scalarProduct = 0;
    for (size_t i = 0; i < arr1.size(); ++i) {
        scalarProduct += arr1[i] * arr2[i];
    }
    cout << "Скалярний добуток масивів: " << scalarProduct << endl;
}

// Завдання 3: Сума елементів двох масивів
void task3(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    for (size_t i = 0; i < arr1.size(); ++i) {
        arr3[i] = arr1[i] - arr2[i];
    }

    cout << "Масив c (різниця елементів a[i] - b[i]): ";
    for (int num : arr3) {
        cout << num << " ";
    }
    cout << endl;
}

// Завдання 4: Перетворення масиву, заміна парних на 0, непарних на 1
void task4(vector<int>& arr) {
    for (int& num : arr) {
        num = (num % 2 == 0) ? 0 : 1;
    }

    cout << "Масив після перетворення: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Завдання 5: Мінімальний непарний елемент і його порядковий номер
void task5(vector<int>& arr) {
    int minOdd = INT_MAX;
    int index = -1;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2 != 0 && arr[i] < minOdd) {
            minOdd = arr[i];
            index = i;
        }
    }

    if (index != -1) {
        cout << "Мінімальний непарний елемент: " << minOdd << ", його порядковий номер: " << index + 1 << endl;
    }
    else {
        cout << "Немає непарних елементів." << endl;
    }
}

int main() {
    srand(time(0));

    int n;
    cout << "Введіть розмір масивів: ";
    cin >> n;

    vector<int> arr1(n), arr2(n), arr3(n);

    int choice;
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Знайти мінімальний елемент та добуток всіх додатних елементів\n";
        cout << "2. Знайти скалярний добуток двох масивів\n";
        cout << "3. Записати в масив c[i] суму відповідних елементів a[i] - b[i]\n";
        cout << "4. Перетворити масив (парні на 0, непарні на 1)\n";
        cout << "5. Знайти мінімальний непарний елемент та його порядковий номер\n";
        cout << "0. Вихід\n";
        cout << "Виберіть пункт меню: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Заповнення масиву випадковими числами з діапазону [-10; 10]
            for (int i = 0; i < n; ++i) {
                arr1[i] = generateRandom(-10, 10);
            }
            task1(arr1);
            break;
        case 2:
            // Заповнення двох масивів випадковими числами з діапазону [-10; 10]
            for (int i = 0; i < n; ++i) {
                arr1[i] = generateRandom(-10, 10);
                arr2[i] = generateRandom(-10, 10);
            }
            task2(arr1, arr2);
            break;
        case 3:
            // Заповнення двох масивів випадковими числами з діапазону [-10; 10]
            for (int i = 0; i < n; ++i) {
                arr1[i] = generateRandom(-10, 10);
                arr2[i] = generateRandom(-10, 10);
            }
            task3(arr1, arr2, arr3);
            break;
        case 4:
            // Заповнення масиву випадковими числами з діапазону [0; 20]
            for (int i = 0; i < n; ++i) {
                arr1[i] = generateRandom(0, 20);
            }
            task4(arr1);
            break;
        case 5:
            // Заповнення масиву випадковими числами з діапазону [0; 20]
            for (int i = 0; i < n; ++i) {
                arr1[i] = generateRandom(0, 20);
            }
            task5(arr1);
            break;
        case 6:
            cout << "Перший масив: ";
            for (int i = 0; i < n; ++i) {
				cout << arr1[i] << " ";
            }
			cout << endl;

            cout << "Другий масив: ";
            for (int i = 0; i < n; ++i) {
				cout << arr2[i] << " ";
            }
			cout << endl;

            cout << "Третій масив: ";
			for (int i = 0; i < n; ++i) {
				cout << arr3[i] << " ";
			}
			cout << endl;
			break;
        case 0:
            return 0;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    }
}
