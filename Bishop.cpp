//
// Created by Iulia on 12/7/2023.
//

#include "Bishop.h"
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

Bishop::Bishop(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) :
        Piece(texture, position, width, height, color) {}

Bishop::Bishop(const Piece& other) : Piece(other) {}

Bishop* Bishop::clone() const {
    return new Bishop(*this);
}

bool Bishop::isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const {
    /// Verificați dacă poziția nouă este în interiorul tablei
    if (newPosition.x < 0 || newPosition.x >= static_cast<float>(board.getSquareSize() * 8) ||
        newPosition.y < 0 || newPosition.y >= static_cast<float>(board.getSquareSize() * 8)) {
        return false;
    }

    /// Calculați diferența de poziție între poziția curentă și cea nouă
    float deltaX = newPosition.x - initialPosition.x;
    float deltaY = newPosition.y - initialPosition.y;

    /// Verificați dacă mișcarea este pe o diagonală
    if (std::abs(deltaX) == std::abs(deltaY))
    {
        // Verificăm dacă pe traseu există alte piese
        int stepX = (deltaX > 0) ? 1 : -1;
        int stepY = (deltaY > 0) ? 1 : -1;

        sf::Vector2f checkPosition = initialPosition;
        while (checkPosition != newPosition)
        {
            // Avansăm pe diagonală
            checkPosition.x += static_cast<float>(stepX);
            checkPosition.y += static_cast<float>(stepY);

            /**
            sf::Vector2i gridPosition(static_cast<int>(checkPosition.x / board.getSquareSize()),
                                      static_cast<int>(checkPosition.y / board.getSquareSize()));

            if (board.getPieceAt(gridPosition.x, gridPosition.y) != nullptr)
            {
                // Există o piesă pe traseu, mutarea nu este validă
                return false;
            }
             */

        }

        /// Nu există piese pe traseu, mutarea este validă
        return true;
    }

    return false;
}

