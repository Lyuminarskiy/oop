[Назад к описанию](../../README.md)

# Шаблоны и исключительные ситуации

Содержание:
- [Цель работы](#Цель-работы)
- [Теоретические сведения](#Теоретические-сведения)
- [Задание](#Задание)
  - [Вариант №1](#Вариант-№1)
  - [Вариант №2](#Вариант-№2)
  - [Вариант №3](#Вариант-№3)
- [Вопросы](#Вопросы)

## Цель работы

Научиться применять на практике шаблоны и исключительные ситуации.

## Теоретические сведения

С момента введения механизма шаблонов и исключительных ситуаций современные компиляторы стали позволили достичь двух актуальных целей программирования: многократное использование программ и их высокую отказоустойчивость.

С помощью шаблонов можно создавать шаблонные функции и шаблонные классы, в которых типы данных, с которыми они работают, задаются в качестве параметра. Это позволяет использовать одну и ту же реализацию класса или функции с различными типами данных.

Основная форма объявления шаблонного класса:

```c++
template <class тип> class имя_класса
{
    // тело класса
}
```

Создание экземпляра шаблонного класса:

```c++
имя_класса<тип> имя_объекта;
```

При помощи механизма обработки исключительных ситуаций, возможно работать с ошибками, которые возникают в процессе работы программы, заранее предусмотренным и управляемым образом.

Пример:

```c++
try
{
    // блок кода, в котором может возникнуть искл. ситуация
}
catch (type arg)
{
    // обработка исключительной ситуации типа type
}
```

## Задание

Используя принципы ООП, необходимо реализовать программу на языке программирования `С++` в зависимости от варианта:

```
Вариант = ((номер_студента_по_списку - 1) % 3) + 1
```

### Вариант №1

Используя шаблоны и исключительные ситуации реализовать класс контейнер очередь (FIFO).

### Вариант №2

Используя шаблоны и исключительные ситуации реализовать класс контейнер стек (LIFO).

### Вариант №3

Используя шаблоны и исключительные ситуации реализовать класс контейнер пара (Pair).

## Вопросы

1. Что такое шаблоны, и где они применятся?
2. Зачем нужны исключительные ситуации?
3. Какие из принципов ООП используются в данной работе?
4. В чем отличие динамического и статического полиморфизма?