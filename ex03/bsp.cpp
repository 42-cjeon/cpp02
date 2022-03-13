/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:18:09 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/14 02:53:25 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

namespace bsp {
bool istrangle(const Point a, const Point b, const Point c) {
  return (a.x() * (b.y() - c.y()) + b.x() * (c.y() - a.y()) +
          c.x() * (a.y() - b.y())) != Fixed(0);
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  if (!istrangle(a, b, c)) {
    return false;
  }
}
}  // namespace bsp
