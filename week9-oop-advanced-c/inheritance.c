#include <stdio.h>
#include <string.h>

// Base struct ("Parent")
struct Animal {
    char name[30];
    int age;
};

void initAnimal(struct Animal *a, const char *name, int age) {
    strcpy(a->name, name);
    a->age = age;
}

void eat(const struct Animal *a) {
    printf("%s (age %d) is eating.\n", a->name, a->age);
}

// Derived struct ("Dog IS-A Animal")
struct Dog {
    struct Animal base; // MUST be the first member for safe upcasting
    char breed[30];
};

void initDog(struct Dog *d, const char *name, int age, const char *breed) {
    initAnimal(&d->base, name, age);
    strcpy(d->breed, breed);
}

void bark(const struct Dog *d) {
    printf("%s the %s says: Woof! Woof!\n", d->base.name, d->breed);
}

int main() {
    struct Dog myDog;
    initDog(&myDog, "Rex", 4, "German Shepherd");

    // Call Dog-specific behavior
    bark(&myDog);

    // Upcast Dog* to Animal* to reuse base behavior
    eat((struct Animal*)&myDog);

    return 0;
}