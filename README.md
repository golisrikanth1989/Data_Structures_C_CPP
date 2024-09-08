# C \& C++ - Data Structures
This is normal  text

## 1. Inroduction
Here we discuss the topics mentioned below

| **C/C++** | **C++** | **Advanced C/C++** |
| - | - | - |
| Arrays | Classes | Matrices |
| Structures | Constructor | Linked Lists |
| Pointers | Templates | Stack
| Reference |  | Queues | Trees
| Parameter Passing |  | Graph
| | | Hashing |
| | | Recursion |
| | | Sorting |
|  |  |  |


| Main Memory |
| - |
| Heap |
| Stack |
| Main: Main functon is called in stack memory for ecxecution
| Code Section: Program is stored in this space with main() function
|  |


## 2. C \& C++ Essentials


### 2.1 Arrays
- **Defintion**: It is used to create or store the same type of vraibles 
- **Declaring**: `int A[5];`
- **Declaration \& Intitilaztion**: `int B[5] = {2,4,6,8,10};` or `int A[] = {1,2,3,4,5,5};` or `int A[10] = {0};`
- **Accessing**: `A[0], A[2], ..` or else use *for loop*

### 2.2 Structures
- **Defintion**: If we want group varaibles of differnt types belonging to same group then we can use structures 
- **Declaring**: `struct Strcture_name var1; `
- **Declaration \& Intitilaztion**: `struct Strcture_name var1 = {0,a,11, ...}`
- **Accessing**: `var1.x` we use `.` operator to acces the structure elements

### 2.13 Functions
- **Function:** A function is a block of code that performs a specific task. It has input parameters and returns a value after processing.
- **Structure:** A structure groups related data members (variables) together.

- **Monolithic Program:** No functions, code is written as one large block.
- **Modular Program:** Uses functions to break tasks into smaller parts, making code reusable and maintainable.
- **Benefits of Functions:**
    - Promotes code reuse and modularity.
    - Helps multiple people work on a project by sharing and reusing functions.

- **Ways to Pass Parameters to Functions:**
    - **Pass by Value:**
        - The actual values of variables are passed to the function.
        - Changes in the function do not affect the original values.
        - No changes to original values.
             ``` 
                void increment(int a) {
                 a = a + 1;
                } 
            ```
    - **Pass by Address:**
        - The memory address of variables is passed to the function (using pointers).
        - Changes in the function affect the original values.
        - Original values can be modified.
             ``` 
                void increment(int *a) {
                    *a = *a + 1;
                }
            ```
    - **Pass by Reference (C++ only):**
        - The function gets a reference (alias) to the original variable.
        - Changes in the function directly affect the original values.
        - Similar to pass by address but uses references (aliases) without extra memory.
            ``` 
                void increment(int &a) {
                    a = a + 1;
                }
            ```

    - One function cannot directly access variables from another function.
Call by Reference allows functions to access and modify variables in other functions, converting procedural code into a more monolithic result at the machine code level.


### 2.14 Arrays with Functions:
- Arrays are passed by address, meaning the function receives a pointer to the first element.
- This allows the function to modify the original array if needed.
    ```
    // Function that takes an array and its size as parameters
    void displayArray(int A[], int n) {
            for (int i = 0; i < n; i++) {
                printf("%d ", A[i]);  // Accessing array elements 
            }
            printf("\n");
    }       

    int main() {
        int arr[] = {1, 2, 3, 4, 5};
        int n = sizeof(arr) / sizeof(arr[0]);

        displayArray(arr, n);  // Passing the array to the function and
        its acctually passing the address of A[0]
        return 0;
        }
    ```
- **Returning Arrays from Functions:**
    - Since arrays cannot be returned directly, we return a pointer to dynamically allocated memory (using `malloc` or new).
    - In this example, `createArray` returns a pointer to an integer array, which is then used in the main function.
- **Memory Management:**
    - Always remember to free the dynamically allocated memory (free in C or delete[] in C++) to prevent memory leaks.

    ```
    int* createArray(int n) {
    // Dynamically allocate memory for the array
    int *A = (int*)malloc(n * sizeof(int));  // or use 'new' in C++

    // Return the pointer to the array
    return A;
    }

    int main() {
    int n = 5;

    // Call the function to create the array and get the pointer
    int *arr = createArray(n);

    // Free the dynamically allocated memory
    free(arr);  // Important to avoid memory leaks
    return 0;
    }
    ```
### 2.15 Strucures in Functions
- Structures in functions are called by value and address. 
- Array in Structure (Call by Value): The entire structure, including the array, is copied when passed by value.
- **Call by Address:** We pass a pointer to the structure, allowing modification of the original structure.
- **Call by Reference (C++):** We use a reference to the structure, modifying the original without creating a copy.

### 2.16 Class and Constructor

- Structure Definition (Before Class): Struct can have data members (like length and breadth) and member functions to manipulate them.
    ```
    struct Rectangle {
    int length;
    int breadth;

    void initialize(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }

    void changeLength(int newLength) {
        length = newLength;
    }
    };
    ```
- Class Definition (Conversion from Struct): 
    - Class allows data members to be accessible directly by functions within the class.
    - A constructor is used for initialization, and it has the same name as the class. This simplifies the process of initializing an object.
    - Data members are accessed without passing them around because they belong to the class and can be used by any function within the class.
Example with class:
    ```
    class Rectangle {
    private:
        int length;
        int breadth;

    public:
        // Constructor to initialize length and breadth
        Rectangle(int l, int b) {
            length = l;
            breadth = b;
        }

        // Function to calculate area
        int area() {
            return length * breadth;
        }

        // Function to change the length
        void changeLength(int newLength) {
            length = newLength;
        }
    };

- Main Function and Object Creation:
    - When you create an instance of the class, it's called an object.
    - Functions within the class are accessed using the dot (.) operator
    - Example of calling the class in the main function:
        ```
        int main() {
        // Creating an object of Rectangle class
        Rectangle rect(10, 5);  // Constructor initializes the values

        // Calling the area function
        int area = rect.area();
        std::cout << "Area: " << area << std::endl;

        // Changing the length
        rect.changeLength(15);

        // Recalculating the area after length change
        area = rect.area();
        std::cout << "New Area: " << area << std::endl;

        return 0;
        }
        ```
- Constructor: A function with the same name as the class, used to initialize data members.
- Object: An instance of a class, created in the main function.
- Dot Operator: Used to call class functions on an object (e.g., rect.area()).
- Encapsulation: All data and functions related to the Rectangle are enclosed within the class, accessible to its methods without passing them explicitly.
- In structure varaibles are public where as in class variables are private thats why we decalre the vraibles as public in class
- Basically class is a combination of struct and fucntions under same group and when we write programming with these classes it is called object orineted programming (OOP)
- In C++, Class has to be complete even we are using minimal use with certain defined functions
    - Private memebers (varaibles)
    - Default constructor for intilizing the varaibles
    - Parameterized constructor (for example processign on vraibles like finding area...)
    - Mutuate Functions
    - Accesser Functions
    - Destructor Fucntons declared using `~` operator

### 2.17 Template Class
- **Template Declaration:** `template <typename T>` declares a template with a placeholder `T` for the data type.
- **Class Definition:** Inside the class, T is used as the type for length and breadth.
- **Constructor and Methods:** These use T to handle the specified data type.
Instantiation: When creating an object of the template class, you specify the data type. 
-For example:
    - `Rectangle<int>` creates an object that uses `int` for `length` and `breadth`.
    - `Rectangle<float>` creates an object that uses `float` for `length` and `breadth`.

- Class Reusability: Write the class once and use it with different data types.
- The compiler checks for type correctness during object creation and method calls.

    ```
    #include <iostream>

    // Template class definition
    template <typename T>
    class Rectangle {
    private:
        T length;
        T breadth;

    public:
        // Constructor: Initializes the length and breadth
        Rectangle(T l, T b) : length(l), breadth(b) {}

        // Member function to calculate area
        T area() {
            return length * breadth;
        }

        // Member function to change the length
        void changeLength(T newLength) {
            length = newLength;
        }

        // Optional: Display the dimensions
        void display() {
            std::cout << "Length: " << length << ", Breadth: " << breadth << std::endl;
        }
    };

    // Main function
    int main() {
        // Creating an object of Rectangle class for int type
        Rectangle<int> rectInt(10, 5);  // Calls the constructor with int

        // Display initial dimensions
        rectInt.display();

        // Calculate and print the area
        std::cout << "Area (int): " << rectInt.area() << std::endl;

        // Change the length
        rectInt.changeLength(15);

        // Display new dimensions
        rectInt.display();

        // Recalculate and print the new area
        std::cout << "New Area (int): " << rectInt.area() << std::endl;

        // Creating an object of Rectangle class for float type
        Rectangle<float> rectFloat(10.5f, 5.5f);  // Calls the constructor with float

        // Display initial dimensions
        rectFloat.display();

        // Calculate and print the area
        std::cout << "Area (float): " << rectFloat.area() << std::endl;

        // Change the length
        rectFloat.changeLength(15.5f);

        // Display new dimensions
        rectFloat.display();

        // Recalculate and print the new area
        std::cout << "New Area (float): " << rectFloat.area() << std::endl;

        return 0;
    }

    ```


### Do it



**Bold text**

*italic Test*

> Blockquote

1. First Item
2. Second Ite

- First unorderd
- second unordered

`code`

---- 



| Syntax | Description |
| ---------- | ------- |
| Header | Ttile |
| Parag | Test |
| ---------- | ------- |

H~2

X^2^  

