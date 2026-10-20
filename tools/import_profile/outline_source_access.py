"""Create an isolated cold-path candidate without editing the active runtime.

The cache-miss body is moved verbatim. Hot cache checks, validation, guest state
access, ownership and exception behavior remain present. Admission still requires
native behavior and performance checks; this tool never changes a release kit.
"""
import difflib
import hashlib
import json
from pathlib import Path
import sys


def closing_brace(text, start):
    depth = 0
    for index in range(start, len(text)):
        if text[index] == '{':
            depth += 1
        elif text[index] == '}':
            depth -= 1
            if not depth:
                return index
    raise ValueError('Unclosed cache-refresh body')


def outline(source):
    signature = 'inline const std::shared_ptr<ControlTarget>& selectedTarget(const void* ram)'
    marker = 'REO_SOURCE_COLD_NOINLINE'
    if source.count(signature) != 1 or marker in source:
        raise ValueError('Unexpected source-access header revision')
    start = source.index(signature)
    begin = source.index('{', start)
    finish = closing_brace(source, begin)
    function = source[start:finish+1]
    branch = function.index('if(accessCache.ram!=ram')
    branch_begin = function.index('{', branch)
    branch_end = closing_brace(function, branch_begin)
    body = function[branch_begin+1:branch_end]
    if 'findActualOwnerTarget(ram)' not in body or 'accessCache=std::move(next);' not in body:
        raise ValueError('Unrecognized cache refresh; refuse to rewrite it')
    macro = ('#if defined(_MSC_VER)\n#define ' + marker + ' __declspec(noinline)\n'
             '#else\n#define ' + marker + ' __attribute__((noinline))\n#endif\n')
    helper = marker + ' inline void refreshSelectedTarget(const void* ram){' + body + '\n}\n'
    rewritten = function[:branch_begin+1] + '\n        refreshSelectedTarget(ram);\n    ' + function[branch_end:]
    candidate = source[:start] + macro + helper + rewritten + source[finish+1:]
    failure = '[[noreturn]] inline void propagateOwnedFailure(PS2Runtime* runtime)'
    if candidate.count(failure) != 1:
        raise ValueError('Unrecognized failure path')
    candidate = candidate.replace(failure, '[[noreturn]] ' + marker + ' inline void propagateOwnedFailure(PS2Runtime* runtime)')
    candidate += '\n#undef ' + marker + '\n'
    # Recovering the old function must restore every original token and guard.
    restored = rewritten.replace('\n        refreshSelectedTarget(ram);\n    ', body)
    assert restored == function
    return candidate, {'refreshBodySha256': hashlib.sha256(body.encode()).hexdigest(),
                       'refreshBodyMovedVerbatim': True, 'hotCacheChecksUnchanged': True,
                       'failureBodyUnchanged': True}


def outline_owned_access(source):
    marker = 'REO_SOURCE_COLD_NOINLINE'
    read_signature = 'template<class T> T readField(R5900Context& ctx,const T* field)'
    start = source.index(read_signature)
    finish = closing_brace(source, source.index('{', start))
    original = source[start:finish+1]
    condition = 'if(target&&(target->ownsAnySource()||target->readyForSelection())){'
    if original.count(condition) != 2:
        raise ValueError('Unexpected read validation sequence')
    first = original.index(condition)+len(condition)-1
    first_end = closing_brace(original, first)
    before_body = original[first+1:first_end]
    second = original.index(condition, first_end)+len(condition)-1
    second_end = closing_brace(original, second)
    after_body = original[second+1:second_end]
    if 'target->read(' not in before_body or 'recordActualGuardedContextInput' not in after_body:
        raise ValueError('Unrecognized owned read operations')
    # Template helpers retain the original sizeof(T), value object and callbacks.
    helpers = (f'template<class T> {marker} void beforeOwnedFieldRead('
               'const std::shared_ptr<ControlTarget>& target,R5900Context& ctx,PS2Runtime* runtime,uint32_t at){'
               + before_body + '\n}\n'
               + f'template<class T> {marker} void afterOwnedFieldRead('
               'const std::shared_ptr<ControlTarget>& target,R5900Context& ctx,uint32_t at,T& value){'
               + after_body + '\n}\n')
    before_call = '\n            beforeOwnedFieldRead<T>(target,ctx,runtime,at);\n        '
    after_call = 'afterOwnedFieldRead(target,ctx,at,value);'
    rewritten = (original[:first+1] + before_call + original[first_end:second+1]
                 + after_call + original[second_end:])
    assert rewritten.replace(before_call, before_body).replace(after_call, after_body) == original
    source = source[:start] + helpers + rewritten + source[finish+1:]

    write_signature = 'template<class T> void writeField('
    start = source.index(write_signature)
    finish = closing_brace(source, source.index('{', start))
    original = source[start:finish+1]
    fast = original.index('if(!target||(!target->ownsAnySource()&&!target->readyForSelection())){')
    body_start = closing_brace(original, original.index('{', fast))+1
    body_end = original.rindex('\n    }catch(...){propagateOwnedFailure(currentRuntime());}')
    body = original[body_start:body_end]
    if 'exact->abandonSourceWrite(permit)' not in body or 'beginGuardedCpuContextWrite' not in body:
        raise ValueError('Unrecognized owned write protocol')
    helper = (f'template<class T> {marker} void writeOwnedField('
              'R5900Context& ctx,T* field,T& value,const InstructionOrigin& origin,'
              'const std::shared_ptr<ControlTarget>& target,uint32_t at){' + body + '\n}\n')
    call = '\n        writeOwnedField(ctx,field,value,origin,target,at);'
    rewritten = original[:body_start]+call+original[body_end:]
    assert rewritten.replace(call, body) == original
    source = source[:start]+helper+rewritten+source[finish+1:]
    return source, {'ownedReadCallbacksMovedVerbatim': True, 'ownedWriteBodyMovedVerbatim': True,
                    'cpuAccessChecksUnchanged': True,
                    'ownedWriteBodySha256': hashlib.sha256(body.encode()).hexdigest()}


def main():
    source_path = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    repo = Path(__file__).resolve().parents[2]
    if not destination.is_relative_to(repo / 'build-ninja') or destination.exists():
        raise ValueError('Use a fresh private candidate directory')
    source = source_path.read_text(encoding='utf-8')
    candidate, evidence = outline(source)
    if '--owned-paths' in sys.argv[3:]:
        candidate, extra = outline_owned_access(candidate)
        evidence.update(extra)
    destination.mkdir(parents=True)
    (destination / source_path.name).write_text(candidate, encoding='utf-8', newline='\n')
    relative = 'third_party/PS2Recomp/ps2xRuntime/src/lib/source_instruction_access.hpp'
    (destination / 'candidate.patch').write_text(''.join(difflib.unified_diff(
        source.splitlines(keepends=True), candidate.splitlines(keepends=True),
        fromfile='a/'+relative, tofile='b/'+relative)), encoding='utf-8', newline='\n')
    evidence.update({'source': str(source_path), 'sourceSha256': hashlib.sha256(source.encode()).hexdigest(),
                     'candidateSha256': hashlib.sha256(candidate.encode()).hexdigest(),
                     'acceptedForRelease': False, 'gameExecuted': False})
    (destination / 'candidate.json').write_text(json.dumps(evidence, indent=2))
    print(json.dumps(evidence, indent=2))


if __name__ == '__main__':
    main()
