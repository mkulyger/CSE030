#include <server.h>

ucm::json big5;

ucm::json lionImages;
ucm::json rhinImages;
ucm::json buffImages;
ucm::json eleImages;
ucm::json leoImages;
ucm::json errorJSON;

std::vector<std::string> lions = {"lion-1.jpeg", "lion-2.jpeg", "lion-3.jpeg", "lion-4.jpeg"};
std::vector<std::string> rhinos = {"rhino-1.jpeg", "rhino-2.jpeg", "rhino-3.jpeg", "rhino-4.jpeg"};
std::vector<std::string> buffalos = {"buffalo-1.jpeg", "buffalo-2.jpeg", "buffalo-3.jpeg", "buffalo-4.jpeg"};
std::vector<std::string> elephants = {"elephant-1.jpeg", "elephant-2.jpeg", "elephant-3.jpeg", "elephant-4.jpeg"};
std::vector<std::string> leopards = {"leopard-1.jpeg", "leopard-2.jpeg", "leopard-3.jpeg", "leopard-4.jpeg"};
std::vector<std::string> errorPic = {"error.png"};

void init(){
	big5["lion"] = lions;
	big5["rhino"] = rhinos;
	big5["buffalo"] = buffalos;
	big5["elephant"] = elephants;
	big5["leopard"] = leopards;
}

ucm::json search(std::string key){
	// Provide your code here
	// This function should return a specific animal category, specified by key
	// The function should return an appropriate message if the key is not found

	lionImages["lion"] = lions;
	rhinImages["rhino"] = rhinos;
	buffImages["buffalo"] = buffalos;
	eleImages["elephant"] = elephants;
	leoImages["leopard"] = leopards;
	errorJSON["errorJSON"] = errorPic;

	if(key == "lion" || key == "lions"){
		return lionImages;
	}
	else if(key == "rhino" || key == "rhinos"){
		return rhinImages;
	}
	else if(key == "buffalo" || key == "buffalos"){
		return buffImages;
	}
	else if(key == "elephant" || key == "elephants"){
		return eleImages;
	}
	else if(key == "leopard" || key == "leopards"){
		return leoImages;
	}
	else{
		return errorJSON;
	}
}

ucm::json getAll(){
	// This should return all the data we have
	return big5;
}
