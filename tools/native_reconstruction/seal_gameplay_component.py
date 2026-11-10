"""Shared dual-compiler evidence sealing for current native gameplay components."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def seal(*,target,suite,status,expected,extra_sources,binaries,prior,limitations,test_count=12,ports=None):
    target=ROOT/target;assert not target.exists()
    sources,cohorts,parent_checks,qualified_binaries={},{},{},{}
    observed=None
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/{suite}-{cc}-v1/receipt.json'
        receipt=json.loads(path.read_bytes());data=receipt['observed']
        assert receipt['status']=='passed' and receipt['source_unchanged']
        assert data==expected,(cc,data)
        if ports is not None:assert receipt['declared_ports']==ports
        assert observed is None or observed==data;observed=data
        for name,digest in receipt['source_sha256'].items():
            assert sha(ROOT/name)==digest,name
            assert name not in sources or sources[name]==digest,name
            sources[name]=digest
        for name,digest in receipt['output_sha256'].items():
            assert sha(path.parent/name)==digest,name
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=data)
        for kind in ['parent','tests']:
            path=ROOT/f'build-native-sjuni/{suite}-{kind}-{cc}-v1.log'
            raw=path.read_bytes();text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert (f'100% tests passed, 0 tests failed out of {test_count}' in text) if kind=='tests' else ('FAILED:' not in text and 'error:' not in text)
            parent_checks[path.relative_to(ROOT).as_posix()]=sha(path)
        for suffix in binaries:
            path=ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            qualified_binaries[path.relative_to(ROOT).as_posix()]=sha(path)
    for name in [*extra_sources,Path(__file__).relative_to(ROOT).as_posix()]:sources[name]=sha(ROOT/name)
    previous=ROOT/prior
    target.write_text(json.dumps(dict(schema=1,status=status,game_launched=False,installed_in_game=False,
        stage4_complete=False,source_sha256=sources,cohorts=cohorts,parent_checks=parent_checks,
        qualified_binaries=qualified_binaries,prior=dict(path=prior,sha256=sha(previous)),limitations=limitations),indent=2)+'\n')
    print(sha(target))
