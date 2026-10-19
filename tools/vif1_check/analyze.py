"""Inspect bounded VIF input boundaries without running native code or VU programs."""
import argparse
import collections
import copy
import json
import struct
from pathlib import Path

NAMES = {0:"NOP",1:"STCYCL",2:"OFFSET",3:"BASE",4:"ITOP",5:"STMOD",6:"MSKPATH3",
         7:"MARK",16:"FLUSHE",17:"FLUSH",19:"FLUSHA",20:"MSCAL",21:"MSCALF",
         23:"MSCNT",32:"STMASK",48:"STROW",49:"STCOL",74:"MPG",80:"DIRECT",81:"DIRECTHL"}

def analyze(directory, include_unfinished=False):
    records = [json.loads(line) for line in (directory/"vif1_buffers.jsonl").read_text().splitlines()]
    if not records:
        raise ValueError("no complete metadata records")
    unfinished = None
    if include_unfinished:
        index = records[-1]["index"] + 1
        filename = directory/f"vif1_{index:04d}.bin"
        if filename.exists():
            unfinished = index
            records.append({"index":index,"bytes":filename.stat().st_size,
                            "complete_file":True,"before":records[-1]["after"],
                            "note":"raw file exists; parser did not produce post-state metadata"})
    state = copy.deepcopy(records[0]["before"])
    pending = bytearray()
    payload = 0
    counts = collections.Counter()
    commands, fragmented, missing = [], [], []
    last_command = None
    for record in records:
        index = record["index"]
        filename = directory/f"vif1_{index:04d}.bin"
        if not record["complete_file"] or not filename.exists() or filename.stat().st_size != record["bytes"]:
            missing.append(index)
            break  # Later bytes cannot be interpreted as a continuous stream.
        if payload or pending:
            fragmented.append({"buffer":index, "remaining_payload":payload,
                               "pending_command_bytes":len(pending),
                               "command":last_command})
        pending.extend(filename.read_bytes())
        position = 0
        while True:
            if payload:
                consumed = min(payload, len(pending)-position)
                payload -= consumed
                position += consumed
                if payload:
                    break
            if len(pending)-position < 4:
                break
            word, = struct.unpack_from("<I", pending, position)
            position += 4
            op = (word>>24)&0x7f
            imm = word&0xffff
            num = (word>>16)&255
            name = "UNPACK" if op&0x60 == 0x60 else NAMES.get(op, "UNKNOWN")
            counts[f"{name}:0x{op:02x}"] += 1
            command = {"buffer":index,"word":f"{word:08x}","name":name,"num":num,"imm":imm}
            last_command = command
            if op == 1:
                state["cycle"] = imm
            elif op == 2:
                state["ofst"] = imm&1023
                state["tops"] = state["base"]
                state["stat"] &= ~128
            elif op == 3:
                state["base"] = imm&1023
            elif op == 4:
                state["itops"] = imm&1023
            elif op in (20,21,23):
                command["expected_top"] = state["tops"]&1023
                command["expected_itop"] = state["itops"]&1023
                state["top"] = state["tops"]&1023
                state["itop"] = state["itops"]&1023
                state["stat"] ^= 128
                state["tops"] = (state["base"]+(state["ofst"] if state["stat"]&128 else 0))&1023
                command["next_tops"] = state["tops"]
            elif op == 32:
                payload = 4
            elif op in (48,49):
                payload = 16
            elif op == 74:
                payload = (num or 256)*8
                command["destination"] = (imm*8)&16383
                command["wraps"] = command["destination"]+payload>16384
            elif op in (80,81):
                payload = (imm or 65536)*16
            elif op&0x60 == 0x60:
                vn,vl = (op>>2)&3,op&3
                bytes_per_vector = 2 if vn==3 and vl==3 else (vn+1)*(4 if vl==0 else 2 if vl in (1,3) else 1)
                cl,wl = state["cycle"]&255,(state["cycle"]>>8)&255 or 256
                writes = num or 256
                sources = writes if cl>=wl else (writes//wl)*cl+min(writes%wl,cl)
                payload = (sources*bytes_per_vector+3)&~3
                command.update(cl=cl,wl=wl,payload_bytes=payload,
                    destination=((imm&1023)+(state["tops"] if imm&0x8000 else 0))&1023)
            command["payload_bytes"] = payload
            if name not in ("NOP","DIRECT","DIRECTHL","FLUSH","FLUSHA","FLUSHE"):
                commands.append(command)
        del pending[:position]
    return {"directory":str(directory),"buffers":len(records),"input_bytes":sum(r["bytes"] for r in records),
            "complete_contiguous":not missing,"missing_or_incomplete":missing,"opcode_counts":dict(counts),
            "unfinished_buffer":unfinished,
            "fragmented_commands":fragmented,"remaining_payload":payload,"remaining_command_bytes":len(pending),
            "commands":commands,
            "note":"Expected TOP/ITOP transitions follow reference semantics. This parser classifies payload sizes; it does not execute UNPACK/VU or prove rendered output."}

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("directory",type=Path)
    parser.add_argument("--report",type=Path)
    parser.add_argument("--include-unfinished",action="store_true",
                        help="after process closure, inspect the next raw buffer without post-state metadata")
    args=parser.parse_args()
    result=analyze(args.directory,args.include_unfinished)
    output=json.dumps(result,indent=2)
    if args.report:
        args.report.write_text(output+"\n")
    summary={key:value for key,value in result.items() if key!="commands"}
    summary["selected_commands"]=result["commands"][:60]
    print(json.dumps(summary,indent=2))
if __name__=="__main__":
    main()
