//
// Created by Iulia on 12/7/2023.
//

#include "Knight.h"

Knight::Knight(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) :
        Piece(texture, position, width, height, color) {}

Knight::Knight(const Piece& other) : Piece(other) {}

Knight* Knight::clone() const {
    return new Knight(*this);
}

bool Knight::isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const {
    /// Verificați dacă poziția nouă este în interiorul tablei
    if (newPosition.x < 0 || newPosition.x >= static_cast<float>(board.getSquareSize() * 8) ||
        newPosition.y < 0 || newPosition.y >= static_cast<float>(board.getSquareSize() * 8)) {
        return false;
    }

    /// Calculați diferența de poziție între poziția curentă și cea nouă
    float deltaX = newPosition.x - initialPosition.x;
    float deltaY = newPosition.y - initialPosition.y;

    /// Definiți vectorii de offset pentru mișcarea în formă de L
    std::vector<int> offsetX = { -2, -1, 1, 2, 2, 1, -1, -2 };
    std::vector<int> offsetY = { 1, 2, 2, 1, -1, -2, -2, -1 };

    /// Verificați dacă mișcarea este în formă de L pentru un cal
    for (size_t i = 0; i < offsetX.size(); ++i) {
        if (deltaX == static_cast<float>(board.getSquareSize()) * static_cast<float>(offsetX[i]) &&
            deltaY == static_cast<float>(board.getSquareSize()) * static_cast<float>(offsetY[i])) {
            return true;
        }
    }


    return false;
}
