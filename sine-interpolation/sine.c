/*
tis-examples
Copyright (C) 2022 TrustInSoft
mailto:contact AT trust-in-soft DOT com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <math.h>
#include "sine.h"

float sin_tbl[91] = {
    0.00000f, 0.01745f, 0.03490f, 0.05234f, 0.06976f, 0.08716f, 0.10453f, 0.12187f,
    0.13917f, 0.15643f, 0.17365f, 0.19081f, 0.20791f, 0.22495f, 0.24192f, 0.25882f,
    0.27564f, 0.29237f, 0.30902f, 0.32557f, 0.34202f, 0.35837f, 0.37461f, 0.39073f,
    0.40674f, 0.42262f, 0.43837f, 0.45399f, 0.46947f, 0.48481f, 0.50000f, 0.51504f,
    0.52992f, 0.54464f, 0.55919f, 0.57358f, 0.58779f, 0.60182f, 0.61566f, 0.62932f,
    0.64279f, 0.65606f, 0.66913f, 0.68200f, 0.69466f, 0.70711f, 0.71934f, 0.73135f,
    0.74314f, 0.75471f, 0.76604f, 0.77715f, 0.78801f, 0.79864f, 0.80902f, 0.81915f,
    0.82904f, 0.83867f, 0.84805f, 0.85717f, 0.86603f, 0.87462f, 0.88295f, 0.89101f,
    0.89879f, 0.90631f, 0.91355f, 0.92050f, 0.92718f, 0.93358f, 0.93969f, 0.94552f,
    0.95106f, 0.95630f, 0.96126f, 0.96593f, 0.97030f, 0.97437f, 0.97815f, 0.98163f,
    0.98481f, 0.98769f, 0.99027f, 0.99255f, 0.99452f, 0.99619f, 0.99756f, 0.99863f,
    0.99939f, 0.99985f, 1.00000f
};

float sin_deg(float x)
{
    if (x < 0.0f || x > 90.0f)
        return OUT_OF_BOUNDS;
    float int_part;
    float fract_part = modff(x, &int_part);
    int i = (int)int_part;
    return sin_tbl[i] * (1.0f - fract_part) + sin_tbl[i + 1] * fract_part;
}