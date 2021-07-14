#pragma once
#include "Direction.hpp"
#include <string>
#include <map>
#include <set>
#include <iostream>

namespace ariel {
    class Board {

		private:
			//Board defult size
    		unsigned int min_row=2147483647; // the maximum integer may be, It will change with the first input
    		unsigned int min_col=2147483647; // the maximum integer may be, It will change with the first input
    		unsigned int max_row=0;
			unsigned int max_col=0;

			std::map<unsigned int, std::map <unsigned int, char>> current_board; //   https://www.geeksforgeeks.org/implementing-multidimensional-map-in-c/

		public:
			/**post
 			* gets location (row, col), direction (Horizontal / Vertical) , String as
 			* The function places the ad on the bord
 			**/
			void post( unsigned int row,  unsigned int col, Direction direction, std::string const &ad);


			/**read
 			* gets location (row, col), direction (Horizontal / Vertical) , and how many chars to read
			* The function return string of the chars that been readed 
 			**/
			std::string read( unsigned int row,  unsigned int col, Direction direction,  unsigned int num_char);

			/**show
 			* The board presentation
 			**/			
			void show();

			/**resize_board
			 * gets location (row, col), direction (Horizontal / Vertical) , ad_length (int)
			 * resize the board
			**/  
			void resize_board(unsigned int row, unsigned int col, enum Direction direction, unsigned int ad_length);

    };
}