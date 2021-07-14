#include "doctest.h"
#include "Board.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

ariel::Board board;


TEST_CASE("Board is Empty"){
    SUBCASE("Check Read when the board is empty"){
        CHECK(board.read(10, 10, Direction::Horizontal, 1) == string("_"));
        CHECK(board.read(20, 20, Direction::Vertical, 1) == string("_"));
    }

    SUBCASE("Check show() when the board is empty"){
        CHECK_NOTHROW(board.show());
    }
}

TEST_CASE("Post in special locations"){
    SUBCASE("0,0"){
        CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "abc"));
        CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "efg"));

        SUBCASE("Read 0,0"){
            CHECK(board.read(0, 0, Direction::Horizontal, 3) == string("ebc")); // first char is 'e' instead 'a' after the override
            CHECK(board.read(0, 0, Direction::Vertical, 3) == string("efg")); 
        }
    }
    SUBCASE("High indexes"){
        CHECK_NOTHROW(board.post(2147483646, 0, Direction::Horizontal, "a"));
        CHECK_NOTHROW(board.post(0, 2147483646, Direction::Vertical, "e"));  

            SUBCASE("Read High indexes"){
                CHECK(board.read(2147483646, 0, Direction::Horizontal, 1) == string("a"));
                CHECK(board.read(0, 2147483646, Direction::Vertical, 1) == string("e")); 
            }  
    }
    // SUBCASE("negative indexes"){ // i think it would be better not to use unsigned int and throw special exception
    //     CHECK_THROWS(board.post(-1, -2, Direction::Horizontal, "abc"));
    //     CHECK_THROWS(board.post(-10, -5, Direction::Vertical, "efg"));    
    // }
}

TEST_CASE("Post special chars"){

    SUBCASE("Empty chars"){
        CHECK_NOTHROW(board.post(7, 7, Direction::Horizontal, "")); 
        CHECK_NOTHROW(board.post(8, 8, Direction::Horizontal, " ")); // 1 space
        CHECK_NOTHROW(board.post(9, 9, Direction::Horizontal, "  ")); // 2 spaces

            SUBCASE("Read Empty chars"){
                CHECK(board.read(7, 7, Direction::Horizontal, 1) == string("_")); //as empty 
                CHECK(board.read(8, 8, Direction::Horizontal, 1) == string(" ")); // 1 space
                CHECK(board.read(9, 9, Direction::Horizontal, 2) == string("  ")); // 2 spaces

            }  
    }    
    SUBCASE("integer Numbers"){
        CHECK_NOTHROW(board.post(10,10 , Direction::Vertical, "111"));
        CHECK_NOTHROW(board.post(20, 20, Direction::Horizontal, "0"));
        CHECK_NOTHROW(board.post(30, 30, Direction::Vertical, "-1"));
        CHECK_NOTHROW(board.post(40, 40, Direction::Vertical, "-1-1"));


        SUBCASE("Read integer Numbers"){
            CHECK(board.read(10, 10, Direction::Vertical, 3) == string("111"));
            CHECK(board.read(20, 20, Direction::Horizontal, 1) == string("0")); 
            CHECK(board.read(30, 30, Direction::Vertical, 1) == string("-"));
            CHECK(board.read(30, 30, Direction::Vertical, 2) == string("-1"));
            CHECK(board.read(40, 40, Direction::Vertical, 4) == string("-1-1"));
        }
    }
    SUBCASE("Symbols"){
        CHECK_NOTHROW(board.post(5, 5, Direction::Horizontal, "_"));

            SUBCASE("Read Symbols"){
                CHECK(board.read(5, 5, Direction::Horizontal, 1) == string("_"));
            }  
    }
    SUBCASE("Double numbers"){
        CHECK_NOTHROW(board.post(15, 15, Direction::Horizontal, "4.5678"));
        CHECK_NOTHROW(board.post(25, 25, Direction::Vertical, "123.45678"));

        SUBCASE("Read Double numbers"){
            CHECK(board.read(15, 15, Direction::Horizontal, 6) == string("4.5678"));
            CHECK(board.read(25, 25, Direction::Vertical, 9) == string("123.45678"));

        }

    }

}

TEST_CASE("Overrides"){

        CHECK_NOTHROW(board.post(50,50 , Direction::Horizontal, "abc"));

        SUBCASE("Read with empty parts"){
            CHECK(board.read(49, 51, Direction::Vertical, 3) == string("_b_"));
        }
        SUBCASE("Vetical override"){
            CHECK_NOTHROW(board.post(49,51 , Direction::Vertical, "efg"));
            CHECK(board.read(50, 50, Direction::Horizontal, 3) == string("afc"));
        }
        SUBCASE("Horizontal override"){
            CHECK_NOTHROW(board.post(50,51 , Direction::Horizontal, "hij"));
            CHECK(board.read(50, 50, Direction::Horizontal, 4) == string("ahij"));
            CHECK(board.read(49, 51, Direction::Vertical, 3) == string("ehg"));

        }
}

