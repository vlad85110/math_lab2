#include <iostream>
#include <thread>
#include "methods.h"

int main() {
    double a = 0;

    auto func = [](double x, double a)-> double {
        return log(1 + x) + a;
    };

    auto reverse = [](double x, double a)-> double {
            return exp(x - a) - 1;
    };

    struct timespec start{}, end{};
    clock_gettime(CLOCK_REALTIME, &start);

    std::optional<double> root1, root2;
    std::thread thread1(simple_iterations_method, func, a / 2, 0.001, a, std::ref(root1));
    std::thread thread2(simple_iterations_method, reverse, a / 2, 0.001, a, std::ref(root2));
    thread1.join();
    thread2.join();

    clock_gettime(CLOCK_REALTIME, &end);

    if (!root1.has_value() && !root2.has_value()) {
        std::cout << "no roots\n";
    } else if (root1.value() == root2.value()) {
        std::cout << root1.value() << std::endl;
    } else {
        std::cout << root1.value() << std::endl << root2.value() << std::endl;
    }

    printf("Time taken: %lf sec.\n",
           (double)(end.tv_sec-start.tv_sec)
           + 0.000000001*(double)(end.tv_nsec-start.tv_nsec));

    return 0;
}
