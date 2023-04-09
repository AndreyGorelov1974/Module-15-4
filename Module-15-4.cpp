/*Задача 4
Что нужно сделать
Вам даётся массив целых чисел, отсортированных по возрастанию.
Необходимо вывести его на экран отсортированным в порядке возрастания модуля чисел.

Пример:

Массив {-100,-50, -5, 1, 10, 15}

Вывод: 1, -5, 10, 15, -50, -100

Советы и рекомендации
Положительные числа уже отсортированы в порядке возрастания модулей.*/

#include <iostream>
#include <algorithm>

//размер массива
const size_t sizeArray = 10;

int main()
{
	//инициализируем массив 
	int arr[sizeArray] = { -10,-9, -8, -7, -6,-5, -4,5,9,8 };

	////заполняем массив случайными числами
	//srand(time(NULL));
	//for (int i = 0; i < sizeArray; ++i) {
	//	rand() % 2 == 0 ? arr[i] = rand() % 100 : arr[i] = -1 * (rand() % 100);
	//}
	////сортируем массив
	std::sort(arr, &arr[sizeArray]);

	//вывод отсортированного массива
	for (size_t i = 0; i < sizeArray; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	int indexMin = 0;
	int indexMax = 0;

	for (size_t i = 0; i < sizeArray; ++i)
	{
		if (arr[i] > 0 && i > 0) {
			indexMin = i - 1;
			indexMax = i;
			break;
		}
	}

	for (size_t i = indexMax; i < sizeArray; ++i) {
		while ((indexMin > -1) && (abs(arr[indexMin]) < arr[i])) {
			std::cout << arr[indexMin] << " ";
			--indexMin;
		}
		std::cout << arr[i] << " ";
	}
	if (indexMin > -1) {
		for (int i = indexMin; i >= 0; --i) {
			std::cout << arr[i] << " ";
		}
	}
}
