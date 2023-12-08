//
// Created by Iulia on 12/7/2023.
//
#include "../headers/Board.h"
#include "../headers/Piece.h"

Board::Board(int boardSize, int squareSize) : boardSize(boardSize), squareSize(boardSize / 8)
{
    white = sf::Color(255, 206, 160);
    black = sf::Color(140, 90, 40);

    squares = new sf::RectangleShape*[8];
    for (int i = 0; i < 8; i++) {
        squares[i] = new sf::RectangleShape[8];
        for (int j = 0; j < 8; j++) {
            squares[i][j] = sf::RectangleShape(sf::Vector2f(static_cast<float>(squareSize), static_cast<float>(squareSize)));
            squares[i][j].setPosition(static_cast<float>(i * squareSize), static_cast<float>(j * squareSize));
            if ((i + j) % 2 == 0)
                squares[i][j].setFillColor(white);
            else
                squares[i][j].setFillColor(black);
        }
    }
}

Board::Board(const Board& board)
{
    boardSize = board.boardSize;
    squareSize = board.squareSize;
    squares = new sf::RectangleShape*[8];
    for (int i = 0; i < 8; i++)
    {
        squares[i] = new sf::RectangleShape[8];
        for (int j = 0; j < 8; j++)
            squares[i][j] = board.squares[i][j];

    }
}

Board& Board::operator=(const Board& board)
{
    if (this != &board)
    {
        for (int i = 0; i < 8; i++)
        {
            delete[] squares[i];
        }
        delete[] squares;

        boardSize = board.boardSize;
        squareSize = board.squareSize;
        squares = new sf::RectangleShape *[8];
        for (int i = 0; i < 8; i++)
        {
            squares[i] = new sf::RectangleShape[8];
            for (int j = 0; j < 8; j++)
                squares[i][j] = board.squares[i][j];
        }
    }
    return *this;

}

Board::~Board() {
    for (int i = 0; i < 8; i++)
    {
        delete[] squares[i];
    }
    delete[] squares;

}

void Board::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            window.draw(squares[i][j]);
    }
}

int Board::getSquareSize() const {
    return static_cast<int>(squareSize);
}

/**
const std::vector<Piece*>& Board::getPieces() const {
    // Implementare metoda getPieces
    return reinterpret_cast<const std::vector<Piece*>&>(pieces);
}
*/
std::ostream& operator<<(std::ostream& os, const Board& board) {
    os << "Board Size: " << board.boardSize << "\n" << "Square Size: " << board.squareSize << std::endl;
    return os;
}
