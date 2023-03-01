/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H2 T4 Bittiesityksen kääntö
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */


#ifndef BITIT_H
#define BITIT_H

/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))        /* '!!' to make sure this returns 0 or 1 */

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))

void kaannaScharBitit(signed char *ptr);
void kaannaShortBitit(short *ptr);
void kaannaIntBitit(int *ptr);
void kaannaLongBitit(long *ptr);

void tulosta_schar_bitit(signed char x);
void tulosta_short_bitit(short x);
void tulosta_int_bitit(int x);
void tulosta_long_bitit(long x);

#endif
