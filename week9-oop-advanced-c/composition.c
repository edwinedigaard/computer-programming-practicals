#include <stdio.h>
#include <string.h>

// Component struct
struct Engine {
    int horsepower;
    char fuelType[20];
};

void initEngine(struct Engine *e, int hp, const char *fuel) {
    e->horsepower = hp;
    strcpy(e->fuelType, fuel);
}

void startEngine(const struct Engine *e) {
    printf("  [Engine] %d HP %s engine roaring to life!\n", e->horsepower, e->fuelType);
}

// Container struct ("Car HAS-A Engine")
struct Car {
    char brand[30];
    struct Engine engine; // Embedded struct
};

void initCar(struct Car *c, const char *brand, int hp, const char *fuel) {
    strcpy(c->brand, brand);
    initEngine(&c->engine, hp, fuel);
}

void driveCar(const struct Car *c) {
    printf("Starting %s...\n", c->brand);
    startEngine(&c->engine);
    printf("%s is now driving!\n", c->brand);
}

int main() {
    struct Car myCar;
    initCar(&myCar, "Subaru Impreza", 250, "Petrol");
    driveCar(&myCar);

    return 0;
}