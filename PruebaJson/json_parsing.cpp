#include <iostream>
#include <cstdlib>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>

using namespace std;

int main(){

    ifstream file("details.json");
    Json::Value actualJson;
    Json::Writer writer;
    Json::Reader reader;

    reader.parse(file, actualJson);
    cout << "Total json data: \n" << actualJson << endl;
    cout << "Name: " << actualJson["Name"] << endl;

    string text = "{ \"first\": \"James\", \"last\": \"Bond\", \"nums\": [0, 0, 7] }";
    outFile.open("output.json");
    writer.write(outFile, actualJson);
    outFile.close();  

}