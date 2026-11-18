"""Record the stock bank inventory and both original-dispatch comparisons."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
BUILD = ROOT / 'build-native-sjuni'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def identity(path):
    return dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path))


def read(path):
    return json.loads(path.read_text(encoding='utf-8-sig'))


def verify_sources(receipt):
    assert receipt['status'] == 'passed'
    assert not receipt['game_launched'] and not receipt['installed_in_game']
    assert all(sha(ROOT / name) == digest for name, digest in receipt['source_sha256'].items())


def main():
    cohorts = []
    for compiler in ('llvm', 'gcc'):
        inventory = BUILD / f'gameplay-script-content-{compiler}-v15'
        vm = BUILD / f'gameplay-scenario-stock-program-{compiler}-v1'
        receipts = [read(base / 'receipt.json') for base in (inventory, vm)]
        for receipt in receipts:
            verify_sources(receipt)
        for name, digest in receipts[0]['output_sha256'].items():
            assert sha(inventory / name) == digest
        assert receipts[1]['result']['stock_room_dispatches'] == 36
        assert sha(vm / 'owned_stock_room.rdt') == receipts[1]['stock_room']['sha256']
        assert receipts[0]['compiler_sha256'] == receipts[1]['compiler_sha256']
        actual = read(inventory / 'program-admission.json')
        stock = read(inventory / 'inventory.json')
        assert len(actual) == len(stock) == 171
        for entry, native in zip(stock, actual):
            for i, graph in enumerate(entry['profiles']):
                assert (native[i]['status'] == 0) == (
                    bool(graph['candidate_records']) and graph['closed_under_qualified_model']
                ), (entry['name'], graph['profile'], native[i])
        cohorts.append(dict(
            compiler=compiler, compiler_sha256=receipts[1]['compiler_sha256'],
            inventory_receipt=identity(inventory / 'receipt.json'),
            native_admission=identity(inventory / 'program-admission.json'),
            vm_receipt=identity(vm / 'receipt.json'),
            result=receipts[1]['result'],
        ))
    assert cohorts[0]['result'] == cohorts[1]['result']
    assert cohorts[0]['native_admission']['sha256'] == cohorts[1]['native_admission']['sha256']
    accepted = [sum(row[i]['status'] == 0 for row in actual) for i in (0, 1)]
    assert accepted == [25, 20]
    result = dict(
        schema='reo.native.gameplay.stock_program.qualification.v1',
        status='passed', admitted=dict(zip(('ordinary', 'offline_actor'), accepted)),
        owned_banks=171, stock_room=receipts[1]['stock_room'],
        cohorts=cohorts, source_sha256=receipts[1]['source_sha256'],
        additional_test_sources=[
            identity(ROOT / 'game/native/gameplay_scenario' / name)
            for name in ('CMakeLists.txt', 'script_program_tests.cpp')
        ],
        documentation=identity(ROOT / 'docs/native-gameplay/SCENARIO_STOCK_PROGRAMS.md'),
        stage4_complete=False, game_launched=False, installed_in_game=False,
        limitations=[
            'Native admission establishes bounded control flow and Program payload validity.',
            'All five scenario EVBs still have unsupported behavior.',
            'Only r0417300 was executed through the original and native VM in this comparison.',
            'The stock RDT was used for script bytes. Runtime scene providers were controlled fixtures.',
        ],
    )
    output = ROOT / 'tools/native_reconstruction/native_stock_script_program_qualification_v1.json'
    with output.open('x', encoding='utf-8') as target:
        target.write(json.dumps(result, indent=2) + '\n')
    print(json.dumps(dict(path=output.relative_to(ROOT).as_posix(), sha256=sha(output), admitted=result['admitted'])))


if __name__ == '__main__':
    main()
