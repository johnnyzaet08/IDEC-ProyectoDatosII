#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>


int main(void) {

  Json::Reader reader;
  Json::Value root;
  Json::StyledWriter writer;
  std::string text = "{ \"tipo\":" + string(tipo) + ", \"nombre\":" + string(nombre)", \"valor\":" string(valor) + "}";
  std::ofstream outFile;
  std::string data;
  char dataa[1024];
  
  // Parse JSON and print errors if needed
  if(!reader.parse(text, root)) {
    std::cout << reader.getFormattedErrorMessages();
    exit(1);
  } else {
    
    /*// Read and modify the json data
    std::cout << "Size: " << root.size() << std::endl;
    std::cout << "Contains nums? " << root.isMember("nums") << std::endl;
    root["first"] = "Jimmy";
    root["middle"] = "Danger";*/
    
    //Write the output to a file
    //outFile.open("output.json");
    data = writer.write(root);
    std::cout << data << std::endl;
    std::copy(data.begin(), data.end(), dataa);
    std::cout << dataa << std::endl;
  }
  return 0;
}