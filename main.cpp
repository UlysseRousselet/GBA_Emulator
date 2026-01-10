#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "Hello World!" << std::endl;
    try {
        Core core(registry_ptr, argc, argv);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
