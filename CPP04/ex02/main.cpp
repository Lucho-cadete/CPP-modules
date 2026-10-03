/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:59:10 by lucho             #+#    #+#             */
/*   Updated: 2026/10/03 17:50:53 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#include <iostream>

int main()
{
	std::cout << "=== ARRAY OF ANIMALS: HALF DOGS, HALF CATS ===" << std::endl << std::endl;

	AAnimal *animals[6];

	for (int i = 0; i < 3; i++)
		animals[i] = new Dog();
	for (int i = 3; i < 6; i++)
		animals[i] = new Cat();

	std::cout << std::endl << "=== EACH ONE MAKES ITS OWN SOUND ===" << std::endl << std::endl;

	for (int i = 0; i < 6; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << std::endl << "=== DELETING THEM ALL AS AANIMAL* ===" << std::endl << std::endl;

	for (int i = 0; i < 6; i++)
		delete animals[i];

	std::cout << std::endl << "=== ABSTRACT CLASS: CANNOT BE INSTANTIATED ===" << std::endl << std::endl;

	AAnimal test;   // uncomment this line: it must NOT compile (AAnimal is abstract)
	std::cout << "AAnimal cannot be instantiated: makeSound is a pure virtual function" << std::endl;

	std::cout << std::endl << "=== DEEP COPY TEST (COPY CONSTRUCTOR) ===" << std::endl << std::endl;

	Dog basic;
	basic.getBrain()->setIdea(0, "I want a bone");
	std::cout << "basic idea 0: " << basic.getBrain()->getIdea(0) << std::endl;

	{
		Dog tmp = basic;
		std::cout << "tmp idea 0 (copied): " << tmp.getBrain()->getIdea(0) << std::endl;
		tmp.getBrain()->setIdea(0, "I want a ball");
		std::cout << "tmp idea 0 (changed): " << tmp.getBrain()->getIdea(0) << std::endl;
		std::cout << "basic idea 0 (must not change): " << basic.getBrain()->getIdea(0) << std::endl;
		std::cout << "--- tmp dies here ---" << std::endl;
	}

	std::cout << "basic idea 0 after tmp died: " << basic.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "=== DEEP COPY TEST (ASSIGNMENT OPERATOR) ===" << std::endl << std::endl;

	Cat one;
	Cat two;
	one.getBrain()->setIdea(0, "I want fish");
	two = one;
	std::cout << "two idea 0 (copied): " << two.getBrain()->getIdea(0) << std::endl;
	two.getBrain()->setIdea(0, "I want milk");
	std::cout << "two idea 0 (changed): " << two.getBrain()->getIdea(0) << std::endl;
	std::cout << "one idea 0 (must not change): " << one.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "=== SELF-ASSIGNMENT ===" << std::endl << std::endl;

	one = one;
	std::cout << "one idea 0 after self-assignment: " << one.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "=== BRAIN INDEX LIMITS ===" << std::endl << std::endl;

	Brain b;
	b.setIdea(0, "first idea");
	b.setIdea(99, "last idea");
	b.setIdea(100, "out of range");
	b.setIdea(-1, "out of range");
	std::cout << "idea 0: [" << b.getIdea(0) << "]" << std::endl;
	std::cout << "idea 99: [" << b.getIdea(99) << "]" << std::endl;
	std::cout << "idea 100: [" << b.getIdea(100) << "]" << std::endl;
	std::cout << "idea -1: [" << b.getIdea(-1) << "]" << std::endl;

	std::cout << std::endl << "=== DESTRUCTION ===" << std::endl << std::endl;

	return 0;
}
