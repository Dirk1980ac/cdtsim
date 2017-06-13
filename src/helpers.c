/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/**************************************************************************
 *            helpers.c
 *
 *  Fr Juni 02 03:45:16 2017
 *  Copyright  2017  Dirk Gottschalk
 *  <dirk.gottschalk1980@googlemail.com>
 **************************************************************************/

#include "cdtsim.h"

unsigned char checksum (unsigned char arr[], int len) {
	int sum = 0;
	for(int i = 0; i < (len-1); ++i) {
		sum += arr[i];
	}

	// Modulo 256 sum
	sum %= 256;

	char ch = sum;

	// Two's complement
	unsigned char twoscompl = ~ch + 1;

	return twoscompl;
}