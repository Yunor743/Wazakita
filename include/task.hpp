/*
** EPITECH PROJECT, 2021
** Wazakita
** File description:
** Wazakita
*/

#ifndef _TASK_HPP_
#define _TASK_HPP_

#include <vector>

class Task {
    std::vector<std::vector<unsigned>> nodes;
public:
    explicit Task(std::vector<std::vector<bool>> matrix);
    [[nodiscard]] std::vector<std::vector<unsigned>> get() const {
        return nodes;
    }
};

#endif
