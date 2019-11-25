"""
This script generates:
1) Nodes identifiers for NodesIdentifierSingleton
2) Differentiation funcs for ExpressionTree
"""

import sys

FUNC_COUNTER = 1


class IdentifiersGenerator:
    def __init__(self, file):
        self.file = file

    def __del__(self):
        self.file.close()

    def generate_identifier(self, func):
        func_name = func.split('\n')[0].split(' ')[1]
        self.file.write('identifiers_[\"{name}\"] = {digit};\n'.format(
                            name=func_name, digit=FUNC_COUNTER))


class InverseIdentifiersGenerator:
    def __init__(self, file):
        self.file = file

    def __del__(self):
        self.file.close()

    def generate_identifier(self, func):
        func_name = func.split('\n')[0].split(' ')[1]
        self.file.write('inverse_identifiers_[{digit}] = \"{name}\";\n'.format(
                            name=func_name, digit=FUNC_COUNTER))


class DerivativeGenerator:
    def __init__(self, file):
        self.file = file
        self.file.write('#include <DerivativesDefines.h>\n')

    def __del__(self):
        self.file.write('\n#include <DerivativesUndefs.h>\n')
        self.file.close()


    def generate_derivative(self, func):
        func_code = '\n'.join(func.split('\n')[1:])
        self.file.write('case {func_num}:\n{code}'.format(
            func_num=FUNC_COUNTER, code=func_code))


if __name__ == '__main__':
    functions = open(sys.argv[1] + '/functions.cpp', 'r')
    identifiers_generator =\
        IdentifiersGenerator(
            open(sys.argv[1] +
                 '/headers/generated/FunctionsIdentifiers.h', 'w'))
    inverse_identifiers_generator =\
        InverseIdentifiersGenerator(
            open(sys.argv[1] +
                 '/headers/generated/InverseFunctionsIdentifiers.h', 'w'))
    derivative_generator =\
        DerivativeGenerator(open(sys.argv[1] +
                            '/headers/generated/FunctionsDerivatives.h', 'w'))

    lines = list(functions)
    it = iter(lines)
    current_func = ''
    try:
        while True:
            line = next(it)
            current_func += line
            if line.startswith('}'):
                identifiers_generator.generate_identifier(current_func)
                inverse_identifiers_generator.generate_identifier(current_func)
                derivative_generator.generate_derivative(current_func)
                FUNC_COUNTER += 1
                current_func = ''
    except StopIteration:
        pass
    finally:
        functions.close()
