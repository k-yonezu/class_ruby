baseruby="/usr/local/bin/ruby --disable=gems"
_\
=begin
_=
ruby="${RUBY-$baseruby}"
case "$ruby" in "echo "*) $ruby; exit $?;; esac
case "$0" in /*) r=-r"$0";; *) r=-r"./$0";; esac
exec $ruby "$r" "$@"
=end
=baseruby
class Object
  remove_const :CROSS_COMPILING if defined?(CROSS_COMPILING)
  CROSS_COMPILING = RUBY_PLATFORM
  constants.grep(/^RUBY_/) {|n| remove_const n}
  RUBY_VERSION = "2.6.0"
  RUBY_RELEASE_DATE = "2018-07-21"
  RUBY_PLATFORM = "x86_64-darwin17"
  RUBY_PATCHLEVEL = -1
  RUBY_REVISION = 64007
  RUBY_DESCRIPTION = RubyVM.const_defined?(:MJIT) && RubyVM::MJIT.enabled? ?
    "ruby 2.6.0dev (2018-07-21 trunk 64007) +JIT [x86_64-darwin17]" :
    "ruby 2.6.0dev (2018-07-21 trunk 64007) [x86_64-darwin17]"
  RUBY_COPYRIGHT = "ruby - Copyright (C) 1993-2018 Yukihiro Matsumoto"
  RUBY_ENGINE = "ruby"
  RUBY_ENGINE_VERSION = "2.6.0"
end
builddir = File.dirname(File.expand_path(__FILE__))
srcdir = "../ruby"
top_srcdir = File.realpath(srcdir, builddir)
fake = File.join(top_srcdir, "tool/fake.rb")
eval(File.read(fake), nil, fake)
ropt = "-r#{__FILE__}"
["RUBYOPT"].each do |flag|
  opt = ENV[flag]
  opt = opt ? ([ropt] | opt.split).join(" ") : ropt
  ENV[flag] = opt
end
