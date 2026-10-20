"""Bound host registration functions without changing registered entries or their order."""
import re


def chunk_registrations(source, limit=256):
    if limit < 1:
        raise ValueError('Registration chunk limit must be positive')
    signature = re.search(r'^void (\w+)\(PS2Runtime& runtime\) \{\n', source, re.M)
    if not signature or source[signature.end():].rstrip()[-1:] != '}':
        raise ValueError('Unexpected registration function layout')
    body = source[signature.end():source.rfind('}')]
    # Only comments, whitespace and standalone registration calls are accepted.
    meaningful = re.sub(r'//[^\n]*', '', body)
    calls = [line.strip() for line in meaningful.splitlines() if line.strip()]
    if not all(re.fullmatch(r'runtime\.register(?:Overlay)?Function\([^;\n]+\);', line) for line in calls):
        raise ValueError('Registration function contains an unreviewed operation')
    if len(calls) <= limit:
        return source
    name = signature[1]
    prefix = source[:signature.start()]
    macro = 'REO_LOCAL_REGISTRATION_NOINLINE'
    prefix += ('#if defined(_MSC_VER)\n#define ' + macro + ' __declspec(noinline)\n'
               '#else\n#define ' + macro + ' __attribute__((noinline))\n#endif\n')
    helpers, invocations = [], []
    for i, start in enumerate(range(0, len(calls), limit)):
        helper = name + '_part_' + str(i)
        helpers.append('static ' + macro + ' void ' + helper + '(PS2Runtime& runtime) {\n' +
                       ''.join('    ' + call + '\n' for call in calls[start:start + limit]) + '}\n')
        invocations.append('    ' + helper + '(runtime);\n')
    return (prefix + ''.join(helpers) + '#undef ' + macro + '\n' +
            source[signature.start():signature.end()] + ''.join(invocations) + '}\n')
