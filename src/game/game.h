#ifndef game_game_h
#define game_game_h

#include "defs.h"
#include "board.h"
#include "player.h"
#include "human_players.h"
#include "../ai/ai_players.h"
#include "../engine/renderHub.h"

#include <string>
#include <vector>

class DebugGame{
	private:
		struct Move{
			std::string label;
			bool owner_id;
			bool is_gem;

			Move(std::string const& label, PlayerID owner_id, bool is_gem)
				:label(label), owner_id(owner_id), is_gem(is_gem){}
		};

		ConsolePlayer** player;
		Board& board;
		MessageReceiver* receiver;

		std::vector<Move> moves;
		std::vector<Move> reverted_moves;

		bool command_player(PlayerID player_id);
		bool command_marker_player(PlayerID player_id);
		void command_back();
		void command_forward();

		void placeGem(PlayerID player_id, NodeLabel label);
		void placeMarker(PlayerID player_id, FaceLabel label);
		void removeGem(Move const& move);
		void removeMarker(Move const& move);

	public:
		DebugGame(ConsolePlayer* player1, ConsolePlayer* player2,
				Board& board, MessageReceiver* receiver = 0);
		void start();
};

class ConsoleGame{
	private:
		Player** player;
		Board& board;

		bool makeMove(PlayerID player_id);
		void placeGem(PlayerID player_id, NodeLabel label);

	public:
		ConsoleGame(Player* player1, Player* player2, Board& board);
		void start();
};

class SimpleGUIGame{
	private:
		Player** player;
		Board& board;
		MessageReceiver* receiver;

		bool makeMove(PlayerID player_id);
		void placeGem(PlayerID player_id, NodeLabel label);

	public:
		SimpleGUIGame(Player* player1, Player* player2,
				Board& board, MessageReceiver* receiver);
		void start();
};

#endif
