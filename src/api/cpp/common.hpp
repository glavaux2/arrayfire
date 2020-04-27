/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <af/dim4.hpp>
#include <af/half.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
#include "half.hpp"
#pragma GCC diagnostic pop

#include <cstring>

namespace af {

/// Get the first non-zero dimension
static inline dim_t getFNSD(const int dim, af::dim4 dims) {
    if (dim >= 0) return dim;

    dim_t fNSD = 0;
    for (dim_t i = 0; i < 4; ++i) {
        if (dims[i] > 1) {
            fNSD = i;
            break;
        }
    }
    return fNSD;
}

namespace {
// casts from one type to another. Needed for af_half conversions specialization
template<typename To, typename T>
To cast(T in) {
    return static_cast<To>(in);
}

template<>
[[gnu::unused]] af_half cast<af_half, double>(double in) {
    half_float::half tmp = static_cast<half_float::half>(in);
    af_half out;
    memcpy(&out, &tmp, sizeof(af_half));
    return out;
}

}  // namespace
}  // namespace af
