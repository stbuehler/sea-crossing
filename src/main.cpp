#include "conf.h"
#include "game/game.h"
#include "engine/renderHub.h"

#include <thread>
#include <vector>

using namespace std;

int main(){

	Conf conf("config");
	vector<string> vec;
	vec.push_back("true");
	conf.readFromFile();
	conf.setValue("use_switch_rule", vec);

	RenderHub testRenderer;
	MessageSender testSender(testRenderer.messageSender());
	//if(testRenderer.init())
	//{
	//	testRenderer.addScene();
	//	testRenderer.setActiveScene(0);
	//	testSender->pushLoadSceneMessages();
	//	std::thread renderThread(&RenderHub::run,&testRenderer);
	//}
	std::thread renderThread(&RenderHub::init,&testRenderer);
	testSender.pushLoadSceneMessages();
	
	Board board;
	RandomAIPlayer player1("Spongebob", board);
	RandomAIPlayer player2("Patrick", board);
	
	SimpleGUIGame g(&player1, &player2, board, testSender);
	std::thread gameThread(&SimpleGUIGame::start,&g);

	gameThread.join();
	renderThread.join();
}
