/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:09:22 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/14 02:52:49 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>

class Fixed {
 public:
  Fixed(void);
  Fixed(const Fixed &fixed);
  Fixed(const int k);
  Fixed(const float k);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(const int raw);

  float toFloat(void) const;
  int toInt(void) const;

 private:
  static const int kFractionalBits = 8;
  int value_;
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed);

#endif
