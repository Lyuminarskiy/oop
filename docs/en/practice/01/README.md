# 1. Basic concepts of OOP. Encapsulation. Classes, fields and methods

## Topics

- Basic concepts of OOP.
- Encapsulation.
- Classes, fields and methods.
- `public` and` private` access modifiers, nested types.
- Objects creation and constructors.
- Static class members and constants.

## Theoretical information

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
problems that are similar in meaning in different ways. Descendants receive 
specific properties missing from the parent when the algorithm of a 
particular method changes.

Class member access modifiers:

1. `public` defines _open_ members of a class that do not have access 
restrictions, can be accessed from both the object and from any derived class.

2. `private` defines _closed_ class members that are available only in the 
class in which they are defined.

## 1.1. Point

Create the point type `Point`, which has fields that store its coordinates 
as floating-point numbers:

- `x` - abscissa,
- `y` - ordinate.

The coordinates of the point should be read-only and set in the constructor.

Add constructors that accept following input:

- ... two floating point numbers.
- ... another point to copy its coordinates.

Add methods that return:

- A string with information about the coordinates of a point like `(x; y)`.
Arrange the string pattern as a constant field.
- The result of comparing two points (boolean value).
- A copy of the point.

Duplicate the method of comparing two points as a static method.
The use of overload operations is allowed.

Demonstrate how to work with a point type.

## 1.2. Vector

Create a vector type `Vector` with the following fields:

- `start` - vector start point.
- `end` - the end point of the vector.

Use the point type `Point` created in the previous task.

Vector coordinates must be read-only and set in the constructor.

Add the following constructors:

- Without arguments (creates a zero vector).
- Takes one point at the input (creates a radius vector).
- Takes two points at the entrance.
- Another vector to copy the start and end points.

Add methods that return:

- A string with information about the vector coordinates of the form
`[(x1; y1), (x2; y2)]`. Arrange the string pattern as a constant field.
- The result of comparing two vectors (Boolean value).
- A copy of the vector.
- Vector module.
- The sum of two vectors.
- The difference of two vectors.
- The result of the scalar product of two vectors.
- The result of multiplying a vector by a number.

Binary operations methods duplicate as static methods.
The use of overload operations is allowed.

Demonstrate how to work with a vector type.

## 1.3. Human

Create a human type `Human` with the following fields:

- `name` - first name.
- `surname` - last name.
- `gender` - gender.
- `age` - age, year.
- `height` - height, centimeters.
- `weight` - weight, kilograms.

All fields must be private and readable and writable using class methods.

The `name` and` surname` fields are strings, `age` is integer,` height` and 
`weight` store floating-point numbers.

The field `gender` must be represented by a separate type of` Gender`, 
nested in the human type `Human`. The type must define two constant values:

- `MALE` - man.
- `FEMALE` - woman.

When implementing the type `Gender` it is allowed to use enumerated types.

Add constructors that accept following input:

- ... first and last name (the floor is undefined, the numeric fields are `0`).
- ... first name, last name and gender (numeric fields are `0`).
- ... name, surname, gender, age, height and weight.
- ... another person to copy the data.

Add methods that return:

- Line with information about a person like:

  ```
  John Smith, male, 31 y.o.
  Height: 171,2 cm
  Weight: 62,3 kg
  ```
  
  Height and weight round up to one decimal place. Arrange the string 
  pattern as a constant field.
  
- The result of comparing two people (Boolean value).
Compare by name and surname.

- A copy of a human.

Duplicate the method of comparing two people as a static method.
The use of overload operations is allowed.

Demonstrate working with the type of person.