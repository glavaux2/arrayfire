/*******************************************************
 * Copyright (c) 2018, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

__kernel void fill_value(__global Tk *buffer,
                         Tk value, int n) {
    const uint lid = get_local_id(0);
    const uint bid = get_group_id(0);
    const uint gid = get_global_id(0);

    if (gid < n)
      buffer[gid] = value;
}
