/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:59:10 by lucho             #+#    #+#             */
/*   Updated: 2026/10/02 11:06:58 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	std::cout << "=== CONSTRUCTION ===" << std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* i = new Dog();
	const Animal* j = new Cat();
	Dog d;
	Cat c;
	const Animal& k = d;
	const Animal& l = c;

	std::cout << std::endl << "=== CONSTRUCTION: WRONG CLASSES ===" << std::endl << std::endl;

	const WrongAnimal* beta = new WrongAnimal();
	const WrongAnimal* m = new WrongCat();
	WrongCat jerry;

	std::cout << std::endl << "=== GETTYPE ===" << std::endl << std::endl;

	std::cout << i->getType() << std::endl;
	std::cout << k.getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << l.getType() << std::endl;

	std::cout << std::endl << "=== GETTYPE: WRONG CLASSES ===" << std::endl << std::endl;

	std::cout << beta->getType() << std::endl;
	std::cout << m->getType() << std::endl;
	std::cout << jerry.getType() << std::endl;

	std::cout << std::endl << "=== MAKESOUND: VIRTUAL PICKS THE REAL OBJECT ===" << std::endl << std::endl;

	meta->makeSound();
	i->makeSound();
	k.makeSound();
	j->makeSound();
	l.makeSound();

	std::cout << std::endl << "=== MAKESOUND: NO VIRTUAL, THE POINTER WINS ===" << std::endl << std::endl;

	beta->makeSound();
	m->makeSound();

	std::cout << std::endl << "=== MAKESOUND: WRONGCAT USED AS A WRONGCAT ===" << std::endl << std::endl;

	jerry.makeSound();

	std::cout << std::endl << "=== ORTHODOX CANONICAL FORM ===" << std::endl << std::endl;

	Dog original;
	Dog copy(original);
	Dog assigned;
	assigned = original;
	std::cout << "copy type: " << copy.getType() << std::endl;
	std::cout << "assigned type: " << assigned.getType() << std::endl;

	std::cout << std::endl << "=== DESTRUCTION ===" << std::endl << std::endl;

	delete j;
	delete i;
	delete meta;
	delete m;
	delete beta;

	return 0;
}
