/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/

#include "Board.h"
#include "Pipe.h"
#include <iostream>
#include <thread>
#include <string>

using std::cout;
using std::endl;
using std::string;


void main()
{
	Place src;
	Place dst;
	enum codes result = DST_CHART;
	bool turn = true; //true for white turn, false for black turn
	string toDo = "";
	string player = turn ? "White" : "Black";
	Board::Board();
	char resultStr[2] = " ";

	srand(time_t(NULL));


	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, Board::boardToStr().c_str()); // just example...

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		Board::boardToStr();
		do
		{

			src = Place((msgFromGraphics[0] - 'a'), 7 - (msgFromGraphics[1] - '1'));
			dst = Place((msgFromGraphics[2] - 'a'), 7 - (msgFromGraphics[3] - '1'));

			result = Board::move(src, dst, turn);

			//debugging:
			player = turn ? "White " : "Black ";
			cout << player << result << endl;

			resultStr[0] = result + '0';
			resultStr[1] = NULL;

			strcpy_s(msgToGraphics, resultStr); // msgToGraphics should contain the result of the operation

			/******* JUST FOR EREZ DEBUGGING ******/
			//int r = rand() % 10; // just for debugging......
			//msgToGraphics[0] = (char)(1 + '0');
			//msgToGraphics[1] = 0;
			/******* JUST FOR EREZ DEBUGGING ******/


			// return result to graphics		
			p.sendMessageToGraphics(msgToGraphics);

			// get message from graphics
			msgFromGraphics = p.getMessageFromGraphics();

		} while (result >= 2 && result <= 7);

		turn = !turn;
	}

	p.close();
}