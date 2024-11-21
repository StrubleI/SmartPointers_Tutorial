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
```

### 2️⃣ `std::shared_ptr`
- Shared ownership: multiple `shared_ptr` instances can share ownership of the same resource.
- Uses a control block to manage reference counting.
- When the last shared_ptr goes out of scope, the resource is **deleted**.
  
**Example:**
```cpp
#include <memory>
#include <iostream>

class Entity {
public:
    Entity() { std::cout << "Entity Created\n"; }
    ~Entity() { std::cout << "Entity Destroyed\n"; }
};

int main() {
    auto sharedEntity = std::make_shared<Entity>();
    auto anotherShared = sharedEntity; // Reference count increases

    // Both pointers manage the same object
    std::cout << "Reference Count: " << sharedEntity.use_count() << std::endl;

    return 0; // Object is destroyed when the last shared_ptr goes out of scope
}
```
### 3️⃣ std::weak_ptr
- A non-owning reference to a `std::shared_ptr` resource.
- Does not affect the reference count.
- Useful for avoiding cyclic dependencies in complex ownership hierarchies.

**Example:**
```cpp
#include <memory>
#include <iostream>

class Entity {
public:
    Entity() { std::cout << "Entity Created\n"; }
    ~Entity() { std::cout << "Entity Destroyed\n"; }
};

int main() {
    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
    std::weak_ptr<Entity> weakEntity = sharedEntity; // Weak reference

    if (auto lockedEntity = weakEntity.lock()) {
        std::cout << "Entity is alive\n";
    } else {
        std::cout << "Entity is destroyed\n";
    }

    return 0;
}
```


## 🔑 Best Practices
- Prefer `std::unique_ptr` unless shared ownership is required.
- Avoid cyclic references when using `std::shared_ptr`. Use `std::weak_ptr` for breaking cycles.
- Use `std::make_unique` and `std::make_shared` to create smart pointers for exception safety.

> [!TIP]
> Use raw pointers only for non-owning references, like function parameters.

