"""Prototype an inline empty-input fast path; keep owned cleanup out of line."""
import difflib
import hashlib
import json
from pathlib import Path
import sys

from outline_source_access import closing_brace


def transform(source):
    scope = source.index('class InstructionInputScope final {')
    start = source.index('    void at(uint32_t pc,uint32_t opcode){', scope)
    end = closing_brace(source, source.index('{', start)) + 1
    original = source[start:end]
    expected = '''    void at(uint32_t pc,uint32_t opcode){
        if(storage_){if(storage_->life->instruction==UINT64_MAX)throw std::overflow_error("Instruction input identity exhausted");++storage_->life->instruction;}
        origin_={pc,opcode,ContextWriteIntent::NumericOrOpaque};target_.reset();reads_=0;transfers_=0;
    }'''
    if original != expected:
        raise ValueError('Unexpected instruction-advance contract; refuse to rewrite')
    helpers = '''    static REO_INPUT_OUTLINE void advanceOwnedInstruction(InstructionInputStorage& storage){
        if(storage.life->instruction==UINT64_MAX)throw std::overflow_error("Instruction input identity exhausted");
        ++storage.life->instruction;
    }
    static REO_INPUT_OUTLINE void releaseInputTarget(std::shared_ptr<reo_parent_natural::ControlTarget>& target){
        target.reset();
    }
'''
    replacement = '''    void at(uint32_t pc,uint32_t opcode){
        if(storage_)advanceOwnedInstruction(*storage_);
        origin_={pc,opcode,ContextWriteIntent::NumericOrOpaque};
        // Also release aliasing shared_ptrs with a null stored pointer, and
        // non-owning aliases with a stored pointer but no control block.
        if(target_||target_.use_count()!=0)releaseInputTarget(target_);
        reads_=0;transfers_=0;
    }'''
    candidate = source[:start] + replacement + source[end:]
    public = candidate.index('\npublic:', scope)
    candidate = candidate[:public]+'\n'+helpers+candidate[public:]
    macro = ('#if defined(_MSC_VER)\n#define REO_INPUT_OUTLINE __declspec(noinline)\n'
             '#else\n#define REO_INPUT_OUTLINE __attribute__((noinline))\n#endif\n')
    candidate = candidate[:scope]+macro+candidate[scope:]+'\n#undef REO_INPUT_OUTLINE\n'
    return candidate, original, helpers+replacement


def main():
    source = Path(sys.argv[1]).resolve()
    out = Path(sys.argv[2]).resolve()
    repo = Path(__file__).resolve().parents[2]
    if not out.is_relative_to(repo/'build-ninja') or out.exists():
        raise ValueError('Use a fresh private candidate directory')
    text = source.read_text(encoding='utf-8')
    candidate, original_method, candidate_methods = transform(text)
    out.mkdir(parents=True)
    header = out / source.name
    header.write_text(candidate, encoding='utf-8', newline='\n')
    relative = 'third_party/PS2Recomp/ps2xRuntime/src/lib/'+source.name
    (out/'candidate.patch').write_text(''.join(difflib.unified_diff(text.splitlines(keepends=True),
        candidate.splitlines(keepends=True), fromfile='a/'+relative, tofile='b/'+relative)), encoding='utf-8')
    (out/'overlay.json').write_text(json.dumps({'version': 0, 'case-sensitive': False, 'use-external-names': False,
        'roots': [{'type': 'file', 'name': source.as_posix(), 'external-contents': header.as_posix()}]}, indent=2))
    (out/'candidate.json').write_text(json.dumps({'source': str(source),
        'sourceSha256': hashlib.sha256(text.encode()).hexdigest(),
        'candidateSha256': hashlib.sha256(candidate.encode()).hexdigest(),
        'originalMethod': original_method, 'candidateMethods': candidate_methods,
        'acceptedForRelease': False, 'gameExecuted': False}, indent=2))
    print('Wrote private instruction-input candidate and VFS overlay:', out)


if __name__ == '__main__':
    main()
