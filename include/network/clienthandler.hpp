#ifndef BRIGHT_NETWORK_CLIENTHANDLER_H
#define BRIGHT_NETWORK_CLIENTHANDLER_H

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <memory>
#include "base/actorcontrolcontroller.hpp"
#include "network/networkmessage.hpp"
#include "network/loginresponsemessage.hpp"
#include "network/updatemessage.hpp"
#include "network/loginmessage.hpp"
#include "input/commandmessage.hpp"

#include "converters/aabbconverter.hpp"

#include "input/globalstructs.hpp"

namespace bright{

  namespace network{

class ClientHandler{

public:
  ClientHandler(std::map<std::string, bright::base::ActorControlController>& playerControllers);

  std::string username();
  std::string password();

  bool is_logged_in();

  void add_message(std::shared_ptr<NetworkMessage>);
  void process_messages();

  bool need_to_send_login_response();
  void need_to_send_login_response(bool value);
  const std::string& get_login_response();

  UpdateMessage get_one_update();
  void clear_one_update();
  bool any_updates();

  void add_update_response();

private:
 
  void empty_commands();
  void handle_login();
  void handle_commands();

  void add_login_message(std::shared_ptr<NetworkMessage> networkMessage);
  void add_command_message(std::shared_ptr<NetworkMessage> networkMessage);

  bool isLoggedIn_;
  bool needToSendLoginResponse_;
  LoginResponseMessage loginResponseMessage_;

  bool needToSendUpdateResponse_;
  std::vector<UpdateMessage> updateResponses_;

  std::map<std::string, bright::base::ActorControlController>& playerControllers_;
  std::vector<bright::input::CommandMessage> commands_;
  LoginMessage loginMessage_;
  bool haveLoginMessage_;

  bright::input::ControlState controlState_;


};



  }

}



#endif



