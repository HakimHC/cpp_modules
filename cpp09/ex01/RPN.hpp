#ifndef __RPN_HPP__
# define __RPN_HPP__

# include <string>
# include <stack>
# include <vector>

class RPN {

	private:
		std::stack<int> 		_stack;
		std::vector<std::string> 	_tokens;

	public:
		RPN();
		RPN(RPN&);
		RPN& operator=(RPN&);
		~RPN();

		void parse(std::string& input);

};

#endif
