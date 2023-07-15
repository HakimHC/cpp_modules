/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakahmed <hakahmed@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:57:30 by hakahmed          #+#    #+#             */
/*   Updated: 2023/07/15 23:02:53 by hakahmed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__

# include <stdint.h>

typedef struct {
	char* ptr;
}	Data;

class Serializer {

	private:
		Serializer();
		Serializer(Serializer&);
		Serializer& operator=(Serializer&);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif
