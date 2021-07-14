#include "Board.hpp"
#include "Direction.hpp"
#include <string>
using ariel::Direction;
#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel{

    /**post
     * gets location (row, col), direction (Horizontal / Vertical) , String as
     * The function places the ad on the bord
     **/
    void Board::post(unsigned int row, unsigned int col, enum Direction direction, const string &ad){

        resize_board(row, col,direction, unsigned(ad.length())); // we will resize the bord first

        for(unsigned int i = 0; i < ad.length(); i++){
            if (direction == Direction::Horizontal){
                current_board[row][col+i]= ad[i];
            }
            else{ // direction is Vertical
                current_board[row+i][col]= ad[i];
            }
        }
    }

    /**read
     * gets location (row, col), direction (Horizontal / Vertical) , and how many chars to read
     * The function return string of the chars that been readed 
     **/
    string Board::read(unsigned int row, unsigned int col , enum Direction direction, unsigned int num_char){
        string str;
        for(unsigned int i = 0; i < num_char; i++){
            if (direction == Direction::Horizontal){
                if(current_board[row][col+i] == 0){ // if the cell is empty add '_' to str
                    str+= "_";
                }
                else{ // the cell is not empty
                    str+= current_board[row][col+i];
                }
            }
            else { // direction is Vertical
                if(current_board[row+i][col] == 0){ // if the cell is empty add '_' to str
                    str+= "_";
                }
                else{ // the cell is not empty
                    str+= current_board[row+i][col];
                }
            }
        }
        return str;
    }

    /**show
    * The board presentation
    **/	
    void Board::show(){
    cout << "show" << endl;
        for (unsigned int i = min_row; i < max_row; i++){
            for (unsigned int j = min_col; j < max_col; j++){
                cout << current_board[i][j];
            }
            cout << endl;
        }
    }

    /**resize_board
     * gets location (row, col), direction (Horizontal / Vertical) , ad_length (int)
     * resize the board
    **/   
    void Board::resize_board(unsigned int row, unsigned int col, enum Direction direction, unsigned int ad_length){
        min_row= min(min_row , row);
        min_col= min(min_col , col);

        if (direction == Direction::Horizontal){
            max_row= max(max_row , row);
            max_col= max((col+ad_length) , max_col);
        }
        else{ // direction is Vertical
            max_row= max((row+ad_length) , max_row);
            max_col= max(min_col , col);
        }
    }    

}



// int main() {
//     cout << "abcabcd"<<endl;

// 	ariel::Board board;
//     //board.show();
// 	 board.post(100, 200, Direction::Horizontal, "abcd");
// 	 cout << board.read(99, 201, Direction::Vertical,3) << endl;  
// 	// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again). ->OK
// 	board.post(99, 202, Direction::Vertical, "xyz");
// 	cout << board.read(100, 200, Direction::Horizontal, 6) << endl;  
// 	// 	// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).  -> OK

// 	board.show(); // shows the board in a reasonable way. For example:
// 		//    98:  _________
// 		//    99:  ____x____
// 		//    100: __abyd___
// 		//    101: ____z____
// 		//    102: _________
// }






