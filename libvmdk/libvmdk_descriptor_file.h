/*
 * Descriptor file functions
 *
 * Copyright (c) 2009-2012 Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBVMDK_DESCRIPTOR_FILE_H )
#define _LIBVMDK_DESCRIPTOR_FILE_H

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include "libvmdk_extent_descriptor.h"
#include "libvmdk_libbfio.h"
#include "libvmdk_libcdata.h"
#include "libvmdk_libcerror.h"
#include "libvmdk_libcsplit.h"

#if defined( __cplusplus )
extern "C" {
#endif

extern const char vmdk_descriptor_file_signature[ 21 ];

typedef struct libvmdk_descriptor_file libvmdk_descriptor_file_t;

struct libvmdk_descriptor_file
{
	/* The format version
	 */
	int version;

	/* The content identifier
	 */
	uint32_t content_identifier;

	/* The parent content identifier
	 */
	uint32_t parent_content_identifier;

	/* The disk type
	 */
	int disk_type;

	/* The (storage) media size
	 */
	size64_t media_size;

	/* The extents array
	 */
	libcdata_array_t *extents_array;
};

int libvmdk_descriptor_file_initialize(
     libvmdk_descriptor_file_t **descriptor_file,
     libcerror_error_t **error );

int libvmdk_descriptor_file_free(
     libvmdk_descriptor_file_t **descriptor_file,
     libcerror_error_t **error );

int libvmdk_descriptor_file_read(
     libvmdk_descriptor_file_t *descriptor_file,
     libbfio_handle_t *file_io_handle,
     libcerror_error_t **error );

int libvmdk_descriptor_file_read_string(
     libvmdk_descriptor_file_t *descriptor_file,
     const char *value_string,
     size_t value_string_size,
     libcerror_error_t **error );

int libvmdk_descriptor_file_read_header(
     libvmdk_descriptor_file_t *descriptor_file,
     libcsplit_narrow_split_string_t *lines,
     int number_of_lines,
     int *line_index,
     libcerror_error_t **error );

int libvmdk_descriptor_file_read_extents(
     libvmdk_descriptor_file_t *descriptor_file,
     libcsplit_narrow_split_string_t *lines,
     int number_of_lines,
     int *line_index,
     libcerror_error_t **error );

int libvmdk_descriptor_file_read_disk_database(
     libvmdk_descriptor_file_t *descriptor_file,
     libcsplit_narrow_split_string_t *lines,
     int number_of_lines,
     int *line_index,
     libcerror_error_t **error );

int libvmdk_descriptor_file_get_number_of_extents(
     libvmdk_descriptor_file_t *descriptor_file,
     int *number_of_extents,
     libcerror_error_t **error );

int libvmdk_descriptor_file_get_extent_by_index(
     libvmdk_descriptor_file_t *descriptor_file,
     int extent_index,
     libvmdk_extent_descriptor_t **extent_descriptor,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif
