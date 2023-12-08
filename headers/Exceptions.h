/**
 * Nume fisier: Exceptions.h
 * Autor: Cucu Iulia-Maria
 * Data: 8/12/2023
 */
#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H


#include <iostream>
#include <exception>

/**
 * @class Exceptions
 * @brief Clasa de bază pentru excepții personalizate.
 */

class Exceptions : public std::exception {
public:
    /**
     * @brief Returnează un mesaj descriind excepția.
     * @return Un șir de caractere care descrie excepția.
     */
    [[nodiscard]] const char* what() const noexcept override;
};

class InvalidMoveException : public Exceptions {
public:
    /**
      * @class InvalidMoveException
      * @brief Excepție pentru mutări invalide.
      */
    [[nodiscard]] const char* what() const noexcept override;
};

class PieceNotFoundException : public Exceptions {
public:
    /**
     * @brief PieceNotFoundException
     * @brief Excepție pentru piese care nu au fost găsite.
     */
    [[nodiscard]] const char* what() const noexcept override;
};

class EmptySquareException : public Exceptions {
public:
    /**
      * @class EmptySquareException
      * @brief Excepție pentru casete goale.
      */
    [[nodiscard]] const char* what() const noexcept override;
};

class SquareOccupiedException : public Exceptions {
public:
    /**
      * @class SquareOccupiedException
      * @brief Excepție pentru casete ocupate.
      */
    [[nodiscard]] const char* what() const noexcept override;
};

class NewDerivedException : public Exceptions {
public:
    /**
      * @class NewDerivedException
      * @brief Excepție derivată pentru exemple demonstrative.
      */
    [[nodiscard]] const char* what() const noexcept override;
};

#endif //OOP_EXCEPTIONS_H
