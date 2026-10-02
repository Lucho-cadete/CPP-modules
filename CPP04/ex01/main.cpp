/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 09:59:10 by lucho             #+#    #+#             */
/*   Updated: 2026/10/02 13:16:23 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <iostream>

int main()
{
    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();

    std::cout << std::endl;

    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << std::endl;

    // Assign ideas to one Dog
    Dog* dog = dynamic_cast<Dog*>(animals[0]);
    if (dog)
    {
        dog->getBrain()->setIdea(0, "I want to eat");
        dog->getBrain()->setIdea(1, "I want to play");

        std::cout << "Dog idea 0: "
                  << dog->getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog idea 1: "
                  << dog->getBrain()->getIdea(1) << std::endl;
    }

    std::cout << std::endl;

    // Assign ideas to one Cat
    Cat* cat = dynamic_cast<Cat*>(animals[5]);
    if (cat)
    {
        cat->getBrain()->setIdea(0, "I want fish");
        cat->getBrain()->setIdea(1, "I want to sleep");

        std::cout << "Cat idea 0: "
                  << cat->getBrain()->getIdea(0) << std::endl;
        std::cout << "Cat idea 1: "
                  << cat->getBrain()->getIdea(1) << std::endl;
    }

    std::cout << std::endl;

    // Delete all animals as Animals
    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}
