ccl_dir = Dir('#/3rdparty/ccl-read-only').abspath
sp_dir = Dir('#/src').abspath
CPPPATH = [ ccl_dir, sp_dir ]

env = Environment(CPPPATH=CPPPATH)
env['CROSS_BUILD'] = None
env['ccl_dir'] = ccl_dir

env['variant_dir'] = Dir('#/built/main').abspath
SConscript('src/main.scons', 
    variant_dir = env['variant_dir'], 
    exports = ['env'])

unittest = int(ARGUMENTS.get('UNITTEST', 0))
if unittest:
    env['variant_dir'] = Dir('#/built/test').abspath
    SConscript('test/test.scons', 
        variant_dir = env['variant_dir'], 
        exports = ['env'])


