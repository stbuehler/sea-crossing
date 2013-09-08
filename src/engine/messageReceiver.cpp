#include "messageReceiver.h"

#include <unordered_map>

const static std::unordered_map<std::string, EntityInfo> entity_info_map {
	{ "A",    EntityInfo(0, glm::vec3(0, 0.125, 0), glm::quat()) },
	{ "BNW",  EntityInfo(1, glm::vec3(-2.5, 0.125, -2.5), glm::rotate(glm::quat(), 45.0, glm::vec3(0, 1, 0))) },
	{ "BNE",  EntityInfo(2, glm::vec3(2.5, 0.125, -2.5), glm::rotate(glm::quat(), -45.0, glm::vec3(0, 1, 0))) },
	{ "BSE",  EntityInfo(3, glm::vec3(2.5, 0.125, 2.5), glm::rotate(glm::quat(), 45.0, glm::vec3(0, 1, 0))) },
	{ "BSW",  EntityInfo(4, glm::vec3(-2.5, 0.125, 2.5), glm::rotate(glm::quat(), -45.0, glm::vec3(0, 1, 0))) },
	{ "CNW",  EntityInfo(5, glm::vec3(-5, 0.125, -5), glm::rotate(glm::quat(), 45.0, glm::vec3(0, 1, 0))) },
	{ "CN",   EntityInfo(6, glm::vec3(0, 0.125, -6.25), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "CNE",  EntityInfo(7, glm::vec3(5, 0.125, -5), glm::rotate(glm::quat(), -45, glm::vec3(0, 1, 0))) },
	{ "CE",   EntityInfo(8, glm::vec3(6.25, 0.125, 0), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "CSE",  EntityInfo(9, glm::vec3(5, 0.125, 5), glm::rotate(glm::quat(), 45, glm::vec3(0, 1, 0))) },
	{ "CS",   EntityInfo(10, glm::vec3(0, 0.125, 6.25), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "CSW",  EntityInfo(11, glm::vec3(-5, 0.125, 5), glm::rotate(glm::quat(), -45, glm::vec3(0, 1, 0))) },
	{ "CW",   EntityInfo(12, glm::vec3(-6.25, 0.125, 0), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "DNW",  EntityInfo(13, glm::vec3(-7.5, 0.125, -7.5), glm::rotate(glm::quat(), 45, glm::vec3(0, 1, 0))) },
	{ "DN-1", EntityInfo(14, glm::vec3(-2.5, 0.125, -8.75), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "DN1",  EntityInfo(15, glm::vec3(2.5, 0.125, -8.75), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "DNE",  EntityInfo(16, glm::vec3(7.5, 0.125, -7.5), glm::rotate(glm::quat(), -45, glm::vec3(0, 1, 0))) },
	{ "DE1",  EntityInfo(17, glm::vec3(8.75, 0.125, -2.5), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "DE-1", EntityInfo(18, glm::vec3(8.75, 0.125, 2.5), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "DSE",  EntityInfo(19, glm::vec3(7.5, 0.125, 7.5), glm::rotate(glm::quat(), 45, glm::vec3(0, 1, 0))) },
	{ "DS1",  EntityInfo(20, glm::vec3(2.5, 0.125, 8.75), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "DS-1", EntityInfo(21, glm::vec3(-2.5, 0.125, 8.75), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "DSW",  EntityInfo(22, glm::vec3(-7.5, 0.125, 7.5), glm::rotate(glm::quat(), -45, glm::vec3(0, 1, 0))) },
	{ "DW-1", EntityInfo(23, glm::vec3(-8.75, 0.125, 2.5), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "DW1",  EntityInfo(24, glm::vec3(-8.75, 0.125, -2.5), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "ENW",  EntityInfo(25, glm::vec3(-10.0, 0.125, -10.0), glm::rotate(glm::quat(), 45, glm::vec3(0, 1, 0))) },
	{ "EN-1", EntityInfo(26, glm::vec3(-5.0, 0.125, -11.25), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "EN",   EntityInfo(27, glm::vec3(0.0, 0.125, -11.25), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "EN1",  EntityInfo(28, glm::vec3(5.0, 0.125, -11.25), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "ENE",  EntityInfo(29, glm::vec3(10.0, 0.125, -10.0), glm::rotate(glm::quat(), -45, glm::vec3(0, 1, 0))) },
	{ "EE1",  EntityInfo(30, glm::vec3(11.25, 0.125, -5.0), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "EE",   EntityInfo(31, glm::vec3(11.25, 0.125, 0.0), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "EE-1", EntityInfo(32, glm::vec3(11.25, 0.125, 5.0), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "ESE",  EntityInfo(33, glm::vec3(10.0, 0.125, 10.0), glm::rotate(glm::quat(), 45, glm::vec3(0, 1, 0))) },
	{ "ES1",  EntityInfo(34, glm::vec3(5.0, 0.125, 11.25), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "ES",   EntityInfo(35, glm::vec3(0.0, 0.125, 11.25), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "ES-1", EntityInfo(36, glm::vec3(-5.0, 0.125, 11.25), glm::rotate(glm::quat(), 0, glm::vec3(0, 1, 0))) },
	{ "ESW",  EntityInfo(37, glm::vec3(-10.0, 0.125, 10.0), glm::rotate(glm::quat(), -45, glm::vec3(0, 1, 0))) },
	{ "EW-1", EntityInfo(38, glm::vec3(-11.25, 0.125, 5.0), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "EW",   EntityInfo(39, glm::vec3(-11.25, 0.125, 0.0), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "EW1",  EntityInfo(40, glm::vec3(-11.25, 0.125, -5.0), glm::rotate(glm::quat(), 90, glm::vec3(0, 1, 0))) },
	{ "eSW",  EntityInfo(41, glm::vec3(-12.5, 0.3, 12.5), glm::quat()) },
	{ "eSE",  EntityInfo(42, glm::vec3(12.5, 0.3, 12.5), glm::quat()) },
	{ "dS-3", EntityInfo(43, glm::vec3(-7.5, 0.3, 10.0), glm::quat()) },
	{ "dS-2", EntityInfo(44, glm::vec3(-5.0, 0.3, 10.0), glm::quat()) },
	{ "dS-1", EntityInfo(45, glm::vec3(-2.5, 0.3, 10.0), glm::quat()) },
	{ "dS",   EntityInfo(46, glm::vec3(0, 0.3, 10.0), glm::quat()) },
	{ "dS1",  EntityInfo(47, glm::vec3(2.5, 0.3, 10.0), glm::quat()) },
	{ "dS2",  EntityInfo(48, glm::vec3(5.0, 0.3, 10.0), glm::quat()) },
	{ "dS3",  EntityInfo(49, glm::vec3(7.5, 0.3, 10.0), glm::quat()) },
	{ "dW-3", EntityInfo(50, glm::vec3(-10.0, 0.3, 7.5), glm::quat()) },
	{ "dE-3", EntityInfo(51, glm::vec3(10.0, 0.3, 7.5), glm::quat()) },
	{ "cS-2", EntityInfo(52, glm::vec3(-5.0, 0.3, 7.5), glm::quat()) },
	{ "cS-1", EntityInfo(53, glm::vec3(-2.5, 0.3, 7.5), glm::quat()) },
	{ "cS",   EntityInfo(54, glm::vec3(0, 0.3, 7.5), glm::quat()) },
	{ "cS1",  EntityInfo(55, glm::vec3(2.5, 0.3, 7.5), glm::quat()) },
	{ "cS2",  EntityInfo(56, glm::vec3(5.0, 0.3, 7.5), glm::quat()) },
	{ "dW-2", EntityInfo(57, glm::vec3(-10.0, 0.3, 5.0), glm::quat()) },
	{ "cW-2", EntityInfo(58, glm::vec3(-7.5, 0.3, 5.0), glm::quat()) },
	{ "cE-2", EntityInfo(59, glm::vec3(7.5, 0.3, 5.0), glm::quat()) },
	{ "dE-2", EntityInfo(60, glm::vec3(10.0, 0.3, 5.0), glm::quat()) },
	{ "bS-1", EntityInfo(61, glm::vec3(-2.5, 0.3, 5.0), glm::quat()) },
	{ "bS",   EntityInfo(62, glm::vec3(0, 0.3, 5.0), glm::quat()) },
	{ "bS1",  EntityInfo(63, glm::vec3(2.5, 0.3, 5.0), glm::quat()) },
	{ "dW-1", EntityInfo(64, glm::vec3(-10, 0.3, 2.5), glm::quat()) },
	{ "cW-1", EntityInfo(65, glm::vec3(-7.5, 0.3, 2.5), glm::quat()) },
	{ "bW-1", EntityInfo(66, glm::vec3(-5.0, 0.3, 2.5), glm::quat()) },
	{ "bE-1", EntityInfo(67, glm::vec3(5.0, 0.3, 2.5), glm::quat()) },
	{ "cE-1", EntityInfo(68, glm::vec3(7.5, 0.3, 2.5), glm::quat()) },
	{ "dE-1", EntityInfo(69, glm::vec3(10, 0.3, 2.5), glm::quat()) },
	{ "aS",   EntityInfo(70, glm::vec3(0, 0.3, 2.5), glm::quat()) },
	{ "dW",   EntityInfo(71, glm::vec3(-10, 0.3, 0), glm::quat()) },
	{ "cW",   EntityInfo(72, glm::vec3(-7.5, 0.3, 0), glm::quat()) },
	{ "bW",   EntityInfo(73, glm::vec3(-5.0, 0.3, 0), glm::quat()) },
	{ "aW",   EntityInfo(74, glm::vec3(-2.5, 0.3, 0), glm::quat()) },
	{ "0",    EntityInfo(75, glm::vec3(0, 0.3, 0), glm::quat()) },
	{ "aE",   EntityInfo(76, glm::vec3(2.5, 0.3, 0), glm::quat()) },
	{ "bE",   EntityInfo(77, glm::vec3(5.0, 0.3, 0), glm::quat()) },
	{ "cE",   EntityInfo(78, glm::vec3(7.5, 0.3, 0), glm::quat()) },
	{ "dE",   EntityInfo(79, glm::vec3(10, 0.3, 0), glm::quat()) },
	{ "aN",   EntityInfo(80, glm::vec3(0, 0.3, -2.5), glm::quat()) },
	{ "dW1",  EntityInfo(81, glm::vec3(-10, 0.3, -2.5), glm::quat()) },
	{ "cW1",  EntityInfo(82, glm::vec3(-7.5, 0.3, -2.5), glm::quat()) },
	{ "bW1",  EntityInfo(83, glm::vec3(-5.0, 0.3, -2.5), glm::quat()) },
	{ "bE1",  EntityInfo(84, glm::vec3(5.0, 0.3, -2.5), glm::quat()) },
	{ "cE1",  EntityInfo(85, glm::vec3(7.5, 0.3, -2.5), glm::quat()) },
	{ "dE1",  EntityInfo(86, glm::vec3(10, 0.3, -2.5), glm::quat()) },
	{ "bN-1", EntityInfo(87, glm::vec3(-2.5, 0.3, -5.0), glm::quat()) },
	{ "bN",   EntityInfo(88, glm::vec3(0, 0.3, -5.0), glm::quat()) },
	{ "bN1",  EntityInfo(89, glm::vec3(2.5, 0.3, -5.0), glm::quat()) },
	{ "dW2",  EntityInfo(90, glm::vec3(-10.0, 0.3, -5.0), glm::quat()) },
	{ "cW2",  EntityInfo(91, glm::vec3(-7.5, 0.3, -5.0), glm::quat()) },
	{ "cE2",  EntityInfo(92, glm::vec3(7.5, 0.3, -5.0), glm::quat()) },
	{ "dE2",  EntityInfo(93, glm::vec3(10.0, 0.3, -5.0), glm::quat()) },
	{ "cN-2", EntityInfo(94, glm::vec3(-5.0, 0.3, -7.5), glm::quat()) },
	{ "cN-1", EntityInfo(95, glm::vec3(-2.5, 0.3, -7.5), glm::quat()) },
	{ "cN",   EntityInfo(96, glm::vec3(0, 0.3, -7.5), glm::quat()) },
	{ "cN1",  EntityInfo(97, glm::vec3(2.5, 0.3, -7.5), glm::quat()) },
	{ "cN2",  EntityInfo(98, glm::vec3(5.0, 0.3, -7.5), glm::quat()) },
	{ "dW3",  EntityInfo(99, glm::vec3(-10.0, 0.3, -7.5), glm::quat()) },
	{ "dE3",  EntityInfo(100, glm::vec3(10.0, 0.3, -7.5), glm::quat()) },
	{ "dN-3", EntityInfo(101, glm::vec3(-7.5, 0.3, -10.0), glm::quat()) },
	{ "dN-2", EntityInfo(102, glm::vec3(-5.0, 0.3, -10.0), glm::quat()) },
	{ "dN-1", EntityInfo(103, glm::vec3(-2.5, 0.3, -10.0), glm::quat()) },
	{ "dN",   EntityInfo(104, glm::vec3(0, 0.3, -10.0), glm::quat()) },
	{ "dN1",  EntityInfo(105, glm::vec3(2.5, 0.3, -10.0), glm::quat()) },
	{ "dN2",  EntityInfo(106, glm::vec3(5.0, 0.3, -10.0), glm::quat()) },
	{ "dN3",  EntityInfo(107, glm::vec3(7.5, 0.3, -10.0), glm::quat()) },
	{ "eNW",  EntityInfo(108, glm::vec3(-12.5, 0.3, -12.5), glm::quat()) },
	{ "eNE",  EntityInfo(109, glm::vec3(12.5, 0.3, -12.5), glm::quat()) },
};

void MessageSender::pushLoadSceneMessages()
{
	std::shared_ptr<Message> newMsg(new Message(CREATE,100,glm::vec3(0.0,0.0,0.0),glm::quat(),glm::vec3(1.0),
		"../resources/meshes/board.fbx",
		"../resources/materials/debugging.slmtl"));

	send< std::shared_ptr<Message> >(newMsg);
}

void MessageSender::pushCreateMarkerMessage(std::string label, int player)
{
	EntityInfo const& entity_info(entity_info_map.at(label));
	int id(entity_info.id);
	glm::vec3 euclid_pos(entity_info.coords);
	glm::quat orientation(entity_info.orientation);
	glm::vec3 scaling(1, 1, 1);
	std::string geom_path = "../resources/meshes/marker.fbx";
	std::string mat_path = "../resources/materials/default.slmtl";
	if(player == 0) mat_path = "../resources/materials/templates/silver.slmtl";
	if(player == 1) mat_path = "../resources/materials/templates/gold.slmtl";
	std::shared_ptr<Message> newMsg(new Message(CREATE,id,euclid_pos,orientation,scaling,geom_path,mat_path));

	send< std::shared_ptr<Message> >(newMsg);
}

void MessageSender::pushCreateGemMessage(std::string label, int player)
{
	EntityInfo const& entity_info(entity_info_map.at(label));
	int id(entity_info.id);
	glm::vec3 euclid_pos(entity_info.coords);
	glm::quat orientation(entity_info.orientation);
	glm::vec3 scaling(1, 1, 1);
	std::string geom_path = "../resources/meshes/gem.fbx";
	std::string mat_path = "../resources/materials/default.slmtl";
	if(player == 0) mat_path = "../resources/materials/templates/silver.slmtl";
	if(player == 1) mat_path = "../resources/materials/templates/gold.slmtl";
	std::shared_ptr<Message> newMsg(new Message(CREATE,id,euclid_pos,orientation,scaling,geom_path,mat_path));

	send< std::shared_ptr<Message> >(newMsg);
}

void MessageSender::pushDeleteMessage(int id)
{
	std::shared_ptr<Message> newMsg(new Message(DELETE,id));
	send< std::shared_ptr<Message> >(newMsg);
}

void MessageSender::pushExitMessage()
{
}
