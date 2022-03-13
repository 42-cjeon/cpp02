/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 02:33:46 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/14 02:37:33 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_H_
#define BSP_H_

#include "Point.hpp"

namespace bsp {
bool bsp(const Point a, const Point b, const Point c, const Point point);
bool istrangle(const Point a, const Point b, const Point c);
}  // namespace bsp

#endif
