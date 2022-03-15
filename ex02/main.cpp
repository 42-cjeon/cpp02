/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:26:48 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/15 19:38:01 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

void AssertEqual(const Fixed &a, const Fixed &b) {
  std::cout << a << std::endl;
  assert((a == b));
}

int main(void) {
  std::cout.setf(std::ios::boolalpha);
  std::cout << "[-] Test constructor" << std::endl;
  {
    Fixed a;
    std::cout << a << ": <- must be 0" << std::endl;
    Fixed b(10);
    std::cout << b << ": <- must be 10" << std::endl;
    Fixed c(100.0f);
    std::cout << c << ": <- must be 100.0" << std::endl;
  }
  std::cout << "[-] Test comparsion operator" << std::endl;
  {
    std::cout << (Fixed(42) == Fixed(42)) << std::endl;
    std::cout << (Fixed(4.2f) == Fixed(4.2f)) << std::endl;
    std::cout << (Fixed(41) <= Fixed(42)) << std::endl;
    std::cout << (Fixed(42) <= Fixed(42)) << std::endl;
    std::cout << (Fixed(42) >= Fixed(41)) << std::endl;
    std::cout << (Fixed(42) >= Fixed(42)) << std::endl;
    std::cout << (Fixed(0.1f) >= Fixed(0.0f)) << std::endl;
    std::cout << (Fixed(0.1f) != Fixed(0.01f)) << std::endl;
  }
  std::cout << "[-] Test arithmetic operator" << std::endl;
  {
    std::cout << Fixed(42) + Fixed(42) << std::endl;
    std::cout << Fixed(0.1f) + Fixed(0.42f) << std::endl;
    std::cout << Fixed(-0.1f) + Fixed(10.0f) << std::endl;
    std::cout << Fixed(42) - Fixed(42) << std::endl;
    std::cout << Fixed(-10) - Fixed(1.5f) << std::endl;
    std::cout << Fixed(1000) - Fixed(10) << std::endl;
    std::cout << Fixed(42) * Fixed(42) << std::endl;
    std::cout << Fixed(42) * Fixed(42) << std::endl;
    std::cout << Fixed(42) * Fixed(42) << std::endl;
    std::cout << Fixed(42) / Fixed(42) << std::endl;
    std::cout << Fixed(1) / Fixed(2) << std::endl;
    std::cout << Fixed(1) / Fixed(3) << std::endl;
  }
  std::cout << "[-] Test [post-pre][in/de]crement operator" << std::endl;
  {
    Fixed a, b;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << b-- << std::endl;
    std::cout << b << std::endl;
    std::cout << -- << std::endl;
  }
  std::cout << "[-] Test min / max static function" << std::endl;
  {
    AssertEqual(Fixed::max(Fixed(41.9f), Fixed(42.001f)), Fixed(42.001f));
    AssertEqual(Fixed::max(Fixed(42), Fixed(43.001f)), Fixed(43.001f));
    AssertEqual(Fixed::min(Fixed(41.9f), Fixed(42.001f)), Fixed(41.9f));
    AssertEqual(Fixed::min(Fixed(42), Fixed(43.001f)), Fixed(42));
  }
  return 0;
}
