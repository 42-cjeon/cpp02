/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:09:22 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/14 02:51:59 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
#define FIXED_H_

class Fixed {
 public:
  Fixed(void);
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(const int raw);

 private:
  static const int kFractionalBits = 8;
  int value_;
};

#endif
