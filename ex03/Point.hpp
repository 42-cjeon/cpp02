/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:18:14 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/14 02:43:52 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H_
#define POINT_H_

#include "Fixed.hpp"

class Point {
 public:
  Point(void);
  Point(const Point &point);
  Point(float x, float y);
  Point &operator=(const Point &point);
  ~Point(void);

  const Fixed &x(void) const;
  const Fixed &y(void) const;

 private:
  const Fixed x_;
  const Fixed y_;
};

#endif
