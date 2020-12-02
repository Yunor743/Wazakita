/*
** EPITECH PROJECT, 2021
** Wazakita
** File description:
** Wazakita
*/

#include <iostream>
#include "task.hpp"

void mean(std::vector<std::vector<unsigned>> tree)
{
    std::vector<unsigned> means;

    for (const auto &row : res) {
        for (const auto &column : row) {
            std::cout << std::to_string(column) << " ";
        }
        std::cout << std::endl;
    }
    for (auto i = 0; i < res.)



    // display
    float acc = 0;
    for (item : means) {
        std::cout << item << std::endl;
        acc += item;
    }
    acc /= means.size();
    std::cout << "Global mean: " << acc << std::endl;
}