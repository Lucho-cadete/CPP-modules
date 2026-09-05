/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:40:38 by lucho             #+#    #+#             */
/*   Updated: 2026/09/05 14:46:12 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string zombieName);
        ~Zombie();
        void announce(void);
        void setName(std::string zombieName);
};

#endif