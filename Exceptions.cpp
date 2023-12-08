//
// Created by Iulia on 12/7/2023.
//

#include "Exceptions.h"

/// Metoda what() furnizează un mesaj generic pentru excepție.
/// \return

const char* Exceptions::what() const noexcept {
    return "Chess exception.";
}

const char* InvalidMoveException::what() const noexcept {
    return "Invalid move.";
}

const char* PieceNotFoundException::what() const noexcept {
    return "Piece not found.";
}

const char* EmptySquareException::what() const noexcept {
    return "Empty square.";
}

const char* SquareOccupiedException::what() const noexcept {
    return "Square occupied.";
}

const char* NewDerivedException::what() const noexcept {
    return "New derived exception.";
}


