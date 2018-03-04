# CSCI251 | Autum 2018 - Exercise 1

## Intro to C++

**Instructions:** Complete the following exercises by writing the programs in appropriately named 
files (e.g. ex1-1.cpp, ex1-2,cpp, etc.). Please ensure you code complies with the C++ Guide Book 
available in the week-1 lecture notes on the subject’s moodle website. Also, test that your files 
compile and run on banshee.uow.edu.au (UNIX). You may need to install ssh on your PC for this 
(see resource folder on moodle). You should demo your programs in your week-2 lab class to 
receive the 2 marks and submit via unix submit by 11.59pm Friday week-2 (see Resource section 
on moodle on how to submit via banshee). If you need more time, ask your tutor for an extension. 
(Failure to comply with these instructions may result in zero marks for this exercise).



## 1. Loops, c-strings, Arrays and Functions

Write a program that reads a string comprised of a number of words and (1) prints the string in 
reverse order, (2) prints the words in reverse order. eg: 

```bash
$ Enter words: This C++ stuff is cool
$ looc si ffuts ++C sihT 
$ sihT ++C ffuts si looc 
```

Your program must be comprised of a **main()**, a function called **PrintReverseString()**
and **PrintReverseWords()** and must use a char array (c-string) for storing the words. Both 
functions are passed the string in a char array and should print the string or words in reverse order 
respectively. 



## 2. Enums 

Enumerated types are declared with the keyword **enum** thus: 

```c++
enum typename {enumerator list};
```

. . . and are explained on page 22 of the C++ Guide Book in the week-1 lecture notes.



1. Declare an **enum** type called **Month** for representing the months of the year:  **( Jan, Feb, Mar, ...... , Oct, Nov, Dec)**.

2. Write a function with the prototype: 

   ```c++
   void GetMonth(Month &Mth); 
   ```

   that asks the user to enter a month represented with an integer (1..12) and sets Mth
   appropriately. (Note: pass-by-reference is explained on page 14 of the C++ Guide book).

3. Write a function with the prototype: 

   ```c++
   void PrintMonth(Month Mth); 
   ```

   that prints on the screen the name of the month passed to the function.

4. Write a **main()** for testing both functions. 



## 3. Structs

Structs are explained on page 19 of the C++ Guide Book. To store a collection of related but 
unlike values use a **struct** e.g.

```c++
struct MyType // "MyType" is a new type 
{ 
	type field_name1; // "type" can be any built-in 
	type field_name2; // or user defined type 
    type field_name3; 
 ... 
}; 

MyType student; // "student" is a variable of type "MyType" 
```

Declare structs and enums according to the following specifications: 

1. ​

   ```c++
   struct name: NameType 

   fields: Last name // array of 20 chars
   Initial // char
   First name // array of 20 chars
   ```

2. ​

   ```c++
   enum name: GenderType 

   enumerators: eMale 
   			 eFemale 
   ```

3. ​

   ```c++
   struct name: AddressType 

   fields: Number // int
   		Street // array of 20 chars
   		Suburb // array of 20 chars
   		PostCode // int 
   ```

4. ​

   ```c++
   struct name: StudentType 

   fields: Name // NameType
   		Gender // GenderType
   		Address // AddressType
   		
   ```

5. Write a function called **GetStudentDetails()** that is passed a **StudentType** by 
   reference and gets student record data for it from the user. Note: Input checking is 
   unnecessary. 

6. ​