# C++ Custom Data Structures Implementation

A robust, performant, and fully dynamic implementation of core Data Structures built from scratch in C++ (`C++11/17`). 

This repository showcases low-level system programming concepts, explicit dynamic memory management, cache-friendly data structures, and object-oriented resource handling without relying on the C++ Standard Template Library (STL).

---

## 📌 Featured Implementations

### 1. Dynamic Vector (`CustomVector<T>`)
A custom template-based dynamic array mimicking `std::vector` with amortized $O(1)$ push operations and explicit capacity management.

#### Key Features:
* **Generic Design:** Full template support (`template <typename T>`) for arbitrary data types.
* **Smart Resizing:** Dynamic capacity doubling ($2 \times \text{capacity}$) upon reaching overflow, ensuring $O(1)$ amortized insertion time complexity.
* **Resource Safety & RAII:** Strict Resource Acquisition Is Initialization design to prevent memory leaks and dangling pointers.
* **Memory Management:** Explicit constructor/destructor dynamic array handling using `new[]` and `delete[]`.
* **Safe Indexing:** Bounds checking with informative assertions/exceptions and direct operator overloading (`operator[]`).

---

## 🛠️ Concepts & Low-Level Mechanics Demonstrated

* **Pointers & Dynamic Memory:** Direct manipulation of raw pointers and heap allocations.
* **RAII & Destructors:** Deterministic cleanups and memory deallocation on object destruction.
* **Templates & Generic Programming:** Type-agnostic data structures.
* **Time & Space Complexity Analysis:** Strict adherence to optimal Big-O bounds.

---

## 📊 Time Complexity Overview

| Operation | Custom Vector Complexity | Notes |
| :--- | :--- | :--- |
| `push_back(val)` | $O(1)$ Amortized | $O(N)$ when reallocation occurs |
| `pop_back()` | $O(1)$ | Decrements size without immediate shrink |
| `operator[]` | $O(1)$ | Direct memory offset access |
| `get(index)` | $O(1)$ | Bounds-checked element access |
| `insert(index, val)` | $O(N)$ | Element shifting required |
| `remove(index)` | $O(N)$ | Element shifting required |

---

## 🚀 Getting Started

### Prerequisites
* GCC/G++ or Clang compiler with C++11 support or higher.
* CMake (optional for build orchestration).

### Running Example
```bash
# Clone the repository
git clone [https://github.com/Qusai-netizen/Data-structures-from-scratch.git](https://github.com/Qusai-netizen/Data-structures-from-scratch.git)

# Navigate to the folder
cd Data-structures-from-scratch

# Compile main/test script
g++ -std=c++17 main.cpp -o main

# Execute
./main
