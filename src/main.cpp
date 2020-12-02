/*
** EPITECH PROJECT, 2021
** Wazakita
** File description:
** Wazakita
*/

#include <iostream>
#include <vector>
#include "main.hpp"

static void display(std::vector<std::vector<unsigned>> res)
{
    for (const auto &row : res) {
        for (const auto &column : row) {
            std::cout << std::to_string(column) << " ";
        }
        std::cout << std::endl;
    }
}


int main()
{
    std::vector<std::vector<bool>> matrix = {
            {0, 1, 1, 0},
            {1, 0, 1, 1},
            {1, 1, 0, 0},
            {0, 1, 0, 0}
    };

//    std::vector<std::vector<bool>> matrix = {
//            {0, 1, 0, 1, 0, 0},
//            {1, 0, 0, 0, 1, 0},
//            {0, 0, 0, 1, 0, 0},
//            {1, 0, 1, 0, 1, 1},
//            {0, 1, 0, 1, 0, 0},
//            {0, 0, 0, 1, 0, 0},
//    };

    auto tree = task(matrix, 0);
    display(tree);
    mean(matrix);
    return 0;
}