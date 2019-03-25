# 1. Basic Concepts of OOP. Encapsulation. Classes, Fields and Methods

## Lesson's topics

- Basic concepts of OOP.
- Encapsulation.
- Classes, fields and methods.
- `public` and `private` access modifiers.
- Constructors and Objects creation.
- Static class members and constants.
- Nested types.

## Theoretical Information

Basic concepts of OOP:

1. _Encapsulation_ - integration of data (fields) and processing
algorithms (methods) of this data into a single whole. Allows you to hide 
the details of the internal implementation of objects and protect the 
integrity of the data.

2. _Inheritance_ - a property of objects to generate their descendants, which 
inherit all fields and methods from a parent, can supplement objects with 
new fields and replace (override) the methods of the parent or supplement them.
Stimulates code reuse and gives code flexibility.

3. _Polymorphism_ - a property of objects that have the same parent to solve
problems that are similar in meaning in different ways. Children receive 
specific properties missing from the parent when the algorithm of a 
particular method changes.

Class members' access modifiers:

1. `public` - defines _open_ members of a class that do not have access 
restrictions, can be accessed from both the object and from any derived class.

2. `private` - defines _closed_ class members that are available only in the 
class in which they are defined.

## 1.1. The Point Type

Tasks:

1. Create the point type `Point`.
2. Define access modifiers for class members.
3. Demonstrate how to work with the point type.

### Fields

Create the following fields:

Name | Type | Access | Description
:---:|:----:|:------:| -----------
`x` | `float` | `Read` | The point's abscissa.
`y` | `float` | `Read` | The point's ordinate.
`format` | `const` `string` | - | A template for representing the point as a string.

### Constructors

Create the following constructors:

Signature | Description
--------- | -----------
`Point(float x, float y)` | Creates a point with the coordinates `x` and `y`.
`Point(Point)` | Creates a point by copying data from another point.

### Methods

Create the following methods:

Signature | Return type | Description
--------- |:-----------:| -----------
`copy()` | `Point` | Returns a copy of the point.
`equals(Point)` | `bool` | Returns the result of comparing the point with another point.
`static` `equals(Point first, Point second)` | `bool` | Returns the result of comparing the point `start` with the point `second`.
`toString()` | `string` | Returns a string* with the information about the coordinates of the point**.

Remarks:

_* Example of a string:_

```
(2.35; 4.26)
```

_** Round the coordinates up to two digits after the point._

::: warning Notice!
If the class has many constructors, if it's possible,
**chain them** together.
:::

::: warning Notice!
If it's possible, use [operator overloading
](https://en.wikipedia.org/wiki/Operator_overloading)
and override standard methods.
:::

::: warning Notice!
If a class contains fields that are read-only or write-only,
it is recommended to make such fields _private_ or _protected_
and implement appropriate **access methods**.
:::

## 1.2. The Vector Type

Tasks:

1. Create the vector type `Vector`.
2. Define access modifiers for class members.
3. Demonstrate how to work with the vector type.

### Fields

Create the following fields:

Name | Type* | Access | Description
:---:|:-----:|:------:| -----------
`start` | `Point` | `Read` | The vector's start point.
`end` | `Point` | `Read` | The vector's end point.
`format` | `const` `string` | - | A template for representing the vector as a string.

Remarks:

_* Use the point type `Point` created in the previous task._

### Constructors

Create the following constructors:

Signature | Description
--------- | -----------
`Vector()` | Creates a zero vector.
`Vector(Point)` | Creates a position vector.
`Vector(Point start, Point end)` | Creates a vector with the start point `start` and the end point `end`.
`Vector(Vector)` | Creates a vector by copying data from another vector.

### Methods

Create the following methods:

Signature | Return type | Description
--------- |:-----------:| -----------
`add(Vector)` | `Vector` | Returns the sum of the vector and another vector.
`static` `add(Vector first, Vector second)` | `Vector` | Returns the sum of the vector `first` with the vector `second`.
`copy()` | `Vector` | Returns a copy of the vector.
`equals(Vector)` | `bool` | Returns the result of comparing the vector with another vector.
`static` `equals(Vector first, Vector second)` | `bool` | Returns the result of comparing the vector `first` with the vector `second`.
`getNorm()` | `float` | Returns the norm (length) of the vector.
`mul(Vector)` | `float` | Returns the dot product of the vector and another vector.
`static` `mul(Vector first, Vector second)` | `float` | Returns the dot product of the vector `first` with the vector `second`.
`mul(float)` | `Vector` | Returns the product of the vector with a number.
`static` `mul(Vector vector, float number)` | `Vector` | Returns the product of the vector `vector` with the number `number`.
`sub(Vector)` | `Vector` | Returns the difference of the vector with another vector.
`static` `sub(Vector first, Vector second)` | `Vector` | Returns the difference of the vector `first` with the vector `second`.
`toString()` | `string` | Returns a string* with the information about the coordinates of the vector.

Remarks:

_* Example of a string:_

```
[(0.00; 0.00), (2.35; 4.26)]
```

## 1.3. The Human Type

Tasks:

1. Create the human type `Human`.
2. Create the gender type `Gender` of a human nested in the human type.
3. Define access modifiers for class members.
4. Demonstrate how to work with the human type.

### The Gender Type

#### Fields

Create the following fields:

Name | Type* | Access | Description
:---:|:-----:|:------:| -----------
`MALE` | `const` `Gender` | `Read` | The value representing the male gender.
`FEMALE` | `const` `Gender` | `Read` | The value representing the female gender.

Remarks:

_* If it's possible, create the gender type `Gender` as an
[enumeration](https://en.wikipedia.org/wiki/Enumerated_type)._

#### Methods

Create the following methods:

Signature | Return type | Description
--------- |:-----------:| -----------
`static` `toString(Gender)` | `string` | Returns a string representation of the gender type of a human.

### The Human Type

#### Fields

Create the following fields:

Name | Type* | Access | Description
:---:|:-----:|:------:| -----------
`name` | `string` | `Read` `Write` | The human's name.
`surname` | `string` | `Read` `Write` | The human's surname.
`gender` | `Gender` | `Read` `Write` | The human's gender.
`age` | `int` | `Read` `Write` | The human's age in years.
`height` | `float` | `Read` `Write` | The human's height in centimeters.
`weight` | `float` | `Read` `Write` | The human's weight in kilograms.
`format` | `const` `string` | - | A template for representing the human as a string.

Remarks:

_* All operations with fields available for reading and writing
should occur only through class methods._

#### Constructors

Create the following constructors:

Signature | Description
--------- | -----------
`Human(string name, string surname)` | Creates a human with the name `name` and the surname `surname` (gender is undefined, numeric fields are `0`).
`Human(string name, string surname, Gender gender)` | Creates a human with the name `name`, the surname `surname` and the gender `gender` (numeric fields are `0`).
`Human(string name, string surname, Gender gender, int age, float height, float weight)` | Creates a human with the name `name`, the surname `surname`, the gender `gender`, the age `age`, the height `height` and the weight `weight`.
`Human(Human)` | Creates a human by copying data from another human.

#### Methods

Create the following methods:

Signature | Return type | Description
--------- |:-----------:| -----------
`copy()` | `Human` | Returns a copy of the human.
`equals(Human)` | `bool` | Returns the result of comparing the human with another human by name and surname.
`static` `equals(Human first, Human second)` | `bool` | Returns the result of comparing the human `first` with the human `second` by name and surname.
`toString()` | `string` | Returns a string* with the information about the human**. 
  
Remarks:

_* Example of a string:_

```
John Smith, male, 31 y.o.
Height: 171,2 cm
Weight: 62,3 kg
```

_** Round the height and the weight up to two digits after the point._

::: warning Notice!
The number of constructors for a class can be reduced by using
**default arguments**.
:::