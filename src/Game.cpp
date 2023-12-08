//
// Created by Iulia on 12/7/2023.
//
#include "../headers/Game.h"
#include "../headers/Pawn.h"
#include "../headers/Knight.h"
#include "../headers/Bishop.h"
#include "../headers/Queen.h"
#include "../headers/Rook.h"
#include "../headers/King.h"
#include "../headers/Exceptions.h"


bool isPieceDragging = false;

Game::Game() : window(sf::VideoMode(596, 596), "Chess Game") {
    board = new Board(600, 600 / 8);
    Textures::loadAllTextures();
    addPiecesToVector();
}


Game::Game(const Game &other)
{
    board = new Board(*other.board);
    pieces.clear();
    for (const auto& piece : other.pieces)
        pieces.push_back(std::unique_ptr<Piece>(piece->clone()));
}

Game& Game::operator=(const Game& other)
{
    if (this != &other)
    {
        board = new Board(*other.board);
        pieces.clear();
        for (const auto& piece : other.pieces) {
            pieces.push_back(std::unique_ptr<Piece>(piece->clone()));
        }
    }
    return *this;

}

Game::~Game()
{
    /**
    delete board;
    for (const Piece *piece: pieces) {
        delete piece;
    }*/
    std::cout << "Chess ended!";
}

void Game::addPiecesToVector()
{
    unsigned int squareSize = board->getSquareSize();
    auto scale = static_cast<float>(squareSize);
    float halfPieceWidth = pieceWidth / 2.0f;
    float halfPieceHeight = pieceHeight / 2.0f;

    /**pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn,
                                            sf::Vector2f(0.0f * scale + squareSize / 2.0f - halfPieceWidth - 0.5f,
                                            6.0f * scale + squareSize / 2.0f - halfPieceHeight - 0.5f),
                                            pieceWidth, pieceHeight, white));
*/
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(0 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(1 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(2 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(3 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(4 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(5 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(6 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Pawn>(Textures::whitePawn, sf::Vector2f(7 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 6 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));

    pieces.push_back(std::make_unique<Rook>(Textures::whiteRook, sf::Vector2f(0 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Knight>(Textures::whiteKnight, sf::Vector2f(1 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Bishop>(Textures::whiteBishop, sf::Vector2f(2 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Queen>(Textures::whiteQueen, sf::Vector2f(3 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<King>(Textures::whiteKing, sf::Vector2f(4 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Bishop>(Textures::whiteBishop, sf::Vector2f(5 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Knight>(Textures::whiteKnight, sf::Vector2f(6 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));
    pieces.push_back(std::make_unique<Rook>(Textures::whiteRook, sf::Vector2f(7 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 7 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, white));


    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(0 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(1 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(2 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(3 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(4 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(5 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(6 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Pawn>(Textures::blackPawn, sf::Vector2f(7 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 1 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));

    pieces.push_back(std::make_unique<Rook>(Textures::blackRook, sf::Vector2f(0 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Knight>(Textures::blackKnight, sf::Vector2f(1 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Bishop>(Textures::blackBishop, sf::Vector2f(2 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Queen>(Textures::blackQueen, sf::Vector2f(3 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<King>(Textures::blackKing, sf::Vector2f(4 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Bishop>(Textures::blackBishop, sf::Vector2f(5 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Knight>(Textures::blackKnight, sf::Vector2f(6 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));
    pieces.push_back(std::make_unique<Rook>(Textures::blackRook, sf::Vector2f(7 * scale + squareSize / 2.0f - halfPieceWidth - 0.5, 0 * scale + squareSize / 2.0f - halfPieceHeight - 0.5), pieceWidth, pieceHeight, black));


}

bool Game::isMouseOverPiece(const Piece& piece, const sf::Vector2f& mousePosition) const
{

    /// Verificăm dacă poziția mouse-ului se află deasupra sprite-ului piesei
    return piece.getPosition().x <= mousePosition.x && mousePosition.x <= piece.getPosition().x + pieceWidth &&
           piece.getPosition().y <= mousePosition.y && mousePosition.y <= piece.getPosition().y + pieceHeight;

}

/**
bool Game::isMouseOverEmptySquare(const sf::Vector2f& mousePosition) const
{
    for (const auto& piecePtr : pieces)
    {
        if (isMouseOverPiece(*piecePtr, mousePosition)) {
            return false;
        }
    }
    return mousePosition.x >= 0 && mousePosition.x < board->getSquareSize() * 8 &&
           mousePosition.y >= 0 && mousePosition.y < board->getSquareSize() * 8;

}


bool Game::isValidPieceMove(const Piece& piece, const sf::Vector2f& initialPos, const sf::Vector2f& finalPos) const
{
    // Verifică dacă mutarea piesei este validă în contextul jocului tău
    // Poți adăuga aici orice reguli specifice jocului de șah
    // În acest exemplu, vom lansa excepții în funcție de cazurile definite

    if (!piece.isValidMove(initialPos, finalPos, *board)) {
        throw InvalidMoveException();
    }

    // Verifică dacă există o piesă pe caseta de destinație
    for (const auto& piecePtr : pieces) {
        if (piecePtr->getPosition() == finalPos) {
            // Caseta este ocupată
            throw SquareOccupiedException();
        }
    }

    // Verifică dacă există o piesă pe caseta de plecare
    bool isPieceOnInitialSquare = false;
    for (const auto& piecePtr : pieces) {
        if (piecePtr->getPosition() == initialPos) {
            isPieceOnInitialSquare = true;
            break;
        }
    }

    if (!isPieceOnInitialSquare) {
        // Caseta de plecare nu conține o piesă
        throw EmptySquareException();
    }

    // Dacă ajungem aici, mutarea este validă
    return true;
}
*/

void Game::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                handleMousePress(event.mouseButton.x, event.mouseButton.y);
                break;
            case sf::Event::MouseButtonReleased:
                handleMouseRelease();
                break;
            case sf::Event::MouseMoved:
                handleMouseMove(event.mouseMove.x, event.mouseMove.y);
                break;
            default:
                break;
        }
    }

}

void Game::handleMousePress(int mouseX, int mouseY)
{
    sf::Vector2f clickPosition(static_cast<float>(mouseX), static_cast<float>(mouseY));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for (const auto& piecePtr : pieces)
        {
            if (isMouseOverPiece(*piecePtr, clickPosition))
            {
                // Piece was clicked, start dragging
                std::cout<<"press"<<"\n";
                piecePtr->setIsSelected(true);
                selectedPiece = piecePtr.get();
                isPieceDragging = true;

                // Set the initial piece position
                initialPiecePos = piecePtr->getPosition();
                break;
            }
        }

    }

}

void Game::handleMouseMove(int mouseX, int mouseY)
{
    sf::Vector2f mousePosition(static_cast<float>(mouseX), static_cast<float>(mouseY));

    /// Verificați dacă o piesă este în mișcare
    if (isPieceDragging && selectedPiece != nullptr) {
        /// Actualizați poziția piesei în funcție de poziția curentă a mouse-ului
        selectedPiece->move(mousePosition);
    }

}
void Game::handleCapture(const sf::Vector2f& dropPosition)
{
    auto capturedPiece = std::find_if(pieces.begin(), pieces.end(), [&](const auto& piecePtr) {
        return piecePtr->getPosition() == dropPosition && piecePtr->getColor() != selectedPiece->getColor();
    });

    if (capturedPiece != pieces.end())
    {
        std::cout << "Piece captured!" << std::endl;

        // Remove the captured piece from the vector
        pieces.erase(capturedPiece);
        std::cout << "Piece deleted!" << std::endl;

    }
}

void Game::handleMouseRelease()
{
    /// Verificați dacă butonul stâng al mouse-ului a fost eliberat
    if (isPieceDragging && selectedPiece != nullptr)
    {
        std::cout<<"drop" << "\n";
        /// O piesă a fost eliberată, opriți trăgând și mutați piesa la poziția curentă a mouse-ului
        selectedPiece->setIsSelected(false);
        isPieceDragging = false;

        /// Verificați dacă piesa este mutată pe o casetă validă
        sf::Vector2f dropPosition = calculateSquareCenter(selectedPiece->getPosition());

        if (selectedPiece->isValidMove(initialPiecePos,dropPosition, *board))
        {
            /// Caseta de destinație este validă, actualizați poziția piesei
            selectedPiece->move(dropPosition);
            /// Verifica captura
            handleCapture(dropPosition);
        } else
        {
            /// Caseta de destinație nu este validă, readuceți piesa la poziția inițială
            selectedPiece->move(initialPiecePos);
        }

        /// Resetați poziția inițială pentru a evita mutarea piesei la fiecare eliberare a mouse-ului
        initialPiecePos = selectedPiece->getPosition();

        ///Deselecteaza piesa
        isPieceDragging = false;
        selectedPiece->setIsSelected(false);
        selectedPiece = nullptr;
    }

}

sf::Vector2f Game::calculateSquareCenter(const sf::Vector2f& mousePosition) const
{
    unsigned int squareSize = board->getSquareSize();
    float halfPieceWidth = pieceWidth / 2.0f;
    float halfPieceHeight = pieceHeight / 2.0f;

    /// Calculați coloana și rândul în funcție de poziția mouse-ului și dimensiunile piesei
    int column = static_cast<int>(mousePosition.x / squareSize);
    int row = static_cast<int>(mousePosition.y / squareSize);

    /// Asigurați-vă rândul si coloana sunt în limitele tablei
    column = std::max(0, std::min(7, column));
    row = std::max(0, std::min(7, row));

    /// Calculați centrul casetei, având în vedere dimensiunile piesei
    sf::Vector2f center(static_cast<float>(column * squareSize + squareSize / 2) - halfPieceWidth,
                        static_cast<float>(row * squareSize + squareSize / 2) - halfPieceHeight);

    return center;


}


void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        window.clear();
        board->draw(window);
        for (const auto& piecePtr : pieces) {
            piecePtr->draw(window);
        }
        window.display();
    }
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    os << "Chess Game Information" << std::endl;
    os << *game.board;
    for (const auto& piecePtr : game.pieces) {
        os << *piecePtr;
    }

    return os;
}