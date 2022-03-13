/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:16:01 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/14 02:53:03 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed(void) : value_(0) {}

Fixed::Fixed(const int k) : value_(k << (kFractionalBits)) {}

Fixed::Fixed(const float k) {
  value_ = static_cast<int>(std::roundf(k * (1 << (kFractionalBits))));
}

Fixed::Fixed(const Fixed &fixed) { *this = fixed; }

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(const Fixed &fixed) {
  value_ = fixed.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
  return getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
  return getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
  return getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
  return getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
  return getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
  return getRawBits() != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
  Fixed n;

  n.setRawBits(getRawBits() + fixed.getRawBits());
  return n;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
  Fixed n;

  n.setRawBits(getRawBits() - fixed.getRawBits());
  return n;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
  Fixed n;

  n.setRawBits((getRawBits() * fixed.getRawBits()) >> kFractionalBits);
  return n;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
  Fixed n;

  n.setRawBits((getRawBits() << kFractionalBits) / fixed.getRawBits());
  return n;
}

Fixed &Fixed::operator++(void) {
  setRawBits(getRawBits() + 1);
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed n(*this);

  setRawBits(getRawBits() + 1);
  return n;
}

Fixed &Fixed::operator--(void) {
  setRawBits(getRawBits() - 1);
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed n(*this);

  setRawBits(getRawBits() - 1);
  return n;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a > b ? b : a; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return a > b ? b : a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a < b ? b : a; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return a < b ? b : a;
}

int Fixed::getRawBits(void) const { return value_; }

void Fixed::setRawBits(const int raw) { value_ = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(value_) / (1 << (kFractionalBits));
}

int Fixed::toInt(void) const { return value_ >> (kFractionalBits); }

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed) {
  stream << fixed.toFloat();
  return stream;
}
