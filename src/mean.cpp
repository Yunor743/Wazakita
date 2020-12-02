/*
** EPITECH PROJECT, 2021
** Wazakita
** File description:
** Wazakita
*/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include "main.hpp"

static float proc(std::vector<std::vector<unsigned>> tree, unsigned row_ndx, unsigned col_ndx)
{
    float acc = 0;
    unsigned iter_nb = 0;
    for (auto i = 0; i < tree.size(); ++i) {
        for (auto j = 0; j < tree.at(i).size(); ++j) {
            ++iter_nb;
            if (row_ndx == i) {
                acc += std::abs(static_cast<float>(col_ndx) - j);
            } else
                acc += std::abs(static_cast<float>(row_ndx) - i);
        }
    }
    acc /= iter_nb - 1;
    return acc;
}

static float tree_mean(std::vector<std::vector<unsigned>> tree)
{
    float acc = 0;
    unsigned iter_nb = 0;
    for (auto i = 0; i < tree.size(); ++i) {
        for (auto j = 0; j < tree.at(i).size(); ++j) {
            ++iter_nb;
            // acc += proc(tree, i, j);
            acc += i;
        }
    }
    acc /= iter_nb - 1;
    return acc;
}

void mean(std::vector<std::vector<bool>> matrix)
{
    std::cout << "means:" << std::endl;
    std::vector<float> means;
    for (auto i = 0; i < matrix.size(); ++i) {
        auto tree = task(matrix, i);
        means.push_back(tree_mean(tree));
    }
    // display
    float acc = 0;
    std::cout << std::fixed << std::setprecision(2);
    for (auto &item : means) {
        std::cout << item << std::endl;
        acc += item;
    }
    acc /= means.size();
    std::cout << "Global mean: " << acc << std::endl;
}