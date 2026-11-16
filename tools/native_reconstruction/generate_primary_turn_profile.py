"""Extract typed, immutable 65F580 turn-rate content from the owned File1 image."""
import hashlib,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
image=ROOT/'build-function-index/owned-overlays/o2.bin';data=image.read_bytes()
assert hashlib.sha256(data).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
def values(at,n,kind='h'):return struct.unpack_from('<'+str(n)+kind,data,at-0x570000)
def matrix(name,rows):
    rows=list(rows)
    return 'constexpr std::array<std::array<std::int16_t,'+str(len(rows[0]))+'>'+','+str(len(rows))+'> '+name+'{{\n'+''.join('    {{'+','.join(map(str,row))+'}},\n' for row in rows)+'}};\n'
text='// Owned File1 o2: complete65F580 turn tables; regenerate with generate_primary_turn_profile.py.\n'
for name,at in [('digital_turns',0x71b430),('analog_turns',0x71b7e0)]:
    text+=matrix(name,(values(ptr,40) for ptr in values(at,10,'I')))
text+=matrix('aim_turns',(values(0x71b360+26*i,13) for i in range(4)))
text+=matrix('digital_character_turns',(values(0x71b3d0+16*i,8) for i in range(6)))
text+=matrix('analog_character_turns',(values(0x71b780+16*i,8) for i in range(6)))
text+='constexpr std::array<std::int16_t,10> status_turns{{'+','.join(map(str,values(0x71b810,10)))+'}};\n'
text+='constexpr std::array<std::array<std::uint8_t,2>,64> turn_resource_classes{{\n'
text+=''.join('    {{'+str(data[0x719a64-0x570000+68*i])+','+str(data[0x719a65-0x570000+68*i])+'}},\n' for i in range(64))+'}};\n'
assert values(0x740638,1,'I')==(0x3f99999a,)
(ROOT/'game/native/gameplay_world/primary_turn_profile.inc').write_text(text)
print('Extracted 64 resource classes, 20 movement rows, 4 aim rows and 12 character rows')
