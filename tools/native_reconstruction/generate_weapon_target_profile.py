"""Extract immutable65ED70/65F060 limits from the owned File1 overlay."""
import hashlib,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
data=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
assert hashlib.sha256(data).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
angles=struct.unpack_from('<8H',data,0x71b960-0x570000)
ranges=[data[0x719a6a-0x570000+68*i] for i in range(64)]
text='// Owned File1 o2: regenerate with generate_weapon_target_profile.py.\n'
text+='constexpr std::array<std::uint16_t,8> aim_angles{{'+','.join(map(str,angles))+'}};\n'
text+='constexpr std::array<std::uint8_t,64> aim_range_hundreds{{'+','.join(map(str,ranges))+'}};\n'
(ROOT/'game/native/gameplay_world/weapon_target_profile.inc').write_text(text)
