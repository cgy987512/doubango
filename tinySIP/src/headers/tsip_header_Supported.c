
/* #line 1 "tsip_parser_header_Supported.rl" */
/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_header_Supported.c
 * @brief SIP Supported header.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tinysip/headers/tsip_header_Supported.h"

#include "tinysip/parsers/tsip_parser_uri.h"

#include "tsk_debug.h"
#include "tsk_memory.h"

#include <string.h>

/**@defgroup tsip_header_Supported_group SIP Supported header.
*/

/***********************************
*	Ragel state machine.
*/

/* #line 70 "tsip_parser_header_Supported.rl" */


int tsip_header_Supported_tostring(const void* header, tsk_buffer_t* output)
{
	if(header)
	{
		const tsip_header_Supported_t *Supported = header;
		tsk_list_item_t *item;
		tsk_string_t *str;
		int ret = 0;

		tsk_list_foreach(item, Supported->options)
		{
			str = item->data;
			if(item == Supported->options->head)
			{
				tsk_buffer_append(output, str->value, strlen(str->value));
			}
			else
			{
				tsk_buffer_appendEx(output, ",%s", str->value);
			}
		}

		return ret;
	}

	return -1;
}

tsip_header_Supported_t *tsip_header_Supported_parse(const char *data, size_t size)
{
	int cs = 0;
	const char *p = data;
	const char *pe = p + size;
	const char *eof = pe;
	tsip_header_Supported_t *hdr_supported = TSIP_HEADER_SUPPORTED_CREATE();
	
	const char *tag_start;

	
/* #line 91 "../src/headers/tsip_header_Supported.c" */
static const char _tsip_machine_parser_header_Supported_actions[] = {
	0, 1, 0, 1, 1, 1, 2
};

static const char _tsip_machine_parser_header_Supported_key_offsets[] = {
	0, 0, 4, 7, 24, 25, 41, 45, 
	46, 48, 51, 68, 69, 71, 87, 89, 
	91, 93, 95, 97, 99, 101, 103
};

static const char _tsip_machine_parser_header_Supported_trans_keys[] = {
	75, 83, 107, 115, 9, 32, 58, 9, 
	13, 32, 33, 37, 39, 126, 42, 43, 
	45, 46, 48, 57, 65, 90, 95, 122, 
	10, 9, 13, 32, 33, 37, 39, 44, 
	126, 42, 46, 48, 57, 65, 90, 95, 
	122, 9, 13, 32, 44, 10, 9, 32, 
	9, 32, 44, 9, 13, 32, 33, 37, 
	39, 126, 42, 43, 45, 46, 48, 57, 
	65, 90, 95, 122, 10, 9, 32, 9, 
	32, 33, 37, 39, 126, 42, 43, 45, 
	46, 48, 57, 65, 90, 95, 122, 85, 
	117, 80, 112, 80, 112, 79, 111, 82, 
	114, 84, 116, 69, 101, 68, 100, 0
};

static const char _tsip_machine_parser_header_Supported_single_lengths[] = {
	0, 4, 3, 7, 1, 8, 4, 1, 
	2, 3, 7, 1, 2, 6, 2, 2, 
	2, 2, 2, 2, 2, 2, 0
};

static const char _tsip_machine_parser_header_Supported_range_lengths[] = {
	0, 0, 0, 5, 0, 4, 0, 0, 
	0, 0, 5, 0, 0, 5, 0, 0, 
	0, 0, 0, 0, 0, 0, 0
};

static const unsigned char _tsip_machine_parser_header_Supported_index_offsets[] = {
	0, 0, 5, 9, 22, 24, 37, 42, 
	44, 47, 51, 64, 66, 69, 81, 84, 
	87, 90, 93, 96, 99, 102, 105
};

static const char _tsip_machine_parser_header_Supported_indicies[] = {
	0, 2, 0, 2, 1, 0, 0, 3, 
	1, 3, 4, 3, 5, 5, 5, 5, 
	5, 5, 5, 5, 5, 1, 6, 1, 
	7, 8, 7, 9, 9, 9, 10, 9, 
	9, 9, 9, 9, 1, 11, 12, 11, 
	13, 1, 14, 1, 15, 15, 1, 15, 
	15, 13, 1, 13, 16, 13, 5, 5, 
	5, 5, 5, 5, 5, 5, 5, 1, 
	17, 1, 18, 18, 1, 18, 18, 5, 
	5, 5, 5, 5, 5, 5, 5, 5, 
	1, 19, 19, 1, 20, 20, 1, 21, 
	21, 1, 22, 22, 1, 23, 23, 1, 
	24, 24, 1, 25, 25, 1, 0, 0, 
	1, 1, 0
};

static const char _tsip_machine_parser_header_Supported_trans_targs[] = {
	2, 0, 14, 3, 4, 5, 22, 6, 
	4, 5, 10, 6, 7, 10, 8, 9, 
	11, 12, 13, 15, 16, 17, 18, 19, 
	20, 21
};

static const char _tsip_machine_parser_header_Supported_trans_actions[] = {
	0, 0, 0, 0, 0, 1, 5, 3, 
	3, 0, 3, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0
};

static const int tsip_machine_parser_header_Supported_start = 1;
static const int tsip_machine_parser_header_Supported_first_final = 22;
static const int tsip_machine_parser_header_Supported_error = 0;

static const int tsip_machine_parser_header_Supported_en_main = 1;


/* #line 111 "tsip_parser_header_Supported.rl" */
	
/* #line 176 "../src/headers/tsip_header_Supported.c" */
	{
	cs = tsip_machine_parser_header_Supported_start;
	}

/* #line 112 "tsip_parser_header_Supported.rl" */
	
/* #line 183 "../src/headers/tsip_header_Supported.c" */
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _tsip_machine_parser_header_Supported_trans_keys + _tsip_machine_parser_header_Supported_key_offsets[cs];
	_trans = _tsip_machine_parser_header_Supported_index_offsets[cs];

	_klen = _tsip_machine_parser_header_Supported_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _tsip_machine_parser_header_Supported_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _tsip_machine_parser_header_Supported_indicies[_trans];
	cs = _tsip_machine_parser_header_Supported_trans_targs[_trans];

	if ( _tsip_machine_parser_header_Supported_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _tsip_machine_parser_header_Supported_actions + _tsip_machine_parser_header_Supported_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
/* #line 52 "tsip_parser_header_Supported.rl" */
	{
		tag_start = p;
	}
	break;
	case 1:
/* #line 57 "tsip_parser_header_Supported.rl" */
	{
		TSK_PARSER_ADD_STRING(hdr_supported->options);
	}
	break;
	case 2:
/* #line 62 "tsip_parser_header_Supported.rl" */
	{
	}
	break;
/* #line 274 "../src/headers/tsip_header_Supported.c" */
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

/* #line 113 "tsip_parser_header_Supported.rl" */
	
	if( cs < 
/* #line 290 "../src/headers/tsip_header_Supported.c" */
22
/* #line 114 "tsip_parser_header_Supported.rl" */
 )
	{
		TSK_OBJECT_SAFE_FREE(hdr_supported);
	}
	
	return hdr_supported;
}







//========================================================
//	Supported header object definition
//

/**@ingroup tsip_header_Supported_group
*/
static void* tsip_header_Supported_create(void *self, va_list * app)
{
	tsip_header_Supported_t *Supported = self;
	if(Supported)
	{
		TSIP_HEADER(Supported)->type = tsip_htype_Supported;
		TSIP_HEADER(Supported)->tostring = tsip_header_Supported_tostring;
	}
	else
	{
		TSK_DEBUG_ERROR("Failed to create new Supported header.");
	}
	return self;
}

/**@ingroup tsip_header_Supported_group
*/
static void* tsip_header_Supported_destroy(void *self)
{
	tsip_header_Supported_t *Supported = self;
	if(Supported)
	{
		TSK_OBJECT_SAFE_FREE(Supported->options);
	}
	else TSK_DEBUG_ERROR("Null Supported header.");

	return self;
}

static const tsk_object_def_t tsip_header_Supported_def_s = 
{
	sizeof(tsip_header_Supported_t),
	tsip_header_Supported_create,
	tsip_header_Supported_destroy,
	0
};
const void *tsip_header_Supported_def_t = &tsip_header_Supported_def_s;