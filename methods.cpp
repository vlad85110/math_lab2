//
// Created by Влад Кирилов on 10.09.2022.
//

#include "methods.h"
#include <iostream>


void simple_iterations_method(double (*function)(double, double), double start_point, double eps,
                                               double a, std::optional<double> &res) {
    double prev_point, new_point = start_point;
    double prev_abs, new_abs = MAX_DOUBLE;
    bool cont;

    do {
        prev_point = new_point;
        new_point = function(prev_point, a);

        prev_abs = new_abs;
        new_abs = abs(prev_point - new_point);

        cont = new_abs < prev_abs;
        if (!cont) {
            res = std::nullopt;
            return;
        }

    } while (new_abs > eps);

    res = new_point;
}
