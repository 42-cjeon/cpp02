/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:16:01 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/14 00:30:53 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed(void) : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Assignation operator called" << std::endl;
  value_ = fixed.getRawBits();
  return *this;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return value_;
}

void Fixed::setRawBits(const int raw) {
  std::cout << "setRawBits member function called" << std::endl;
  value_ = raw;
}
