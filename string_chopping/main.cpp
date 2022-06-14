#include <iostream>

int main() {
  std::string t = "AntiKt4EMPflowJets_Btagging2019";
  std::string s = "Jets";

  std::string::size_type i = t.find(s);

  if (i != std::string::npos)
   t.erase(i, (t.length() - i));
  std::cout<<t<<std::endl;
}
