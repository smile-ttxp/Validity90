/*
 * Main definitions for libfprint
 * Copyright (C) 2007 Daniel Drake <dsd@gentoo.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __FPRINT_H__
#define __FPRINT_H__

/* structs that applications are not allowed to peek into */
struct fp_dscv_dev;
struct fp_dev;
struct fp_driver;
struct fp_print_data;

/* Device discovery */
struct fp_dscv_dev **fp_discover_devs(void);
void fp_dscv_devs_free(struct fp_dscv_dev **devs);
const struct fp_driver *fp_dscv_dev_get_driver(struct fp_dscv_dev *dev);

/* Device handling */
struct fp_dev *fp_dev_open(struct fp_dscv_dev *ddev);
void fp_dev_close(struct fp_dev *dev);
const struct fp_driver *fp_dev_get_driver(struct fp_dev *dev);

/* Drivers */
const char *fp_driver_get_name(const struct fp_driver *drv);
const char *fp_driver_get_full_name(const struct fp_driver *drv);

/* Data handling */
void fp_print_data_free(struct fp_print_data *data);

/* Library */
int fp_init(void);

#endif

