#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

int main() {
  std::cout<<"Hi, Please type your name"<<std::endl;
  char username[100];
  std::cin.getline(username, sizeof(username));
  strcat(username, ":   ");

  std::cout<<"====================================== Happy chatting ======================================="<<std::endl;
  std::cout<<"======= START TYPING ========"<<std::endl;
  std::string filename = "backupchat.txt";

  char message[1000];
  while (message != "exit_chat"){
    std::fstream uidlFile(filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
    std::cin.getline(message,sizeof(message));
    uidlFile << username<< message << "\n";

    uidlFile.close();
    system("clear");
    std::cout << std::ifstream(filename.c_str()).rdbuf()<<std::endl;

  }

  return 0;
}
