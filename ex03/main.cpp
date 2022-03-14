/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:26:48 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/14 15:00:11 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "bsp.hpp"

int main(void) {
  std::cout.setf(std::ios::boolalpha);
  std::cout << bsp::bsp(Point(0.0f, 0.0f), Point(0.0f, 1.0f), Point(1.0f, 0.0f),
                        Point(0.2f, 0.2f))
            << std::endl;
  std::cout << bsp::bsp(Point(0.0f, 0.0f), Point(0.0f, 1.0f), Point(1.0f, 0.0f),
                        Point(0.0f, 0.0f))
            << std::endl;
  std::cout << bsp::bsp(Point(0.0f, 0.0f), Point(0.0f, 1.0f), Point(1.0f, 0.0f),
                        Point(0.3f, 0.1f))
            << std::endl;
  return 0;
}
