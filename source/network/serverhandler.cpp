#include "network/serverhandler.hpp"

using namespace bright::network;


ServerHandler::ServerHandler( std::string username, 
                              std::string password, 
                              std::map<std::string, bright::base::ActorControlController>& playerContollers,
                              std::map<std::string, bright::base::ActorControlController>& npcContollers):
  username_(username), password_(password), isLoggedIn_(false), playerControllers_(playerContollers), npcContollers_(npcContollers),
  loginMessage_(username_, password_) {
}



std::string& ServerHandler::get_login_message(){
  loginReqestMessage_ = loginMessage_.request_message();
  return loginReqestMessage_;
}


void ServerHandler::add_message(std::shared_ptr<NetworkMessage> pNetworkMessage){

  if( pNetworkMessage->type() == MessageType::SERVER_LOGIN_RESPONSE ){
    add_login_response_message(pNetworkMessage);
  }
  else if( pNetworkMessage->type() == MessageType::SERVER_UPDATE_RESPONSE ){
    add_update_message(pNetworkMessage);
  }

}


void ServerHandler::process_messages(){
  
  if (!isLoggedIn_ && !loginResponseMessage_.logged_in()){
    empty_updates();
    return;
  }

  if( !isLoggedIn_ && loginResponseMessage_.logged_in() ){
    handle_login_response();
    return;
  }
  
  //now we're logged into the server.. handle all other types of messages
  handle_update_responses();

}


void ServerHandler::add_login_response_message(std::shared_ptr<NetworkMessage> pNetworkMessage){
  if(isLoggedIn_) { return; }

  std::istringstream in( pNetworkMessage->data() );
  bool isLoggedIn = false;
  std::string logedIn;
  std::string message;
  in >> logedIn;
  in >> message;
  if (logedIn.compare("true") == 0){
    isLoggedIn = true;
  }

  loginResponseMessage_ = LoginResponseMessage(isLoggedIn, message);
}

void ServerHandler::add_update_message(std::shared_ptr<NetworkMessage> pNetworkMessage){
  if(!isLoggedIn_) { return; }
  //create newUpdateMessage by parsing the networkMessage's data
  std::istringstream in( pNetworkMessage->data() );
  std::string name;
  glm::vec3 position;
  glm::vec3 rotation;
  std::string isP;
  bool isPlayer = false;
  in >> name;
  in >> isP;
  in >> position.x;
  in >> position.y;
  in >> position.z;
  in >> rotation.x;
  in >> rotation.y;
  in >> rotation.z;
  if (isP.compare("true") == 0){
    isPlayer = true;
  }
  updateMessages_.push_back( UpdateMessage(name, position, rotation, isPlayer) );
}


void ServerHandler::handle_login_response(){

  if ( !loginResponseMessage_.logged_in() ){
    return;
  }

  isLoggedIn_ = true;
}


void ServerHandler::handle_update_responses(){

  auto handle_updates = [&] (UpdateMessage& updateMessage) { 
    //what to do with the update message?
    if( updateMessage.is_player() && updateMessage.name().compare(username_) == 0 ){
      playerControllers_[updateMessage.name()].update( updateMessage.position(), updateMessage.rotation() );
    }
    else if( updateMessage.is_player() ){
      auto it = playerControllers_.find( updateMessage.name() );
      if ( it == playerControllers_.end() ){
        playerControllers_[updateMessage.name()] = bright::base::ActorControlController();
      }
      playerControllers_[updateMessage.name()].update( updateMessage.position(), updateMessage.rotation() );
    }
    else{
      auto it = npcContollers_.find( updateMessage.name() );
      if ( it == npcContollers_.end() ){
        npcContollers_[updateMessage.name()] = bright::base::ActorControlController();
      }
      npcContollers_[updateMessage.name()].update( updateMessage.position(), updateMessage.rotation() );
    }
  };
  std::for_each(updateMessages_.begin(), updateMessages_.end(), handle_updates);

  updateMessages_.clear();
}



void ServerHandler::empty_updates(){
  updateMessages_.clear();
}
