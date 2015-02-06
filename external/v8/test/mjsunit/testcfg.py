import test
import os
from os.path import join, dirname, exists
import re
import tempfile

MJSUNIT_DEBUG_FLAGS = ['--enable-slow-asserts', '--debug-code', '--verify-heap']
FLAGS_PATTERN = re.compile(r"//\s+Flags:(.*)")
FILES_PATTERN = re.compile(r"//\s+Files:(.*)")
SELF_SCRIPT_PATTERN = re.compile(r"//\s+Env: TEST_FILE_NAME")


class MjsunitTestCase(test.TestCase):

  def __init__(self, path, file, mode, context, config):
    super(MjsunitTestCase, self).__init__(context, path)
    self.file = file
    self.config = config
    self.mode = mode
    self.self_script = False

  def GetLabel(self):
    return "%s %s" % (self.mode, self.GetName())

  def GetName(self):
    return self.path[-1]

  def GetCommand(self):
    result = [self.config.context.GetVm(self.mode)]
    source = open(self.file).read()
    flags_match = FLAGS_PATTERN.search(source)
    if flags_match:
      result += flags_match.group(1).strip().split()
    if self.mode == 'debug':
      result += MJSUNIT_DEBUG_FLAGS
    additional_files = []
    files_match = FILES_PATTERN.search(source);
    # Accept several lines of 'Files:'
    while True:
      if files_match:
        additional_files += files_match.group(1).strip().split()
        files_match = FILES_PATTERN.search(source, files_match.end())
      else:
        break
    for a_file in additional_files:
      result.append(join(dirname(self.config.root), '..', a_file))
    framework = join(dirname(self.config.root), 'mjsunit', 'mjsunit.js')
    if SELF_SCRIPT_PATTERN.search(source):
      result.append(self.CreateSelfScript())
    result += [framework, self.file]
    return result

  def GetSource(self):
    return open(self.file).read()

  def CreateSelfScript(self):
    (fd_self_script, self_script) = tempfile.mkstemp(suffix=".js")
    def MakeJsConst(name, value):
      return "var %(name)s=\'%(value)s\';\n" % \
             {'name': name, \
              'value': value.replace('\\', '\\\\').replace('\'', '\\\'') }
    try:
      os.write(fd_self_script, MakeJsConst('TEST_FILE_NAME', self.file))
    except IOError, e:
      test.PrintError("write() " + str(e))
    os.close(fd_self_script)
    self.self_script = self_script
    return self_script

  def Cleanup(self):
    if self.self_script:
      test.CheckedUnlink(self.self_script)

class MjsunitTestConfiguration(test.TestConfiguration):

  def __init__(self, context, root):
    super(MjsunitTestConfiguration, self).__init__(context, root)

  def Ls(self, path):
    def SelectTest(name):
      return name.endswith('.js') and name != 'mjsunit.js'
    return [f[:-3] for f in os.listdir(path) if SelectTest(f)]

  def ListTests(self, current_path, path, mode):
    mjsunit = [current_path + [t] for t in self.Ls(self.root)]
    regress = [current_path + ['regress', t] for t in self.Ls(join(self.root, 'regress'))]
    bugs = [current_path + ['bugs', t] for t in self.Ls(join(self.root, 'bugs'))]
    third_party = [current_path + ['third_party', t] for t in self.Ls(join(self.root, 'third_party'))]
    tools = [current_path + ['tools', t] for t in self.Ls(join(self.root, 'tools'))]
    compiler = [current_path + ['compiler', t] for t in self.Ls(join(self.root, 'compiler'))]
    all_tests = mjsunit + regress + bugs + third_party + tools + compiler
    result = []
    for test in all_tests:
      if self.Contains(path, test):
        file_path = join(self.root, reduce(join, test[1:], "") + ".js")
        result.append(MjsunitTestCase(test, file_path, mode, self.context, self))
    return result

  def GetBuildRequirements(self):
    return ['sample', 'sample=shell']

  def GetTestStatus(self, sections, defs):
    status_file = join(self.root, 'mjsunit.status')
    if exists(status_file):
      test.ReadConfigurationInto(status_file, sections, defs)



def GetConfiguration(context, root):
  return MjsunitTestConfiguration(context, root)
