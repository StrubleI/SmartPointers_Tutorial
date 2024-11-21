# 🧠 Smart Pointers in Modern C++

Smart pointers are an essential feature introduced in C++11 to handle memory management automatically. The primary types of smart pointers are:
1. **`std::unique_ptr`**
2. **`std::shared_ptr`**
3. **`std::weak_ptr`**

---

## 📚 Key Concepts

### 🌟 Why Use Smart Pointers?

- **Automatic Memory Management**: They allocate and deallocate memory automatically, avoiding manual `new` and `delete` operations.
- **Exception Safety**: Reduce the risk of memory leaks, especially in complex programs.
- **Ownership Semantics**: Clearly define which part of your program owns a given resource.

> **⚠️ Important**: Avoid raw pointers (`new` and `delete`) in modern C++! Use smart pointers whenever possible.

---

## 🛠️ Types of Smart Pointers

### 1️⃣ `std::unique_ptr`
- Owns a resource exclusively (only one `unique_ptr` can own a resource).
- Cannot be copied, only **moved**.
- Minimal overhead.

**Example:**
```cpp
#include <memory>
#include <iostream>

class Entity {
public:
    Entity() { std::cout << "Entity Created\n"; }
    ~Entity() { std::cout << "Entity Destroyed\n"; }
    void Print() { std::cout << "Hello from Entity\n"; }
};

int main() {
    auto uniqueEntity = std::make_unique<Entity>(); // Create a unique_ptr
    uniqueEntity->Print(); // Access the object
    return 0; // unique_ptr automatically deletes the object
}
