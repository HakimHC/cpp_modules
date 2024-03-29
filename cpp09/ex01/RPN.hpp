#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <list>
#include <stack>
#include <string>

class RPN {
 private:
  std::stack<int> _stack;
  std::list<std::string> _tokens;

 public:
  RPN();
  RPN(const RPN&);
  RPN& operator=(const RPN&);
  ~RPN();

  void parse(std::string& input);
  void operate();
};

#endif
