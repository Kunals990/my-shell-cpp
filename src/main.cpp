#include <iostream>
#include <map>
#include <string.h>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Uncomment this block to pass the first stage
  while (true) {
      std::cout << "$ ";

      std::string input;
      std::getline(std::cin, input);
      std::pmr::map<std::string,int>mpp={{"echo",1},{"exit",1},{"type",1}};
      if (input =="exit 0") {
          return 0;
      }
      if (input.substr(0,5)=="echo ") {
          std::cout<<input.substr(5)<<std::endl;
      }
      else if (input.substr(0,5)=="type ") {
          std::string command = input.substr(5);
          if (mpp.find(command) != mpp.end()) {
              std::cout<<command<<" is a shell builtin"<<std::endl;
          }
          else {
              std::cout<<command<<": not found"<<std::endl;
          }

      }
      else {
          std::cout << input <<": command not found"<<std::endl;
      }
  }
}
