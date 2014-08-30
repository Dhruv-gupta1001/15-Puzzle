// Copyright (C) 2014 Călin Cruceru <calin@rosedu.org>
//
// This program is free software licenced under MIT Licence. You can
// find a copy of this licence in LICENCE.txt in the top directory of
// source code.
//

#ifndef BOARD_H__
#define BOARD_H__

// Project specific
#include "Queue.h"

// Standard Library
#include <string>
#include <vector>


namespace Puzzle15
{

class Board
{
public:
    Board();
    Board(const Board &other);
    Board(const std::vector<int> &initBlocks, int dim);
    ~Board();

    // Apply copy-and-swap idiom
    Board &operator=(Board other);
    friend void swap(Board &first, Board &second) throw();

    bool operator==(const Board &other) const;
    bool operator!=(const Board &other) const;

    int dimension() const;
    int hamming() const;
    int manhattan() const;
    bool isGoal() const;
    Board twin() const;
    Queue<Board> neighbours() const;
    std::string toString() const;

private:
    void emptyPosition(int &emptyRow, int &emptyColumn) const;
    Board upperNeighbour(int emptyRow, int emptyColumn) const;
    Board lowerNeighbour(int emptyRow, int emptyColumn) const;
    Board leftNeighbour(int emptyRow, int emptyColumn) const;
    Board rightNeighbour(int emptyRow, int emptyColumn) const;

    std::vector<int> m_blocks;
    int m_size;
};

}

#endif
