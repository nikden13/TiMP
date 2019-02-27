# Практическая работа №2

## Варианты и задания

**Вариант 3. Сумма последовательности.** На вход подается число *n* ∈ N: *n* ≤ 2147483647, а также *n* чисел *xi* ∈ Z: |xi| ≤ 2147483647 для любого целого *i* от 1 до *n*. Вывести значение Σ*xi*.

**Вариант 14. Сумма нечётных квадратов.** На вход подается число *n* ∈ N: *n* ≤ 2147483647, а также *n* чисел *xi* ∈ Z: |xi| ≤ 2147483647 для любого целого *i* от 1 до *n*. Вывести значение Σ(*i* mod 2)*(xi)2*.

## Ход работы

1. Был написан код для каждого из задания.
2. Каждый файл с кодом был скомпилирован и запущен для проверки:
.. gcc 03_summa_posledovatelnosty.c -p 03_summa_posledovatelnosty
.. ./03_summa_posledovatelnosty
.. gcc 14_summa_nechet_kvadratov.c -p 14_summa_nechet_kvadratov
.. ./14_summa_nechet_kvadratov
3. Файлы были загружены на удалённый репозиторий:
..* git checkout -b pr2
..* git add .
..* git commit -m "Added files for the second practical work"
..* git push -u origin pr2

## Результаты

Результаты представлены на скриншотах.
Сумма последовательности:
На вход поступило 5 целых чисел, сумма которых в результате программы оказалась равна 25.
![2019-02-28 03-31-44](https://user-images.githubusercontent.com/47746685/53521381-8b0b5c00-3b0a-11e9-96f1-3b971b20280e.png)

Сумма нечётных квадратов:
На вход поступило 5 целых чисел. Сумма квадратов чисел с нечётными индексами в результате программы оказалась равна 110.
![2019-02-28 03-45-41](https://user-images.githubusercontent.com/47746685/53521671-551aa780-3b0b-11e9-9555-a5a620ab3340.png)




