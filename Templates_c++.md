GOOD TEMPLATE FOR COMPETITIVE PROGRAMMING IN C++

WHAT ARE TEMPLATES IN C++?

Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular type. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types.

TEMPLATES IN C++

FUNCTION TEMPLATES: We write a generic function that can be used for different data types. Examples of function templates are sort(), max(), min(), printArray().

Here, type is a placeholder name for a data type used by the function. This name can be used within the function definition.


General form of function template is-

template class type ret-type func-name (parameter list) 

{
   // body of function
}  


CLASS TEMPLATE:

Class templates are useful when a class defines something that is independent of the data type. Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc.

Here, type is the placeholder type name, which will be specified when a class is instantiated. You can define more than one generic data type by using a comma-separated list.

General form of class template is-

template class type class class-name 

{
   .
   .
   .
}

C++ STANDARD TEMPLATE LIBRARY (STL):

C++ STL is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks. It is a generalized library and so, its components are parameterized.

C++ STL has four components:

1. Algorithms
2. Containers
3. Functions
4. Iterators

ALGORITHMS: 

The header algorithm defines a collection of functions especially designed to be used on ranges of elements. Finding, sorting, reversing, and the like are standard programming requirements that should not require the programmer to reinvent implementation to support. This is precisely why STL supplies these functions in the form of STL algorithms that work well with containers using iterators to help the programmer with some of the most common
requirements.

Some of the most used STL algorithms are:

std::find—Helps find a value in a collection.

std::find_if—Helps find a value in a collection on the basis of a specific user-defined predicate.

std::reverse—Reverses a collection.

std::remove_if—Helps remove an item from a collection on the basis of a user-defined predicate.

std::transform—Helps apply a user-defined transformation function to elements in a container.

CONTAINERS: Containers or container classes store objects and data.
STL supplies two types of container classes:

1.Sequential Containers.

2.Associative Containers.

In addition to these STL also provides classes called container adapters that are variants of the same with reduced functionality to support a specific purpose.

SEQUENTIAL CONTAINERS: 

As the name suggests, these are containers used to hold data in a sequential fashion, such as arrays and lists. Sequential containers are characterized by a fast insertion time, but are relatively slow in find operations.

The STL sequential containers are:-

std::vector—Operates like a dynamic array and grows at the end. Think of a
vector like a shelf of books to which you can add or remove books on one end.

std::deque—Similar to std::vector except that it allows for new elements to
be inserted or removed at the beginning, too.

std::list—Operates like a doubly linked list. Think of this like a chain where an object is a link in the chain. You can add or remove links—that is, objects—at any position.

std::forward_list—Similar to a std::list except that it is a singly linked
list of elements that allows you to iterate only in one direction.

ASSOCISTIVE CONTAINERS: 

Associative containers are those that store data in a sorted fashion—akin to a dictionary. This results in slower insertion times, but presents significant advantages when it comes to searching.

The associative containers supplied by STL are:-

std::set—Stores unique values sorted on insertion in a container featuring
logarithmic complexity

std::unordered_set—Stores unique values sorted on insertion in a container
f eaturing near constant complexity. Available starting C++11

std::map—Stores key-value pairs sorted by their unique keys in a container with logarithmic complexity

std::unordered_map—Stores key-value pairs sorted by their unique keys in a
container with near constant complexity. Available starting C++11

std::multiset—Akin to a set. Additionally, supports the ability to store multiple items having the same value; that is, the value doesn’t need to be unique

std::unordered_multiset—Akin to a unordered_set. Additionally, supports
the ability to store multiple items having the same value; that is, the value doesn’t need to be unique. Available starting C++11.

std::multimap—Akin to a map. Additionally, supports the ability to store
key-value pairs where keys don’t need to be unique.

std::unordered_multimap—Akin to a unordered_map. Additionally, supports
the ability to store key-value pairs where keys don’t need to be unique.

FUNTIONS: 

The STL includes classes that overload the function call operator. Instances of such classes are called function objects or functors. Functors allow the working of the associated function to be customized with the help of parameters to be passed.

ITERATORS: 

Iterators in STL are template classes that in some ways are a generalization of pointers. These are template classes that give the programmer a handle by which he can work with and manipulate STL containers and perform operations on them.

Iterators in STL can be broadly classified into the following:

Input iterator: One that can be dereferenced to reference an object. The object can be in a collection, for instance. Input iterators of the purest kinds guarantee read access only.

Output iterator: One that allows the programmer to write to the collection.
Output iterators of the strictest types guarantee write access only.