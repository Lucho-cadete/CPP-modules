#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

int	main(void)
{
	std::cout << "---> MutantStack <---" << std::endl;
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int>	s(mstack);

		std::cout << s.top() << std::endl;
	}

	std::cout << "\n---> std::list <---" << std::endl;
	{
		std::list<int>	lst;

		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::list<int>::iterator	it = lst.begin();
		std::list<int>::iterator	ite = lst.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::list<int>	s(lst);

		std::cout << s.back() << std::endl;
	}
		std::cout << "\n---> Empty MutantStack: begin() == end() <---" << std::endl;
	{
		MutantStack<int>	empty;

		if (empty.begin() == empty.end())
			std::cout << "nothing to iterate" << std::endl;
	}
		std::cout << "\n---> Change an element through an iterator <---" << std::endl;
	{
		MutantStack<int>	mstack;

		mstack.push(10);
		mstack.push(20);
		mstack.push(30);

		MutantStack<int>::iterator	it = std::find(mstack.begin(), mstack.end(), 20);

		*it = 99;
		for (it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "top is still: " << mstack.top() << std::endl;
	}
		std::cout << "\n---> Const MutantStack of strings <---" << std::endl;
	{
		MutantStack<std::string>	words;

		words.push("hello");
		words.push("mutant");
		words.push("stack");

		MutantStack<std::string> const	frozen(words);

		for (MutantStack<std::string>::const_iterator it = frozen.begin(); it != frozen.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "size: " << frozen.size() << ", top: " << frozen.top() << std::endl;
	}
	return (0);
}
