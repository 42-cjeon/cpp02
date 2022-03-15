/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:18:09 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/15 13:54:11 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

namespace bsp {

static Fixed det(const Point &u, const Point &v) {
  return (u.x() * v.y()) - (u.y() * v.x());
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  Fixed div = det(b, c);
  if (div == 0) {
    return false;
  }
  Fixed alpha = ((det(point, c) - det(a, c)) / div);
  Fixed beta = -((det(point, b) - det(a, b)) / div);
  return alpha > 0 && beta > 0 && alpha + beta < 1;
}
}  // namespace bsp
