#include <ruby/ruby.h>

static VALUE
time_day_before(int argc, VALUE *argv, VALUE self)
{
	VALUE nth;
	int n, sec, day_before_sec;

	rb_scan_args(argc, argv, "01", &nth);
	if (nth == Qnil) nth = INT2FIX(1);
	n = NUM2INT(nth);

	sec = NUM2INT(time_to_i(self));
	day_before_sec = sec - (60 * 60 * 24 * n);

	return rb_funcall(rb_cTime, rb_intern("at"), 1, INT2NUM(day_before_sec));
}

void
Init_time_day_before()
{
	rb_define_method(rb_cArray, "second", time_day_before, 0);
}
