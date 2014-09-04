
def TOOL_ADD_HEADER(env):
   """A Tool to add a header from $HEADER to the source file"""
   add_header = Builder(action=['echo "$HEADER" > $TARGET',
                              'cat $SOURCE >> $TARGET'])
   env.Append(BUILDERS = {'AddHeader' : add_header})
   env['HEADER'] = '' # set default value
