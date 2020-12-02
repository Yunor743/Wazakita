/*
** EPITECH PROJECT, 2021
** Wazakita
** File description:
** Wazakita
*/

#include <iostream>
#include <algorithm>
#include "task.hpp"

static std::vector<std::pair<std::vector<unsigned>, unsigned>> process(std::vector<std::vector<bool>> &matrix, unsigned row_index, unsigned zindex, std::vector<unsigned> &prev)
{
    std::vector<std::pair<std::vector<unsigned>, unsigned>> ret;
    std::pair<std::vector<unsigned>, unsigned> node;
    node.second = zindex;
    auto row = matrix.at(row_index);
    for (auto i = 0; i < row.size(); ++i) {
        auto cell = row.at(i);
        auto it = std::find(prev.begin(), prev.end(), i);
        if (cell && it == prev.end()) node.first.push_back(i);
    }
    ret.push_back(node);
    for (auto index : node.first) {
        prev.push_back(row_index);
        auto tmp = process(matrix, index, zindex + 1, prev);
        // concat ret & tmp
        ret.reserve(ret.size() + tmp.size());
        ret.insert(ret.end(), tmp.begin(), tmp.end());
    }
    return ret;
}

static std::vector<std::vector<unsigned>> group(std::vector<std::pair<std::vector<unsigned>, unsigned>> zindexes)
{
    // TODO
    std::vector<std::vector<unsigned>> ret;
    auto max_index = 0;
    for (const auto &zindex : zindexes)
        if (zindex.second > max_index) max_index = zindex.second;
    ret.resize(max_index + 1);
    for (const auto &zindex : zindexes) {
        auto &dest = ret.at(zindex.second);
        auto &src = zindex.first;
        dest.reserve(dest.size() + src.size());
        dest.insert(dest.end(), src.begin(), src.end());
    }
    return ret;
}

static std::vector<std::vector<unsigned>> clean(std::vector<std::vector<unsigned>> nodes)
{
    std::vector<unsigned> prev;
    for (auto &node : nodes) {
        std::vector<unsigned> to_erase;
        for (auto i = 0; i < node.size(); ++i) {
            auto cell = node[i];
            if (std::find(prev.begin(), prev.end(), cell) == prev.end()) {
                prev.push_back(cell);
            } else
                to_erase.push_back(i);
        }
        std::reverse(to_erase.begin(), to_erase.end());
        for (const auto i : to_erase)
            node.erase(node.begin() + i);
    }
    for (auto i = nodes.size() - 1; i > 0 ; --i)
        if (nodes[i].empty()) nodes.erase(nodes.begin() + i);
    return nodes;
}

Task::Task(std::vector<std::vector<bool>> matrix)
{
    std::vector<unsigned> prev;
    auto zindexes = process(matrix, 0, 0, prev);
    nodes = group(zindexes);
    nodes = clean(nodes);
    nodes.insert(nodes.begin(), {0});
}
