#include <server.h>
#include <scratchpad.cpp>

using namespace ucm;

int main(int argc, char** argv){

    Server server(argc, argv);

    server.renderHTML("/", "index.html");

   
      server.route("/Press", [&](const request& req, response& res){
         if(req.has_params({"amount"})){
        
        std::string length = req.url_params.get("amount");
         
         int amount = std::stoi(length);

         int answer = main();

         std::string answer_string = std::to_string(answer);

         res.sendHTML(answer_string);

         } else {
             res.sendError400();
         }
     });

    server.run();
};
