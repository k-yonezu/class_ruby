#include <ruby/ruby.h>
#include "../internal.h"

static VALUE
fix_plus(VALUE x, VALUE y)
{
	if (FIXNUM_P(y)) {
		return rb_fix_plus_fix(x, y);
	}
	else if (RB_TYPE_P(y, T_BIGNUM)) {
		return rb_big_plus(y, x);
	}
	else if (RB_TYPE_P(y, T_FLOAT)) {
		return DBL2NUM((double)FIX2LONG(x) + RFLOAT_VALUE(y));
	}
	else if (RB_TYPE_P(y, T_COMPLEX)) {
		return rb_complex_plus(y, x);
	}
	else {
		return rb_num_coerce_bin(x, y, '+');
	}
}

VALUE
rb_int_plus(VALUE x, VALUE y)
{
	if (FIXNUM_P(x)) {
		return fix_plus(x, y);
	}
	else if (RB_TYPE_P(x, T_BIGNUM)) {
		return rb_big_plus(x, y);
	}
	return rb_num_coerce_bin(x, y, '+');
}

static VALUE
int_add(VALUE self, VALUE n)
{
	return rb_int_plus(self, n);
}

void
Init_int_add()
{
	rb_define_method(rb_cInteger, "add", int_add, 1);
}
