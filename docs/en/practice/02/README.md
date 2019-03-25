# 2. Inheritance and Polymorphism. Interfaces and Abstract classes

## Lesson's topics

- Inheritance and Polymorphism.
- `protected` access modifier.
- Interfaces, Abstract classes and Multiple Inheritance.
- Generic Classes and Methods.

## Theoretical Information

The `protected` access modifier defines _protected_ members of a class 
that can be used by the class that defined them and any child class.

## 2.1. Inheritance and Polymorphism

Using the human type `Human`, created in the task [1.3. The Human Type
](/practice/01/#_1-3-the-human-type), perform the following tasks:

1. Create the citizen type `Citizen`, inheriting from the human type.

2. Create the worker type `Worker`, inheriting from the citizen type.

3. Define access modifiers for class members.

4. Demonstrate how to work with the citizen and worker types.

5. Demonstrate polymorphism of the human type and his children by creating
following function:

    Signature | Return type | Description
    --------- |:-----------:| -----------
    `display(Human[])` | - | Displays information about all the humans in the array.
    
    Demonstrate how to work with this function by passing it an array filled 
    with instances of the human type and it's children. For instances of
    different types, different information should be displayed.

### The Citizen Type

#### Fields

Create the following fields:

Name | Type | Access | Description
:---:|:----:|:------:| -----------
`id` | `int` | `Read` | The citizen's ID. It must consist of `10` digits.

#### Constructors

Create the following constructors:

Signature | Description
--------- | -----------
`Citizen(int id, string name, string surname, Gender gender)` | Creates a citizen with the ID `id`, the name `name`, the surname `surname` and the gender `gender` (numeric fields are `0`).
`Citizen(int id, string name, string surname, Gender gender, int age, float height, float weight)` | Creates a citizen with the ID `id`, the name `name`, the surname `surname`, the gender `gender`, the age `age`, the height `height` and the weight `weight`.
`Citizen(Citizen)` | Creates a citizen by copying data from another citizen.

#### Methods

Create the following methods:

Signature | Return type | Description
--------- |:-----------:| -----------
`override` `copy()` | `Citizen` | Returns a copy of the citizen.
`equals(Citizen)` | `bool` | Returns the result of comparing the citizen with another citizen by name, surname and ID.
`static` `equals(Citizen first, Citizen second)` | `bool` | Returns the result of comparing the citizen `first` with the citizen `second` by name, surname and ID.
`override` `toString()` | `string` | Returns a string* with the information about the citizen.
  
Remarks:

_* Example of a string:_

```
# 1234567890
John Smith, male, 31 y.o.
Height: 171,2 cm
Weight: 62,3 kg
```

### The Worker Type

#### Поля

Create the following fields:

Name | Type | Access | Description
:---:|:----:|:------:| -----------
`jobTitle` | `string` | `Read` `Write` | The worker's job title.

#### Constructors

Create the following constructors:

Signature | Description
--------- | -----------
`Worker(string jobTitle, int id, string name, string surname, Gender gender, int age, float height, float weight)` | Creates a worker with the job title `jobTitle`, the ID `id`, the name `name`, the surname `surname`, the gender `gender`, the age `age`, the height `height` and the weight `weight`.
`Worker(Worker)` | Creates a worker by copying data from another worker.

#### Methods

Create the following methods:, ID and job title.

Signature | Return type | Description
--------- |:-----------:| -----------
`override` `copy()` | `Worker` | Returns a copy of the worker.
`equals(Worker)` | `bool` | Returns the result of comparing the worker with another worker by name, surname, ID and job title.
`static` `equals(Worker first, Worker second)` | `bool` | Returns the result of comparing the worker `first` with the worker `second` by name, surname, ID and job title.
`override` `toString()` | `string` | Returns a string* with the information about the worker.
  
Remarks:

_* Example of a string:_

```
Senior Developer
# 1234567890
John Smith, male, 31 y.o.
Height: 171,2 cm
Weight: 62,3 kg
```

## 2.2. Interfaces, Abstract classes and Multiple Inheritance

## 2.3. Generic Classes and Methods

Tasks:

1. Create a generic doubly linked list `List <T>`, where `T` is an arbitrary type.

2. List items should be presented as a separate generalized
type `Item <T>`, nested in the type of list.

3. Define access modifiers for class members.

4. Demonstrate how to work with the list type.

### Тип элемента списка

#### Поля

Создайте следующие поля:

Имя | Тип | Доступ | Описание
:--:|:---:|:------:| --------
`value` | `T` | `Чтение` `Запись` | Значение, хранимое в элементе списка.
`prev` | `Item<T>` | `Чтение` `Запись` | Ссылка на предыдущий элемент списка.
`next` | `Item<T>` | `Чтение` `Запись` | Ссылка на последующий элемент списка.

Заметьте, что у первого элемента списка нет предудыщего элемента,
а у последего элемента - последующего.

#### Конструкторы

Создайте следующие конструкторы:

Сигнатура | Описание
--------- | --------
`Item(T)` | Создаёт элемент и сохраняет в нём указанное значение.
`Item(T value, Item<T> prev, Item<T> next)` | Создаёт элемент и сохраняет в нём значение `value`, а также ссылки на предыдущий `prex` и последующий `next` элементы списка.
`Item(Item<T>)` | Создаёт элемент, копируя данные из другого элемента.

#### Методы

Создайте следующие методы:

Сигнатура | Возвр. тип | Описание
--------- |:----------:| --------
`equals(Item<T>)` | `bool` | Возвращает результат сравнения элемента с другим элементом по значению.
`static` `equals(Item<T> first, Item<T> second)` | `bool` | Возвращает результат сравнения элемента `first` с элементом `second` по значению.

### Тип двусвязного списка

#### Поля

Создайте следующие поля:

Имя | Тип | Доступ | Описание
:--:|:---:|:------:| --------
`head` | `Item<T>` | - | Ссылка на первый элемент списка.
`tail` | `Item<T>` | - | Ссылка на предыдущий элемент списка.
`size` | `int` | `Чтение` | Количество элементов в списке.

#### Конструкторы

Создайте следующие конструкторы:

Сигнатура | Описание
--------- | --------
`List()` | Создаёт пустой список.
`List(List<T>)` | Создаёт список, копируя данные из другого списка.

#### Методы

Создайте следующие методы:

Сигнатура | Возвр. тип | Описание
--------- |:----------:| --------
`append(T)`| - | Добавляет новый элемент в конец списка.
`append(List<T>)`| - | Добавляет элементы из другого списка в конец списка.
`clear()` | - | Удаляет все элементы из списка.
`contains(T)` | `bool` | Возвращает результат проверки того, что указанное значение есть в списке.
`copy()` | `List<T>` | Возвращает копию списка.
`equals(List<T>)` | `bool` | Возвращает результат поэлементного сравнения списка с другим списком.
`static` `equals(List<T> first, List<T> second)` | `bool` | Возвращает результат поэлементного сравнения `first` со списком `second`.
`getItem(int)` | `T` | Возвращает значение, хранящееся в элементе списка с указанным индексом.
`indexOf(T value, int index)` | `int` | Возвращает индекс первого найденного вхождения значения `value` в пределах всего списка, начиная с указанного индекса `index`.
`insert(T value, int index)` | - | Добавляет новый элемент со значением `value` в список по индексу `index`.
`insert(List<T> list, int index)` | - | Добавляет элементы из другого списка `list` в список, начиная с индекса `index`.
`lastIndexOf(T value, int index)` | `int` | Возвращает индекс последнего найденного вхождения значения `value` в пределах всего списка, начиная с указанного индекса `index`.
`prepend(T)` | - | Добавляет новый элемент в начало списка.
`prepend(List<T>)`| - | Добавляет элементы из другого списка в начало списка.
`remove(int)` | - | Удаляет элемент списка с указанным индексом.
`remove(int start, int end)` | - | Удаляет элементы списка в указанном диапазоне.
`reverse()` | - | Обращает порядок элементов в списке.

::: warning Обратите внимание!
При удалении списка должны удаляться и его элементы. Если вы используете
язык с ручным управлением памятью (например, `C++`), то создайте
**деструктор класса**.
:::