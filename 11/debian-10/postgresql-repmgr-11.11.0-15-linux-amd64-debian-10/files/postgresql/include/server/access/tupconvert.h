/*-------------------------------------------------------------------------
 *
 * tupconvert.h
 *	  Tuple conversion support.
 *
 *
 * Portions Copyright (c) 1996-2018, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/access/tupconvert.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef TUPCONVERT_H
#define TUPCONVERT_H

#include "access/htup.h"
#include "access/tupdesc.h"
#include "nodes/bitmapset.h"


typedef struct TupleConversionMap
{
	TupleDesc	indesc;			/* tupdesc for source rowtype */
	TupleDesc	outdesc;		/* tupdesc for result rowtype */
	AttrNumber *attrMap;		/* indexes of input fields, or 0 for null */
	Datum	   *invalues;		/* workspace for deconstructing source */
	bool	   *inisnull;
	Datum	   *outvalues;		/* workspace for constructing result */
	bool	   *outisnull;
} TupleConversionMap;


extern TupleConversionMap *convert_tuples_by_position(TupleDesc indesc,
						   TupleDesc outdesc,
						   const char *msg);

extern TupleConversionMap *convert_tuples_by_name(TupleDesc indesc,
					   TupleDesc outdesc,
					   const char *msg);

extern AttrNumber *convert_tuples_by_name_map(TupleDesc indesc,
						   TupleDesc outdesc,
						   const char *msg);

extern HeapTuple do_convert_tuple(HeapTuple tuple, TupleConversionMap *map);
extern Bitmapset *execute_attr_map_cols(Bitmapset *inbitmap, TupleConversionMap *map);

extern void free_conversion_map(TupleConversionMap *map);

#endif							/* TUPCONVERT_H */