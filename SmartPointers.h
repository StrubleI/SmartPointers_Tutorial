#pragma once
#include <iostream>
#include <memory>

class Entity {
public:
    Entity() { std::cout << "Entity Created\n"; }
    ~Entity() { std::cout << "Entity Destroyed\n"; }
    void Print() { std::cout << "Hello from Entity\n"; }
};

int main() {
    // =============================================
    // SECTION 1: Unique Pointer Example
    // =============================================
    std::cout << "\n=== Unique Pointer Example ===\n";
    auto uniqueEntity = std::make_unique<Entity>(); // Creates a unique_ptr
    uniqueEntity->Print(); // Access the object

    // =============================================
    // SECTION 2: Shared Pointer Example
    // =============================================
    std::cout << "\n=== Shared Pointer Example ===\n";
    auto sharedEntity = std::make_shared<Entity>();
    auto anotherShared = sharedEntity; // Increases reference count
    std::cout << "Reference Count: " << sharedEntity.use_count() << "\n";

    // =============================================
    // SECTION 3: Weak Pointer Example
    // =============================================
    std::cout << "\n=== Weak Pointer Example ===\n";
    std::weak_ptr<Entity> weakEntity = sharedEntity; // Weak reference
    if (auto lockedEntity = weakEntity.lock()) {
        std::cout << "Entity is alive\n";
    }
    else {
        std::cout << "Entity is destroyed\n";
    }

    return 0; // All resources are automatically freed
}