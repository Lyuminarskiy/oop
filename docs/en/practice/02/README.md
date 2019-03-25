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

#### Fields

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

Create the following methods:

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

1. Create the doubly linked list generic type `List<T>`,
where `T` is an arbitrary type.
2. List items must be represented by the separate generic type `Item<T>`
nested in a list type.
3. Define access modifiers for class members.
4. Demonstrate how to work with the list type.

### The List Item Type

#### Fields

Create the following fields:

Name | Type | Access | Description
:---:|:----:|:------:| -----------
`value` | `T` | `Read` `Write` | The value stored in the list item.
`prev` | `Item<T>` | `Read` `Write` | Reference to the previous list item.
`next` | `Item<T>` | `Read` `Write` | Reference to the next list item.

Notice that the first list item does not have a previous item,
and the last item has no follow item.

#### Constructors

Create the following constructors:

Signature | Description
--------- | -----------
`Item(T)` | Creates an item and stores the specified value in it.
`Item(T value, Item<T> prev, Item<T> next)` | Creates an item and stores in it the value `value`, as well as references to the previous `prev` and the next `next` list items.
`Item(Item<T>)` | Creates an item by copying data from another item.

#### Methods

Create the following methods:

Signature | Return type | Description
--------- |:-----------:| -----------
`equals(Item<T>)` | `bool` | Returns the result of comparing the item with another item by value.
`static` `equals(Item<T> first, Item<T> second)` | `bool` | Returns the result of comparing the item `first` with the item `second` by value.

### The Doubly Linked List Type

#### Fields

Create the following fields:

Name | Type | Access | Description
:---:|:----:|:------:| -----------
`head` | `Item<T>` | - | Reference to the first list item.
`tail` | `Item<T>` | - | Reference to the last list item.
`size` | `int` | `Чтение` | The number of the list items.

#### Constructors

Create the following constructors:

Signature | Description
--------- | -----------
`List()` | Creates an empty list.
`List(List<T>)` | Creates a list by copying data from another list.

#### Methods

Create the following methods:

Signature | Return type | Description
--------- |:-----------:| -----------
`append(T)`| - | Adds a new item with the specified value to the end of the list.
`append(List<T>)`| - | Adds items from another list to the end of the list.
`clear()` | - | Removes all items from the list.
`contains(T)` | `bool` | Returns the result of checking that the specified value is in the list.
`copy()` | `List<T>` | Returns a copy of the list.
`equals(List<T>)` | `bool` | Returns the result of the elementwise comparison of the list with another list.
`static` `equals(List<T> first, List<T> second)` | `bool` | Returns the result of the elementwise comparison of the list `first` with the list `second`.
`getItem(int)` | `T` | Returns the value stored in the list item with the specified index.
`indexOf(T value, int index)` | `int` | Returns the index of the first found occurrence of the value `value` within the entire list, starting at the index `index`.
`insert(T value, int index)` | - | Adds a new item with the value `value` to the list at the index` index`.
`insert(List<T> list, int index)` | - | Adds items from another list `list` to the list, starting at the index `index`.
`lastIndexOf(T value, int index)` | `int` | Returns the index of the last found occurrence of the value `value` within the entire list, starting at the index `index`.
`prepend(T)` | - | Adds a new item with the specified value to the top of the list.
`prepend(List<T>)`| - | Adds items from another list to the top of the list.
`remove(int)` | - | Removes the list item with the specified index.
`remove(int start, int end)` | - | Removes list items starting from the index `start` (inclusive) and ending on the index `end` (exclusive).
`reverse()` | - | Reverses the order of the list items.

::: warning Notice!
When deleting a list, its items should also be deleted.
If you are using a language with manual memory management (for example, `C++`),
then create a **class destructor**.
:::