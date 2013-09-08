#ifndef  messageReceiver_h
#define messageReceiver_h

#include "messageGeneric.h"

#include <string>
#include <queue>
#include <atomic>
#include <map>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/core/type_vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum messageType { CREATE, DELETE, EXIT };

struct Message
{
	Message(messageType in_type, int in_id)
			: type(in_type), id(in_id), position(), orientation(),
				scaling(), geometry_path(), material_path() {}
	Message(messageType in_type,
			int in_id,
			glm::vec3 in_position,
			glm::quat in_orientation,
			glm::vec3 in_scaling,
			std::string in_geometry_path,
			std::string in_material_path)
			: type(in_type), id(in_id), position(in_position), orientation(in_orientation),
				scaling(in_scaling), geometry_path(in_geometry_path), material_path(in_material_path) {}

	messageType type;
	int id;
	glm::vec3 position;
	glm::quat orientation;
	glm::vec3 scaling;
	std::string geometry_path;
	std::string material_path;
};

struct EntityInfo
{
	unsigned int id;
	glm::vec3 coords;
	glm::quat orientation;

	EntityInfo(unsigned int id, glm::vec3 coords, glm::quat orientation)
		:id(id), coords(coords), orientation(orientation){}
};

class MessageReceiver : public MessageChannel::MessageReceiver {
public:
	MessageReceiver() : MessageChannel::MessageReceiver() { }
	MessageReceiver(const MessageChannel::MessageReceiver &receiver) : MessageChannel::MessageReceiver(receiver) { }
	MessageReceiver(MessageChannel::MessageReceiver &&receiver) : MessageChannel::MessageReceiver(receiver) { }

	bool tryGetMessage(std::shared_ptr<Message>& message) {
		return tryGet< std::shared_ptr<Message> >(message);
	}
};

class MessageSender : public MessageChannel::MessageSender {
public:
	MessageSender() : MessageChannel::MessageSender() { }
	MessageSender(const MessageChannel::MessageSender &receiver) : MessageChannel::MessageSender(receiver) { }
	MessageSender(MessageChannel::MessageSender &&receiver) : MessageChannel::MessageSender(receiver) { }

	void pushLoadSceneMessages();
	void pushCreateMarkerMessage(std::string label, int player);
	void pushCreateGemMessage(std::string label, int player);
	void pushDeleteMessage(int id);
	void pushExitMessage();
};

#endif
