//
// Created by Iulia on 12/7/2023.
//

#include "../headers/King.h"

King::King(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) :
        Piece(texture, position, width, height, color) {}

King::King(const Piece& other) : Piece(other) {}

King* King::clone() const {
    return new King(*this);
}

bool King::isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const
{
    /// Verificați dacă poziția nouă este în interiorul tablei
    if (newPosition.x < 0 || newPosition.x >= static_cast<float>(board.getSquareSize() * 8) ||
        newPosition.y < 0 || newPosition.y >= static_cast<float>(board.getSquareSize() * 8)) {
        return false;
    }

    /// Calculați diferența de poziție între poziția curentă și cea nouă
    float deltaX = std::abs(newPosition.x - initialPosition.x);
    float deltaY = std::abs(newPosition.y - initialPosition.y);

    /// Verificați dacă mișcarea este pe orizontală, verticală sau pe una dintre diagonale, și dacă este o mutare de un singur pătrățel
    if ((deltaX == static_cast<float>(board.getSquareSize()) && deltaY == 0) ||
        (deltaX == 0 && deltaY == static_cast<float>(board.getSquareSize())) ||
        (deltaX == static_cast<float>(board.getSquareSize()) && deltaY == static_cast<float>(board.getSquareSize()))) {
        return true;
    }
    return false;
}