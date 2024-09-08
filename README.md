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

