/*
** EPITECH PROJECT, 2021
** Wazakita
** File description:
** Wazakita
*/

#include <iostream>
#include "task.hpp"

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
//    std::vector<std::vector<bool>> matrix = {
//        {0, 1, 1, 0},
//        {1, 0, 1, 1},
//        {1, 1, 0, 0},
//        {0, 1, 0, 0}
//    };
    std::vector<std::vector<bool>> matrix = {
            {0, 1, 0, 1, 0, 0},
            {1, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0},
            {1, 0, 1, 0, 1, 1},
            {0, 1, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 0},
    };
    Task task3(matrix);
    display(task3.get());
    return 0;
}