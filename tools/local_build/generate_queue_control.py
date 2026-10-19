"""Translate a bounded integer queue closure from the user's verified ELF.

Only source PCs are published. All instruction operands and control flow come
from the local ELF; generated output must stay in private build storage.
"""

import hashlib
import json
from pathlib import Path
import struct
import argparse


def scalar(word):
    op, rs, rt, rd, shift, fn = word >> 26, word >> 21 & 31, word >> 16 & 31, word >> 11 & 31, word >> 6 & 31, word & 63
    imm = word & 65535
    signed = imm if imm < 32768 else imm - 65536
    h = lambda value: f"0x{value & 0xffffffff:08x}u"
    address = f"(g32({rs}u) + {h(signed)})"
    if word == 0:
        return []
    if op == 0:
        expressions = {0: f"g32({rt}u) << ({h(shift)} & 31u)",
                       2: f"g32({rt}u) >> ({h(shift)} & 31u)",
                       0x21: f"g32({rs}u) + g32({rt}u)",
                       0x2d: f"g64({rs}u) + g64({rt}u)",
                       0x24: f"g64({rs}u) & g64({rt}u)",
                       0x2a: f"static_cast<int64_t>(g64({rs}u)) < static_cast<int64_t>(g64({rt}u)) ? 1u : 0u",
                       0x2b: f"g64({rs}u) < g64({rt}u) ? 1u : 0u",
                       0x3c: f"g64({rt}u) << {shift + 32}u",
                       0x3e: f"g64({rt}u) >> {shift + 32}u"}
        if fn in expressions:
            setter = "set32" if fn in {0, 2, 0x21} else "set64"
            return [f"{setter}({rd}u, {expressions[fn]});"]
    expressions = {9: ("set32", f"g32({rs}u) + {h(signed)}"),
                   11: ("set64", f"g64({rs}u) < static_cast<uint64_t>(static_cast<int64_t>(static_cast<int16_t>({h(imm)}))) ? 1u : 0u"),
                   12: ("set64", f"g64({rs}u) & {h(imm)}"),
                   15: ("set32", f"{h(imm)} << 16u"),
                   35: ("set32", f"read32({address})"),
                   55: ("set64", f"read64({address})")}
    if op in expressions:
        setter, expression = expressions[op]
        return [f"{setter}({rt}u, {expression});"]
    actions = {31: f"saveOpaque({rt}u, {address});", 30: f"restoreOpaque({rt}u, {address});",
               43: f"write32({address}, g32({rt}u));", 63: f"write64({address}, g64({rt}u));"}
    if op in actions:
        return [actions[op]]
    raise ValueError("Unsupported instruction in admitted integer queue closure")


def generate(elf, plan, output):
    image, plan = Path(elf).read_bytes(), json.loads(Path(plan).read_text())
    if plan.get("format") != 1 or hashlib.sha256(image).hexdigest() != plan["elfSha256"]:
        raise ValueError("Unsupported queue-control source ELF")
    phoff = struct.unpack_from("<I", image, 28)[0]
    phsize, count = struct.unpack_from("<HH", image, 42)
    segments = [struct.unpack_from("<8I", image, phoff + i * phsize) for i in range(count)]

    def word(pc):
        if pc & 3:
            raise ValueError("Unaligned source PC")
        for kind, offset, address, _, size, *_ in segments:
            if kind == 1 and address <= pc and pc + 4 <= address + size:
                return struct.unpack_from("<I", image, offset + pc - address)[0]
        raise ValueError("Queue source PC is not in the ELF")

    source = ["// Generated locally from owned game instructions; do not distribute.",
              "inline void reo_gpu_upstream::QueueControlAdapter::State::run() { for (;;) {",
              "if (pc == static_cast<uint32_t>(call.returnPc_)) { append(QueueOperation::Pc,128u*4u,pc); return; }",
              "if (pc == 0x18dca0u && call.resolver_->kind() == QueueResolverKind::NativeRawPointerPassthrough) {",
              "tick(0x18dca0u); set64(2u,uint64_t(g32(4u))); pc=g32(31u); append(QueueOperation::Pc,128u*4u,pc);",
              'if (++instructions > 8192u) throw std::invalid_argument("Native queue control event budget exhausted"); continue; }',
              "switch (pc) {"]
    starts = set()
    for block in plan["blocks"]:
        pc, sites = block["pc"], block["sites"]
        if pc in starts or not sites or sites[0] != pc or sites != list(range(pc, sites[-1] + 4, 4)):
            raise ValueError("Invalid queue closure block metadata")
        starts.add(pc)
        source.append(f"case 0x{pc:x}u: {{")
        transfer, branch_pc = None, None
        for site in sites:
            w = word(site)
            op, rs, rt, fn = w >> 26, w >> 21 & 31, w >> 16 & 31, w & 63
            source.append(f"tick(0x{site:x}u);")
            control = op in {2, 3, 4, 5} or op == 0 and fn == 8
            if control:
                if transfer is not None:
                    raise ValueError("Nested queue delay slot")
                branch_pc = site
                if op in {4, 5}:
                    imm = w & 65535
                    displacement = imm if imm < 32768 else imm - 65536
                    target = site + 4 + displacement * 4
                    if rs == rt == 0:
                        condition = "true" if op == 4 else "false"
                    else:
                        right = f"g64({rt}u)" if rt else "0u"
                        condition = f"(g64({rs}u) {'==' if op == 4 else '!='} {right})"
                    source.append("const bool taken = " + condition + ";")
                    transfer = f"pc = taken ? 0x{target:x}u : 0x{site + 8:x}u;"
                elif op in {2, 3}:
                    target = ((site + 4) & 0xf0000000) | (w & 0x3ffffff) * 4
                    if op == 3:
                        source.append(f"set64(31u,0x{site + 8:x}u);")
                    transfer = f"pc = 0x{target:x}u;"
                else:
                    source.append(f"const uint32_t next = g32({rs}u);")
                    transfer = "pc = next;"
            else:
                source.extend(scalar(w))
        if branch_pc is not None and sites[-1] == branch_pc:
            if word(branch_pc + 4) != 0:
                raise ValueError("Queue metadata omitted a nonempty delay slot")
        if branch_pc is not None and sites[-1] > branch_pc:
            if sites[-1] != branch_pc + 4:
                raise ValueError("Queue block extends beyond delay slot")
            source.append(f"branch(0x{branch_pc:x}u);")
        source.append(transfer or f"pc = 0x{sites[-1] + 4:x}u;")
        source.extend(["break;", "}"])
    source += ['default: throw std::invalid_argument("Queue branch target leaves actual source closure");', "} } }"]
    output = Path(output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text("\n".join(source) + "\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ["elf", "plan", "output"]:
        parser.add_argument("--" + name, type=Path, required=True)
    args = parser.parse_args()
    generate(args.elf, args.plan, args.output)
