"""Read original gameplay/input/transition state from bounded full EE snapshots."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import sys


def snapshot(path):
    ram = path.read_bytes()
    if len(ram) != 32*1024*1024:
        raise RuntimeError('Snapshot must contain complete original EE RAM')
    def u32(a): return struct.unpack_from('<I', ram, a)[0]
    def u16(a): return struct.unpack_from('<H', ram, a)[0]
    def f3(a): return list(struct.unpack_from('<3f', ram, a))
    def readable_pointer(a, size):
        return 0x100000 <= a < len(ram) and 0 < size <= len(ram)-a
    def front_work(address):
        pointer = u32(address)
        valid = readable_pointer(pointer, 2)
        return {'pointer':hex(pointer), 'valid':valid,
                'mode':ram[pointer] if valid else None,
                'substate':ram[pointer+1] if valid else None}
    message = u32(0x4A5C20)
    message_valid = readable_pointer(message, 0x18)
    actors = []
    for player in range(4):
        base = 0x4A5C30+player*0x10E0
        manager = u32(base+0x34)
        motion_root = u32(manager+0x828) if 0<manager<len(ram)-0x82C else 0
        actors.append({'base':hex(base), 'active':ram[base], 'type':ram[base+2],
                       'player':ram[base+3], 'state':list(ram[base+8:base+12]),
                       'xyz':f3(base+0x38), 'yaw':struct.unpack_from('<h',ram,base+0x92)[0],
                       'animation':hex(u16(base+0x520)),
                       'animation_frames':f3(base+0x1E4),
                       'animation_flags':ram[base+0x1F1],
                       'animation_class':hex(u16(base+0x1F2)),
                       'root_displacement':f3(base+0x4E4),
                       'speed':struct.unpack_from('<f',ram,base+0xBA8)[0],
                       'motion_mode':ram[base+0xB98],
                       'extra_root':hex(motion_root),
                       'extra_root_position':f3(motion_root+0x70) if 0<motion_root<len(ram)-0x80 else None,
                       'extra_root_previous':struct.unpack_from('<f',ram,base+0xCE4)[0],
                       'edge':hex(u32(base+0xF78)), 'held':hex(u32(base+0xF80)),
                       'left_magnitude':u16(base+0xF98),
                       'left_angle':struct.unpack_from('<h',ram,base+0xF9A)[0],
                       'left_xy':list(struct.unpack_from('<2h',ram,base+0xF9C)),
                       'input_gate':ram[base+0xBD0], 'flags':hex(u32(base+0xBA0)),
                       'flags_ba4':hex(u32(base+0xBA4)),
                       'inventory_slots':list(ram[base+0xC84:base+0xC88]),
                       'candidate':list(ram[base+0xAB8:base+0xABC]),
                       'event_candidate':list(ram[base+0xC74:base+0xC79])})
    return {'file':str(path), 'second':int(re.search(r'eeram_(\d+)\.bin',path.name)[1]),
            'sha256':hashlib.sha256(ram).hexdigest(),
            'phase':ram[0x4BADD0], 'phase_substate':ram[0x4BADD1],
            'room':u16(0x3243DC), 'destination_room':u16(0x3243E2),
            'transition_request':ram[0x4BAE07], 'destination_door':ram[0x4BAE05],
            'cinematic':ram[0x4BADF8], 'global_input_gate':ram[0x4BAE8D],
            'controlled_player':ram[0x4BADED], 'inventory_owner':ram[0x4BADEE],
            'inventory_initialized':ram[0x4BAE33],
            'inventory_state':list(ram[0x755EC0:0x755EC6]),
            'inventory_page':ram[0x759C9E],
            'inventory_edge':hex(u16(0x759BA0)),
            'world_message':{'pointer':hex(message), 'valid':message_valid,
                             'busy':ram[0x4BAE0A],
                             'message_id':u16(message+0x12) if message_valid else None,
                             'callback':hex(u32(message+0x14)) if message_valid else None},
            'options_state':{'stage':ram[0x755EC0], 'row':ram[0x755EC1],
                             'substate':ram[0x755EC2], 'yes_no':ram[0x755EC3],
                             'ui_type':ram[0x755EC4], 'pause':ram[0x4BAE94]},
            'front_work_shared':front_work(0x324424),
            'front_work_cached':front_work(0x5D4898),
            'quit_state':{'front_reason':ram[0x324489],
                          'requested':ram[0x4BAE76], 'confirmed':ram[0x4BAE77]},
            'raw_left':list(ram[0x2B09E6:0x2B09E8]),
            'normalized_left':list(struct.unpack_from('<2h',ram,0x324264)),
            'camera_position':f3(0x324138),'camera_target':f3(0x324144),
            'event_list_root':hex(u32(0x3B5160)), 'actors':actors}


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('run',type=Path)
    parser.add_argument('--out',type=Path)
    args=parser.parse_args()
    paths=sorted(args.run.glob('eeram_*.bin'),key=lambda p:int(re.search(r'eeram_(\d+)',p.name)[1]))
    rows=[]
    for path in paths:
        if path.stat().st_size != 32*1024*1024:
            print('Skipping incomplete live snapshot: '+str(path),file=sys.stderr)
            continue
        rows.append(snapshot(path))
    if args.out:
        args.out.parent.mkdir(parents=True,exist_ok=True)
        args.out.write_text(json.dumps(rows,indent=2))
    for row in rows:
        actor=row['actors'][0]
        print(f"{row['second']:3}s phase={row['phase']:02X}/{row['phase_substate']} "
              f"room={row['room']}->{row['destination_room']} request={row['transition_request']} "
              f"modal={row['inventory_owner']}/{row['inventory_state'][4]} "
              f"actor={actor['active']} state={actor['state']} xyz={actor['xyz']} "
              f"yaw={actor['yaw']} held={actor['held']} left={actor['left_xy']} "
              f"candidate={actor['candidate']} event={actor['event_candidate']}")


if __name__=='__main__':main()
