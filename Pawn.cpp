//
// Created by Iulia on 12/7/2023.
//

#include "Pawn.h"


Pawn::Pawn(const sf::Texture& texture, const sf::Vector2f& position, float width, float height, Color color) :
        Piece(texture, position, width, height, color) {}

Pawn::Pawn(const Piece& other) : Piece(other) {}

Pawn* Pawn::clone() const {
    return new Pawn(*this);
}

bool Pawn::isValidMove(const sf::Vector2f& initialPosition, const sf::Vector2f& newPosition, const Board& board) const {
    std::cout<< "Poz initiala: " << initialPosition.x << " " << initialPosition.y << "\n";
    std::cout<< "Poz finala: " << newPosition.x << " " << newPosition.y << "\n";

    /// Verificați dacă poziția nouă este în interiorul tablei
    if (newPosition.x < 0 || newPosition.x >= static_cast<float>(board.getSquareSize() * 8) ||
        newPosition.y < 0 || newPosition.y >= static_cast<float>(board.getSquareSize() * 8)) {
        return false;
    }

    /// Calculați diferența de poziție între poziția curentă și cea nouă
    float deltaX = newPosition.x - initialPosition.x;
    float deltaY = newPosition.y - initialPosition.y;

    std::cout << "deltax si delta y: " << deltaX << " " << deltaY << "\n";

    /// Obțineți direcția piesei în funcție de culoarea ei
    int direction = (getColor() == sf::Color::White) ? -1 : 1;

    std::cout<< "direction: " << direction << "\n";
    std::cout<< "square size: " << board.getSquareSize() << "\n";

    /// Verificați dacă  este o mutare validă pentru un pion
    if (deltaX == 0 && deltaY == static_cast<float>(direction) * static_cast<float>(board.getSquareSize()))
    {
        /// Mutare simplă înainte
        std::cout << "1 Pas in fata" << "\n";
        return true;
    } else if (direction == -1 && initialPosition.y > 6 * static_cast<float>(board.getSquareSize()) &&
               initialPosition.y < 7 * static_cast<float>(board.getSquareSize()) &&
               deltaX == 0 && deltaY == 2 * static_cast<float>(direction) * static_cast<float>(board.getSquareSize()))
    {
        /// Mutare cu două celule înainte, doar din poziția inițială
        return true;
    }
    else if (direction == 1 && initialPosition.y > static_cast<float>(board.getSquareSize()) &&
            initialPosition.y < 2 * static_cast<float>(board.getSquareSize()) &&
            deltaX == 0 && deltaY == 2 * static_cast<float>(direction) * static_cast<float>(board.getSquareSize()))
    {
        /// Mutare cu două celule înainte, doar din poziția inițială
        return true;
    }

    else if (std::abs(deltaX) == static_cast<float>(board.getSquareSize()) &&
             std::abs(deltaY) == static_cast<float>(board.getSquareSize()))
    {
        /// Capturare pe diagonală
        return true;
    }

    return false;
}