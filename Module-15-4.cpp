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
#include <vector>


int main()
{
	//инициализируем вектор 
	std::vector<int> userVector(0);
	//инициализируем переменную для ввода элемента массива 
	int elements = 0;
	//инициализируем индекс для сортировки 
	size_t index = 0;

	//ввод первого элемента
	std::cout << "Input numbers: ";
	std::cin >> elements;

	//основной цикл продолжается пока не ввели -2
	while (elements != -2) {
		//если ввели -1 
		if (elements == -1) {
			//проверяем длинну вектора
			if (userVector.size() < 5) {
				//если меньше 5 выводим предупреждение
				std::cout << "There are still less than five elements in the array!" << std::endl;
			}
			else {
				//если больше 5 выводим 5 по порядку элемент
				std::cout << "Five element: " << userVector[4] << std::endl;
			}
		}
		//если ввели новый элемент вектора
		else {
			//вставляем его в конец вектора
			userVector.push_back(elements);
			//устанавливаем индекс на новый элемент
			index = userVector.size() - 1;
			//двигаемего к началу на своё место по порядку
			while ((index > 0) && (userVector[index] < userVector[index - 1])) {
				std::swap(userVector[index], userVector[index - 1]);
				--index;
			}
		}
		//вывод отсортированного вектора
		for (int i = 0; i < userVector.size(); ++i)
		{
			std::cout << userVector[i] << " ";
		}
		std::cout << std::endl;
		//ввод следующего элемента
		std::cout << "Input numbers: ";
		std::cin >> elements;
	}
}
