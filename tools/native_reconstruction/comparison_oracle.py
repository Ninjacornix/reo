"""Cache separately compiled owned comparison bodies with complete input identity.

The current fixture and final executable are always rebuilt. An oracle object
is reusable only when the compiler, generated original bodies, test runtime
headers and every compile flag match. Each cohort retains a verified copy.
"""
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import uuid


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def compile_oracle(root, out, compiler, flags, env):
    unit = out / 'oracle.cpp'
    unit.write_text('#include "reference.hpp"\n#include "functions.h"\n#pragma GCC diagnostic push\n#pragma GCC diagnostic ignored "-Wunused-variable"\n#include "original_visuals.cpp"\n#pragma GCC diagnostic pop\n')
    inputs = sorted(set([unit, out / 'original_visuals.cpp', *out.glob('*.h'), *out.glob('*.hpp')]))
    compile_flags = [*flags, f'-ffile-prefix-map={out}=reo-comparison']
    identity = dict(schema=1, compiler_sha256=sha(compiler), sources={p.name:sha(p) for p in inputs}, flags=[arg.replace(str(out), '<cohort>') for arg in compile_flags])
    key = hashlib.sha256(json.dumps(identity, sort_keys=True).encode()).hexdigest()
    cache = root / 'build-native-sjuni/comparison-oracle-cache-v1'
    cache.mkdir(exist_ok=True)
    metadata = cache / (key + '.json')
    target = out / 'oracle.o'
    hit = False
    if metadata.is_file():
        prior = json.loads(metadata.read_bytes())
        previous = cache / (key + '-' + prior['object_sha256'] + '.o')
        if prior['identity'] == identity and previous.is_file() and sha(previous) == prior['object_sha256']:
            shutil.copyfile(previous, target)
            hit = True
    command = [str(compiler), *compile_flags, '-c', str(unit), '-o', str(target)]
    if not hit:
        result = subprocess.run(command, capture_output=True, env=env, timeout=180)
        (out / 'compile-oracle.stdout.txt').write_bytes(result.stdout)
        (out / 'compile-oracle.stderr.txt').write_bytes(result.stderr)
        assert result.returncode == 0, 'Original comparison object failed; see retained compile-oracle logs'
    object_hash = sha(target)
    if not hit:
        content = cache / (key + '-' + object_hash + '.o')
        temporary = cache / (uuid.uuid4().hex + '.tmp')
        shutil.copyfile(target, temporary)
        os.replace(temporary, content)
        temporary = cache / (uuid.uuid4().hex + '.tmp')
        temporary.write_text(json.dumps(dict(identity=identity, object_sha256=object_hash), sort_keys=True) + '\n')
        os.replace(temporary, metadata)
    receipt = dict(identity=identity, cache_key=key, cache_hit=hit, object='oracle.o', object_sha256=object_hash, command=command)
    (out / 'original-object.json').write_text(json.dumps(receipt, indent=2) + '\n')
    return str(target), receipt
