#include <server.h>
#include <string>
#include <mymath.h>

using namespace ucm;

int main(int argc, char** argv){

    Server server(argc, argv);

    server.renderHTML("/", "index.html");

    //              | Name of endpoint     | The function that will execute when endpoint is visited
    //              v                      v
    server.route("/sayHello", [&](const request& req, response& res){
        res.sendHTML("Hello World");
    });

    server.route("/echo", [&](const request& req, response& res){
        if (req.has_params({"text"})){
            // User has provided appropriate data
            std::string input = req.url_params.get("text");
            res.sendHTML(input);
        }
        else{
            // User has not provided appropriate data
            res.sendError400();
        }
    });

    server.route("/Add", [&](const request& req, response& res){
        if (req.has_params({"x", "y"})){
            // Request is valid... 
            std::string x_string = req.url_params.get("x");
            std::string y_string = req.url_params.get("y");

            int x = std::stoi(x_string);
            int y = std::stoi(y_string);

            int ans = Add(x, y);

            std::string ans_string = std::to_string(ans);

            res.sendHTML(ans_string);
        }
        else{
            // request is not valid
            res.sendError400();
        }
    });

server.route("/Subtract", [&](const request& req, response& res){
         if (req.has_params({"x", "y"})){
            //Subtraction
            std::string x_string = req.url_params.get("x");
            std::string y_string = req.url_params.get("y");

            int x = std::stoi(x_string);
            int y = std::stoi(y_string);
           
            int ans = Sub(x, y);
           
            std::string ans_string = std::to_string(ans);
           
            res.sendHTML(ans_string);
       } 
        else{
            // User has not provided appropriate data
            res.sendError400();
        }
    });   
    
       
    server.route("/Multiply", [&](const request& req, response& res){
         if (req.has_params({"x", "y"})){
            //Multiplication
            std::string x_string = req.url_params.get("x");
            std::string y_string = req.url_params.get("y");

            int x = std::stoi(x_string);
            int y = std::stoi(y_string);
           
            int ans = Multi(x, y);
           
            std::string ans_string = std::to_string(ans);
           
            res.sendHTML(ans_string);
        }
       else{
            // User has not provided appropriate data
            res.sendError400();
        }
    });


    server.route("/Divide", [&](const request& req, response& res){
         if (req.has_params({"x", "y"})){
            //Division
            std::string x_string = req.url_params.get("x");
            std::string y_string = req.url_params.get("y");

            int x = std::stoi(x_string);
            int y = std::stoi(y_string);
           
            int ans = Divi(x, y);
           
            std::string ans_string = std::to_string(ans);
           
            res.sendHTML(ans_string);
    }
        else{
            // User has not provided appropriate data
            res.sendError400();
        }
    });

    server.run();
}
