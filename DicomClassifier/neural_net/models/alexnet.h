/*
    Copyright (c) 2013, Taiga Nomi and the respective contributors
    All rights reserved.

    Use of this source code is governed by a BSD-style license that can be found
    in the LICENSE file.
*/
#pragma once

#include <string>

namespace models {

// Based on:
// https://github.com/DeepMark/deepmark/blob/master/torch/image%2Bvideo/alexnet.lua
class alexnet : public neural_net::network<neural_net::sequential> {
 public:
  explicit alexnet(const std::string &name = "")
    : neural_net::network<neural_net::sequential>(name) {
    // todo: (karandesai) shift this to neural_net::activation
    using relu     = neural_net::activation::relu;
    using conv     = neural_net::layers::conv;
    using max_pool = neural_net::layers::max_pool;
    *this << conv(224, 224, 11, 11, 3, 64, padding::valid, true, 4, 4);
    *this << relu(54, 54, 64);
    *this << max_pool(54, 54, 64, 2);
    *this << conv(27, 27, 5, 5, 64, 192, padding::valid, true, 1, 1);
    *this << relu(23, 23, 192);
    *this << max_pool(23, 23, 192, 1);
    *this << conv(23, 23, 3, 3, 192, 384, padding::valid, true, 1, 1);
    *this << relu(21, 21, 384);
    *this << conv(21, 21, 3, 3, 384, 256, padding::valid, true, 1, 1);
    *this << relu(19, 19, 256);
    *this << conv(19, 19, 3, 3, 256, 256, padding::valid, true, 1, 1);
    *this << relu(17, 17, 256);
    *this << max_pool(17, 17, 256, 1);
  }
};

}  // namespace models
