//
// Created by Влад Кирилов on 10.09.2022.
//

#pragma once


#include <cmath>
#include <optional>

#define MAX_DOUBLE 1.79769e+308

void simple_iterations_method(double (*function)(double, double), double start_point, double eps,
                              double a, std::optional<double> &res);

