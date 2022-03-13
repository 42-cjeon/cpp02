/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:18:12 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/14 02:54:59 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x_(0), y_(0) {}

Point::Point(float x, float y) : x_(x), y_(y) {}

Point::Point(const Point &point) { *this = point; }

Point &Point::operator=(const Point &point) {
  const_cast<Fixed &>(this->x_) = point.x_;
  const_cast<Fixed &>(this->y_) = point.y_;
  return *this;
}

Point::~Point(void) {}

const Fixed &Point::x(void) const { return x_; }

const Fixed &Point::y(void) const { return y_; }
