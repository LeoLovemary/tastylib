# TastyLib

C++ implementations of data structures, algorithms and whatever attracts me.

## Build Status

| Linux | Windows | Coverage |
|:-----:|:-------:|:--------:|
|[![][ci-linux-badge]][ci-linux-state]|[![][ci-win-badge]][ci-win-state]|[![][coverage-badge]][coverage-state]|

## Outline

### Data Structures

| Name | Source | Benchmarked | Note | Definition |
|:----:|:------:|:-----------:|------|:----------:|
|[DoublyLinkedList][doublylist-details]|[Tests][doublylist-tests]<br>[.h][doublylist-src]|Yes|A linked data structure that consists of a set of sequentially linked records. It also supports merge sort.|[Wikipedia][doublylist-wiki]|
|[BinaryHeap][binheap-details]|[Tests][binheap-tests]<br>[.h][binheap-src]|Yes|A heap data structure taking the form of a complete binary tree. A common way of implementing [priority queue][priqueue-wiki].|[Wikipedia][binheap-wiki]|
|[HashTable][hashtbl-details]|[Tests][hashtbl-tests]<br>[.h][hashtbl-src]|No|A data structure that stores unique elements in no particular order, and which allows for fast retrieval of individual elements based on their values. Similar to [std::unordered_set][unorderedset-wiki].|[Wikipedia][hashtbl-wiki]|
|[AVLTree][avltree-details]|[Tests][avltree-tests]<br>[.h][avltree-src]|Yes|A self-balancing binary search tree.|[Wikipedia][avltree-wiki]|
|[Graph][graph-details]|[Tests][graph-tests]<br>[.h][graph-src]|No|A data structure to implement the directed/undirected graph concepts from mathematics. It stores a graph in an adjacency list or matrix.|[Wikipedia][graph-wiki]|

### Algorithms

| Name | Source | Benchmarked | Note | Definition |
|:----:|:------:|:-----------:|------|:----------:|
|[MD5][md5-details]|[Tests][md5-tests]<br>[.h][md5-src]|Yes|A widely used hash function producing a 128-bit hash value.|[Wikipedia][md5-wiki]|
|[NPuzzle][npuzzle-details]|[Tests][npuzzle-tests]<br>[.h][npuzzle-src]|Yes|A classic searching problem solved with [A* search][astar-wiki]. A [GUI demo][npuzzle-demo] is provided.|[Wikipedia][npuzzle-wiki]|
|[Sort][sort-details]|[Tests][sort-tests]<br>[.h][sort-src]|Yes|Including [insertion sort][sort-wiki-insertion], [selection sort][sort-wiki-selection], [heapsort][sort-wiki-heap], [quicksort][sort-wiki-quick], [quickselect][sort-wiki-quickselect]. For [merge sort][sort-wiki-merge], please refer to [DoublyLinkedList.sort()][doublylist-details].|[Wikipedia][sort-wiki]|
|[Dijkstra][dijkstra-details]|[Tests][dijkstra-tests]<br>[.h][dijkstra-src]|No|An algorithm to find the shortest paths between vertices in a graph.|[Wikipedia][dijkstra-wiki]|
|[LCS][lcs-details]|[Tests][lcs-tests]<br>[.h][lcs-src]|No|A dynamic programming solution to find the longest subsequence or substring common to two sequences.|[Wikipedia (substring)][lcs-wiki-substr]<br>[Wikipedia (subsequence)][lcs-wiki-subseq]|

### Programs

| Name | Source | Benchmarked | Note | Reference |
|:----:|:------:|:-----------:|------|:---------:|
|[TextQuery][textquery-details]|[Tests][textquery-tests]<br>[.h][textquery-h] [.cpp][textquery-cpp]|No|Search a given input stream for words. (OOP practice)|§12.3 & §15.9, C++ Primer, 5th Edition|
|[SharedPtr][sharedptr-details]|[Tests][sharedptr-tests]<br>[.h][sharedptr-src]|No|My owe version of [std::shared_ptr][sharedptr-std].|§12.1 & §16.1.6, C++ Primer, 5th Edition|

## Installation

1. Build with [CMake][cmake-site]:

    * Build benchmarks only

        ```bash
        $ mkdir build
        $ cd build
        $ cmake [-G <generator>] ..
        ```

    * Build benchmarks and testss

        ```bash
        $ mkdir build
        $ cd build
        $ git submodule init
        $ git submodule update
        $ cmake [-G <generator>] -DTASTYLIB_BUILD_TEST=ON ..
        ```

    You can customize the [CMake Generators][cmake-generator-docs].

2. Build with GNU Make (assuming a Makefile generator was used):

    ```bash
    $ make
    ```

3. All executables will be generated in the `bin` directory. Run all tests:

    ```
    $ ctest
    ```

## License

See the [LICENSE](./LICENSE) file for license rights and limitations.


[ci-linux-badge]: https://travis-ci.org/chuyangliu/TastyLib.svg?branch=master
[ci-linux-state]: https://travis-ci.org/chuyangliu/TastyLib
[ci-win-badge]: https://ci.appveyor.com/api/projects/status/snba7lqd9fnx6kvt/branch/master?svg=true
[ci-win-state]: https://ci.appveyor.com/project/chuyangliu/tastylib/branch/master
[coverage-badge]: https://coveralls.io/repos/github/chuyangliu/TastyLib/badge.svg?branch=master
[coverage-state]: https://coveralls.io/github/chuyangliu/TastyLib?branch=master

[cmake-site]: https://cmake.org
[cmake-generator-docs]: https://cmake.org/cmake/help/v3.10/manual/cmake-generators.7.html

[doublylist-details]: ./docs/details.md#doublylinkedlist
[doublylist-tests]: ./test/test_DoublyLinkedList.cpp
[doublylist-src]: ./include/tastylib/DoublyLinkedList.h
[doublylist-wiki]: https://en.wikipedia.org/wiki/Doubly_linked_list

[binheap-details]: ./docs/details.md#binaryheap
[binheap-tests]: ./test/test_BinaryHeap.cpp
[binheap-src]: ./include/tastylib/BinaryHeap.h
[binheap-wiki]: https://en.wikipedia.org/wiki/Binary_heap
[priqueue-wiki]: https://en.wikipedia.org/wiki/Priority_queue

[hashtbl-details]: ./docs/details.md#hashtable
[hashtbl-tests]: ./test/test_HashTable.cpp
[hashtbl-src]: ./include/tastylib/HashTable.h
[hashtbl-wiki]: https://en.wikipedia.org/wiki/Hash_table
[unorderedset-wiki]: http://www.cplusplus.com/reference/unordered_set/unordered_set

[avltree-details]: ./docs/details.md#avltree
[avltree-tests]: ./test/test_AVLTree.cpp
[avltree-src]: ./include/tastylib/AVLTree.h
[avltree-wiki]: https://en.wikipedia.org/wiki/AVL_tree

[graph-details]: ./docs/details.md#graph
[graph-tests]: ./test/test_Graph.cpp
[graph-src]: ./include/tastylib/Graph.h
[graph-wiki]: https://en.wikipedia.org/wiki/Graph_(abstract_data_type)

[md5-details]: ./docs/details.md#md5
[md5-tests]: ./test/test_MD5.cpp
[md5-src]: ./include/tastylib/MD5.h
[md5-wiki]: https://en.wikipedia.org/wiki/MD5

[npuzzle-details]: ./docs/details.md#npuzzle
[npuzzle-tests]: ./test/test_NPuzzle.cpp
[npuzzle-src]: ./include/tastylib/NPuzzle.h
[npuzzle-wiki]: https://en.wikipedia.org/wiki/15_puzzle
[astar-wiki]: https://en.wikipedia.org/wiki/A*_search_algorithm
[npuzzle-demo]: https://github.com/chuyangliu/Puzzle

[sort-details]: ./docs/details.md#sort
[sort-tests]: ./test/test_Sort.cpp
[sort-src]: ./include/tastylib/Sort.h
[sort-wiki-insertion]: https://en.wikipedia.org/wiki/Insertion_sort
[sort-wiki-selection]: https://en.wikipedia.org/wiki/Selection_sort
[sort-wiki-heap]: https://en.wikipedia.org/wiki/Heapsort
[sort-wiki-quick]: https://en.wikipedia.org/wiki/Quicksort
[sort-wiki-quickselect]: https://en.wikipedia.org/wiki/Quickselect
[sort-wiki-merge]: https://en.wikipedia.org/wiki/Merge_sort
[sort-wiki]: https://en.wikipedia.org/wiki/Sorting_algorithm

[dijkstra-details]: ./docs/details.md#dijkstra
[dijkstra-tests]: ./test/test_Dijkstra.cpp
[dijkstra-src]: ./include/tastylib/Dijkstra.h
[dijkstra-wiki]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

[lcs-details]: ./docs/details.md#lcs
[lcs-tests]: ./test/test_LCS.cpp
[lcs-src]: ./include/tastylib/LCS.h
[lcs-wiki-substr]: https://en.wikipedia.org/wiki/Longest_common_substring_problem
[lcs-wiki-subseq]: https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

[textquery-details]: ./docs/details.md#textquery
[textquery-tests]: ./test/test_TextQuery.cpp
[textquery-h]: ./include/tastylib/TextQuery.h
[textquery-cpp]: ./src/tastylib/TextQuery.cpp

[sharedptr-details]: ./docs/details.md#sharedptr
[sharedptr-tests]: ./test/test_SharedPtr.cpp
[sharedptr-src]: ./include/tastylib/SharedPtr.h
[sharedptr-std]: http://www.cplusplus.com/reference/memory/shared_ptr/?kw=shared_ptr
