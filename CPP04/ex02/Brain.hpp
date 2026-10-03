/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:40:12 by lucho             #+#    #+#             */
/*   Updated: 2026/10/03 17:34:50 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(Brain const &other);
		Brain& operator=(Brain const &other);
		~Brain(void);

		void setIdea(int index, std::string const &idea);
		std::string getIdea(int index) const;
};
