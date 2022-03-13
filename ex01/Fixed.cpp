/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:16:01 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/14 02:52:35 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed(void) : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int k) : value_(k << (kFractionalBits)) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float k) {
  value_ = static_cast<int>(std::roundf(k * (1 << (kFractionalBits))));
  std::cout << "Float constructor called" << std::endl;
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

int Fixed::getRawBits(void) const { return value_; }

void Fixed::setRawBits(const int raw) { value_ = raw; }

float Fixed::toFloat(void) const {
  return static_cast<double>(value_) / (1 << (kFractionalBits));
}

int Fixed::toInt(void) const { return value_ >> (kFractionalBits); }

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed) {
  stream << fixed.toFloat();
  return stream;
}
