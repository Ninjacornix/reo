#!/usr/bin/env python3
"""Transport frozen original SJRB inputs to the standalone real native core.

No expected-output field generates commands or enters native code. This file
was authored after frozen_identity.json, not used to derive the original oracle.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
COHORTS = {
    'e0cef81bc8d6c546481a0258c3a66f13ef42d9f3ec94e5a61aa2e1a52fbca021':
        ('v3-smaller-synthetic-pcm', '13dc90fbcfa9a6380c3bb664f9de0ef89597023ce77eaee347064efc155f9564'),
    'f59c20e67e99bdf6a1d023dd4c4e5667278ea675b27181005e4e28d4c35955c9':
        ('v4-actual-pcm-byte-geometry', '0fbd6dc535541105733bcc295cf0494132e52ca391df63e244f3a70b14240a35'),
}
EXCLUDED = {
    'second-object-and-destroy-reuse': 'Original global pool/object destruction is outside standalone Ring.',
    'module-references-clear-not-backing': 'Original global module reference lifecycle is outside standalone Ring.',
    'pool-exhaustion': 'Original 256-object pool admission is outside standalone Ring.',
    'zero-capacity-unget-original-break': 'Zero capacity refuses native whole geometry before effects; original BREAK is retained in original fixture.',
    'zero-capacity-get-undefined-div-refusal': 'Zero capacity refuses native whole geometry before effects; original partial DIV refusal remains recorded.',
    'negative-request-observation-outside-adxt': 'Negative Get would create an unsafe negative position; native admission refuses before effects.',
}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def require(condition, message):
    if not condition:
        raise RuntimeError(message)


def signed(value):
    return value - (1 << 32) if value & (1 << 31) else value


def project(words):
    return dict(capacity=signed(words[8]), extension=signed(words[9]),
                data=signed(words[3]), free=signed(words[4]), write=signed(words[5]), read=signed(words[6]),
                totals=words[10:14])


def commands(inputs):
    """Authored input fields ONLY; no expected dictionaries are accepted."""
    require(set(inputs) == {'name', 'capacity', 'extension', 'actions'}, 'Unexpected input schema')
    result = [f"NEW {inputs['capacity']} {inputs['extension']}"]
    index = 0
    for action in inputs['actions']:
        if 'call' in action:
            name, args = action['call'], action['arguments']
            if name not in ('initialize', 'create'):
                result.append(f"CALL {index} {name} {len(args)} " + ' '.join(map(str, args)))
            index += 1
        elif 'words' in action:
            result.append(f"WORDS {action['words']} {len(action['values'])} " + ' '.join(map(str, action['values'])))
        elif 'bytes' in action:
            result.append(f"BYTES {action['bytes']} {action['hex']}")
        elif 'callback_words' in action:
            result.append(f"CALLBACK {action['callback_words']} {len(action['values'])} " + ' '.join(map(str, action['values'])))
        else:
            raise RuntimeError('Unadmitted input action')
    return '\n'.join(result) + '\n'


def expected_events(operation):
    result = []
    for event in operation['events']:
        kind = {'enter': 'E', 'leave': 'L', 'error_callback': 'X', 'diagnostic': 'D'}.get(event['kind'])
        if kind is None:
            continue  # generic memset/memcpy hook is not a typed-core callback
        row = dict(kind=kind, before=event['guard_depth_before'], after=event['guard_depth_after'])
        if kind in ('X', 'D'):
            row.update(state=project(event['object_words_before']), descriptors=event['descriptors_before_hex'])
            if kind == 'X':
                row.update(code=event['error_i32'], context=event['arguments_u64'][0] & 0xFFFFFFFF)
        result.append(row)
    return result


def compare_case(inputs, original, observed):
    expected = []
    guards = callbacks = returns = physical_bytes = state_fields = 0
    for index, op in enumerate(original['operations']):
        name = op['action']['call']
        if name in ('initialize', 'create'):
            continue
        old = op['expected']
        require(old['status'] == 'returned', 'Partial original case cannot silently enter parity domain')
        backing = bytes.fromhex(old['after']['backing_with_guards_hex'])
        require(backing[:16] == b'\xa5' * 16 and backing[-16:] == b'\xa5' * 16, 'Original backing guard changed')
        events = expected_events(old)
        value = old['return_u32'] if name not in ('uuid', 'buffer') else None
        expected.append(dict(index=index, op=name, state=project(old['after']['object_words_u32']),
            descriptors=old['after']['descriptors_hex'], backing=backing[16:-16].hex(), events=events, **{'return': value}))
        state_fields += 10  # six signed words plus four raw transfer words
        physical_bytes += len(backing) - 32
        guards += sum(event['kind'] in ('E', 'L') for event in events)
        callbacks += sum(event['kind'] in ('X', 'D') for event in events)
        returns += value is not None
    require(len(observed) == len(expected), f"{inputs['name']}: observation count differs")
    for index, (actual, old) in enumerate(zip(observed, expected)):
        if actual != old:
            differences = {key: dict(native=actual.get(key), original=old[key]) for key in old if actual.get(key) != old[key]}
            # Full observations are saved separately; don't echo megabytes.
            raise RuntimeError(f"{inputs['name']} call {index} ({old['op']}) differs in {list(differences)}")
    return dict(calls=len(expected), state_words=state_fields, physical_bytes=physical_bytes,
                descriptor_bytes=256 * len(expected), guard_events=guards, error_callbacks=callbacks, defined_returns=returns)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler', default='g++')
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--fixture', type=Path, default=ROOT / 'build-native-sjuni/sjrb-oracle-v4/original-fixture.json')
    args = parser.parse_args()
    output = args.output.resolve()
    require(not output.exists(), 'Select a new output directory; no evidence is overwritten')
    frozen = json.loads((HERE / 'frozen_identity.json').read_bytes())
    for name, value in frozen['source_sha256'].items():
        require(sha((HERE / name).read_bytes()) == value, 'Frozen implementation differs: ' + name)
    fixture_data = args.fixture.read_bytes()
    fixture_sha = sha(fixture_data)
    require(fixture_sha in COHORTS, 'Frozen original fixture changed')
    cohort, input_sha = COHORTS[fixture_sha]
    fixture = json.loads(fixture_data)
    inputs_path = ROOT / fixture['inputs_file']
    inputs_data = inputs_path.read_bytes()
    require(sha(inputs_data) == input_sha == fixture['inputs_sha256'], 'Frozen authored inputs changed')
    input_rows = json.loads(inputs_data)['cases']
    originals = {row['name']: row for row in fixture['cases']}
    compiler = shutil.which(args.compiler)
    require(compiler is not None, 'Compiler unavailable')
    output.mkdir(parents=True)
    compiled = []
    for source, target in [('sjrb_tests.cpp', 'units.exe'), ('fixture_runner.cpp', 'fixture_runner.exe')]:
        command = [compiler, '-std=c++20', '-O2', '-Wall', '-Wextra', '-Wpedantic', '-Werror',
                   str(HERE / 'sjrb.cpp'), str(HERE / source), '-o', str(output / target)]
        ran = subprocess.run(command, capture_output=True, text=True)
        (output / (target + '-compile.txt')).write_text(ran.stdout + ran.stderr)
        require(ran.returncode == 0, 'Isolated compilation failed: ' + ran.stderr)
        compiled.append(dict(command=command, binary_sha256=sha((output / target).read_bytes())))
    unit = subprocess.run([str(output / 'units.exe')], capture_output=True, text=True)
    (output / 'unit-output.txt').write_text(unit.stdout + unit.stderr)
    require(unit.returncode == 0, 'Native unit checks failed')
    cases = []
    for inputs in input_rows:
        name = inputs['name']
        if name in EXCLUDED:
            continue
        authored = commands(inputs)
        command_file = output / (name + '.commands')
        command_file.write_text(authored, encoding='utf-8')
        ran = subprocess.run([str(output / 'fixture_runner.exe'), str(command_file)], capture_output=True, text=True)
        (output / (name + '-native.jsonl')).write_text(ran.stdout, encoding='utf-8')
        require(ran.returncode == 0, f'{name}: native command failed: {ran.stderr}')
        observed = [json.loads(line) for line in ran.stdout.splitlines()]
        cases.append(dict(name=name, input_commands_sha256=sha(authored.encode()),
                          observations_sha256=sha(ran.stdout.encode()), **compare_case(inputs, originals[name], observed)))
    receipt = dict(schema=1, provenance='Core frozen after original-oracle exposure, before comparator development. Synthetic parity only.',
        result='passed', frozen_identity_sha256=sha((HERE / 'frozen_identity.json').read_bytes()),
        cohort=cohort, original_fixture_sha256=fixture_sha, original_inputs_sha256=input_sha,
        source_sha256={name: sha((HERE / name).read_bytes()) for name in
                       ('sjrb.hpp', 'sjrb.cpp', 'sjrb_tests.cpp', 'fixture_runner.cpp', 'compare_original.py')},
        compiler=compiler, compiler_sha256=sha(Path(compiler).read_bytes()), compiled=compiled,
        units=unit.stdout.strip(), excluded_cases=EXCLUDED, cases=cases,
        totals={field: sum(row[field] for row in cases) for field in
                ('calls', 'state_words', 'physical_bytes', 'descriptor_bytes', 'guard_events', 'error_callbacks', 'defined_returns')},
        projections=['Original module init/create are replaced only as an initial standalone owner seed, not compared.',
            'Source backing-pointer and UUID return addresses have no typed-core address return; their returns are excluded.',
            'Exact physical bytes, numeric descriptor spans, numeric ring state, defined numeric returns and guard/error observations are compared.',
            'Guest ABI/context/stack writes and generic libc hook-call boundaries have no native layout equivalent and are excluded.'])
    (output / 'receipt.json').write_text(json.dumps(receipt, indent=2, sort_keys=True) + '\n')
    print(json.dumps(dict(result='passed', cases=len(cases), units=unit.stdout.strip(), **receipt['totals'], receipt=str(output / 'receipt.json')), indent=2))


if __name__ == '__main__':
    main()
