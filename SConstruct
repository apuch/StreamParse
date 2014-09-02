
unittest = int(ARGUMENTS.get('UNITTEST', 0))
if unittest:
    SConscript('test/test.scons', variant_dir = 'built/test')

SConscript('src/main.scons', variant_dir = 'built/main')

