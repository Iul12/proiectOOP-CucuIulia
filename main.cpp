#include <iostream>
#include "headers/Game.h"
#include "headers/Exceptions.h"


int main() {
    try {
        Game chessGame;
        chessGame.run();
    }
    catch (const InvalidMoveException &e) {
        std::cerr << "Invalid move exception: " << e.what() << std::endl;
    } catch (const PieceNotFoundException &e) {
        std::cerr << "Piece not found exception: " << e.what() << std::endl;
    } catch (const EmptySquareException &e) {
        std::cerr << "Empty square exception: " << e.what() << std::endl;
    } catch (const SquareOccupiedException &e) {
        std::cerr << "Square occupied exception: " << e.what() << std::endl;
    } catch (const NewDerivedException &e) {
        std::cerr << "New derived exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception occurred" << std::endl;
    }
    return 0;
}
