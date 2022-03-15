/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:16:01 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/15 13:55:17 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed(void) : value_(0) {}

Fixed::Fixed(const int k) : value_(k * (1 << kFractionalBits)) {}

Fixed::Fixed(const float k) : value_(std::roundf(k * (1 << kFractionalBits))) {}

Fixed::Fixed(const Fixed &fixed) { *this = fixed; }

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(const Fixed &fixed) {
  value_ = fixed.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
  return value_ > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
  return value_ < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
  return value_ >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
  return value_ <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
  return value_ == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
  return value_ != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
  Fixed n;

  n.setRawBits(value_ + fixed.getRawBits());
  return n;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
  Fixed n;

  n.setRawBits(value_ - fixed.getRawBits());
  return n;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
  return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
  return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void) {
  ++value_;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed n(*this);

  ++value_;
  return n;
}

Fixed &Fixed::operator--(void) {
  --value_;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed n(*this);

  --value_;
  return n;
}

Fixed Fixed::operator-(void) {
  Fixed n;

  n.setRawBits(-value_);
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
  return static_cast<float>(value_) / (1 << kFractionalBits);
}

int Fixed::toInt(void) const { return value_ / (1 << kFractionalBits); }

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed) {
  stream << fixed.toFloat();
  return stream;
}
