#include <iostream> 

int hashmapper(int value);

int
main() {
    int input,
        arr[5];

    FLAG:

    std::cout << "type a number: ";
    std::cin >> input;

    int pos = hashmapper(input);

    arr[pos] = input;

    goto FLAG;

    return EXIT_SUCCESS;
}

int
hashmapper(int value) {
    return value / 2; // TODO: need to do a ceil
}
