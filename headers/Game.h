/**
 * Nume fisier: Game.h
 * Autor: Cucu Iulia-Maria
 * Data: 8/12/2023
 */

#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "board.h"
#include "piece.h"
#include "textures.h"

/**
 * @class Game
 * @brief Reprezintă starea și logica jocului de șah.
 */

class Game {
private:
    sf::RenderWindow window; ///< Fereastra de afișare a jocului.
    Board* board; ///< Tabla de șah a jocului.
    std::vector<std::unique_ptr<Piece>> pieces; ///< Vector de piese pe tabla de șah.
    Piece* selectedPiece = nullptr; ///< Piesa selectată de utilizator.
    static constexpr float pieceWidth = 60.0f; ///< Lățimea unei piese de șah.
    static constexpr float pieceHeight = 60.0f; ///< Înălțimea unei piese de șah.
    sf::Vector2f initialPiecePos; ///< Poziția inițială a piesei selectate.


public:
    /**
    * @brief Constructor pentru clasa Game.
    */
    Game();

    /**
     * @brief Constructor de copiere pentru clasa Game.
     * @param other Obiectul Game care va fi copiat.
     */
    Game(const Game& other);

    /**
     * @brief Operator de atribuire pentru clasa Game.
     * @param other Obiectul Game de la care se copiază.
     * @return O referință la obiectul Game curent.
     */
    Game& operator=(const Game& other);

    /**
    * @brief Destructor pentru clasa Game.
    */
    ~Game();

    /**
     * @brief Rulează bucla principală a jocului.
     */
    void run();

    /**
     * @brief Suprascrie operatorul << pentru a afișa informații despre obiectul Game.
     * @param os Fluxul de ieșire în care se afișează informațiile.
     * @param game Obiectul Game care se afișează.
     * @return O referință la fluxul de ieșire.
     */
    friend std::ostream& operator<<(std::ostream& os, const Game& game);

private:
    /**
     * @brief Adaugă piesele pe tabla de șah la vectorul de piese.
     */
    void addPiecesToVector();

    ////sf::Vector2f getInitialPiecePosition() const;
    ////bool isMouseOverEmptySquare(const sf::Vector2f& mousePosition) const;
    ///bool isValidPieceMove(const Piece& piece, const sf::Vector2f& initialPos, const sf::Vector2f& finalPos) const;

    /**
     * @brief Verifică dacă cursorul mouse-ului se află peste o piesă.
     * @param piece Piesa de verificat.
     * @param mousePosition Poziția cursorului mouse-ului.
     * @return True dacă cursorul se află peste piesă, false altfel.
     */
    bool isMouseOverPiece(const Piece& piece, const sf::Vector2f& mousePosition) const;

    /**
     * @brief Procesează evenimentele de la tastatură și mouse.
     */
    void handleEvents();

    /**
     * @brief Tratează apăsarea butonului mouse-ului.
     * @param mouseX Poziția cursorului mouse-ului pe axa X.
     * @param mouseY Poziția cursorului mouse-ului pe axa Y.
     */
    void handleMousePress(int mouseX, int mouseY);

    /**
     * @brief Tratează mișcarea cursorului mouse-ului.
     * @param mouseX Poziția cursorului mouse-ului pe axa X.
     * @param mouseY Poziția cursorului mouse-ului pe axa Y.
     */
    void handleMouseMove(int mouseX, int mouseY);

    /**
     * @brief Tratează eliberarea butonului mouse-ului.
     */
    void handleMouseRelease();

    /**
    * @brief Tratează capturarea unei piese de către alta.
    * @param dropPosition Poziția la care a fost eliberată piesa.
    */
    void handleCapture(const sf::Vector2f& dropPosition);

    /**
     * @brief Calculează centrul pătrățelei pe care se află cursorul mouse-ului.
     * @param mousePosition Poziția cursorului mouse-ului.
     * @return Poziția centrului pătrățelei.
     */
    sf::Vector2f calculateSquareCenter(const sf::Vector2f& mousePosition) const;

};

#endif //OOP_GAME_H
